#include "double_field_backend.hpp"

#include <cmath>
#include <limits>

#include "abstract_view_model.hpp"


namespace
{

double roundDouble(double value, int decimals)
{
    return (std::floor((value * std::pow(10.0, decimals)) + 0.5) / std::pow(10.0, decimals));
}

}


namespace ViewModelsFramework
{


DoubleFieldBackend::DoubleFieldBackend(QObject* parent) : EditFieldBackendBase(parent)
{
}


DoubleFieldBackend::DoubleFieldBackend(AbstractViewModel* parent, double& value, int fieldId, const QString& label) :
    EditFieldBackendBase(parent, fieldId, label),
    m_value(value),
    m_minValue(std::numeric_limits<double>::lowest()),
    m_maxValue(std::numeric_limits<double>::max()),
    m_decimals(2)
{
    connect(this, SIGNAL(valueChanged()), parent, SLOT(onFieldChanged()));
}


DoubleFieldBackend::~DoubleFieldBackend()
{
}


double DoubleFieldBackend::value() const
{
    return roundDouble(m_value, m_decimals);
}


double DoubleFieldBackend::minValue() const
{
    return roundDouble(m_minValue, m_decimals);
}


double DoubleFieldBackend::maxValue() const
{
    return roundDouble(m_maxValue, m_decimals);
}


int DoubleFieldBackend::decimals() const
{
    return m_decimals;
}


void DoubleFieldBackend::setValue(double value)
{
    if (m_value != value)
    {
        m_value = roundDouble(value, m_decimals);
        emit valueChanged();
    }
}


void DoubleFieldBackend::setMinValue(double value)
{
    if (m_minValue != value)
    {
        m_minValue = roundDouble(value, m_decimals);
        emit minValueChanged();
    }
}


void DoubleFieldBackend::setMaxValue(double value)
{
    if (m_maxValue != value)
    {
        m_maxValue = roundDouble(value, m_decimals);
        emit maxValueChanged();
    }
}


void DoubleFieldBackend::setValueRange(double minVal, double maxVal)
{
    setMinValue(minVal);
    setMaxValue(maxVal);
}


void DoubleFieldBackend::setDecimals(int value)
{
    if (m_decimals != value)
    {
        m_decimals = value;
        emit decimalsChanged();
    }
}


void DoubleFieldBackend::beginFieldUpdate()
{
    EditFieldBackendBase::beginFieldUpdate();

    m_value.storeCurrentValue();
    m_minValue.storeCurrentValue();
    m_maxValue.storeCurrentValue();
    m_decimals.storeCurrentValue();
}


void DoubleFieldBackend::endFieldUpdate()
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

    if (m_decimals.isCurrentValueDifferentFromStoredValue())
    {
        emit decimalsChanged();
    }
}


} // namespace ViewModelsFramework
