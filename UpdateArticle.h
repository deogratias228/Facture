#ifndef UPDATEARTICLE_H
#define UPDATEARTICLE_H

#include <QWidget>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QStatusBar>
#include <QPushButton>


class UpdateArticle : public QWidget{
    Q_OBJECT

public:
    UpdateArticle(QWidget *parent = nullptr);
    void cleanFormulaire();

private:
    QLineEdit *lineEditReference;
    QLineEdit *lineEditLibelle;
    QLineEdit *lineEditCategorie;
    QDoubleSpinBox *spinBoxPrix;

    QPushButton *btnAnnuler;
    QPushButton *btnValider;
    QStatusBar *statusBar;

    QString reference;
    QString libelle;
    QString categorie;
    double prix;


private slots:
    void submit();
    void cancel();
    //void actSelection();
};

#endif // UPDATEARTICLE_H
