#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "configwizard.h"

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


private slots:
  void showDialog();

};

#endif // MAINWINDOW_H
