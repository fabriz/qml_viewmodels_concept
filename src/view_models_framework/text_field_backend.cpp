#include "text_field_backend.hpp"

#include "abstract_view_model.hpp"


namespace ViewModelsFramework
{


TextFieldBackend::TextFieldBackend(QObject* parent) : EditFieldBackendBase(parent)
{
}


TextFieldBackend::TextFieldBackend(AbstractViewModel* parent, QString& value, int fieldId, const QString& label) :
    EditFieldBackendBase(parent, fieldId, label),
    m_value(value)
{
    connect(this, SIGNAL(valueChanged()), parent, SLOT(onFieldChanged()));
}


TextFieldBackend::~TextFieldBackend()
{
}


QString TextFieldBackend::value() const
{
    return m_value;
}


QString TextFieldBackend::placeholderText() const
{
    return m_placeholderText;
}


void TextFieldBackend::setValue(const QString& value)
{
    if (m_value != value)
    {
        m_value = value;
        emit valueChanged();
    }
}


void TextFieldBackend::setPlaceholderText(const QString& value)
{
    if (m_placeholderText != value)
    {
        m_placeholderText = value;
        emit placeholderTextChanged();
    }
}


void TextFieldBackend::beginFieldUpdate()
{
    EditFieldBackendBase::beginFieldUpdate();

    m_value.storeCurrentValue();
    m_placeholderText.storeCurrentValue();
}


void TextFieldBackend::endFieldUpdate()
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
