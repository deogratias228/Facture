#ifndef ONGLETFICHIER_H
#define ONGLETFICHIER_H

#include <QWidget>
#include <QLabel>

class OngletFichier : public QWidget{

    public:
        OngletFichier(QWidget *parent = nullptr);
    private:
        QLabel *bienvenuTexte;

};

#endif // ONGLETFICHIER_H
