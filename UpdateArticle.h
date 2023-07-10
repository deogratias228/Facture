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

private:
    QLineEdit *lineEditReference;
    QLineEdit *lineEditLibelle;
    QLineEdit *lineEditCategorie;
    QDoubleSpinBox *spinBoxPrix;

    QPushButton *btnAnnuler;
    QPushButton *btnValider;
    QStatusBar *statusBar;
};

#endif // UPDATEARTICLE_H
