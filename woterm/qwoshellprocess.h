#pragma once


#include "qwoprocess.h"

#include <QPointer>


class QWoShellProcess : public QWoProcess
{
    Q_OBJECT
public:
    explicit QWoShellProcess(QObject *parent=nullptr);
    virtual ~QWoShellProcess();

};
