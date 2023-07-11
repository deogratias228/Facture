#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>
#include <QString>

bool createConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("gratias");
    db.setPassword("gratias");
    db.setDatabaseName("essai");

    if (!db.open()) {
        QMessageBox::critical(0, QObject::tr("Database Error"), db.lastError().text());

        return false;
    }

    QMessageBox::information(0,"Information", "Vous êtes maintenant connecté !");
    return true;
}
