#ifndef MANY_FIELDS_VIEW_MODEL_HPP
#define MANY_FIELDS_VIEW_MODEL_HPP

#include "view_models_framework/abstract_view_model.hpp"
#include "model/person_info.hpp"


namespace ViewModels
{


class ManyFieldsViewModel : public ViewModelsFramework::AbstractViewModel
{
    Q_OBJECT

    DECLARE_FIELD_BACKEND(TextFieldBackend, field_01)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_02)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_03)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_04)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_05)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_06)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_07)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_08)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_09)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_10)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_11)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_12)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_13)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_14)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_15)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_16)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_17)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_18)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_19)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_20)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_21)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_22)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_23)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_24)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_25)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_26)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_27)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_28)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_29)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_30)

public:
    explicit ManyFieldsViewModel(QObject* parent = nullptr);
    virtual ~ManyFieldsViewModel();

signals:

public slots:

private:
    QString m_strings[30];
};


} // namespace ViewModels

#endif // MANY_FIELDS_VIEW_MODEL_HPP
