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
    private:
        QSpinBox *lineEditNumClient;
        QLineEdit *lineEditNom;
        QLineEdit *lineEditPrenom;
        QLineEdit *lineEditQuartier;
        QLineEdit *lineEditRue;
        QSpinBox *lineEditNumMaison;

        QPushButton *btnAnnuler;
        QPushButton *btnValider;

        QStatusBar *statusBar;

};

#endif // UPDATECLIENT_H
