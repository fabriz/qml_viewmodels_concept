#ifndef EDIT_FIELD_BACKEND_BASE_HPP
#define EDIT_FIELD_BACKEND_BASE_HPP

#include "field_backend_base.hpp"


namespace ViewModelsFramework
{

class EditFieldBackendBase : public FieldBackendBase
{
    Q_OBJECT

    Q_PROPERTY(bool readOnly READ readOnly NOTIFY readOnlyChanged)

public:
    explicit EditFieldBackendBase(QObject* parent = nullptr);
    EditFieldBackendBase(AbstractViewModel* parent, int fieldId, const QString& label);
    virtual ~EditFieldBackendBase();

    bool readOnly() const;

signals:
    void readOnlyChanged();

public slots:
    void setReadOnly(bool value);

protected:
    void beginFieldUpdate() override;
    void endFieldUpdate() override;

private:
    FieldBackendProperty<bool>      m_readOnly;
};


} // namespace ViewModelsFramework

#endif // EDIT_FIELD_BACKEND_BASE_HPP
