#include "ListeArticle.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtWidgets>
#include <QSqlError>
#include <QLabel>
#include <QLineEdit>


ListeArticle::ListeArticle() : QWidget() {

    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *layoutSearch = new QHBoxLayout;
    QFormLayout *formLayout = new QFormLayout;
    QHBoxLayout *descriptLayout = new QHBoxLayout;
    QLabel *descript = new QLabel("Liste des articles");
    descript->setStyleSheet("font-size: 30px; font-family: 'Times New Roman'; font-weight: bold;");
    descriptLayout->addWidget(descript);
    descriptLayout->setAlignment(Qt::AlignHCenter);
    editSearch = new QLineEdit;
    formLayout->addRow(tr("<span style=\"font-size: 25px; font-family: 'Times New Roman'; font-weight: bold;\">Filtre sur libellé</span>"), editSearch);
    layoutSearch->addSpacing(800);
    layoutSearch->addLayout(formLayout);
    formLayout->setContentsMargins(0, 20, 20, 10);

    layout->addLayout(descriptLayout);
    layout->addLayout(layoutSearch);

    // Le model
    modele = new QSqlTableModel(this);
    modele->setTable("article");
    modele->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modele->setSort(0, Qt::AscendingOrder);
    modele->setHeaderData(0, Qt::Horizontal, tr("Reférence"));
    modele->setHeaderData(1, Qt::Horizontal, tr("libelle"));
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
    //QObject::connect(editSearch, SIGNAL(textChanged(QString)), this, SLOT(&ListeArticle::actFiltre(QString)));
    QObject::connect(editSearch, &QLineEdit::textChanged, this, &ListeArticle::actFiltre);

}


void ListeArticle::actFiltre(const QString& filtre)
/*  But     : Faire un filtre sur les libellés
 *  Auteurs : AYEWA Dyanatou & WOBLESSE K. Déo Gratias
 *  Date    : 14 juillet 2023
 */
{
    modele->setFilter("libelle LIKE '%"+filtre+"%'");
    modele->setSort(2, Qt::AscendingOrder);
    modele->select();
}//void ListeArticle::actFiltre(QString filtre)


