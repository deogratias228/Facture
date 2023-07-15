#include "UpdateClient.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QFormLayout>
#include <QPushButton>
#include <QSqlQuery>
#include <QMessageBox>

/* But:     L'enregistrement d'un nouveau client
 * Auteurs: AYEWA & WOBLESSE
 * Date:    08 juillet 2023
*/
UpdateClient::UpdateClient(QWidget *parent) : QWidget(parent){

    QVBoxLayout *layout = new QVBoxLayout(parent);
    QString labelForm(QString lib);

    // La description de l'activité
    QLabel *labDescription = new QLabel("Ajout d'un client");
    labDescription->setStyleSheet("font-size: 28px; font-family: Arial; font-weight: BOLD;");
    labDescription->setFixedHeight(40);
    QVBoxLayout *layoutDescription = new QVBoxLayout;
    layoutDescription->addWidget(labDescription);
    layoutDescription->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    layout->addLayout(layoutDescription);

    // Le formulaire
    spinBoxNumClient = new QSpinBox();
    spinBoxNumClient->setValue(numeroClient());
    spinBoxNumClient->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spinBoxNumClient->setReadOnly(true);
    lineEditNom = new QLineEdit();
    lineEditPrenom = new QLineEdit();
    lineEditQuartier = new QLineEdit();
    lineEditRue = new QLineEdit();
    SpinBoxNumMaison = new QSpinBox();
    SpinBoxNumMaison->setButtonSymbols(QAbstractSpinBox::NoButtons);
    SpinBoxNumMaison->setRange(1, 10000);

    QFormLayout *layoutForm = new QFormLayout;
    layoutForm->setContentsMargins(90, 15, 90, 10);
    layoutForm->addRow(labelForm("N°"), spinBoxNumClient);
    layoutForm->addRow(tr("<font size='5' face='Arial' style='italic'>&Nom : </font>"), lineEditNom);
    layoutForm->addRow(tr("<font size='5' face='Arial' style='italic'>&Prénoms : </font>"), lineEditPrenom);
    layoutForm->addRow(tr("<font size='5' face='Arial' style='italic'>&Quartier : </font>"), lineEditQuartier);
    layoutForm->addRow(tr("<font size='5' face='Arial' style='italic'>&Rue : </font>"), lineEditRue);
    layoutForm->addRow(tr("<font size='5' face='Arial' style='italic'>&N° de Maison : </font>"), SpinBoxNumMaison);



    layout->addLayout(layoutForm);


    // Les boutons
    QString styleBtn("font-size: 20px; font-family: Arial; font-style: italic;");
    btnAnnuler = new QPushButton(tr("Annuler"));
    btnValider = new QPushButton("Valider");
    btnAnnuler->setStyleSheet(styleBtn);
    btnValider->setStyleSheet(styleBtn);

    QHBoxLayout *layoutBouton = new QHBoxLayout;
    layoutBouton->setContentsMargins(90, 15, 90, 10);
    layoutBouton->addWidget(btnAnnuler);
    layoutBouton->addSpacerItem(new QSpacerItem(70, 15));
    layoutBouton->addWidget(btnValider);
    layout->addLayout(layoutBouton);

    // Ajout du layout
    this->setLayout(layout);

    connect(btnAnnuler, &QPushButton::clicked, this, &UpdateClient::cleanFormulaire);
    connect(btnValider, &QPushButton::clicked, this, &UpdateClient::submit);
}


void UpdateClient::cleanFormulaire()
/* But: Réinitialiser le formulaire
* Auteurs: AYEWA & WOBLESSE
* Date: 13 juillet 2023
*/
{
    //SpinBoxNumClient->setValue(SpinBoxNumClient->value() + 1);
    lineEditNom->setText("");
    lineEditPrenom->setText("");
    lineEditQuartier->setText("");
    lineEditRue->setText("");
    SpinBoxNumMaison->setValue(0);
}

int UpdateClient::numeroClient()
/*But    : le numero du client en cours d'enregistrement
* Auteurs: AYEWA & WOBLESSE
* Date   : 15juillet
*/
{
    int numClient(0);

    QSqlQuery query;
    query.exec("SELECT numero_client FROM client ORDER BY numero_client DESC LIMIT 1");

    if(query.next())
        numClient = query.value(0).toInt();

    return numClient + 1;
}


void UpdateClient::submit()
/*But    : Le slot qui envoie le nouveau client dans la base
* Auteurs: AYEWA & WOBLESSE
* Date   : 13 juillet 2023
*/
{
    nom = lineEditNom->text();
    prenom = lineEditPrenom->text();
    quartier = lineEditQuartier->text();
    rue = lineEditRue->text();
    numMaison = SpinBoxNumMaison->value();

    QSqlQuery query;
    query.prepare("INSERT INTO client(nom, prenom, quartier, rue, numero_maison) VALUES (:nom,:prenom,:quartier,:rue, :numero_maison)");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":quartier", quartier);
    query.bindValue(":rue", rue);
    query.bindValue(":numero_maison", numMaison);

    if(!query.exec()){
        QMessageBox::critical(nullptr, tr("Avertissement"), tr("Echec de l'insertion"));
    }else {
        QMessageBox::information(nullptr, tr("Opération validée"), tr("Vous avez bien inséré ")+ nom + " " +prenom);
        cleanFormulaire();
    }

}


QString labelForm(QString lib)
/* Raccourcir la mise en forme des labels du formulaire.
*  Auteurs: AYEWA & WOBLESSE
*  10 juillet 2023
*/
{
    QString str = "<font size='5' face='Arial' style='italic'> ";
    str.append(lib);
    str.append(": </font>");
    const QString str1(str);

    return str1;
}


