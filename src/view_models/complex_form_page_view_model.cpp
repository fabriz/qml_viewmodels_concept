#include "complex_form_page_view_model.hpp"

#include <QMessageBox>


using namespace ViewModelsFramework;


namespace ViewModels
{


ComplexFormPageViewModel::ComplexFormPageViewModel(QObject* parent) : AbstractViewModel(parent)
{
    DropDownFieldBackendItems currencyUnits;
    currencyUnits.addItem(Model::CURRENCY_UNIT_EURO, Model::currencyUnitToString(Model::CURRENCY_UNIT_EURO));
    currencyUnits.addItem(Model::CURRENCY_UNIT_DOLLAR, Model::currencyUnitToString(Model::CURRENCY_UNIT_DOLLAR));
    currencyUnits.addItem(Model::CURRENCY_UNIT_POUND, Model::currencyUnitToString(Model::CURRENCY_UNIT_POUND));
    currencyUnits.addItem(Model::CURRENCY_UNIT_YEN, Model::currencyUnitToString(Model::CURRENCY_UNIT_YEN));

    DropDownFieldBackendItems temperatureUnits;
    temperatureUnits.addItem(Model::TEMPERATURE_UNIT_CELSIUS, Model::temperatureUnitToString(Model::TEMPERATURE_UNIT_CELSIUS));
    temperatureUnits.addItem(Model::TEMPERATURE_UNIT_FAHRENHEIT, Model::temperatureUnitToString(Model::TEMPERATURE_UNIT_FAHRENHEIT));
    temperatureUnits.addItem(Model::TEMPERATURE_UNIT_KELVIN, Model::temperatureUnitToString(Model::TEMPERATURE_UNIT_KELVIN));

    m_userName = new TextFieldBackend(this, m_modelEntity.userName);
    m_userName->setPlaceholderText("Insert your name");
    m_userName->statusMessages()->addHelpMessage("Ciao!");

    m_password = new PasswordFieldBackend(this, m_modelEntity.password);
    m_password->setPlaceholderText("Insert your password");
    m_password->statusMessages()->addWarningMessage("A good password is important!");

    m_firstName = new TextFieldBackend(this, m_modelEntity.firstName);
    m_lastName = new TextFieldBackend(this, m_modelEntity.lastName);
    m_street = new TextFieldBackend(this, m_modelEntity.street);
    m_city = new TextFieldBackend(this, m_modelEntity.city);
    m_stateOrProvince = new TextFieldBackend(this, m_modelEntity.stateOrProvince);
    m_postalCode = new TextFieldBackend(this, m_modelEntity.postalCode);
    m_country = new TextFieldBackend(this, m_modelEntity.country);

    m_enablePriceFields = new SwitchFieldBackend(this, m_modelEntity.enablePriceFields);

    m_priceUnit = new DropDownFieldBackend(this, *(int*)(&m_modelEntity.priceUnit), currencyUnits);

    m_priceMin = new QuantityFieldBackend(this, m_modelEntity.priceMin);
    m_priceMin->setValueRange(0, 200);
    m_priceMin->setDecimals(2);

    m_priceMax = new QuantityFieldBackend(this, m_modelEntity.priceMax);
    m_priceMax->setValueRange(0, 200);
    m_priceMax->setDecimals(2);

    m_priceValue = new QuantityFieldBackend(this, m_modelEntity.priceValue);
    m_priceValue->setValueRange(0, 200);
    m_priceValue->setDecimals(2);

    m_enableTemperatureFields = new SwitchFieldBackend(this, m_modelEntity.enableTemperatureFields);

    m_temperatureUnit = new DropDownFieldBackend(this, *(int*)(&m_modelEntity.temperatureUnit), temperatureUnits);

    m_temperatureMin = new QuantityFieldBackend(this, m_modelEntity.temperatureMin);
    m_temperatureMin->setValueRange(0, 30);
    m_temperatureMin->setDecimals(1);

    m_temperatureMax = new QuantityFieldBackend(this, m_modelEntity.temperatureMax);
    m_temperatureMax->setValueRange(0, 30);
    m_temperatureMax->setDecimals(1);

    m_temperatureValue = new QuantityFieldBackend(this, m_modelEntity.temperatureValue);
    m_temperatureValue->setValueRange(0, 30);
    m_temperatureValue->setDecimals(1);

    m_notes = new MemoFieldBackend(this, m_modelEntity.notes);

    updateView();
}


ComplexFormPageViewModel::~ComplexFormPageViewModel()
{
}


void ComplexFormPageViewModel::acceptButtonHandler()
{
}


void ComplexFormPageViewModel::do_updateView()
{
    AbstractViewModel::deleteFieldsMessagesBySeverity(FieldMessage::WARNING);

    m_priceUnit->setEnabled(m_modelEntity.enablePriceFields);
    m_priceMin->setEnabled(m_modelEntity.enablePriceFields);
    m_priceMax->setEnabled(m_modelEntity.enablePriceFields);
    m_priceValue->setEnabled(m_modelEntity.enablePriceFields);

    m_temperatureUnit->setEnabled(m_modelEntity.enableTemperatureFields);
    m_temperatureMin->setEnabled(m_modelEntity.enableTemperatureFields);
    m_temperatureMax->setEnabled(m_modelEntity.enableTemperatureFields);
    m_temperatureValue->setEnabled(m_modelEntity.enableTemperatureFields);

    m_priceMin->setPrefixText(Model::currencyUnitToSymbol(m_modelEntity.priceUnit));
    m_priceMax->setPrefixText(Model::currencyUnitToSymbol(m_modelEntity.priceUnit));
    m_priceValue->setPrefixText(Model::currencyUnitToSymbol(m_modelEntity.priceUnit));

    m_temperatureMin->setSuffixText(Model::temperatureUnitToSymbol(m_modelEntity.temperatureUnit));
    m_temperatureMax->setSuffixText(Model::temperatureUnitToSymbol(m_modelEntity.temperatureUnit));
    m_temperatureValue->setSuffixText(Model::temperatureUnitToSymbol(m_modelEntity.temperatureUnit));


    if (!m_priceMin->isValueInRange())
    {
        m_priceMin->statusMessages()->addErrorMessage("Value is out of range");
    }

    if (!m_priceMax->isValueInRange())
    {
        m_priceMax->statusMessages()->addErrorMessage("Value is out of range");
    }

    if (m_modelEntity.priceMin >= m_modelEntity.priceMax)
    {
        m_priceMin->statusMessages()->addErrorMessage("Invalid range");
        m_priceMax->statusMessages()->addErrorMessage("Invalid range");
    }

    if ((m_modelEntity.priceValue < m_modelEntity.priceMin) ||
        (m_modelEntity.priceValue > m_modelEntity.priceMax))
    {
        m_priceValue->statusMessages()->addErrorMessage("Value is out of range");
    }


    if (!m_temperatureMin->isValueInRange())
    {
        m_temperatureMin->statusMessages()->addErrorMessage("Value is out of range");
    }

    if (!m_temperatureMax->isValueInRange())
    {
        m_temperatureMax->statusMessages()->addErrorMessage("Value is out of range");
    }

    if (m_modelEntity.temperatureMin >= m_modelEntity.temperatureMax)
    {
        m_temperatureMin->statusMessages()->addErrorMessage("Invalid range");
        m_temperatureMax->statusMessages()->addErrorMessage("Invalid range");
    }

    if ((m_modelEntity.temperatureValue < m_modelEntity.temperatureMin) ||
        (m_modelEntity.temperatureValue > m_modelEntity.temperatureMax))
    {
        m_temperatureValue->statusMessages()->addErrorMessage("Value is out of range");
    }

}


} // namespace ViewModels







