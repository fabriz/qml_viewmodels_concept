#ifndef SIMPLE_PAGE_VIEW_MODEL_HPP
#define SIMPLE_PAGE_VIEW_MODEL_HPP

#include "view_models_framework/abstract_view_model.hpp"
#include "model/person_info.hpp"


namespace ViewModels
{


class SimpleFormPageViewModel : public ViewModelsFramework::AbstractViewModel
{
    Q_OBJECT

    DECLARE_FIELD_BACKEND(TextFieldBackend, name)
    DECLARE_FIELD_BACKEND(PasswordFieldBackend, password)
    DECLARE_FIELD_BACKEND(SwitchFieldBackend, enableOptionalFields)
    DECLARE_FIELD_BACKEND(IntFieldBackend, age)
    DECLARE_FIELD_BACKEND(DropDownFieldBackend, gender)
    DECLARE_FIELD_BACKEND(QuantityFieldBackend, height)
    DECLARE_FIELD_BACKEND(QuantityFieldBackend, weight)
    DECLARE_FIELD_BACKEND(MemoFieldBackend, notes)

public:
    explicit SimpleFormPageViewModel(QObject* parent = nullptr);
    virtual ~SimpleFormPageViewModel();

    Q_INVOKABLE void acceptButtonHandler();

signals:

public slots:

private:
    void do_updateView() override;

    Model::PersonInfo   m_modelEntity;
};


} // namespace ViewModels

#endif // SIMPLE_PAGE_VIEW_MODEL_HPP
