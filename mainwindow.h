#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "configwizard.h"
#include "net/network_handler.h"
#include "controller/ataritiacontroller.h"
namespace Ui {
class MainWindow;
class NetworkDialog;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ConfigWizard *wizard;

    NetworkHandler *networkHandler;
    AtariTiaController *controller;

private slots:
  void showDialog();

};

#endif // MAINWINDOW_H
