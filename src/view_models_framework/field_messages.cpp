#include "field_messages.hpp"

#include <QMutableListIterator>


namespace ViewModelsFramework
{


FieldMessage::FieldMessage(FieldMessage::MessageSeverity severity, const QString& message, QObject* parent) : QObject(parent),
    m_severity(severity),
    m_message(message)
{
}


FieldMessage::~FieldMessage()
{
}


FieldMessage::MessageSeverity FieldMessage::severity() const
{
    return m_severity;
}


QString FieldMessage::message() const
{
    return m_message;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


FieldMessages::FieldMessages(QObject* parent) : QObject(parent),
    m_messageStatus(FieldMessage::NONE)
{
}


FieldMessages::~FieldMessages()
{
}


QQmlListProperty<FieldMessage> FieldMessages::messages()
{
    return QQmlListProperty<FieldMessage>(this, m_messages);
}


int FieldMessages::messageStatus() const
{
    return m_messageStatus;
}


void FieldMessages::addMessage(FieldMessage::MessageSeverity severity, const QString& message)
{
    FieldMessage* newMsg = new FieldMessage(severity, message, this);

    QMutableListIterator<FieldMessage*> it(m_messages);
    while (it.hasNext())
    {
        if (it.next()->severity() < severity)
        {
            it.insert(newMsg);
            newMsg = nullptr;
            break;
        }
    }

    if (newMsg)
    {
        m_messages.append(newMsg);
    }

    emit messagesChanged();

    if (m_messageStatus < severity)
    {
        m_messageStatus = severity;
        emit messageStatusChanged();
    }
}


void FieldMessages::clearMessages()
{
    if (!m_messages.isEmpty())
    {
        while (!m_messages.isEmpty())
        {
            delete m_messages.takeFirst();
        }

        emit messagesChanged();
    }

    if (m_messageStatus != FieldMessage::NONE)
    {
        m_messageStatus = FieldMessage::NONE;
        emit messageStatusChanged();
    }
}


void FieldMessages::deleteMessagesBySeverity(FieldMessage::MessageSeverity minSeverityToDelete)
{
    FieldMessage::MessageSeverity maxSeverity = FieldMessage::NONE;

    QMutableListIterator<FieldMessage*> it(m_messages);
    while (it.hasNext())
    {
        const FieldMessage* msg = it.next();
        if (msg->severity() >= minSeverityToDelete)
        {
            it.remove();
        }
        else
        {
            if (maxSeverity < msg->severity())
            {
                maxSeverity = msg->severity();
            }
        }
    }

    if (m_messageStatus != maxSeverity)
    {
        m_messageStatus = maxSeverity;
        emit messageStatusChanged();
    }
}


void FieldMessages::addHelpMessage(const QString& message)
{
    addMessage(FieldMessage::HELP, message);
}


void FieldMessages::addInformationMessage(const QString& message)
{
    addMessage(FieldMessage::INFORMATION, message);
}


void FieldMessages::addWarningMessage(const QString& message)
{
    addMessage(FieldMessage::WARNING, message);
}


void FieldMessages::addErrorMessage(const QString& message)
{
    addMessage(FieldMessage::ERROR, message);
}


void FieldMessages::beginFieldUpdate()
{
    QObject::blockSignals(true);

    m_messageStatus.storeCurrentValue();
}


void FieldMessages::endFieldUpdate()
{
    QObject::blockSignals(false);

    if (m_messageStatus.isCurrentValueDifferentFromStoredValue())
    {
        emit messageStatusChanged();
    }
}


} // namespace ViewModelsFramework
