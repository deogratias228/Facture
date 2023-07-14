#ifndef FACTUREFORM_H
#define FACTUREFORM_H

#include <QWidget>

class QLabel;
class QLineEdit;
class QComboBox;

class FactureForm : public QWidget
{
    Q_OBJECT

public:
    FactureForm(QWidget *parent = nullptr);

private slots:
    void updateTotal();

private:
    QLabel *articleLabel;
    QComboBox *articleComboBox;
    QLabel *quantiteLabel;
    QLineEdit *quantiteLineEdit;
    QLabel *totalLabel;
    QLineEdit *totalLineEdit;
    void loadArticleOptions();
};

#endif // FACTUREFORM_H
