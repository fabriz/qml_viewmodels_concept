#include "many_fields_view_model.hpp"


using namespace ViewModelsFramework;


namespace ViewModels
{


ManyFieldsViewModel::ManyFieldsViewModel(QObject* parent) : AbstractViewModel(parent)
{
    for (int i = 0; i < 30; i++)
    {
        m_strings[i] = QString("Value %1").arg(i + 1);
    }

    m_field_01 = new TextFieldBackend(this, m_strings[0],  -1, "Field 1");
    m_field_02 = new TextFieldBackend(this, m_strings[1],  -1, "Field 2");
    m_field_03 = new TextFieldBackend(this, m_strings[2],  -1, "Field 3");
    m_field_04 = new TextFieldBackend(this, m_strings[3],  -1, "Field 4");
    m_field_05 = new TextFieldBackend(this, m_strings[4],  -1, "Field 5");
    m_field_06 = new TextFieldBackend(this, m_strings[5],  -1, "Field 6");
    m_field_07 = new TextFieldBackend(this, m_strings[6],  -1, "Field 7");
    m_field_08 = new TextFieldBackend(this, m_strings[7],  -1, "Field 8");
    m_field_09 = new TextFieldBackend(this, m_strings[8],  -1, "Field 9");
    m_field_10 = new TextFieldBackend(this, m_strings[9],  -1, "Field 10");
    m_field_11 = new TextFieldBackend(this, m_strings[10], -1, "Field 11");
    m_field_12 = new TextFieldBackend(this, m_strings[11], -1, "Field 12");
    m_field_13 = new TextFieldBackend(this, m_strings[12], -1, "Field 13");
    m_field_14 = new TextFieldBackend(this, m_strings[13], -1, "Field 14");
    m_field_15 = new TextFieldBackend(this, m_strings[14], -1, "Field 15");
    m_field_16 = new TextFieldBackend(this, m_strings[15], -1, "Field 16");
    m_field_17 = new TextFieldBackend(this, m_strings[16], -1, "Field 17");
    m_field_18 = new TextFieldBackend(this, m_strings[17], -1, "Field 18");
    m_field_19 = new TextFieldBackend(this, m_strings[18], -1, "Field 19");
    m_field_20 = new TextFieldBackend(this, m_strings[19], -1, "Field 20");
    m_field_21 = new TextFieldBackend(this, m_strings[20], -1, "Field 21");
    m_field_22 = new TextFieldBackend(this, m_strings[21], -1, "Field 22");
    m_field_23 = new TextFieldBackend(this, m_strings[22], -1, "Field 23");
    m_field_24 = new TextFieldBackend(this, m_strings[23], -1, "Field 24");
    m_field_25 = new TextFieldBackend(this, m_strings[24], -1, "Field 25");
    m_field_26 = new TextFieldBackend(this, m_strings[25], -1, "Field 26");
    m_field_27 = new TextFieldBackend(this, m_strings[26], -1, "Field 27");
    m_field_28 = new TextFieldBackend(this, m_strings[27], -1, "Field 28");
    m_field_29 = new TextFieldBackend(this, m_strings[28], -1, "Field 29");
    m_field_30 = new TextFieldBackend(this, m_strings[29], -1, "Field 30");

    updateView();
}


ManyFieldsViewModel::~ManyFieldsViewModel()
{
}


} // namespace ViewModels
