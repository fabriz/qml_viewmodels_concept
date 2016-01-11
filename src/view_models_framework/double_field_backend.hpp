#ifndef DOUBLE_FIELD_BACKEND_HPP
#define DOUBLE_FIELD_BACKEND_HPP

#include "edit_field_backend_base.hpp"


namespace ViewModelsFramework
{


class DoubleFieldBackend : public EditFieldBackendBase
{
    Q_OBJECT

    Q_PROPERTY(double value READ value NOTIFY valueChanged)
    Q_PROPERTY(double minValue READ minValue NOTIFY minValueChanged)
    Q_PROPERTY(double maxValue READ maxValue NOTIFY maxValueChanged)
    Q_PROPERTY(int decimals READ decimals NOTIFY decimalsChanged)

public:
    explicit DoubleFieldBackend(QObject* parent = nullptr);
    explicit DoubleFieldBackend(AbstractViewModel* parent, double& value, int fieldId = -1, const QString& label = QString());

    virtual ~DoubleFieldBackend();

    double value() const;
    double minValue() const;
    double maxValue() const;
    int decimals() const;

    bool isValueInRange() const;

signals:
    void valueChanged();
    void minValueChanged();
    void maxValueChanged();
    void decimalsChanged();

public slots:
    void setValue(double value);
    void setMinValue(double value);
    void setMaxValue(double value);
    void setValueRange(double minVal, double maxVal);
    void setDecimals(int value);

protected:
    void beginFieldUpdate() override;
    void endFieldUpdate() override;

private:
    FieldBackendValue<double>       m_value;
    FieldBackendProperty<double>    m_minValue;
    FieldBackendProperty<double>    m_maxValue;
    FieldBackendProperty<int>       m_decimals;
};


} // namespace ViewModelsFramework

#endif // DOUBLE_FIELD_BACKEND_HPP

