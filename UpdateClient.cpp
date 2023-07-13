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

/* Pour l'ajout d'un nouveau client
 * WOBLESSE K. Déo Gratias
 * 08 juillet 2023
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
    SpinBoxNumClient = new QSpinBox();
    SpinBoxNumClient->setButtonSymbols(QAbstractSpinBox::NoButtons);
    SpinBoxNumClient->setReadOnly(true);
    lineEditNom = new QLineEdit();
    lineEditPrenom = new QLineEdit();
    lineEditQuartier = new QLineEdit();
    lineEditRue = new QLineEdit();
    SpinBoxNumMaison = new QSpinBox();
    SpinBoxNumMaison->setButtonSymbols(QAbstractSpinBox::NoButtons);
    SpinBoxNumMaison->setRange(1, 10000);

    QFormLayout *layoutForm = new QFormLayout;
    layoutForm->setContentsMargins(90, 15, 90, 10);
    layoutForm->addRow(labelForm("N°"), SpinBoxNumClient);
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
* Date: 13 juillet 2023
* Auteur: WOBLESSE K. Déo Gratias
*/
{
    //SpinBoxNumClient->setValue(SpinBoxNumClient->value() + 1);
    lineEditNom->setText("");
    lineEditPrenom->setText("");
    lineEditQuartier->setText("");
    lineEditRue->setText("");
    SpinBoxNumMaison->setValue(0);
}


void UpdateClient::submit(){
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
*  Déo Gratias
*  10 juillet 2023
*/
{
    QString str = "<font size='5' face='Arial' style='italic'> ";
    str.append(lib);
    str.append(": </font>");
    const QString str1(str);

    return str1;
}

