#ifndef CONFIGWIZARD_H
#define CONFIGWIZARD_H

#include <QtWidgets>
#include <QWizard>
#include "net/network_handler.h"

class QCheckBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QRadioButton;

class ConfigWizard:public QWizard
{
    Q_OBJECT
public:
    ConfigWizard(QWidget *parent = nullptr, NetworkHandler *networkHandler = nullptr);

    void accept() override;

private:
    NetworkHandler *networkHandler;
};

class IntroPage : public QWizardPage
{
    Q_OBJECT

public:
    IntroPage(QWidget *parent = nullptr);

private:
    QLabel *label;
};

class ServerConnectPage : public QWizardPage
{
    Q_OBJECT

public:
    ServerConnectPage(QWidget *parent = nullptr, NetworkHandler *networkHandler = nullptr);

protected:
    void initializePage() override;
    bool isComplete() const override;

private slots:
    void connectNetwork();

private:

    QLabel *lblIp;
    QString defaultIp;
    QLineEdit *lineEditIp;

    // TODO
    QString defaultPort;
    QLineEdit *lineEditPort;

    QString defaultSsid;
    QString defaultPassword;

    QLabel *lblSsid;
    QLabel *lblPassword;
    QLineEdit *lineEditSsid;
    QLineEdit *lineEditPassword;

    QCheckBox *cbUdp;
    QCheckBox *cbCoap;
    QCheckBox *cbMqtt;

    QGroupBox *groupBox;

    QPushButton * btnConnect;
    QTextEdit *textEditStatus;

    NetworkHandler *networkHandler;

};

class ResourceSelectPage : public QWizardPage
{
    Q_OBJECT

public:
    ResourceSelectPage(QWidget *parent = nullptr);

protected:
    void initializePage() override;


private:
    QListWidget *lvCoapResources;
    QListWidget *lvUdpResources;
};




#endif // CONFIGWIZARD_H
