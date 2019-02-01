#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui/tab_atari_tia.h"
#include "ui/tab_saa1099.h"
#include "ui/tab_sn76489.h"

#include <QTimer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    networkHandler = new NetworkHandler(this);
    controller = new AtariTiaController(this, networkHandler);

    TabAtariTia *tabAtariTia = new TabAtariTia(this);
    tabAtariTia->getWidgetAUD0()->setController(controller);
    tabAtariTia->getWidgetAUD1()->setController(controller);

    ui->setupUi(this);
    ui->tabWidget->addTab(tabAtariTia, "Atari TIA" );
    ui->tabWidget->addTab(new TabSaa1099(this), "SAA1099" );
    ui->tabWidget->addTab(new TabSN76489(this), "SN76489" );
    this->setWindowFlags(Qt::Window
    | Qt::WindowMinimizeButtonHint
    | Qt::WindowMaximizeButtonHint
    | Qt::WindowCloseButtonHint);

    this->showMaximized();
    //this->showFullScreen();

    //QTimer::singleShot(1000, this, SLOT(showFullScreen()));
    QTimer::singleShot(1001, this, SLOT(showDialog()));

}

MainWindow::~MainWindow()
{
    delete networkHandler;
    delete ui;
}

void MainWindow::showDialog()
{
    wizard = new ConfigWizard(this);

    connect( wizard, SIGNAL( accepted() ), this, SLOT( show() ) );
    connect( wizard, SIGNAL( rejected() ), this, SLOT( show() ) );
    wizard->show();
}
