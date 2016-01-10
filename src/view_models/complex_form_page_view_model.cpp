#include "complex_form_page_view_model.hpp"

#include <QMessageBox>


using namespace ViewModelsFramework;


namespace ViewModels
{


ComplexFormPageViewModel::ComplexFormPageViewModel(QObject* parent) : AbstractViewModel(parent)
{
//    m_name = new TextFieldBackend(this, m_modelEntity.name, "Insert your name");
//    m_password = new PasswordFieldBackend(this, m_modelEntity.password, "Insert your password");
//    m_enableOptionalFields = new SwitchFieldBackend(this, m_modelEntity.enableOptionalFields);
//    m_age = new IntFieldBackend(this, m_modelEntity.age, 10, 150);
//    m_height = new QuantityFieldBackend(this, m_modelEntity.height, "", "cm", 40, 250, 1);
//    m_weight = new QuantityFieldBackend(this, m_modelEntity.weight, "", "Kg", 1, 400);
//    m_notes = new MemoFieldBackend(this, m_modelEntity.notes);

    updateView();
}


ComplexFormPageViewModel::~ComplexFormPageViewModel()
{
}


void ComplexFormPageViewModel::acceptButtonHandler()
{
//    QString msg;

//    msg += "Name: " + m_modelEntity.name + "\n";
//    msg += "Password: " + m_modelEntity.password + "\n";
//    msg += "Enable optional fields: " + QString(m_modelEntity.enableOptionalFields ? "yes" : "no") + "\n";

//    if (m_modelEntity.enableOptionalFields)
//    {
//        msg += "Age: " + QString::number(m_modelEntity.age) + "\n";
//        msg += "Height: " + QString::number(m_modelEntity.height, 'f', m_height->decimals()) + "\n";
//        msg += "Weight: " + QString::number(m_modelEntity.weight, 'f', m_weight->decimals()) + "\n";
//        msg += "Notes: " + m_modelEntity.notes + "\n";
//    }

//    QMessageBox::information(nullptr, tr("C++ accept button handler"), msg);
}


void ComplexFormPageViewModel::do_updateView()
{
//    m_age->setEnabled(m_modelEntity.enableOptionalFields);
//    m_height->setEnabled(m_modelEntity.enableOptionalFields);
//    m_weight->setEnabled(m_modelEntity.enableOptionalFields);
//    m_notes->setEnabled(m_modelEntity.enableOptionalFields);

//    if (!m_modelEntity.enableOptionalFields)
//    {
//        m_notes->setValue("");
//    }
}


} // namespace ViewModels







