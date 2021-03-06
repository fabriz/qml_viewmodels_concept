#ifndef TEXT_FIELD_BACKEND_HPP
#define TEXT_FIELD_BACKEND_HPP

#include <QString>

#include "edit_field_backend_base.hpp"


namespace ViewModelsFramework
{

class TextFieldBackend : public EditFieldBackendBase
{
    Q_OBJECT

    Q_PROPERTY(QString value READ value NOTIFY valueChanged)
    Q_PROPERTY(QString placeholderText READ placeholderText NOTIFY placeholderTextChanged)

public:
    explicit TextFieldBackend(QObject* parent = nullptr);
    explicit TextFieldBackend(AbstractViewModel* parent, QString& value, int fieldId = -1, const QString& label = QString());
    virtual ~TextFieldBackend();

    QString value() const;
    QString placeholderText() const;

    bool isChangedFromOriginalValue() const override;
    void restoreOriginalValue() override;

signals:
    void valueChanged();
    void placeholderTextChanged();

public slots:
    void setValue(const QString& value);
    void setPlaceholderText(const QString& value);

protected:
    void beginFieldUpdate() override;
    void endFieldUpdate() override;

private:
    FieldBackendValue<QString>      m_value;
    FieldBackendProperty<QString>   m_placeholderText;
};


} // namespace ViewModelsFramework

#endif // TEXT_FIELD_BACKEND_HPP
