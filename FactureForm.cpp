#include "FactureForm.h"
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>

FactureForm::FactureForm(QWidget *parent) : QWidget(parent)
{
    // Création des labels
    articleLabel = new QLabel("Article :", this);
    quantiteLabel = new QLabel("Quantité :", this);
    totalLabel = new QLabel("Total :", this);

    // Création des champs de saisie
    articleComboBox = new QComboBox(this);

    // Ajouter les options pour les articles dans le ComboBox
    loadArticleOptions();

    quantiteLineEdit = new QLineEdit(this);
    totalLineEdit = new QLineEdit(this);
    totalLineEdit->setReadOnly(true);

    // Connexion du signal "textChanged" de quantiteLineEdit au slot updateTotal
    connect(quantiteLineEdit, &QLineEdit::textChanged, this, &FactureForm::updateTotal);

    // Configuration de la mise en page
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(articleLabel);
    layout->addWidget(articleComboBox);
    layout->addWidget(quantiteLabel);
    layout->addWidget(quantiteLineEdit);
    layout->addWidget(totalLabel);
    layout->addWidget(totalLineEdit);

    this->setLayout(layout);
}


void FactureForm::updateTotal()
{
    // Récupérer la quantité saisie
    QString quantiteStr = quantiteLineEdit->text();
    double quantite = quantiteStr.toDouble();

    // Récupérer la référence de l'article sélectionné
    QString referenceArticle = articleComboBox->currentText();

    // Ouvrir la connexion à la base de données
    QSqlDatabase database = QSqlDatabase::database(); // Utilisez votre nom de connexion de base de données approprié
    if (!database.isValid()) {
        // Gérer les erreurs de connexion à la base de données
        return;
    }

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
        double prixUnitaire = query.value(0).toDouble();

        // Calculer le prix total
        double total = quantite * prixUnitaire;

        // Mettre à jour le champ totalLineEdit avec le total calculé
        totalLineEdit->setText(QString::number(total));
    }
}


void FactureForm::loadArticleOptions()
{
    // Supprimer les options existantes du ComboBox
    articleComboBox->clear();

    // Exécuter la requête pour récupérer les références et les libellés des articles
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT reference, libelle FROM article");

    // Parcourir les résultats de la requête et ajouter les références et les libellés au ComboBox
    for (int i = 0; i < model->rowCount(); ++i) {
        QString reference = model->record(i).value("reference").toString();
        QString libelle = model->record(i).value("libelle").toString();
        QString optionText = reference + " - " + libelle;
        articleComboBox->addItem(optionText);
    }

    // Libérer la mémoire du modèle
    delete model;
}
