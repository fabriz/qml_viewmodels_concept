#include "settings_page_view_model.hpp"

using namespace ViewModelsFramework;


namespace ViewModels
{


SettingsPageViewModel::SettingsPageViewModel(QObject* parent) : AbstractViewModel(parent)
{
    qDebug("SettingsPageViewModel::SettingsPageViewModel");

    m_field_1 = new TextFieldBackend(this, m_stringVal);
    m_field_2 = new TextFieldBackend(this, m_stringVal);
    m_field_3 = new TextFieldBackend(this, m_stringVal);
    m_field_4 = new TextFieldBackend(this, m_stringVal);

    m_field_10 = new MemoFieldBackend(this, m_stringVal);
    m_field_11 = new MemoFieldBackend(this, m_stringVal);
    m_field_12 = new MemoFieldBackend(this, m_stringVal);

    m_field_20 = new IntFieldBackend(this, m_intVal);
    m_field_21 = new IntFieldBackend(this, m_intVal);
    m_field_22 = new IntFieldBackend(this, m_intVal);

    m_field_30 = new DoubleFieldBackend(this, m_doubleVal);
    m_field_31 = new DoubleFieldBackend(this, m_doubleVal);
    m_field_32 = new DoubleFieldBackend(this, m_doubleVal);

    m_field_40 = new QuantityFieldBackend(this, m_doubleVal);
    m_field_41 = new QuantityFieldBackend(this, m_doubleVal);
    m_field_42 = new QuantityFieldBackend(this, m_doubleVal);

    m_field_50 = new SwitchFieldBackend(this, m_boolVal);
    m_field_51 = new SwitchFieldBackend(this, m_boolVal);
    m_field_51->setEnabled(false);

    m_field_60 = new PasswordFieldBackend(this, m_stringVal);
    m_field_61 = new PasswordFieldBackend(this, m_stringVal);
    m_field_62 = new PasswordFieldBackend(this, m_stringVal);
}


SettingsPageViewModel::~SettingsPageViewModel()
{
    qDebug("SettingsPageViewModel::~SettingsPageViewModel");
}


void SettingsPageViewModel::buttonHandler1()
{
    m_field_1->setValue("Button pressed!");
}


void SettingsPageViewModel::buttonHandler2()
{
    m_field_20->setValue(12);
}


void SettingsPageViewModel::buttonHandler3()
{
    m_field_30->setValue(49);
}


void SettingsPageViewModel::buttonHandler4()
{
    m_field_4->setVisible(!m_field_4->visible());
}


void SettingsPageViewModel::do_updateView()
{
}


} // namespace ViewModels
