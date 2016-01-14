#include "view_models_registration.hpp"

#include <QtQml>

#include "basic_controls_page_view_model.hpp"
#include "simple_form_page_view_model.hpp"
#include "complex_form_page_view_model.hpp"
#include "many_fields_view_model.hpp"


namespace ViewModels
{


void registerTypes()
{
    //const char* namespaceUri = "ViewModels";

    qmlRegisterType<ViewModels::BasicControlsPageViewModel>("ViewModels", 1, 0, "BasicControlsPageViewModel");
    qmlRegisterType<ViewModels::SimpleFormPageViewModel>("ViewModels", 1, 0, "SimpleFormPageViewModel");
    qmlRegisterType<ViewModels::ComplexFormPageViewModel>("ViewModels", 1, 0, "ComplexFormPageViewModel");
    qmlRegisterType<ViewModels::ManyFieldsViewModel>("ViewModels", 1, 0, "ManyFieldsViewModel");
}


} // namespace ViewModels
