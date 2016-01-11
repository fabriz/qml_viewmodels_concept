#include "int_field_backend.hpp"

#include <limits>

#include "abstract_view_model.hpp"


namespace ViewModelsFramework
{


IntFieldBackend::IntFieldBackend(QObject* parent) : EditFieldBackendBase(parent)
{
}


IntFieldBackend::IntFieldBackend(AbstractViewModel* parent, int& value, int fieldId, const QString& label) :
    EditFieldBackendBase(parent, fieldId, label),
    m_value(value),
    m_minValue(std::numeric_limits<int>::min()),
    m_maxValue(std::numeric_limits<int>::max())
{
    connect(this, SIGNAL(valueChanged()), parent, SLOT(onFieldChanged()));
}


IntFieldBackend::~IntFieldBackend()
{
}


int IntFieldBackend::value() const
{
    return m_value;
}


int IntFieldBackend::minValue() const
{
    return m_minValue;
}


int IntFieldBackend::maxValue() const
{
    return m_maxValue;
}


bool IntFieldBackend::isValueInRange() const
{
    return ((m_value >= m_minValue) && (m_value <= m_maxValue));
}


void IntFieldBackend::setValue(int value)
{
    if (m_value != value)
    {
        m_value = value;
        emit valueChanged();
    }
}


void IntFieldBackend::setMinValue(int value)
{
    if (m_minValue != value)
    {
        m_minValue = value;
        emit minValueChanged();
    }
}


void IntFieldBackend::setMaxValue(int value)
{
    if (m_maxValue != value)
    {
        m_maxValue = value;
        emit maxValueChanged();
    }
}


void IntFieldBackend::setValueRange(int minVal, int maxVal)
{
    setMinValue(minVal);
    setMaxValue(maxVal);
}


void IntFieldBackend::beginFieldUpdate()
{
    EditFieldBackendBase::beginFieldUpdate();

    m_value.storeCurrentValue();
    m_minValue.storeCurrentValue();
    m_maxValue.storeCurrentValue();
}


void IntFieldBackend::endFieldUpdate()
{
    EditFieldBackendBase::endFieldUpdate();

    if (m_value.isCurrentValueDifferentFromStoredValue())
    {
        emit valueChanged();
    }

    if (m_minValue.isCurrentValueDifferentFromStoredValue())
    {
        emit minValueChanged();
    }

    if (m_maxValue.isCurrentValueDifferentFromStoredValue())
    {
        emit maxValueChanged();
    }
}


} // namespace ViewModelsFramework
