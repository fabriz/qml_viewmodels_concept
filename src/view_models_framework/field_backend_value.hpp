#ifndef FIELD_BACKEND_VALUE_HPP
#define FIELD_BACKEND_VALUE_HPP


namespace ViewModelsFramework
{


template <typename TYPE>
class FieldBackendValue
{
public:

    FieldBackendValue() :
        m_value(nullptr),
        m_originalValue(TYPE()),
        m_storedValue(TYPE())
    {
    }

    FieldBackendValue(TYPE& value) :
        m_value(&value),
        m_originalValue(value),
        m_storedValue(value)
    {
    }

    const TYPE& originalValue() const
    {
        return m_originalValue;
    }

    operator const TYPE& () const
    {
        return *m_value;
    }

    FieldBackendValue<TYPE>& operator=(const TYPE& value)
    {
        *m_value = value;
        return *this;
    }

    void storeCurrentValue()
    {
        m_storedValue = *m_value;
    }

    bool isCurrentValueDifferentFromStoredValue() const
    {
        return (m_storedValue != *m_value);
    }

    bool isCurrentValueDifferentFromOriginalValue() const
    {
        return (m_originalValue != *m_value);
    }

private:

    TYPE*   m_value;
    TYPE    m_originalValue;
    TYPE    m_storedValue;
};


} // namespace ViewModelsFramework

#endif // FIELD_BACKEND_VALUE_HPP
