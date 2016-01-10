#include "drop_down_field_backend.hpp"

#include "abstract_view_model.hpp"


namespace ViewModelsFramework
{


DropDownFieldBackendListModel::DropDownFieldBackendListModel(const DropDownFieldBackendItems& model, QObject* parent) : QAbstractListModel(parent),
    m_model(model)
{
}


DropDownFieldBackendListModel::~DropDownFieldBackendListModel()
{
}


QHash<int, QByteArray> DropDownFieldBackendListModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[ROLE_INDEX] = "index";
    roles[ROLE_VALUE] = "value";
    roles[ROLE_TEXT] = "text";

    return roles;
}


int DropDownFieldBackendListModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return static_cast<int>(m_model.m_items.size());
}


QVariant DropDownFieldBackendListModel::data(const QModelIndex& index, int role) const
{
    int rowIndex = index.row();
    if ((rowIndex < 0) || (rowIndex >= rowCount()))
    {
        return QVariant();
    }

    const DropDownFieldBackendItems::item& item = m_model.m_items.at(rowIndex);

    switch (role)
    {
    case ROLE_INDEX:    return item.index;
    case ROLE_VALUE:    return item.value;
    case ROLE_TEXT:     return item.text;
    }

    return QVariant();
}


void DropDownFieldBackendListModel::updateViews()
{
    beginResetModel();
    endResetModel();
}


void DropDownFieldBackendListModel::setModel(const DropDownFieldBackendItems& model)
{
    beginResetModel();
    m_model = model;
    endResetModel();
}






DropDownFieldBackend::DropDownFieldBackend(QObject* parent) : FieldBackendBase(parent)
{
}


DropDownFieldBackend::DropDownFieldBackend(AbstractViewModel* parent, int& value, const DropDownFieldBackendItems& model, int fieldId, const QString& label) :
    FieldBackendBase(parent, fieldId, label),
    m_value(value),
    m_modelChanged(false)
{
    connect(this, SIGNAL(valueChanged()), parent, SLOT(onFieldChanged()));

    m_model = new DropDownFieldBackendListModel(model, this);
}


DropDownFieldBackend::~DropDownFieldBackend()
{
}


int DropDownFieldBackend::value() const
{
    return m_value;
}


QAbstractListModel* DropDownFieldBackend::model() const
{
    return m_model;
}


void DropDownFieldBackend::setValue(int value)
{
    if (m_value != value)
    {
        m_value = value;
        emit valueChanged();
    }
}


void DropDownFieldBackend::setModel(const DropDownFieldBackendItems& model)
{
    m_model->setModel(model);
    m_modelChanged = true;
}


void DropDownFieldBackend::beginFieldUpdate()
{
    FieldBackendBase::beginFieldUpdate();

    m_model->blockSignals(true);
    m_modelChanged = false;

    m_value.storeCurrentValue();
}


void DropDownFieldBackend::endFieldUpdate()
{
    FieldBackendBase::endFieldUpdate();

    if (m_value.isCurrentValueDifferentFromStoredValue())
    {
        emit valueChanged();
    }

    m_model->blockSignals(false);
    if (m_modelChanged)
    {
        m_model->updateViews();
    }
}


} // namespace ViewModelsFramework
