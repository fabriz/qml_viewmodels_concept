#include "quantity_field_backend.hpp"

#include <limits>
#include <cmath>

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


QuantityFieldBackend::QuantityFieldBackend(QObject* parent) : EditFieldBackendBase(parent)
{
}


QuantityFieldBackend::QuantityFieldBackend(AbstractViewModel* parent, double& value, int fieldId, const QString& label) :
    EditFieldBackendBase(parent, fieldId, label),
    m_value(value),
    m_minValue(std::numeric_limits<double>::lowest()),
    m_maxValue(std::numeric_limits<double>::max()),
    m_decimals(2),
    m_scalingFactor(1.0),
    m_valueOffset(0.0)
{
    connect(this, SIGNAL(valueChanged()), parent, SLOT(onFieldChanged()));
}


QuantityFieldBackend::~QuantityFieldBackend()
{
}


double QuantityFieldBackend::value() const
{
    return roundDouble(m_value, m_decimals);
}


double QuantityFieldBackend::minValue() const
{
    return roundDouble(m_minValue, m_decimals);
}


double QuantityFieldBackend::maxValue() const
{
    return roundDouble(m_maxValue, m_decimals);
}


int QuantityFieldBackend::decimals() const
{
    return m_decimals;
}


QString QuantityFieldBackend::prefixText() const
{
    return m_prefixText;
}


QString QuantityFieldBackend::suffixText() const
{
    return m_suffixText;
}


double QuantityFieldBackend::scalingFactor() const
{
    return m_scalingFactor;
}


double QuantityFieldBackend::valueOffset() const
{
    return m_valueOffset;
}


bool QuantityFieldBackend::isValueInRange() const
{
    return ((m_value >= m_minValue) && (m_value <= m_maxValue));
}


void QuantityFieldBackend::setValue(double value)
{
    if (m_value != value)
    {
        m_value = roundDouble(value, m_decimals);
        emit valueChanged();
    }
}


void QuantityFieldBackend::setMinValue(double value)
{
    if (m_minValue != value)
    {
        m_minValue = roundDouble(value, m_decimals);
        emit minValueChanged();
    }
}


void QuantityFieldBackend::setMaxValue(double value)
{
    if (m_maxValue != value)
    {
        m_maxValue = roundDouble(value, m_decimals);
        emit maxValueChanged();
    }
}


void QuantityFieldBackend::setValueRange(double minVal, double maxVal)
{
    setMinValue(minVal);
    setMaxValue(maxVal);
}


void QuantityFieldBackend::setDecimals(int value)
{
    if (m_decimals != value)
    {
        m_decimals = value;
        emit decimalsChanged();
    }
}


void QuantityFieldBackend::setPrefixText(const QString& value)
{
    if (m_prefixText != value)
    {
        m_prefixText = value;
        emit prefixTextChanged();
    }
}


void QuantityFieldBackend::setSuffixText(const QString& value)
{
    if (m_suffixText != value)
    {
        m_suffixText = value;
        emit suffixTextChanged();
    }
}


void QuantityFieldBackend::setScalingFactor(double value)
{
    if (m_scalingFactor != value)
    {
        m_scalingFactor = value;
        emit valueChanged();
    }
}


void QuantityFieldBackend::setValueOffset(double value)
{
    if (m_valueOffset != value)
    {
        m_valueOffset = value;
        emit valueChanged();
    }
}


void QuantityFieldBackend::beginFieldUpdate()
{
    EditFieldBackendBase::beginFieldUpdate();

    m_value.storeCurrentValue();
    m_minValue.storeCurrentValue();
    m_maxValue.storeCurrentValue();
    m_decimals.storeCurrentValue();
    m_prefixText.storeCurrentValue();
    m_suffixText.storeCurrentValue();
    m_scalingFactor.storeCurrentValue();
    m_valueOffset.storeCurrentValue();
}


void QuantityFieldBackend::endFieldUpdate()
{
    EditFieldBackendBase::endFieldUpdate();

    if (m_value.isCurrentValueDifferentFromStoredValue() ||
        m_scalingFactor.isCurrentValueDifferentFromStoredValue() ||
        m_valueOffset.isCurrentValueDifferentFromStoredValue())
    {
        emit valueChanged();
    }

    if (m_minValue.isCurrentValueDifferentFromStoredValue() ||
        m_scalingFactor.isCurrentValueDifferentFromStoredValue() ||
        m_valueOffset.isCurrentValueDifferentFromStoredValue())
    {
        emit minValueChanged();
    }

    if (m_maxValue.isCurrentValueDifferentFromStoredValue() ||
        m_scalingFactor.isCurrentValueDifferentFromStoredValue() ||
        m_valueOffset.isCurrentValueDifferentFromStoredValue())
    {
        emit maxValueChanged();
    }

    if (m_decimals.isCurrentValueDifferentFromStoredValue())
    {
        emit decimalsChanged();
    }

    if (m_prefixText.isCurrentValueDifferentFromStoredValue())
    {
        emit prefixTextChanged();
    }

    if (m_suffixText.isCurrentValueDifferentFromStoredValue())
    {
        emit suffixTextChanged();
    }
}


} // namespace ViewModelsFramework
