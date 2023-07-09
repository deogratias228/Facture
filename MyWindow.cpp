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
MyWindow::MyWindow(QWidget *parent) : QMainWindow(parent) {

    // Quelques paramétrages perso
    this->setMinimumSize(620, 420);

    // La barre de menu
    menuBar = new QMenuBar();
    this->setMenuBar(menuBar);

    // Les menus de la menuBar
    menuFichier = new QMenu("Fichier");
    menuUpdate = new QMenu("Mise à jour");
    menuEdit = new QMenu("Edition");


            //les actions sur les menus
    // Le menu Fichier
    actionQuitter = menuFichier->addAction("Quitter");
    // Le menu de Mise à jour
    actionArticle = menuUpdate->addAction("Article");
    actionClient = menuUpdate->addAction("Client");
    actionFacture = menuUpdate->addAction("Facture");
    // Le menu Edition
    actionListeArticle = menuEdit->addAction("Liste Articles");
    actionListeClient = menuEdit->addAction("Liste Clients");


    // Connexion des slots aux actions
    //QObject::connect(actionQuitter, SIGNAL(clicked), QApplication:, SLOT(quit()));

    // Ajout des Menu au menuBar
    menuBar->addMenu(menuFichier);
    menuBar->addMenu(menuUpdate);
    menuBar->addMenu(menuEdit);

    // partie de test

    newAccueil();
}


/*
 * Formulaire d'ajout d'un nouveau client
 * WOBLESSE K. Déo Gratias
 * 09 juillet 2023
*/
void MyWindow::newClient(){
    centralWidget = new UpdateClient();
    this->setCentralWidget(centralWidget);
    centralWidget->show();
}

/*
 * Accueil de l'application
 * WOBLESSE K. Déo Gratias
 * 09 juillet 2023
*/
void MyWindow::newAccueil(){
    centralWidget = new OngletFichier();
    this->setCentralWidget(centralWidget);
    centralWidget->show();
}
