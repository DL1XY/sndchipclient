/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Quit;
    QWidget *centralWidget;
    QFormLayout *formLayout;
    QGridLayout *chipStatus;
    QGroupBox *audioChipStatus;
    QGridLayout *gridLayout_3;
    QTableView *tableAudioChipStatus;
    QGroupBox *espChipStatus;
    QGridLayout *gridLayout_4;
    QTableView *tableEsChipStatus;
    QTabWidget *tabWidget;
    QWidget *udpRawTab;
    QTextEdit *textEditUdpRaw;
    QWidget *coapRawPage;
    QTextEdit *textEditCoapRaw;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuConfig;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1024, 768);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        action_Quit = new QAction(MainWindow);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(centralWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetMaximumSize);
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        chipStatus = new QGridLayout();
        chipStatus->setSpacing(6);
        chipStatus->setObjectName(QString::fromUtf8("chipStatus"));
        chipStatus->setSizeConstraint(QLayout::SetNoConstraint);
        audioChipStatus = new QGroupBox(centralWidget);
        audioChipStatus->setObjectName(QString::fromUtf8("audioChipStatus"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(audioChipStatus->sizePolicy().hasHeightForWidth());
        audioChipStatus->setSizePolicy(sizePolicy1);
        audioChipStatus->setMaximumSize(QSize(300, 16777215));
        audioChipStatus->setLayoutDirection(Qt::LeftToRight);
        gridLayout_3 = new QGridLayout(audioChipStatus);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tableAudioChipStatus = new QTableView(audioChipStatus);
        tableAudioChipStatus->setObjectName(QString::fromUtf8("tableAudioChipStatus"));

        gridLayout_3->addWidget(tableAudioChipStatus, 1, 0, 1, 1);


        chipStatus->addWidget(audioChipStatus, 0, 0, 1, 1);

        espChipStatus = new QGroupBox(centralWidget);
        espChipStatus->setObjectName(QString::fromUtf8("espChipStatus"));
        sizePolicy1.setHeightForWidth(espChipStatus->sizePolicy().hasHeightForWidth());
        espChipStatus->setSizePolicy(sizePolicy1);
        espChipStatus->setMaximumSize(QSize(300, 16777215));
        gridLayout_4 = new QGridLayout(espChipStatus);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tableEsChipStatus = new QTableView(espChipStatus);
        tableEsChipStatus->setObjectName(QString::fromUtf8("tableEsChipStatus"));

        gridLayout_4->addWidget(tableEsChipStatus, 0, 1, 1, 1);


        chipStatus->addWidget(espChipStatus, 1, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::LabelRole, chipStatus);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        udpRawTab = new QWidget();
        udpRawTab->setObjectName(QString::fromUtf8("udpRawTab"));
        udpRawTab->setEnabled(true);
        textEditUdpRaw = new QTextEdit(udpRawTab);
        textEditUdpRaw->setObjectName(QString::fromUtf8("textEditUdpRaw"));
        textEditUdpRaw->setGeometry(QRect(3, 9, 711, 451));
        tabWidget->addTab(udpRawTab, QString());
        tabWidget->setTabText(tabWidget->indexOf(udpRawTab), QString::fromUtf8("UDP Raw"));
        coapRawPage = new QWidget();
        coapRawPage->setObjectName(QString::fromUtf8("coapRawPage"));
        textEditCoapRaw = new QTextEdit(coapRawPage);
        textEditCoapRaw->setObjectName(QString::fromUtf8("textEditCoapRaw"));
        textEditCoapRaw->setGeometry(QRect(3, 9, 401, 441));
        tabWidget->addTab(coapRawPage, QString());
        tabWidget->setTabText(tabWidget->indexOf(coapRawPage), QString::fromUtf8("CoAP Raw"));

        formLayout->setWidget(0, QFormLayout::FieldRole, tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFile->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuConfig = new QMenu(menuBar);
        menuConfig->setObjectName(QString::fromUtf8("menuConfig"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuConfig->menuAction());
        menuFile->addAction(action_Quit);

        retranslateUi(MainWindow);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "EspUdbClient", nullptr));
        action_Quit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
        audioChipStatus->setTitle(QApplication::translate("MainWindow", "Chip Status", nullptr));
        espChipStatus->setTitle(QApplication::translate("MainWindow", "ESP8266 Status", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Config", nullptr));
        menuConfig->setTitle(QApplication::translate("MainWindow", "&Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
