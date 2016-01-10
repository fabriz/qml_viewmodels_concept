#ifndef SWITCH_FIELD_BACKEND_HPP
#define SWITCH_FIELD_BACKEND_HPP

#include "field_backend_base.hpp"


namespace ViewModelsFramework
{


class SwitchFieldBackend : public FieldBackendBase
{
    Q_OBJECT

    Q_PROPERTY(bool value READ value NOTIFY valueChanged)

public:
    explicit SwitchFieldBackend(QObject* parent = nullptr);
    explicit SwitchFieldBackend(AbstractViewModel* parent, bool& value, int fieldId = -1, const QString& label = QString());
    virtual ~SwitchFieldBackend();

    bool value() const;

signals:
    void valueChanged();

public slots:
    void setValue(bool value);

protected:
    void beginFieldUpdate() override;
    void endFieldUpdate() override;

private:
    FieldBackendValue<bool>     m_value;
};


} // namespace ViewModelsFramework

#endif // SWITCH_FIELD_BACKEND_HPP

