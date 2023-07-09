#include "OngletFichier.h"
#include <QVBoxLayout>

/*
 * Tout ce qui concerne l'onglet d'affichage du menu Fichier
 * WOBLESSE K. Déo Gratias
 * 08 juillet 2023
*/

OngletFichier::OngletFichier(QWidget *parent) : QWidget(parent) {

    //Layout associé
    QVBoxLayout *layout = new QVBoxLayout(this);
    // Le texte d'accueil
    QString styleBienvenu("margin: auto; text-align: center; font-size: 25px;");
    bienvenuTexte = new QLabel("Bienvenu dans l'application de gestion des factures");
    bienvenuTexte->setStyleSheet(styleBienvenu);
    layout->addWidget(bienvenuTexte);
    layout->setAlignment(bienvenuTexte, Qt::AlignHCenter|Qt::AlignVCenter);

}
