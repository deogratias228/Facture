#include "UpdateArticle.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QFormLayout>

UpdateArticle::UpdateArticle(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout;

    QLabel *labDescript = new QLabel(tr("Ajouter un article"));
    labDescript->setStyleSheet("font-size: 28px; font-family: Arial; font-weight: BOLD;");
    QHBoxLayout *layoutDescript = new QHBoxLayout;
    labDescript->setFixedHeight(30);
    layoutDescript->addWidget(labDescript);
    layoutDescript->setAlignment(Qt::AlignHCenter);
    layout->addLayout(layoutDescript);

    //Le formulaire
    lineEditReference = new QLineEdit();
    lineEditLibelle = new QLineEdit();
    lineEditCategorie = new QLineEdit();
    spinBoxPrix = new QDoubleSpinBox();

    QFormLayout *formLayout = new QFormLayout;
    formLayout->setContentsMargins(90, 15, 90, 10);
    formLayout->addRow(tr("<font size='5' face='Arial' style='italic'>&Reférence : </font>"), lineEditReference);
    formLayout->addRow(tr("<font size='5' face='Arial' style='italic'>&Libellé : </font>"), lineEditLibelle);
    formLayout->addRow(tr("<font size='5' face='Arial' style='italic'>&Categorie : </font>"), lineEditCategorie);
    formLayout->addRow(tr("<font size='5' face='Arial' style='italic'>&Prix : </font>"), spinBoxPrix);
    layout->addLayout(formLayout);

    // Les boutons
    QString styleBtn("font-size: 20px; font-family: Arial; font-style: italic;");
    btnAnnuler = new QPushButton(tr("Annuler"));
    btnValider = new QPushButton("Valider");
    btnAnnuler->setStyleSheet(styleBtn);
    btnValider->setStyleSheet(styleBtn);

    QHBoxLayout *layoutBouton = new QHBoxLayout;
    layoutBouton->setContentsMargins(90, 15, 90, 10);
    layoutBouton->addWidget(btnAnnuler);
    layoutBouton->addSpacerItem(new QSpacerItem(70, 15));
    layoutBouton->addWidget(btnValider);
    layout->addLayout(layoutBouton);
    layout->addSpacerItem(new QSpacerItem(75, 100));

    this->setLayout(layout);

}


