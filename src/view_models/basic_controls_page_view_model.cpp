#include "basic_controls_page_view_model.hpp"

#include <QMessageBox>


using namespace ViewModelsFramework;


namespace ViewModels
{


BasicControlsPageViewModel::BasicControlsPageViewModel(QObject* parent) : AbstractViewModel(parent)
{
    DropDownFieldBackendItems genders;
    genders.addItem(Model::GENDER_UNKNOWN, "");
    genders.addItem(Model::GENDER_MALE, Model::genderToString(Model::GENDER_MALE));
    genders.addItem(Model::GENDER_FEMALE, Model::genderToString(Model::GENDER_FEMALE));

    m_name = new TextFieldBackend(this, m_modelEntity.name);
    m_name->setPlaceholderText("Insert your name");

    m_password = new PasswordFieldBackend(this, m_modelEntity.password);
    m_password->setPlaceholderText("Insert your password");

    m_enableOptionalFields = new SwitchFieldBackend(this, m_modelEntity.enableOptionalFields);

    m_age = new IntFieldBackend(this, m_modelEntity.age);
    m_age->setValueRange(10, 50);

    m_gender = new DropDownFieldBackend(this, *(int*)(&m_modelEntity.gender), genders);

    m_height = new QuantityFieldBackend(this, m_modelEntity.height);
    m_height->setSuffixText("cm");
    m_height->setValueRange(40, 250);
    m_height->setDecimals(1);

    m_weight = new QuantityFieldBackend(this, m_modelEntity.weight);
    m_weight->setSuffixText("Kg");
    m_weight->setValueRange(1, 400);

    m_notes = new MemoFieldBackend(this, m_modelEntity.notes);

    updateView();
}


BasicControlsPageViewModel::~BasicControlsPageViewModel()
{
}


void BasicControlsPageViewModel::acceptButtonHandler()
{
    QString msg;

    msg += "Name: " + m_modelEntity.name + "\n";
    msg += "Password: " + m_modelEntity.password + "\n";
    msg += "Enable optional fields: " + QString(m_modelEntity.enableOptionalFields ? "yes" : "no") + "\n";

    if (m_modelEntity.enableOptionalFields)
    {
        msg += "Age: " + QString::number(m_modelEntity.age) + "\n";
        msg += "Gender: " + Model::genderToString(m_modelEntity.gender) + "\n";
        msg += "Height: " + QString::number(m_modelEntity.height, 'f', m_height->decimals()) + "\n";
        msg += "Weight: " + QString::number(m_modelEntity.weight, 'f', m_weight->decimals()) + "\n";
        msg += "Notes: " + m_modelEntity.notes + "\n";
    }

    QMessageBox::information(nullptr, tr("C++ accept button handler"), msg);
}


void BasicControlsPageViewModel::do_updateView()
{
    m_age->setEnabled(m_modelEntity.enableOptionalFields);
    m_gender->setEnabled(m_modelEntity.enableOptionalFields);
    m_height->setEnabled(m_modelEntity.enableOptionalFields);
    m_weight->setEnabled(m_modelEntity.enableOptionalFields);
    m_notes->setEnabled(m_modelEntity.enableOptionalFields);

    if (!m_modelEntity.enableOptionalFields)
    {
        m_notes->setValue("");
    }
}


} // namespace ViewModels
