#ifndef FIELD_MESSAGES_HPP
#define FIELD_MESSAGES_HPP

#include <QList>
#include <QObject>
#include <QQmlListProperty>
#include <QString>

#include "field_backend_property.hpp"


namespace ViewModelsFramework
{


class FieldMessage : public QObject
{
    Q_OBJECT
    Q_ENUMS(MessageSeverity)

    Q_PROPERTY(MessageSeverity severity READ severity CONSTANT)
    Q_PROPERTY(QString message READ message CONSTANT)

public:

    enum MessageSeverity
    {
        NONE,
        HELP,
        INFORMATION,
        WARNING,
        ERROR
    };

//    explicit FieldMessage(QObject* parent = nullptr);
    FieldMessage(MessageSeverity severity, const QString& message, QObject* parent = nullptr);
    virtual ~FieldMessage();

    MessageSeverity severity() const;
    QString message() const;

private:
    MessageSeverity     m_severity;
    QString             m_message;
};




class FieldMessages : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QQmlListProperty<ViewModelsFramework::FieldMessage> messages READ messages NOTIFY messagesChanged)
    Q_PROPERTY(int messageStatus READ messageStatus NOTIFY messageStatusChanged)

public:

    explicit FieldMessages(QObject* parent = nullptr);
    virtual ~FieldMessages();

    QQmlListProperty<FieldMessage> messages();
    int messageStatus() const;

    void addMessage(FieldMessage::MessageSeverity severity, const QString& message);
    void clearMessages();
    void addHelpMessage(const QString& message);
    void addInformationMessage(const QString& message);
    void addWarningMessage(const QString& message);
    void addErrorMessage(const QString& message);

    void beginFieldUpdate();
    void endFieldUpdate();

signals:
    void messagesChanged();
    void messageStatusChanged();

private:
    QList<FieldMessage*>        m_messages;
    FieldBackendProperty<int>   m_messageStatus;
};


} // namespace ViewModelsFramework

#endif // FIELD_MESSAGES_HPP
