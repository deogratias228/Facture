#include "UpdateFacture.h"
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QDate>
#include <QMessageBox>

UpdateFacture::UpdateFacture(QWidget *parent) : QWidget(parent)
{
    this->setMinimumWidth(700);
    QVBoxLayout *layout = new QVBoxLayout(this);
    QVBoxLayout *layoutArt = new QVBoxLayout;

    // La description de l'activité
    QLabel *labDescription = new QLabel("Créer une facture");
    labDescription->setStyleSheet("font-size: 28px; font-family: 'Times New Roman'; font-weight: BOLD;");
    QVBoxLayout *layoutDescription = new QVBoxLayout;
    layoutDescription->addWidget(labDescription);
    layoutDescription->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    layout->addLayout(layoutDescription);

    QHBoxLayout *labelLayout = new QHBoxLayout;
    //labelLayout->addSpacing(100);
    labelArticle = new QLabel(tr("<span style=\"font-size: 18px; font-weight: BOLD; font-family: 'Times New Roman'; color: #000000;\">Article </span>"));
    labelQuantite = new QLabel(tr("<span style=\"font-size: 18px; font-weight: BOLD; font-family: 'Times New Roman'; color: #000000;\">Quantité</span>"));
    labelTotal = new QLabel(tr("<span style=\"font-size: 18px; font-weight: BOLD; font-family: 'Times New Roman'; color: #000000;\">Total</span>"));
    labelArticle->setMinimumWidth(this->size().width()*0.8);
    labelArticle->setAlignment(Qt::AlignHCenter);
    labelArticle->setMaximumHeight(30);
    labelQuantite->setMinimumWidth(this->size().width()*0.18);
    labelQuantite->setAlignment(Qt::AlignHCenter);
    labelQuantite->setMaximumHeight(30);
    labelTotal->setMinimumWidth(this->size().width()*0.1);
    labelTotal->setAlignment(Qt::AlignHCenter);
    labelTotal->setMaximumHeight(30);
    labelLayout->addWidget(labelArticle);
    labelLayout->addWidget(labelQuantite);
    labelLayout->addWidget(labelTotal);
    layout->addLayout(labelLayout);


    for (int i = 0; i < 10; ++i) {
        // Création des labels
        QString lArticle = QString::number(i +1) + " -   ";
        labArticle[i] = new QLabel(lArticle, this);

        //la liste d'option d'un article
        comboBoxArticle[i] = new QComboBox(this);
        loadArticleOptions(comboBoxArticle[i]);
        // Création des champs de saisie
        spinBoxQuantite[i] = new QSpinBox;
        spinBoxMontant[i] = new QSpinBox;
        spinBoxMontant[i]->setRange(0, 1000000);
        spinBoxMontant[i]->setReadOnly(true);
        spinBoxMontant[i]->setButtonSymbols(QAbstractSpinBox::NoButtons);

        // Connexion du signal "valueChanged" de spinBoxQuantite au slot updateTotal
        connect(spinBoxQuantite[i], QOverload<int>::of(&QSpinBox::valueChanged), this, [=](int newValue) {
            updateMontant(newValue, i);
        });

        // Configuration de la mise en page
        QHBoxLayout *articleLayout = new QHBoxLayout;
        QFormLayout *articleFormLayout = new QFormLayout;

        labArticle[i]->setMinimumWidth(this->size().width()*0.2);
        comboBoxArticle[i]->setMinimumWidth(this->size().width()*0.52);
        spinBoxQuantite[i]->setMinimumWidth(this->size().width()*0.18);
        spinBoxMontant[i]->setMinimumWidth(this->size().width()*0.1);
        articleFormLayout->addRow(labArticle[i], comboBoxArticle[i]);
        articleLayout->addLayout(articleFormLayout);
        articleLayout->addWidget(spinBoxQuantite[i]);
        articleLayout->addWidget(spinBoxMontant[i]);


        layoutArt->addLayout(articleLayout);
    }


    // Le choix du client
    QHBoxLayout *layoutClient = new QHBoxLayout;
    QFormLayout *formLayouClient = new QFormLayout;
    QHBoxLayout *layoutTotal = new QHBoxLayout;
    QFormLayout *formLayoutTotal = new QFormLayout;

    comboBoxClient = new QComboBox(this);
    loadClientOptions(comboBoxClient);
    formLayouClient->addRow(new QLabel(tr("<span style=\"font-size: 22px; font-weight: BOLD; font-family: 'Times New Roman'; color: #000000;\">Client : </span>")), comboBoxClient);
    layoutClient->addLayout(formLayouClient);
    layoutClient->setAlignment(Qt::AlignLeft);


    spinBoxTotal = new QDoubleSpinBox;
    spinBoxTotal->setRange(0, 1000000);
    spinBoxTotal->setReadOnly(true);
    spinBoxTotal->setButtonSymbols(QAbstractSpinBox::NoButtons);
    formLayoutTotal->addRow(new QLabel(tr("<span style=\"font-size: 22px; font-weight: BOLD; font-family: 'Times New Roman'; color: #000000;\">Total HT : </span>")), spinBoxTotal);

    spinBoxTVA = new QDoubleSpinBox;
    spinBoxTVA->setValue(19.6);
    spinBoxTVA->setButtonSymbols(QAbstractSpinBox::NoButtons);
    formLayoutTotal->addRow(new QLabel(tr("<span style=\"font-size: 22px; font-weight: BOLD; font-family: 'Times New Roman'; color: #000000;\">TVA(%) : </span>")), spinBoxTVA);

    spinBoxTotalTTC = new QDoubleSpinBox;
    spinBoxTotalTTC->setRange(0, 1000000);
    spinBoxTotalTTC->setButtonSymbols(QAbstractSpinBox::NoButtons);
    formLayoutTotal->addRow(new QLabel(tr("<span style=\"font-size: 22px; font-weight: BOLD; font-family: 'Times New Roman'; color: #000000;\">Total TTC: </span>")), spinBoxTotalTTC);

    layoutTotal->addLayout(formLayoutTotal);
    layoutTotal->setAlignment(Qt::AlignRight);


    // Enregistrer la facture
    btnEnregistrer = new QPushButton("Enregistrer");
    btnEnregistrer->setMaximumWidth(200);
    QHBoxLayout *layoutSave = new QHBoxLayout;
    layoutSave->addWidget(btnEnregistrer);

    // Connexion du signal "valueChanged" de spinBoxQuantite au slot updateTotal
    for (int i = 0; i<10; i++) {
        connect(spinBoxMontant[i], QOverload<int>::of(&QSpinBox::valueChanged), this, &UpdateFacture::updateTotal);
    }

    connect(spinBoxTotal, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &UpdateFacture::updateTotalTTC);
    connect(spinBoxTVA , QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &UpdateFacture::updateTotalTTC);
    connect(btnEnregistrer, &QPushButton::clicked, this, &UpdateFacture::enregistrer);

    layout->addLayout(layoutArt);
    layout->addLayout(layoutClient);
    layout->addLayout(layoutTotal);
    layout->addLayout(layoutSave);

}



