#pragma once

#include "qwolinenoise.h"

#include <qtermwidget.h>

#include <QPointer>

class QWoProcess;
class QMenu;
class QWoShellWidgetImpl;


class QWoShellWidget : public QTermWidget, QWoLineNoise
{
    Q_OBJECT
public:
    explicit QWoShellWidget(QWidget *parent=nullptr);
    virtual ~QWoShellWidget();

    void closeAndDelete();

signals:
    void aboutToClose(QCloseEvent* event);

private
slots:
    void onTimeout();
    void onSendData(const QByteArray& buf);
    void onCopyToClipboard();
    void onPasteFromClipboard();
    void onVerticalSplitView();
    void onHorizontalSplitView();
    void onCloseThisSession();
private:
    void contextMenuEvent(QContextMenuEvent *event);
    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
private:
    void initDefault();
    void resetProperty(QVariantMap data);
    void splitWidget(bool vertical);

protected:
    void handleCommand(const QByteArray& line);
private:
    friend class QWoShellWidgetImpl;
    QPointer<QMenu> m_menu;
    QPointer<QAction> m_copy;
    QPointer<QAction> m_paste;
    QPointer<QWoLineNoise> m_linenoise;
    bool m_bexit;
};
