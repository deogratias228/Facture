#include "EditArticle.h"
#include <QSqlQuery>
#include <QVBoxLayout>

EditArticle::EditArticle(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout;

    tableModel = new QSqlTableModel;

    QSqlQuery query;
    query.exec("SELECT * FROM article");

    tableView = new QTableView;
    tableView->setModel(tableModel);
    tableView->resizeColumnsToContents();

    layout->addWidget(tableView);
    this->setLayout(layout);
}
