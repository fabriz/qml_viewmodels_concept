#ifndef DROP_DOWN_FIELD_BACKEND_HPP
#define DROP_DOWN_FIELD_BACKEND_HPP

#include <vector>

#include <QAbstractListModel>

#include "field_backend_base.hpp"


namespace ViewModelsFramework
{


// Forward declarations
class DropDownFieldBackendListModel;


class DropDownFieldBackendItems
{
public:

    DropDownFieldBackendItems() {}
    ~DropDownFieldBackendItems() {}

    void addItem(int value, const QString& text)
    {
        m_items.push_back(item {(int)m_items.size(), value, text});
    }

private:
    friend class DropDownFieldBackendListModel;

    struct item
    {
        int         index;
        int         value;
        QString     text;
    };

    std::vector<item>   m_items;
};




class DropDownFieldBackendListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_ENUMS(Roles)

public:

    enum Roles
    {
        ROLE_INDEX = Qt::UserRole + 1,
        ROLE_VALUE,
        ROLE_TEXT,
    };

    explicit DropDownFieldBackendListModel(const DropDownFieldBackendItems& model, QObject* parent = nullptr);
    virtual ~DropDownFieldBackendListModel();

    // Implementation of QAbstractListModel
    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    //QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    void updateViews();
    void setModel(const DropDownFieldBackendItems& model);

private:
    DropDownFieldBackendItems   m_model;
};




class DropDownFieldBackend : public FieldBackendBase
{
    Q_OBJECT

    Q_PROPERTY(int value READ value NOTIFY valueChanged)
    Q_PROPERTY(QAbstractListModel* model READ model CONSTANT)

public:
    explicit DropDownFieldBackend(QObject* parent = nullptr);
    DropDownFieldBackend(AbstractViewModel* parent, int& value, const DropDownFieldBackendItems& model, int fieldId = -1, const QString& label = QString());
    virtual ~DropDownFieldBackend();

    int value() const;
    QAbstractListModel* model() const;

signals:
    void valueChanged();

public slots:
    void setValue(int value);
    void setModel(const DropDownFieldBackendItems& model);

protected:
    void beginFieldUpdate() override;
    void endFieldUpdate() override;

private:
    FieldBackendValue<int>              m_value;
    DropDownFieldBackendListModel*      m_model;
    bool                                m_modelChanged;
};


} // namespace ViewModelsFramework

#endif // DROP_DOWN_FIELD_BACKEND_HPP
