#ifndef SETTINGS_PAGE_VIEW_MODEL_HPP
#define SETTINGS_PAGE_VIEW_MODEL_HPP

#include "view_models_framework/abstract_view_model.hpp"


namespace ViewModels
{


class SettingsPageViewModel : public ViewModelsFramework::AbstractViewModel
{
    Q_OBJECT

    DECLARE_FIELD_BACKEND(TextFieldBackend, field_1)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_2)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_3)
    DECLARE_FIELD_BACKEND(TextFieldBackend, field_4)
    DECLARE_FIELD_BACKEND(MemoFieldBackend, field_10)
    DECLARE_FIELD_BACKEND(MemoFieldBackend, field_11)
    DECLARE_FIELD_BACKEND(MemoFieldBackend, field_12)
    DECLARE_FIELD_BACKEND(IntFieldBackend, field_20)
    DECLARE_FIELD_BACKEND(IntFieldBackend, field_21)
    DECLARE_FIELD_BACKEND(IntFieldBackend, field_22)
    DECLARE_FIELD_BACKEND(DoubleFieldBackend, field_30)
    DECLARE_FIELD_BACKEND(DoubleFieldBackend, field_31)
    DECLARE_FIELD_BACKEND(DoubleFieldBackend, field_32)
    DECLARE_FIELD_BACKEND(QuantityFieldBackend, field_40)
    DECLARE_FIELD_BACKEND(QuantityFieldBackend, field_41)
    DECLARE_FIELD_BACKEND(QuantityFieldBackend, field_42)
    DECLARE_FIELD_BACKEND(SwitchFieldBackend, field_50)
    DECLARE_FIELD_BACKEND(SwitchFieldBackend, field_51)
    DECLARE_FIELD_BACKEND(PasswordFieldBackend, field_60)
    DECLARE_FIELD_BACKEND(PasswordFieldBackend, field_61)
    DECLARE_FIELD_BACKEND(PasswordFieldBackend, field_62)

public:
    explicit SettingsPageViewModel(QObject* parent = 0);
    virtual ~SettingsPageViewModel();

    Q_INVOKABLE void buttonHandler1();
    Q_INVOKABLE void buttonHandler2();
    Q_INVOKABLE void buttonHandler3();
    Q_INVOKABLE void buttonHandler4();

signals:

public slots:

private:
    void do_updateView() override;

    QString     m_stringVal;
    int         m_intVal = 0;
    double      m_doubleVal = 0.0;
    bool        m_boolVal = false;
};


} // namespace ViewModels

#endif // SETTINGS_PAGE_VIEW_MODEL_HPP
