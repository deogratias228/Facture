#ifndef LISTEARTICLE_H
#define LISTEARTICLE_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTableView>
#include <QSqlTableModel>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QHBoxLayout>

class ListeArticle : public QWidget {

    //Q_OBJECT
public:
    ListeArticle(QWidget *parent = nullptr);

private:
    QLabel *lblTitle;
    QLineEdit *editSearch;
    QPushButton *quitButton;
    QPushButton *btnAfficher;
    QHBoxLayout *hbOperation;
    QVBoxLayout *viewLayout;
    QDialogButtonBox *buttonBox;
    QSqlTableModel *modele;
    QTableView *view;

 public slots:
    void actFiltre(QString filtre);
    void actSelection();

};

#endif // LISTEARTICLE_H
