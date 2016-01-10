#ifndef INT_FIELD_BACKEND_HPP
#define INT_FIELD_BACKEND_HPP

#include "edit_field_backend_base.hpp"


namespace ViewModelsFramework
{


class IntFieldBackend : public EditFieldBackendBase
{
    Q_OBJECT

    Q_PROPERTY(int value READ value NOTIFY valueChanged)
    Q_PROPERTY(int minValue READ minValue NOTIFY minValueChanged)
    Q_PROPERTY(int maxValue READ maxValue NOTIFY maxValueChanged)

public:
    explicit IntFieldBackend(QObject* parent = nullptr);
    explicit IntFieldBackend(AbstractViewModel* parent, int& value, int fieldId = -1, const QString& label = QString());

    virtual ~IntFieldBackend();

    int value() const;
    int minValue() const;
    int maxValue() const;

signals:
    void valueChanged();
    void minValueChanged();
    void maxValueChanged();

public slots:
    void setValue(int value);
    void setMinValue(int value);
    void setMaxValue(int value);
    void setValueRange(int minVal, int maxVal);

protected:
    void beginFieldUpdate() override;
    void endFieldUpdate() override;

private:
    FieldBackendValue<int>      m_value;
    FieldBackendProperty<int>   m_minValue;
    FieldBackendProperty<int>   m_maxValue;
};


} // namespace ViewModelsFramework

#endif // INT_FIELD_BACKEND_HPP

