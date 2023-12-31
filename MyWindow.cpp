#include "MyWindow.h"
#include "OngletFichier.h"
#include "UpdateClient.h"
#include "UpdateArticle.h"
#include "EditArticle.h"
#include "EditClient.h"
#include "ListeArticle.h"
#include "ListeClient.h"
#include "UpdateFacture.h"

#include <QApplication>
#include <QMenu>
#include <QAction>
#include <QMainWindow>

/*
 * La fenêtre principale contenant la barre de menu...
 * WOBLESSE K. Déo Gratias
 * 07 juillet 2023
*/

MyWindow::MyWindow(QWidget *parent) : QMainWindow(parent) {

    menuBar = new QMenuBar();
    // Quelques paramétrages perso
    this->setMenuBar(menuBar);
    this->setMinimumSize(620, 420);
    this->setWindowTitle("Gestion des factures");


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


    // Le centralWidget par défaut réduit à l'accuiel
    newAccueil();
    // Connexion des slots aux actions
    QObject::connect(actionQuitter, &QAction::triggered, this, &MyWindow::quitter);
    QObject::connect(actionArticle, &QAction::triggered, this, &MyWindow::newArticle);
    QObject::connect(actionClient, &QAction::triggered, this, &MyWindow::newClient);
    QObject::connect(actionFacture, &QAction::triggered, this, &MyWindow::newFacture);
    QObject::connect(actionListeArticle, &QAction::triggered, this, &MyWindow::listerArticle);
    QObject::connect(actionListeClient, &QAction::triggered, this, &MyWindow::listerClients);

    // Ajout des Menu au menuBar
    menuBar->addMenu(menuFichier);
    menuBar->addMenu(menuUpdate);
    menuBar->addMenu(menuEdit);

}


/* * Le slot "quitter"
 * WOBLESSE K. Déo Gratias, ce 09 juillet 2023
*/
void MyWindow::quitter(){
    QApplication::quit();
}


/* * Formulaire d'ajout d'un nouveau client
 * WOBLESSE K. Déo Gratias, ce 09 juillet 2023
*/
void MyWindow::newClient(){
    centralWidget = new UpdateClient();
    this->setCentralWidget(centralWidget);
    //centralWidget->show();
}


/* * Accueil de l'application
 * WOBLESSE K. Déo Gratias, ce 09 juillet 2023
*/
void MyWindow::newAccueil(){
    centralWidget = new OngletFichier();
    this->setCentralWidget(centralWidget);
    //centralWidget->show();
}


/** Ajout d'un nouveau article
 * WOBLESSE K. Déo Gratias, ce 10 juillet 2023
*/
void MyWindow::newArticle(){
    centralWidget = new UpdateArticle();
    this->setCentralWidget(centralWidget);
    //centralWidget->show();
}

void MyWindow::newFacture(){
    centralWidget = new UpdateFacture();
    this->setMinimumWidth(750);
    this->setCentralWidget(centralWidget);
}

/** Lister les articles
 *  WOBLESSE K. Déo Gratias,ce 11 juillet 2023
*/
void MyWindow::listerArticle(){
    centralWidget = new ListeArticle();
    this->setCentralWidget(centralWidget);
}

/** Lister les clients
 *  WOBLESSE K. Déo Gratias,ce 11 juillet 2023
*/
void MyWindow::listerClients(){
    centralWidget = new ListeClient();
    this->setCentralWidget(centralWidget);
}

