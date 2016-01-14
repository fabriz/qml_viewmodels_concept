TEMPLATE = app

TARGET = qml_viewmodels_concept

CONFIG += c++11

QT += qml quick widgets svg

HEADERS += \
    src/view_models_framework/view_models_framework_registration.hpp \
    src/view_models_framework/abstract_view_model.hpp \
    src/view_models_framework/field_backend_property.hpp \
    src/view_models_framework/field_backend_value.hpp \
    src/view_models_framework/field_backend_base.hpp \
    src/view_models_framework/field_messages.hpp \
    src/view_models_framework/edit_field_backend_base.hpp \
    src/view_models_framework/double_field_backend.hpp \
    src/view_models_framework/drop_down_field_backend.hpp \
    src/view_models_framework/int_field_backend.hpp \
    src/view_models_framework/label_field_backend.hpp \
    src/view_models_framework/memo_field_backend.hpp \
    src/view_models_framework/password_field_backend.hpp \
    src/view_models_framework/quantity_field_backend.hpp \
    src/view_models_framework/switch_field_backend.hpp \
    src/view_models_framework/text_field_backend.hpp \
    src/model/person_info.hpp \
    src/model/sample_settings.hpp \
    src/view_models/view_models_registration.hpp \
    src/view_models/basic_controls_page_view_model.hpp \
    src/view_models/simple_form_page_view_model.hpp \
    src/view_models/complex_form_page_view_model.hpp \
    src/view_models/many_fields_view_model.hpp

SOURCES += \
    src/main.cpp \
    src/view_models_framework/view_models_framework_registration.cpp \
    src/view_models_framework/abstract_view_model.cpp \
    src/view_models_framework/field_backend_base.cpp \
    src/view_models_framework/field_messages.cpp \
    src/view_models_framework/edit_field_backend_base.cpp \
    src/view_models_framework/double_field_backend.cpp \
    src/view_models_framework/drop_down_field_backend.cpp \
    src/view_models_framework/int_field_backend.cpp \
    src/view_models_framework/label_field_backend.cpp \
    src/view_models_framework/memo_field_backend.cpp \
    src/view_models_framework/password_field_backend.cpp \
    src/view_models_framework/quantity_field_backend.cpp \
    src/view_models_framework/switch_field_backend.cpp \
    src/view_models_framework/text_field_backend.cpp \
    src/view_models/view_models_registration.cpp \
    src/view_models/basic_controls_page_view_model.cpp \
    src/view_models/simple_form_page_view_model.cpp \
    src/view_models/complex_form_page_view_model.cpp \
    src/view_models/many_fields_view_model.cpp

RESOURCES += \
    qml/layout_1/qml.qrc \
    qml/layout_1/fmcontrols/fmcontrols.qrc \
    qml/layout_1/pages/pages.qrc \
    qml/layout_2/qml_2.qrc \
    qml/layout_3/qml_3.qrc \
    qml/layout_4/qml_4.qrc \
    images/images.qrc

INCLUDEPATH += $$PWD/src

lupdate_only {
    SOURCES += \
    qml/layout_1/*.qml \
    qml/layout_1/fmcontrols/*.qml \
    qml/layout_1/pages/*.qml \
    qml/layout_2/*.qml \
    qml/layout_3/*.qml \
    qml/layout_4/*.qml
}

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
