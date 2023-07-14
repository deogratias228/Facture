#ifndef UPDATEFACTURE_H
#define UPDATEFACTURE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QComboBox>

class FactureForm : public QWidget
{
    Q_OBJECT

public:
    FactureForm(QWidget *parent = nullptr);

private:
    QLabel *labelArticle[10];
    QComboBox *comboBoxArticle[10];
    QLabel *labelQuantite[10];
    QSpinBox *spinBoxQuantite[10];
    QLabel *labelTotal[10];
    QSpinBox *spinBoxTotal[10];

private slots:
    void updateTotal(int newValue, int index);
    void loadArticleOptions(QComboBox *comboBox);

};

#endif // UPDATEFACTURE_H
