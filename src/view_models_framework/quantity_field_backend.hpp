#ifndef QUANTITY_FIELD_BACKEND_HPP
#define QUANTITY_FIELD_BACKEND_HPP

#include "edit_field_backend_base.hpp"


namespace ViewModelsFramework
{


class QuantityFieldBackend : public EditFieldBackendBase
{
    Q_OBJECT

    Q_PROPERTY(double value READ value NOTIFY valueChanged)
    Q_PROPERTY(double minValue READ minValue NOTIFY minValueChanged)
    Q_PROPERTY(double maxValue READ maxValue NOTIFY maxValueChanged)
    Q_PROPERTY(int decimals READ decimals NOTIFY decimalsChanged)
    Q_PROPERTY(QString prefixText READ prefixText NOTIFY prefixTextChanged)
    Q_PROPERTY(QString suffixText READ suffixText NOTIFY suffixTextChanged)

public:
    explicit QuantityFieldBackend(QObject* parent = nullptr);
    explicit QuantityFieldBackend(AbstractViewModel* parent, double& value, int fieldId = -1, const QString& label = QString());

    virtual ~QuantityFieldBackend();

    double value() const;
    double minValue() const;
    double maxValue() const;
    int decimals() const;
    QString prefixText() const;
    QString suffixText() const;
    double scalingFactor() const;
    double valueOffset() const;

    bool isValueInRange() const;

signals:
    void valueChanged();
    void minValueChanged();
    void maxValueChanged();
    void decimalsChanged();
    void prefixTextChanged();
    void suffixTextChanged();

public slots:
    void setValue(double value);
    void setMinValue(double value);
    void setMaxValue(double value);
    void setValueRange(double minVal, double maxVal);
    void setDecimals(int value);
    void setPrefixText(const QString& value);
    void setSuffixText(const QString& value);
    void setScalingFactor(double value);
    void setValueOffset(double value);

protected:
    void beginFieldUpdate() override;
    void endFieldUpdate() override;

private:
    FieldBackendValue<double>       m_value;
    FieldBackendProperty<double>    m_minValue;
    FieldBackendProperty<double>    m_maxValue;
    FieldBackendProperty<int>       m_decimals;
    FieldBackendProperty<QString>   m_prefixText;
    FieldBackendProperty<QString>   m_suffixText;
    FieldBackendProperty<double>    m_scalingFactor;
    FieldBackendProperty<double>    m_valueOffset;
};


} // namespace ViewModelsFramework

#endif // QUANTITY_FIELD_BACKEND_HPP

