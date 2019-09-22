#pragma once

#include "qwowidget.h"

#include <QPointer>

class QWoShowerWidget : public QWoWidget
{
    Q_OBJECT
public:
    explicit QWoShowerWidget(QWidget *parent=nullptr);

protected:
    virtual void handleTabMouseEvent(QMouseEvent *ev);

private:
    friend class QWoShower;
};
