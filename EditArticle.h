#ifndef EDITARTICLE_H
#define EDITARTICLE_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTableView>

class EditArticle : public QWidget {

    Q_OBJECT
    private:
        QSqlTableModel *tableModel;
        QTableView *tableView;
    public:
        EditArticle(QWidget *parent = nullptr);
};

#endif // EDITARTICLE_H
