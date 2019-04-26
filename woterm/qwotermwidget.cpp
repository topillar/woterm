#include "qwotermwidget.h"

#include <QApplication>

QWoTermWidget::QWoTermWidget(QWidget *parent)
    :QTermWidget (parent)
{
    QFont font = QApplication::font();
#ifdef Q_OS_MACOS
    font.setFamily("Monaco");
#elif defined(Q_WS_QWS)
    font.setFamily("fixed");
#else
    font.setFamily("Monospace");
#endif
    font.setPointSize(12);

    setTerminalFont(font);

    setScrollBarPosition(QTermWidget::ScrollBarRight);

    const auto arguments = QApplication::arguments();
    for (const QString& arg : arguments)
    {
        if (availableColorSchemes().contains(arg)){
            setColorScheme(arg);
        }
        if (availableKeyBindings().contains(arg)){
            setKeyBindings(arg);
        }
    }
}
