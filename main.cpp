#include "mainwindow.h"
#include "configwizard.h"
#include <QApplication>

int main(int argc, char *argv[])
{
   // Q_INIT_RESOURCE(configwizard);

    QApplication a(argc, argv);
    MainWindow w;

    w.show();



    return a.exec();
}
