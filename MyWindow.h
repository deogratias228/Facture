#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QMainWindow>
#include <QStatusBar>

class MyWindow : public QMainWindow {
    Q_OBJECT

    public:
        MyWindow(QWidget *parent = nullptr);

    private:
        QMenuBar *menuBar;
        QWidget *centralWidget;
        QStatusBar *bottomBar;

        QMenu *menuFichier;
        QMenu *menuUpdate;
        QMenu *menuEdit;

        QAction *actionQuitter;
        QAction *actionArticle;
        QAction *actionClient;
        QAction *actionFacture;
        QAction *actionListeArticle;
        QAction *actionListeClient;


    private slots:
        void quitter();
        void newAccueil();
        void newClient();
        void newFacture();
        void newArticle();
        void listerArticle();
        void listerClients();

};

#endif // MYWINDOW_H
