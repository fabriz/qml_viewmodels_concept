#include "memo_field_backend.hpp"

#include "abstract_view_model.hpp"


namespace ViewModelsFramework
{


MemoFieldBackend::MemoFieldBackend(QObject* parent) : EditFieldBackendBase(parent)
{
}


MemoFieldBackend::MemoFieldBackend(AbstractViewModel* parent, QString& value, int fieldId, const QString& label) :
    EditFieldBackendBase(parent, fieldId, label),
    m_value(value)
{
    connect(this, SIGNAL(valueChanged()), parent, SLOT(onFieldChanged()));
}


MemoFieldBackend::~MemoFieldBackend()
{
}


QString MemoFieldBackend::value() const
{
    return m_value;
}


bool MemoFieldBackend::isChangedFromOriginalValue() const
{
    return m_value.isCurrentValueDifferentFromOriginalValue();
}


void MemoFieldBackend::restoreOriginalValue()
{
    setValue(m_value.originalValue());
}


void MemoFieldBackend::setValue(const QString& value)
{
    if (m_value != value)
    {
        m_value = value;
        emit valueChanged();
    }
}


void MemoFieldBackend::beginFieldUpdate()
{
    EditFieldBackendBase::beginFieldUpdate();

    m_value.storeCurrentValue();
}


void MemoFieldBackend::endFieldUpdate()
{
    EditFieldBackendBase::endFieldUpdate();

    if (m_value.isCurrentValueDifferentFromStoredValue())
    {
        emit valueChanged();
    }
}


} // namespace ViewModelsFramework
