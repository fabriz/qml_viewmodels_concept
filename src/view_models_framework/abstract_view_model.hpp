#ifndef ABSTRACT_VIEW_MODEL_HPP
#define ABSTRACT_VIEW_MODEL_HPP

#include <QObject>

#include "field_backend_base.hpp"
#include "double_field_backend.hpp"
#include "drop_down_field_backend.hpp"
#include "int_field_backend.hpp"
#include "label_field_backend.hpp"
#include "memo_field_backend.hpp"
#include "password_field_backend.hpp"
#include "quantity_field_backend.hpp"
#include "switch_field_backend.hpp"
#include "text_field_backend.hpp"


namespace ViewModelsFramework
{


class AbstractViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool modified READ modified NOTIFY modifiedChanged)

public:
    explicit AbstractViewModel(QObject* parent = 0);

    bool modified() const;
    bool isUpdatingView() const;

    void updateView();

    void clearFieldsMessages();
    void deleteFieldsMessagesBySeverity(FieldMessage::MessageSeverity minSeverityToDelete);
    void addFieldMessageByFieldId(int fieldId, FieldMessage::MessageSeverity severity, const QString& message);

signals:
    void modifiedChanged();

public slots:
    void onFieldChanged();
    void setModified(bool value);

private:

    virtual void do_updateView();

    bool    m_modified;
    bool    m_isUpdatingView;
};



#define DECLARE_FIELD_BACKEND(FIELD_TYPE, FIELD_NAME) \
    Q_PROPERTY(ViewModelsFramework::FIELD_TYPE* FIELD_NAME READ FIELD_NAME CONSTANT)\
    ViewModelsFramework::FIELD_TYPE* m_##FIELD_NAME = nullptr;\
    ViewModelsFramework::FIELD_TYPE* FIELD_NAME() {\
        if (!m_##FIELD_NAME) qDebug("WARNING!!! Field m_" #FIELD_NAME " is null!!!");\
        return m_##FIELD_NAME;}



} // namespace ViewModelsFramework

#endif // ABSTRACT_VIEW_MODEL_HPP
