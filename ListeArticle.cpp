#include "ListeArticle.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVBoxLayout>
#include <QtWidgets>
#include <QSqlError>


ListeArticle::ListeArticle(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout;

    // Le model
    modele = new QSqlTableModel(this);
    modele->setTable("article");
    modele->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modele->setSort(0, Qt::AscendingOrder);
    modele->setHeaderData(0, Qt::Horizontal, tr("Reférence"));
    modele->setHeaderData(1, Qt::Horizontal, tr("Libellé"));
    modele->setHeaderData(2, Qt::Horizontal, tr("Catégorie"));
    modele->setHeaderData(3, Qt::Horizontal, tr("Prix"));
    modele->select();

    // La vue (le widget pour l'affichage)
    viewLayout = new QVBoxLayout;
    view = new QTableView;
    view->setModel(modele);
    view->resizeColumnsToContents();
    view->verticalHeader()->hide();
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setAlternatingRowColors(true);
    view->setStyleSheet("alternate-background-color: lightgrey;");

    viewLayout->addWidget(view);
    viewLayout->setContentsMargins(45, 20, 20, 45);
    layout->addLayout(viewLayout);

    this->setLayout(layout);

    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void ListeArticle::actSelection()
/*  But     : Appliquer la sélection
 *  Auteurs : Equipe Les IT-DIS
 *  Date    : 2015 Octobre
 */
{
    QModelIndex intIndex = view->selectionModel()->currentIndex();
    QSqlRecord record = modele->record(intIndex.row());
    QString currentValue = record.value(record.indexOf("nuPays")).toString();
    //qobject_cast<Pays *>(this->parent())->refresh(currentValue);
    this->destroy(true,true);
}//void ListePays::actSelection()

