#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include <QMenuBar>

class MyWindow : public QWidget{
    Q_OBJECT

    public:
        MyWindow(QWidget *parent = nullptr);

    private:
        QMenuBar *menuBar;
};

#endif // MYWINDOW_H
