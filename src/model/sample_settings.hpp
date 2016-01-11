#ifndef SAMPLE_SETTINGS_HPP
#define SAMPLE_SETTINGS_HPP


namespace Model
{


enum CurrencyUnit
{
    CURRENCY_UNIT_EURO = 0,
    CURRENCY_UNIT_DOLLAR,
    CURRENCY_UNIT_POUND,
    CURRENCY_UNIT_YEN,
};

inline QString currencyUnitToString(CurrencyUnit unit)
{
    switch (unit)
    {
    case CURRENCY_UNIT_EURO:    return QString::fromUtf8("Euro (\xE2\x82\xAC)");
    case CURRENCY_UNIT_DOLLAR:  return QString("Dollar ($)");
    case CURRENCY_UNIT_POUND:   return QString::fromUtf8("Pound (\xC2\xA3)");
    case CURRENCY_UNIT_YEN:     return QString::fromUtf8("Yen (\xC2\xA5)");
    default:                    return QString("Unknown (?)");
    }
}

inline QString currencyUnitToSymbol(CurrencyUnit unit)
{
    switch (unit)
    {
    case CURRENCY_UNIT_EURO:    return QString::fromUtf8("\xE2\x82\xAC");
    case CURRENCY_UNIT_DOLLAR:  return QString("$");
    case CURRENCY_UNIT_POUND:   return QString::fromUtf8("\xC2\xA3");
    case CURRENCY_UNIT_YEN:     return QString::fromUtf8("\xC2\xA5");
    default:                    return QString("?");
    }
}


enum TemperatureUnit : int
{
    TEMPERATURE_UNIT_CELSIUS = 0,
    TEMPERATURE_UNIT_FAHRENHEIT,
    TEMPERATURE_UNIT_KELVIN,
};

inline QString temperatureUnitToString(TemperatureUnit unit)
{
    switch (unit)
    {
    case TEMPERATURE_UNIT_CELSIUS:      return QString::fromUtf8("Celsius (\xC2\xB0" "C)");
    case TEMPERATURE_UNIT_FAHRENHEIT:   return QString::fromUtf8("Fahrenheit (\xC2\xB0" "F)");
    case TEMPERATURE_UNIT_KELVIN:       return QString("Kelvin (K)");
    default:                            return QString("Unknown (?)");
    }
}

inline QString temperatureUnitToSymbol(TemperatureUnit unit)
{
    switch (unit)
    {
    case TEMPERATURE_UNIT_CELSIUS:      return QString::fromUtf8("\xC2\xB0" "C");
    case TEMPERATURE_UNIT_FAHRENHEIT:   return QString::fromUtf8("\xC2\xB0" "F");
    case TEMPERATURE_UNIT_KELVIN:       return QString("K");
    default:                            return QString("?");
    }
}




class SampleSettings
{
public:

    QString userName;
    QString password;
    QString firstName;
    QString lastName;
    QString street;
    QString city;
    QString stateOrProvince;
    QString postalCode;
    QString country;

    bool enablePriceFields = false;
    CurrencyUnit priceUnit = CURRENCY_UNIT_EURO;
    double priceMin = 10.0;
    double priceMax = 100.0;
    double priceValue = 30.0;

    bool enableTemperatureFields = false;
    TemperatureUnit temperatureUnit = TEMPERATURE_UNIT_CELSIUS;
    double temperatureMin = 0.0;
    double temperatureMax = 30.0;
    double temperatureValue = 20.0;

    QString notes;
};


} // namespace Model

#endif // SAMPLE_SETTINGS_HPP
