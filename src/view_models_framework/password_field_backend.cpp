#include "password_field_backend.hpp"

#include "abstract_view_model.hpp"


namespace ViewModelsFramework
{


PasswordFieldBackend::PasswordFieldBackend(QObject* parent) : EditFieldBackendBase(parent)
{
}


PasswordFieldBackend::PasswordFieldBackend(AbstractViewModel* parent, QString& value, int fieldId, const QString& label) :
    EditFieldBackendBase(parent, fieldId, label),
    m_value(value)
{
    connect(this, SIGNAL(valueChanged()), parent, SLOT(onFieldChanged()));
}


PasswordFieldBackend::~PasswordFieldBackend()
{
}


QString PasswordFieldBackend::value() const
{
    return m_value;
}


QString PasswordFieldBackend::placeholderText() const
{
    return m_placeholderText;
}


void PasswordFieldBackend::setValue(const QString& value)
{
    if (m_value != value)
    {
        m_value = value;
        emit valueChanged();
    }
}


void PasswordFieldBackend::setPlaceholderText(const QString& value)
{
    if (m_placeholderText != value)
    {
        m_placeholderText = value;
        emit placeholderTextChanged();
    }
}


void PasswordFieldBackend::beginFieldUpdate()
{
    EditFieldBackendBase::beginFieldUpdate();

    m_value.storeCurrentValue();
    m_placeholderText.storeCurrentValue();
}


void PasswordFieldBackend::endFieldUpdate()
{
    EditFieldBackendBase::endFieldUpdate();

    if (m_value.isCurrentValueDifferentFromStoredValue())
    {
        emit valueChanged();
    }

    if (m_placeholderText.isCurrentValueDifferentFromStoredValue())
    {
        emit placeholderTextChanged();
    }
}

} // namespace ViewModelsFramework
