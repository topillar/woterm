/*  Copyright (C) 2008 e_k (e_k@users.sourceforge.net)

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/


#include <QApplication>
#include <QtDebug>
#include <QIcon>
#include <QMainWindow>
#include <QMenuBar>

#include "qwotermwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QIcon::setThemeName("oxygen");
    qputenv("TERM", "xterm-256color");
    QMainWindow *mainWindow = new QMainWindow();
    QWoTermWidget *console = new QWoTermWidget();

    QMenuBar *menuBar = new QMenuBar(mainWindow);
    QMenu *actionsMenu = new QMenu("Actions", menuBar);
    menuBar->addMenu(actionsMenu);
    actionsMenu->addAction("Find...", console, SLOT(toggleShowSearchBar()), QKeySequence(Qt::CTRL +  Qt::Key_F));
    actionsMenu->addAction("About Qt", &app, SLOT(aboutQt()));
    mainWindow->setMenuBar(menuBar);

    mainWindow->setCentralWidget(console);
    mainWindow->resize(600, 400);

    // info output
    qDebug() << "* INFO *************************";
    qDebug() << " availableKeyBindings:" << console->availableKeyBindings();
    qDebug() << " keyBindings:" << console->keyBindings();
    qDebug() << " availableColorSchemes:" << console->availableColorSchemes();
    qDebug() << "* INFO END *********************";

    // real startup
    QObject::connect(console, SIGNAL(finished()), mainWindow, SLOT(close()));

    mainWindow->show();
    return app.exec();
}