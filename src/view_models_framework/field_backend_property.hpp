#ifndef FIELD_BACKEND_PROPERTY_HPP
#define FIELD_BACKEND_PROPERTY_HPP


namespace ViewModelsFramework
{


template <typename TYPE>
class FieldBackendProperty
{
public:

    FieldBackendProperty() :
        m_value(TYPE()),
        m_storedValue(TYPE())
    {
    }

    FieldBackendProperty(const TYPE& value) :
        m_value(value),
        m_storedValue(value)
    {
    }

    operator const TYPE&() const
    {
        return m_value;
    }

    FieldBackendProperty<TYPE>& operator=(const TYPE& value)
    {
        m_value = value;
        return *this;
    }

    void storeCurrentValue()
    {
        m_storedValue = m_value;
    }

    bool isCurrentValueDifferentFromStoredValue() const
    {
        return (m_storedValue != m_value);
    }

private:

    TYPE    m_value;
    TYPE    m_storedValue;
};


} // namespace ViewModelsFramework

#endif // FIELD_BACKEND_PROPERTY_HPP
