#include "field_backend_base.hpp"

#include "abstract_view_model.hpp"


namespace ViewModelsFramework
{


FieldBackendBase::FieldBackendBase(QObject* parent) : QObject(parent)
{
    qDebug("FieldBackendBase::FieldBackendBase() - Default constructor called!!!");
}


FieldBackendBase::FieldBackendBase(AbstractViewModel* parent, int fieldId, const QString& label) : QObject(parent),
    m_fieldId(fieldId),
    m_label(label),
    m_enabled(true),
    m_visible(true),
    m_statusMessages(new FieldMessages(this))
{
    // Disable signals during object construction
    QObject::blockSignals(true);
}


FieldBackendBase::~FieldBackendBase()
{
}


int FieldBackendBase::fieldId() const
{
    return m_fieldId;
}


QString FieldBackendBase::label() const
{
    return m_label;
}


bool FieldBackendBase::enabled() const
{
    return m_enabled;
}


bool FieldBackendBase::visible() const
{
    return m_visible;
}


QString FieldBackendBase::state() const
{
    return m_state;
}


FieldMessages* FieldBackendBase::statusMessages()
{
    return m_statusMessages;
}


void FieldBackendBase::setLabel(const QString& value)
{
    if (m_label != value)
    {
        m_label = value;
        emit labelChanged();
    }
}


void FieldBackendBase::setEnabled(bool value)
{
    if (m_enabled != value)
    {
        m_enabled = value;
        emit enabledChanged();
    }
}


void FieldBackendBase::setVisible(bool value)
{
    if (m_visible != value)
    {
        m_visible = value;
        emit visibleChanged();
    }
}


void FieldBackendBase::setState(const QString& value)
{
    if (m_state != value)
    {
        m_state = value;
        emit stateChanged();
    }
}


void FieldBackendBase::beginFieldUpdate()
{
    m_label.storeCurrentValue();
    m_enabled.storeCurrentValue();
    m_visible.storeCurrentValue();
    m_state.storeCurrentValue();

    m_statusMessages->beginFieldUpdate();
}


void FieldBackendBase::endFieldUpdate()
{
    if (m_label.isCurrentValueDifferentFromStoredValue())
    {
        emit labelChanged();
    }

    if (m_enabled.isCurrentValueDifferentFromStoredValue())
    {
        emit enabledChanged();
    }

    if (m_visible.isCurrentValueDifferentFromStoredValue())
    {
        emit visibleChanged();
    }

    if (m_state.isCurrentValueDifferentFromStoredValue())
    {
        emit stateChanged();
    }

    m_statusMessages->endFieldUpdate();
}


} // namespace ViewModelsFramework
