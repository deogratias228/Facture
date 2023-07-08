#include "UpdateClient.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QPushButton>

/* Pour l'ajout d'un nouveau client
 * WOBLESSE K. Déo Gratias
 * 08 juillet 2023
*/
UpdateClient::UpdateClient(QWidget *parent) : QWidget(parent){

    QVBoxLayout *layout = new QVBoxLayout(parent);

    // La description de l'activité
    QLabel *labDescription = new QLabel("Ajout d'un client");
    labDescription->setStyleSheet("font-size: 28px; font-family: Arial; font-weight: BOLD;");
    QVBoxLayout *layoutDescription = new QVBoxLayout;
    layoutDescription->addWidget(labDescription);
    layoutDescription->setAlignment(Qt::AlignHCenter);
    layout->addLayout(layoutDescription);
    labDescription->setFixedHeight(40);

    // Le formulaire
    QLineEdit *lineEditNumClient = new QLineEdit();
    QLineEdit *lineEditNom = new QLineEdit();
    QLineEdit *lineEditPrenom = new QLineEdit();
    QLineEdit *lineEditQuartier = new QLineEdit();
    QLineEdit *lineEditRue = new QLineEdit();
    QLineEdit *lineEditNumMaison = new QLineEdit();

    QFormLayout *layoutForm = new QFormLayout;
    layoutForm->setContentsMargins(90, 15, 90, 10);
    layoutForm->addRow(tr("<font size='5' face='Arial' style='italic'>&N° : </font>"), lineEditNumClient);
    layoutForm->addRow(tr("<font size='5' face='Arial' style='italic'>&Nom : </font>"), lineEditNom);
    layoutForm->addRow(tr("<font size='5' face='Arial' style='italic'>&Prénoms : </font>"), lineEditPrenom);
    layoutForm->addRow(tr("<font size='5' face='Arial' style='italic'>&Quartier : </font>"), lineEditQuartier);
    layoutForm->addRow(tr("<font size='5' face='Arial' style='italic'>&Rue : </font>"), lineEditRue);
    layoutForm->addRow(tr("<font size='5' face='Arial' style='italic'>&N° de maison : </font>"), lineEditNumMaison);

    layout->addLayout(layoutForm);


    // Les boutons
    QString styleBtn("font-size: 20px; font-family: Arial; font-style: italic;");
    QPushButton *btnAnnuler = new QPushButton(tr("Annuler"));
    QPushButton *btnValider = new QPushButton("Valider");
    btnAnnuler->setStyleSheet(styleBtn);
    btnValider->setStyleSheet(styleBtn);

    QHBoxLayout *layoutBouton = new QHBoxLayout;
    layoutBouton->setContentsMargins(90, 15, 90, 10);
    layoutBouton->addWidget(btnAnnuler);
    layoutBouton->addSpacerItem(new QSpacerItem(70, 15));
    layoutBouton->addWidget(btnValider);
    layout->addLayout(layoutBouton);

}
