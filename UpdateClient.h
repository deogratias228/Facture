#ifndef UPDATECLIENT_H
#define UPDATECLIENT_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QStatusBar>

class UpdateClient : public QWidget {
    public:
        UpdateClient(QWidget *parent = nullptr);
        void cleanFormulaire();
    private:
        QSpinBox *SpinBoxNumClient;
        QLineEdit *lineEditNom;
        QLineEdit *lineEditPrenom;
        QLineEdit *lineEditQuartier;
        QLineEdit *lineEditRue;
        QSpinBox *SpinBoxNumMaison;

        int numClient;
        QString nom;
        QString prenom;
        QString quartier;
        QString rue;
        int numMaison;

        QPushButton *btnAnnuler;
        QPushButton *btnValider;
        QStatusBar *statusBar;

    private slots:
        void submit();
        void cancel();

};

#endif // UPDATECLIENT_H
