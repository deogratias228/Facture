#include "ListeClient.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtWidgets>
#include <QSqlError>
#include <QLabel>
#include <QLineEdit>

ListeClient::ListeClient(QWidget *parent) : QWidget(parent)
  /*But: Afficher la liste des clients
  * Date: 14 juillet 2023
  * Auteurs: AYEWA Dyanatou & WOBLESSE K. Déo
  */
{
    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *layoutSearch = new QHBoxLayout;
    QFormLayout *formLayout = new QFormLayout;
    QHBoxLayout *descriptLayout = new QHBoxLayout;
    QLabel *descript = new QLabel("Liste des clients");
    descript->setStyleSheet("font-size: 30px; font-family: 'Times New Roman'; font-weight: bold;");
    descriptLayout->addWidget(descript);
    descriptLayout->setAlignment(Qt::AlignHCenter);
    editSearch = new QLineEdit;
    formLayout->addRow(tr("<span style=\"font-size: 20px; font-family: 'Times New Roman'; font-weight: bold;\">Filtre sur Nom Prenom</span>"), editSearch);
    layoutSearch->addSpacing(800);
    layoutSearch->addLayout(formLayout);
    formLayout->setContentsMargins(0, 20, 20, 10);

    layout->addLayout(descriptLayout);
    layout->addLayout(layoutSearch);

    // Le model
    modele = new QSqlTableModel(this);
    modele->setTable("client");
    modele->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modele->setSort(0, Qt::AscendingOrder);
    modele->setHeaderData(0, Qt::Horizontal, tr("N° Client"));
    modele->setHeaderData(1, Qt::Horizontal, tr("Nom du client"));
    modele->setHeaderData(2, Qt::Horizontal, tr("Prénom du client"));
    modele->setHeaderData(3, Qt::Horizontal, tr("Quartier "));
    modele->setHeaderData(4, Qt::Horizontal, tr("Rue "));
    modele->setHeaderData(5, Qt::Horizontal, tr("N° Maison "));
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
    QObject::connect(editSearch, &QLineEdit::textChanged, this, &ListeClient::actFiltre);
}


void ListeClient::actFiltre(const QString& filtre)
/*  But     : Faire un filtre sur les libellés
 *  Auteurs : AYEWA Dyanatou & WOBLESSE K. Déo Gratias
 *  Date    : 14 juillet 2023
 */
{
    modele->setFilter("nom LIKE '%"+filtre+"%' OR prenom LIKE '%"+filtre+"%'");
    modele->setSort(2, Qt::AscendingOrder);
    modele->select();
}//void ListeClient::actFiltre(QString filtre)