void UpdateFacture::updateMontant(int newValue, int index)
/* But:     Mise à jour du champ Montant pour un article
* Auteurs:  AYEWA & WOBLESSE
* Date:     14 juillet
*/
{
    // Récupérer la quantité saisie
    int quantite = newValue;

    // Récupérer la référence de l'article sélectionné
    QString referenceArticle = comboBoxArticle[index]->currentData(Qt::UserRole).toString();

    // Exécuter la requête pour récupérer le prix de l'article
    QSqlQuery query;
    query.prepare("SELECT prix FROM article WHERE reference = :reference");
    query.bindValue(":reference", referenceArticle);

    if (!query.exec()) {
        // Gérer les erreurs d'exécution de la requête
        return;
    }

    // Vérifier si la requête a renvoyé un résultat
    if (query.next()) {
        // Récupérer le prix de l'article
        double prix = query.value("prix").toDouble();

        // Calculer le prix total
        double total = quantite * prix;

        // Mettre à jour la valeur de spinBoxTotal avec le total calculé
        spinBoxMontant[index]->setValue(total);
    }
}


void UpdateFacture::updateTotal()
/* But:     Mise à jour du champ total de la facture
* Auteurs:  AYEWA & WOBLESSE
* Date:     14 juillet
*/
{
    double total(0);
    // Calculer le prix total
    for(int i=0; i<10; i++) {
        total += spinBoxMontant[i]->value();
    }

    // Mettre à jour la valeur de spinBoxTotal avec le total calculé
    spinBoxTotal->setValue(total);

}

