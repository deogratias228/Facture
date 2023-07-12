#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QtSql>
#include <QString>
#include <QSqlError>
#include <iostream>

bool createConnection()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("gratias");
    db.setPassword("gratias");
    db.setDatabaseName("facture");
    if (!db.open()){
        QMessageBox::critical(0, "Avertissement", db.lastError().text());
        return false;
    }
    QMessageBox::information(0,"Information", "Vous êtes maintenant connecté !");
    return true;
}
