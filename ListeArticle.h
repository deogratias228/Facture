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
#include <QString>

class ListeArticle : public QWidget {

    //Q_OBJECT
public:
    ListeArticle();

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
    //void actFiltre(QString filtre);
    void actSelection();
    void actFiltre(const QString& filtre);

};

#endif // LISTEARTICLE_H
