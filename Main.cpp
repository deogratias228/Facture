#include <QApplication>
#include "MyWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWindow mainWindow;
    mainWindow.show();

    return app.exec();

}

