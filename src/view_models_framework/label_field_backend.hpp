#ifndef LABEL_FIELD_BACKEND_HPP
#define LABEL_FIELD_BACKEND_HPP

#include <QString>

#include "edit_field_backend_base.hpp"


namespace ViewModelsFramework
{

class LabelFieldBackend : public EditFieldBackendBase
{
    Q_OBJECT

    Q_PROPERTY(QString value READ value NOTIFY valueChanged)

public:
    explicit LabelFieldBackend(QObject* parent = nullptr);
    explicit LabelFieldBackend(AbstractViewModel* parent, QString& value, int fieldId = -1, const QString& label = QString());
    virtual ~LabelFieldBackend();

    QString value() const;

signals:
    void valueChanged();

public slots:
    void setValue(const QString& value);

protected:
    void beginFieldUpdate() override;
    void endFieldUpdate() override;

private:
    FieldBackendValue<QString>      m_value;
};


} // namespace ViewModelsFramework

#endif // LABEL_FIELD_BACKEND_HPP
