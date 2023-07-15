#ifndef UPDATEFACTURE_H
#define UPDATEFACTURE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QPushButton>

class UpdateFacture : public QWidget
{
    Q_OBJECT

public:
    UpdateFacture(QWidget *parent = nullptr);
    int numeroFacture();
    bool saveFactureDetail(int index);
    bool saveFacture();

private:
    QLabel *labelArticle;
    QLabel *labelQuantite;
    QLabel *labelTotal;
    QComboBox *comboBoxArticle[10];
    QComboBox *comboBoxClient;
    QSpinBox *spinBoxQuantite[10];
    QSpinBox *spinBoxMontant[10];
    QDoubleSpinBox *spinBoxTotal;
    QDoubleSpinBox *spinBoxTVA;
    QDoubleSpinBox *spinBoxTotalTTC;
    QLabel *labArticle[10];
    QPushButton *btnEnregistrer;

private slots:
    void updateMontant(int newValue, int index);
    void updateTotal();
    void updateTotalTTC();
    void loadArticleOptions(QComboBox *comboBox);
    void loadClientOptions(QComboBox *comboBox);
    void enregistrer();

};

#endif // UPDATEFACTURE_H
