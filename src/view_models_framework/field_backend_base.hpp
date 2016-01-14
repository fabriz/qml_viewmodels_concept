#ifndef FIELD_BACKEND_BASE_HPP
#define FIELD_BACKEND_BASE_HPP

#include <QObject>

#include "field_backend_property.hpp"
#include "field_backend_value.hpp"
#include "field_messages.hpp"


namespace ViewModelsFramework
{

// Forward declaration
class AbstractViewModel;


class FieldBackendBase : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString label READ label NOTIFY labelChanged)
    Q_PROPERTY(bool enabled READ enabled NOTIFY enabledChanged)
    Q_PROPERTY(bool visible READ visible NOTIFY visibleChanged)
    Q_PROPERTY(QString state READ state NOTIFY stateChanged)
    Q_PROPERTY(FieldMessages* statusMessages READ statusMessages CONSTANT)

public:

    explicit FieldBackendBase(QObject* parent = nullptr);
    FieldBackendBase(AbstractViewModel* parent, int fieldId, const QString& label);
    virtual ~FieldBackendBase();

    int fieldId() const;
    QString label() const;
    bool enabled() const;
    bool visible() const;
    QString state() const;
    FieldMessages* statusMessages();

signals:
    void labelChanged();
    void enabledChanged();
    void visibleChanged();
    void stateChanged();

public slots:
    void setLabel(const QString& value);
    void setEnabled(bool value);
    void setVisible(bool value);
    void setState(const QString& value);

protected:
    friend class AbstractViewModel;

    virtual void beginFieldUpdate();
    virtual void endFieldUpdate();

private:
    int                             m_fieldId;
    FieldBackendProperty<QString>   m_label;
    FieldBackendProperty<bool>      m_enabled;
    FieldBackendProperty<bool>      m_visible;
    FieldBackendProperty<QString>   m_state;
    FieldMessages*                  m_statusMessages;
};


} // namespace ViewModelsFramework

#endif // FIELD_BACKEND_BASE_HPP