void UpdateFacture::updateTotalTTC()
/* But:     Mise à jour du champ total Tout Taxe Compris de la facture
* Auteurs:  AYEWA & WOBLESSE
* Date:     15 juillet
*/
{
    double total = spinBoxTotal->value();
    double tva = spinBoxTVA->value();

    spinBoxTotalTTC->setValue(total*tva/100 +total);

}


void UpdateFacture::loadArticleOptions(QComboBox* comboBox)
/* But:     Charger la liste de tous les articles
* Auteurs:  AYEWA & WOBLESSE
* Date:     14 juillet
*/
{
    comboBox->clear();

    QSqlQuery query("SELECT reference, libelle, prix FROM article");
    if (query.exec()) {
        while (query.next()) {
            QString reference = query.value("reference").toString();
            QString libelle = query.value("libelle").toString();

            QString optionText = reference + " : " + libelle;
            comboBox->addItem(optionText, reference);
        }
    }
}


void UpdateFacture::loadClientOptions(QComboBox* comboBox)
/* But:     Charger la liste de tous les client de la base
* Auteurs:  AYEWA & WOBLESSE
* Date:     15 juillet
*/
{
    comboBox->clear();

    QSqlQuery query("SELECT  numero_client, nom, prenom FROM client");
    if (query.exec()) {
        while (query.next()) {
            QString nom = query.value("nom").toString();
            QString prenom = query.value("prenom").toString();
            int numeroClient = query.value("numero_client").toInt();

            QString optionText = nom + " : " + prenom;
            comboBox->addItem(optionText, numeroClient);
        }
    }
}


int UpdateFacture::numeroFacture()
/* But: le numero de la facture courante
* Auteurs: AYEWA & WOBLESSE
* Date 15juillet
*/
{
   QSqlQuery query;
   query.exec("SELECT id FROM facture ORDER BY id DESC LIMIT 1");

   int numFacture(1);
   if (query.next())
       numFacture = query.value(0).toInt();

   return numFacture+1;
}


bool UpdateFacture::saveFacture()
/* But: Enregistrer les infos sur la facture
* Auteurs: AYEWA & WOBLESSE
* Date 15juillet
*/
{
    bool response = false;
    QDate date = QDate::currentDate();
    int numero_client = comboBoxClient->currentData(Qt::UserRole).toInt();


    QSqlQuery query;
    query.prepare("INSERT INTO facture(date, montant, id_client) "
                  "VALUES(:date, :montant, :id_client)");
    query.bindValue(":date", date);
    query.bindValue(":montant", spinBoxTotalTTC->value());
    query.bindValue(":id_client", numero_client );

    if(query.exec()){
        response = true;
        QMessageBox::information(this, tr("Information"), tr("Vous avez ajouter une facture"));
    }else
        QMessageBox::critical(this, tr("Avertissement"), tr("La facture n'a pas pu être créée"));


    return response;
}


bool UpdateFacture::saveFactureDetail(int index)
/* But: Enregistrer les articles associés à une facture
* Auteurs: AYEWA & WOBLESSE
* Date 15juillet
*/
{
    bool response = false;

    QString refArticle = comboBoxArticle[index]->currentData(Qt::UserRole).toString();
    int quantite = spinBoxQuantite[index]->value();
    double total = spinBoxMontant[index]->value();

    QSqlQuery query;
    query.prepare("INSERT INTO detail_facture(id_facture, reference_article, quantite, total) VALUES (:id_facture, :reference_article, :quantite, :total)");
    query.bindValue(":id_facture", numeroFacture());
    query.bindValue(":reference_article", refArticle);
    query.bindValue(":quantite", quantite);
    query.bindValue(":total", total);

    if(query.exec())
        response = true;

    return response;
}


void UpdateFacture::enregistrer()
/* But: Valider la facture
* Auteurs: AYEWA & WOBLESSE
* Date 15juillet
*/
{
    for(int i=0; i<10; i++){
        if((spinBoxQuantite[i]->value()!=0)){
            if( !(saveFactureDetail(i))){
                 return;
            }
        }
    }

    QMessageBox::information(this, "Information", "les délails sont enregistrés avec succès");
    if(saveFacture())
        QMessageBox::information(this, "Information", "Facture enregistrée avec succès");
    else
        QMessageBox::critical(this, "Information", "Les détails sont enregistrés mais pas la facture");
}
