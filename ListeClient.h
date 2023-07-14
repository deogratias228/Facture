#ifndef LISTECLIENT_H
#define LISTECLIENT_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTableView>
#include <QSqlTableModel>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QHBoxLayout>

class ListeClient : public QWidget
{
private:
    QLabel *lblTitle;
    QLineEdit *editSearch;
    //QPushButton *quitButton;
    //QPushButton *btnAfficher;
    QHBoxLayout *hbOperation;
    QVBoxLayout *viewLayout;
    QDialogButtonBox *buttonBox;
    QSqlTableModel *modele;
    QTableView *view;

 public slots:
    void actFiltre(const QString& filtre);
    void actSelection();
 public:
    ListeClient(QWidget *parent = nullptr);
};

#endif // LISTECLIENT_H
