#include "view_models_framework_registration.hpp"

#include <QString>
#include <QtQml>

#include "abstract_view_model.hpp"


namespace ViewModelsFramework
{

void registerTypes()
{
    //const char* namespaceUri = "ViewModelsFramework";
    //const QString reason = "Field backends cannot be created in QML.";

    //qmlRegisterUncreatableType<ViewModelsFramework::TextFieldBackend>("ViewModelsFramework", 1, 0, "TextFieldBackend", reason);

    qmlRegisterUncreatableType<ViewModelsFramework::FieldMessage>("ViewModelsFramework", 1, 0, "FieldMessage", "");
    qmlRegisterUncreatableType<ViewModelsFramework::FieldMessages>("ViewModelsFramework", 1, 0, "FieldMessages", "");


    // TODO: All these types should be uncreatable

    qmlRegisterType<ViewModelsFramework::FieldBackendBase>("ViewModelsFramework", 1, 0, "FieldBackendBase");
    qmlRegisterType<ViewModelsFramework::DoubleFieldBackend>("ViewModelsFramework", 1, 0, "DoubleFieldBackend");
    qmlRegisterType<ViewModelsFramework::DropDownFieldBackend>("ViewModelsFramework", 1, 0, "DropDownFieldBackend");
    qmlRegisterType<ViewModelsFramework::IntFieldBackend>("ViewModelsFramework", 1, 0, "IntFieldBackend");
    qmlRegisterType<ViewModelsFramework::LabelFieldBackend>("ViewModelsFramework", 1, 0, "LabelFieldBackend");
    qmlRegisterType<ViewModelsFramework::MemoFieldBackend>("ViewModelsFramework", 1, 0, "MemoFieldBackend");
    qmlRegisterType<ViewModelsFramework::PasswordFieldBackend>("ViewModelsFramework", 1, 0, "PasswordFieldBackend");
    qmlRegisterType<ViewModelsFramework::QuantityFieldBackend>("ViewModelsFramework", 1, 0, "QuantityFieldBackend");
    qmlRegisterType<ViewModelsFramework::SwitchFieldBackend>("ViewModelsFramework", 1, 0, "SwitchFieldBackend");
    qmlRegisterType<ViewModelsFramework::TextFieldBackend>("ViewModelsFramework", 1, 0, "TextFieldBackend");
}


} // namespace ViewModelsFramework
