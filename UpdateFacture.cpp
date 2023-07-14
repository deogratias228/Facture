#include "UpdateFacture.h"
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

FactureForm::FactureForm(QWidget *parent) : QWidget(parent)
{

    QVBoxLayout *layout = new QVBoxLayout(this);

    // La description de l'activité
    QLabel *labDescription = new QLabel("Créer une facture");
    labDescription->setStyleSheet("font-size: 28px; font-family: 'Times New Roman'; font-weight: BOLD;");
    //labDescription->setFixedHeight(40);
    QVBoxLayout *layoutDescription = new QVBoxLayout;
    layoutDescription->addWidget(labDescription);
    layoutDescription->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    layout->addLayout(layoutDescription);

    QHBoxLayout *labelLayout = new QHBoxLayout;
    labelLayout->addSpacing(100);
    labelLayout->addWidget(new QLabel(tr("<span style=\"font-size: 18px; font-weight: BOLD; font-family: 'Times New Roman'; color: #000000;\">Article </span>")));
    labelLayout->addSpacing(150);
    labelLayout->addWidget(new QLabel(tr("<span style=\"font-size: 18px; font-weight: BOLD; font-family: 'Times New Roman'; color: #000000;\">Quantité</span>")));
    labelLayout->addWidget(new QLabel(tr("<span style=\"font-size: 18px; font-weight: BOLD; font-family: 'Times New Roman'; color: #000000;\">Total</span>")));
    //labelLayout->setContentsMargins(100, 5, 100, 5);
    layout->addLayout(labelLayout);


    for (int i = 0; i < 10; ++i) {
        // Création des labels
        QString strArticle(tr("Article"));
        QString i_str(i);

        strArticle = strArticle + " Vue " +QString(i+1);
        labelArticle[i] = new QLabel(strArticle, this);
        labelQuantite[i] = new QLabel(tr("Quantité : "), this);
        labelTotal[i] = new QLabel(tr("Total : "), this);

        // Création des champs de saisie
        comboBoxArticle[i] = new QComboBox(this);
        loadArticleOptions(comboBoxArticle[i]);

        spinBoxQuantite[i] = new QSpinBox;
        spinBoxTotal[i] = new QSpinBox;
        spinBoxTotal[i]->setRange(0, 1000000);
        spinBoxTotal[i]->setReadOnly(true);
        spinBoxTotal[i]->setButtonSymbols(QAbstractSpinBox::NoButtons);

        // Connexion du signal "valueChanged" de spinBoxQuantite au slot updateTotal
        connect(spinBoxQuantite[i], QOverload<int>::of(&QSpinBox::valueChanged), this, [=](int newValue) {
            updateTotal(newValue, i);
        });

        // Configuration de la mise en page
        QHBoxLayout *articleLayout = new QHBoxLayout;

        articleLayout->addWidget(new QLabel(i_str));
        articleLayout->addWidget(comboBoxArticle[i]);
        articleLayout->addWidget(spinBoxQuantite[i]);
        articleLayout->addWidget(spinBoxTotal[i]);


        layout->addLayout(articleLayout);
    }

}


/*void FactureForm::updateTotal(int newValue)
{
    // Récupérer la quantité saisie
    int quantite = newValue;

    // Récupérer la référence de l'article sélectionné
    QString referenceArticle = comboBoxArticle->currentData(Qt::UserRole).toString();

    // Exécuter la requête pour récupérer le prix de l'article
    QSqlQuery query;
    query.prepare("SELECT prix FROM article WHERE reference = :reference");
    query.bindValue(":reference", referenceArticle);

    if (!query.exec()) {
        // Gérer les erreurs d'exécution de la requête
        return;
    }

    // Vérifier si la requête a renvoyé un résultat
    if (query.next()) {
        // Récupérer le prix de l'article
        double prix = query.value("prix").toDouble();

        // Calculer le prix total
        double total = quantite * prix;

        // Mettre à jour la valeur de spinBoxTotal avec le total calculé
        spinBoxTotal->setValue(total);
    }
}



void FactureForm::loadArticleOptions()
{
    // Supprimer les options existantes du ComboBox
    comboBoxArticle->clear();

    QSqlQuery query("SELECT reference, libelle, prix FROM article");
    if (query.exec()) {
        // Parcourir les résultats de la requête et ajouter les références et les libellés au ComboBox
        while (query.next()) {
            QString reference = query.value("reference").toString();
            QString libelle = query.value("libelle").toString();

            QString optionText = reference + " : " + libelle;
            comboBoxArticle->addItem(optionText, reference);
        }
    }

}
*/

void FactureForm::updateTotal(int newValue, int index)
{
    // Récupérer la quantité saisie
    int quantite = newValue;

    // Récupérer la référence de l'article sélectionné
    QString referenceArticle = comboBoxArticle[index]->currentData(Qt::UserRole).toString();

    // Exécuter la requête pour récupérer le prix de l'article
    QSqlQuery query;
    query.prepare("SELECT prix FROM article WHERE reference = :reference");
    query.bindValue(":reference", referenceArticle);

    if (!query.exec()) {
        // Gérer les erreurs d'exécution de la requête
        return;
    }

    // Vérifier si la requête a renvoyé un résultat
    if (query.next()) {
        // Récupérer le prix de l'article
        double prix = query.value("prix").toDouble();

        // Calculer le prix total
        double total = quantite * prix;

        // Mettre à jour la valeur de spinBoxTotal avec le total calculé
        spinBoxTotal[index]->setValue(total);
    }
}


void FactureForm::loadArticleOptions(QComboBox* comboBox)
{
    comboBox->clear();

    QSqlQuery query("SELECT reference, libelle, prix FROM article");
    if (query.exec()) {
        while (query.next()) {
            QString reference = query.value("reference").toString();
            QString libelle = query.value("libelle").toString();

            QString optionText = reference + " : " + libelle;
            comboBox->addItem(optionText, reference);
        }
    }
}

