#ifndef MEMO_FIELD_BACKEND_HPP
#define MEMO_FIELD_BACKEND_HPP

#include <QString>

#include "edit_field_backend_base.hpp"


namespace ViewModelsFramework
{

class MemoFieldBackend : public EditFieldBackendBase
{
    Q_OBJECT

    Q_PROPERTY(QString value READ value NOTIFY valueChanged)

public:
    explicit MemoFieldBackend(QObject* parent = nullptr);
    explicit MemoFieldBackend(AbstractViewModel* parent, QString& value, int fieldId = -1, const QString& label = QString());
    virtual ~MemoFieldBackend();

    QString value() const;

signals:
    void valueChanged();

public slots:
    void setValue(const QString& value);

protected:
    void beginFieldUpdate() override;
    void endFieldUpdate() override;

private:
    FieldBackendValue<QString>  m_value;
};


} // namespace ViewModelsFramework

#endif // MEMO_FIELD_BACKEND_HPP
