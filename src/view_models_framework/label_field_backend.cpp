#include "label_field_backend.hpp"

#include "abstract_view_model.hpp"


namespace ViewModelsFramework
{


LabelFieldBackend::LabelFieldBackend(QObject* parent) : EditFieldBackendBase(parent)
{
}


LabelFieldBackend::LabelFieldBackend(AbstractViewModel* parent, QString& value, int fieldId, const QString& label) :
    EditFieldBackendBase(parent, fieldId, label),
    m_value(value)
{
//    connect(this, SIGNAL(valueChanged()), parent, SLOT(onFieldChanged()));
}


LabelFieldBackend::~LabelFieldBackend()
{
}


QString LabelFieldBackend::value() const
{
    return m_value;
}


void LabelFieldBackend::setValue(const QString& value)
{
    if (m_value != value)
    {
        m_value = value;
        emit valueChanged();
    }
}


void LabelFieldBackend::beginFieldUpdate()
{
    EditFieldBackendBase::beginFieldUpdate();

    m_value.storeCurrentValue();
}


void LabelFieldBackend::endFieldUpdate()
{
    EditFieldBackendBase::endFieldUpdate();

    if (m_value.isCurrentValueDifferentFromStoredValue())
    {
        emit valueChanged();
    }
}

} // namespace ViewModelsFramework
