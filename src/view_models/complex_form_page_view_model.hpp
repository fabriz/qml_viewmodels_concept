#ifndef COMPLEX_FORM_PAGE_VIEW_MODEL_HPP
#define COMPLEX_FORM_PAGE_VIEW_MODEL_HPP

#include "view_models_framework/abstract_view_model.hpp"
#include "model/sample_settings.hpp"


namespace ViewModels
{


class ComplexFormPageViewModel : public ViewModelsFramework::AbstractViewModel
{
    Q_OBJECT

    DECLARE_FIELD_BACKEND(TextFieldBackend, userName)
    DECLARE_FIELD_BACKEND(PasswordFieldBackend, password)
    DECLARE_FIELD_BACKEND(TextFieldBackend, firstName)
    DECLARE_FIELD_BACKEND(TextFieldBackend, lastName)
    DECLARE_FIELD_BACKEND(TextFieldBackend, street)
    DECLARE_FIELD_BACKEND(TextFieldBackend, city)
    DECLARE_FIELD_BACKEND(TextFieldBackend, stateOrProvince)
    DECLARE_FIELD_BACKEND(TextFieldBackend, postalCode)
    DECLARE_FIELD_BACKEND(TextFieldBackend, country)
    DECLARE_FIELD_BACKEND(SwitchFieldBackend, enablePriceFields)
    DECLARE_FIELD_BACKEND(DropDownFieldBackend, priceUnit)
    DECLARE_FIELD_BACKEND(QuantityFieldBackend, priceMin)
    DECLARE_FIELD_BACKEND(QuantityFieldBackend, priceMax)
    DECLARE_FIELD_BACKEND(QuantityFieldBackend, priceValue)
    DECLARE_FIELD_BACKEND(SwitchFieldBackend, enableTemperatureFields)
    DECLARE_FIELD_BACKEND(DropDownFieldBackend, temperatureUnit)
    DECLARE_FIELD_BACKEND(QuantityFieldBackend, temperatureMin)
    DECLARE_FIELD_BACKEND(QuantityFieldBackend, temperatureMax)
    DECLARE_FIELD_BACKEND(QuantityFieldBackend, temperatureValue)
    DECLARE_FIELD_BACKEND(MemoFieldBackend, notes)

public:
    explicit ComplexFormPageViewModel(QObject* parent = nullptr);
    virtual ~ComplexFormPageViewModel();

    Q_INVOKABLE void acceptButtonHandler();

signals:

public slots:

private:
    void do_updateView() override;

    Model::SampleSettings   m_modelEntity;
};


} // namespace ViewModels

#endif // COMPLEX_FORM_PAGE_VIEW_MODEL_HPP
