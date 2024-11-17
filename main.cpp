#include "mainwindow.h"
#include <QApplication>
#include "connection.h"
#include <Windows.h>
#include <QResource>
#include <QDir>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);


    HANDLE hMutex = CreateMutex(nullptr, TRUE, (LPCWSTR)qApp->applicationName().toStdWString().c_str());
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        QMessageBox::warning(nullptr, "Error", "An instance of the application is already running.");
        CloseHandle(hMutex);
        hMutex = NULL;
        return 1;
    }

    if(QResource::registerResource("./res.rcc"))
        qDebug()<<"res.rcc load success.";

    MainWindow w;
    if(!createConnection())
        return 1;
    w.show();
    CloseHandle(hMutex);
    hMutex = NULL;
    return a.exec();
}


