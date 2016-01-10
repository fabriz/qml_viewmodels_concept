#include "edit_field_backend_base.hpp"

#include "abstract_view_model.hpp"


namespace ViewModelsFramework
{


EditFieldBackendBase::EditFieldBackendBase(QObject* parent) : FieldBackendBase(parent)
{
}


EditFieldBackendBase::EditFieldBackendBase(AbstractViewModel* parent, int fieldId, const QString& label) :
    FieldBackendBase(parent, fieldId, label),
    m_readOnly(false)
{
}


EditFieldBackendBase::~EditFieldBackendBase()
{
}


bool EditFieldBackendBase::readOnly() const
{
    return m_readOnly;
}


void EditFieldBackendBase::setReadOnly(bool value)
{
    if (m_readOnly != value)
    {
        m_readOnly = value;
        emit readOnlyChanged();
    }
}


void EditFieldBackendBase::beginFieldUpdate()
{
    FieldBackendBase::beginFieldUpdate();

    m_readOnly.storeCurrentValue();
}


void EditFieldBackendBase::endFieldUpdate()
{
    FieldBackendBase::endFieldUpdate();

    if (m_readOnly.isCurrentValueDifferentFromStoredValue())
    {
        emit readOnlyChanged();
    }
}


} // namespace ViewModelsFramework
