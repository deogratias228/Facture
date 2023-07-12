#include <QApplication>
#include "MyWindow.h"
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QtSql>
#include <QString>
#include <QSqlError>
#include <iostream>
bool createConnection();

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    if(!createConnection()){
        return 1;
    }

    MyWindow window;
    window.show();

    return app.exec();
}

