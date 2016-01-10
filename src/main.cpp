#include <QApplication>
#include <QInputDialog>
#include <QQmlApplicationEngine>
#include <QStringList>

#include "view_models_framework/view_models_framework_registration.hpp"
#include "view_models/view_models_registration.hpp"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    ViewModelsFramework::registerTypes();
    ViewModels::registerTypes();

    QStringList layouts;
    layouts << "1 - Examples" << "2 - Form with two columns" << "3 - Form with one column" << "4 - Form with adaptive layout";

    bool ok;
    QString selectedLayout = QInputDialog::getItem(nullptr, "Select layout", "Select GUI layout to run", layouts, 0, false, &ok);
    if (!ok)
    {
        return 0;
    }

    QString mainQmlPageRoot = "qrc:/qml/layout_1/main.qml";
    if (selectedLayout.startsWith("1 "))
    {
        mainQmlPageRoot = "qrc:/qml/layout_1/main.qml";
    }
    else if (selectedLayout.startsWith("2 "))
    {
        mainQmlPageRoot = "qrc:/qml/layout_2/main.qml";
    }
    else if (selectedLayout.startsWith("3 "))
    {
        mainQmlPageRoot = "qrc:/qml/layout_3/main.qml";
    }
    else if (selectedLayout.startsWith("4 "))
    {
        mainQmlPageRoot = "qrc:/qml/layout_4/main.qml";
    }

//    std::shared_ptr<AppEngine> appEngine = AppEngine::getAppEngine();
//    appEngine->start();

    QQmlApplicationEngine qmlEngine;
    qmlEngine.load(QUrl(mainQmlPageRoot));

    int appExecResult = app.exec();

//    appEngine->stop();

    return appExecResult;
}

