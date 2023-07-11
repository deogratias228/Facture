QT += widgets
QT += sql

SOURCES += \
    EditArticle.cpp \
    EditClient.cpp \
    Main.cpp \
    MyWindow.cpp \
    OngletFichier.cpp \
    UpdateArticle.cpp \
    UpdateClient.cpp \
    connexion_file.cpp

HEADERS += \
    EditArticle.h \
    EditClient.h \
    MyWindow.h \
    OngletFichier.h \
    UpdateArticle.h \
    UpdateClient.h

unix:!macx: LIBS += -L$$PWD/../../../Téléchargements/mysql-connector-c-6.1.11-linux-glibc2.12-x86_64/lib/ -lmysqlclient

INCLUDEPATH += $$PWD/../../../Téléchargements/mysql-connector-c-6.1.11-linux-glibc2.12-x86_64/include
DEPENDPATH += $$PWD/../../../Téléchargements/mysql-connector-c-6.1.11-linux-glibc2.12-x86_64/include
