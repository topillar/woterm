#pragma once

#include <QObject>
#include <QPointer>
#include <QEvent>

class QTermWidget;
class QWoTermWidget;
class QMenu;
class QProcess;

class QWoProcessEvent : public QEvent
{
public:
    enum WoEventType{StdIn, StdOut, StdErr};
public:
    QWoProcessEvent(WoEventType t, const QByteArray& data = QByteArray());

    WoEventType type() const;
    QByteArray data() const;

    void setResult(const QByteArray& result);
    QByteArray result() const;

    static int EventType;
private:
    WoEventType m_type;
    QByteArray m_data;
    QByteArray m_result;

};


class QWoProcess : public QObject
{
    Q_OBJECT
public:
    explicit QWoProcess(QObject *parent=nullptr);
    virtual ~QWoProcess();
    QString program() const;
    void setProgram(const QString &program);

    QStringList arguments() const;
    void setArguments(const QStringList & arguments);

    QStringList environment() const;
    void setEnvironment(const QStringList& env);

    void setWorkingDirectory(const QString &dir);

    void start();
    QByteArray readAllStandardOutput();
    QByteArray readAllStandardError();
    void write(const QByteArray& data);
    void writeError(const QByteArray& data);

    void enableDebugConsole(bool on);
private:
signals:
    void readyReadStandardOutput();
    void readyReadStandardError();
    void finished(int code);

protected:
    virtual bool readStandardOutputFilter();
    virtual bool readStandardErrorFilter();
    virtual bool finishFilter(int code);
    virtual bool writeFilter(const QByteArray& data);
    virtual void setTermWidget(QTermWidget *widget);
    virtual void prepareContextMenu(QMenu *menu);

private slots:
    void onReadyReadStandardOutput();
    void onReadyReadStandardError();
    void onFinished(int code);

protected:
    QPointer<QTermWidget> m_term;
    QPointer<QProcess> m_process;

    friend class QWoTermWidget;
};
