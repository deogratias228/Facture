#include "OngletFichier.h"

/*
 * Tout ce qui concerne l'onglet d'affichage du menu Fichier
 * WOBLESSE K. Déo Gratias
 * 08 juillet 2023
*/

OngletFichier::OngletFichier(QWidget *parent) : QWidget(parent) {

    //QLayout layout()
    this->setStyleSheet("background-color: darkblue;");
    // Le texte d'accueil
    QString styleBienvenu("margin: auto; text-align: center; size: 45px;");
    bienvenuTexte = new QLabel(this);
    bienvenuTexte->setText("Bienvenu dans l'application de gestion des factures");
    bienvenuTexte->setStyleSheet(styleBienvenu);

}
