#include "MyWindow.h"
#include "OngletFichier.h"
#include "UpdateClient.h"

#include <QMenu>
#include <QAction>
#include <QMainWindow>

/*
 * La fenêtre principale contenant la barre de menu...
 * WOBLESSE K. Déo Gratias
 * 07 juillet 2023
*/
MyWindow::MyWindow(QWidget *parent) : QWidget(parent) {

    // Quelques paramétrages perso
    this->setMinimumSize(620, 420);

    // La barre de menu
    menuBar = new QMenuBar(this);

    // Les menus de la menuBar
    QMenu *menuFichier = new QMenu("Fichier");
    QMenu *menuUpdate = new QMenu("Mise à jour");
    QMenu *menuEdit = new QMenu("Edition");

    // Les onglets
    //OngletFichier *ongletFichier = new OngletFichier(this);
    //ongletFichier->setGeometry(0, 30, 620, 370);


    /*
     * les actions sur les menus
    */
    // Le menu Fichier
    QAction *actionQuitter = menuFichier->addAction("Quitter");
    // Le menu de Mise à jour
    QAction *actionArticle = menuUpdate->addAction("Article");
    QAction *actionClient = menuUpdate->addAction("Client");
    QAction *actionFacture = menuUpdate->addAction("Facture");
    // Le menu Edition
    QAction *actionListeClient = menuEdit->addAction("Liste Clients");
    QAction *actionListeArticle = menuEdit->addAction("Liste Articles");


    // Connexion des slots aux actions
    //QObject::connect(actionQuitter, SIGNAL(clicked), QApplication:, SLOT(quit()));

    // Ajout des Menu au menuBar
    menuBar->addMenu(menuFichier);
    menuBar->addMenu(menuUpdate);
    menuBar->addMenu(menuEdit);

    // partie de test
    UpdateClient * client = new UpdateClient();

    client->setGeometry(0, 50, 620, 370);

}
