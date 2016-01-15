#include "switch_field_backend.hpp"

#include "abstract_view_model.hpp"


namespace ViewModelsFramework
{


SwitchFieldBackend::SwitchFieldBackend(QObject* parent) : FieldBackendBase(parent)
{
}


SwitchFieldBackend::SwitchFieldBackend(AbstractViewModel* parent, bool& value, int fieldId, const QString& label) :
    FieldBackendBase(parent, fieldId, label),
    m_value(value)
{
    connect(this, SIGNAL(valueChanged()), parent, SLOT(onFieldChanged()));
}


SwitchFieldBackend::~SwitchFieldBackend()
{
}


bool SwitchFieldBackend::value() const
{
    return m_value;
}


bool SwitchFieldBackend::isChangedFromOriginalValue() const
{
    return m_value.isCurrentValueDifferentFromOriginalValue();
}


void SwitchFieldBackend::restoreOriginalValue()
{
    setValue(m_value.originalValue());
}


void SwitchFieldBackend::setValue(bool value)
{
    if (m_value != value)
    {
        m_value = value;
        emit valueChanged();
    }
}


void SwitchFieldBackend::beginFieldUpdate()
{
    FieldBackendBase::beginFieldUpdate();

    m_value.storeCurrentValue();
}


void SwitchFieldBackend::endFieldUpdate()
{
    FieldBackendBase::endFieldUpdate();

    if (m_value.isCurrentValueDifferentFromStoredValue())
    {
        emit valueChanged();
    }
}


} // namespace ViewModelsFramework
