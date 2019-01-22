#include "configwizard.h"


ConfigWizard::ConfigWizard(QWidget *parent)
    : QWizard(parent)
{

    addPage(new IntroPage);
    addPage(new WifiConnectPage);
    addPage(new ResourceSelectPage);

    QAbstractButton *backButton = this->button(QWizard::FinishButton);
    connect(backButton, SIGNAL(clicked()), this, SLOT(close()));
    //addPage(new ChipSelectPage);

   // setPixmap(QWizard::BannerPixmap, QPixmap(":/images/banner.png"));
   // setPixmap(QWizard::BackgroundPixmap, QPixmap(":/images/background.png"));

    setWindowTitle(tr("Configuration"));
}

void ConfigWizard::accept()
{
    /*
    QByteArray className = field("className").toByteArray();
    QByteArray baseClass = field("baseClass").toByteArray();
    QByteArray macroName = field("macroName").toByteArray();
    QByteArray baseInclude = field("baseInclude").toByteArray();

    QString outputDir = field("outputDir").toString();
    QString header = field("header").toString();
    QString implementation = field("implementation").toString();
    QDialog::accept();
    */
}

IntroPage::IntroPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(tr("Introduction"));
   // setPixmap(QWizard::WatermarkPixmap, QPixmap(":/images/watermark1.png"));

    label = new QLabel(tr("This wizard is a UDP/CoAP Client for ESP8266 or ESP32 based UDP/CoAP Servers."));
    label->setWordWrap(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    setLayout(layout);
}

WifiConnectPage::WifiConnectPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(tr("Connect to ESP WiFi Device"));
  //  setSubTitle(tr("SSID, Password and a stable connection are required to continue. Check network status output for details."));
  //  setPixmap(QWizard::LogoPixmap, QPixmap(":/images/logo1.png"));

    lblIp = new QLabel(tr("IP"));
    lineEditIp = new QLineEdit(defaultIp);
    lblIp->setBuddy(lineEditIp);


    lblSsid = new QLabel(tr("SSID:"));
    lineEditSsid = new QLineEdit(defaultSsid);
    lblSsid->setBuddy(lineEditSsid);
    lblSsid->setEnabled(false);
    lineEditSsid->setEnabled(false);

    lblPassword = new QLabel(tr("Password:"));
    lineEditPassword = new QLineEdit(defaultPassword);
    lblPassword->setBuddy(lineEditPassword);
    lineEditPassword->setEchoMode(QLineEdit::Password);
    lblPassword->setEnabled(false);
    lineEditPassword->setEnabled(false);


    btnConnect = new QPushButton("Connect");
    textEditStatus = new QTextEdit();

    // TODO take this out
    QWidget* container = new QWidget;
    QHBoxLayout* hBoxLayout = new QHBoxLayout(container);
    cbCoap = new QCheckBox("CoAP");
    cbCoap->setChecked(true);
    cbUdp = new QCheckBox("UDP");
    cbUdp->setChecked(true);
    cbMqtt = new QCheckBox("MQTT");
    cbMqtt->setChecked(true);

    hBoxLayout->addWidget(cbCoap);
    hBoxLayout->addWidget(cbUdp);
    hBoxLayout->addWidget(cbMqtt);

    textEditStatus->setReadOnly(true);
    textEditStatus->setText("Not connected");
    groupBox = new QGroupBox(tr("Connection Status"));

    registerField("ssid*", lineEditSsid);
    registerField("password*", lineEditPassword);
    //registerField("connect*", btnConnect);
    registerField("coap", cbCoap);
    registerField("udp", cbUdp);
    registerField("mqtt", cbMqtt);
    registerField("status", textEditStatus);

    QVBoxLayout *groupBoxLayout = new QVBoxLayout;
    groupBoxLayout->addWidget(textEditStatus);

    groupBox->setLayout(groupBoxLayout);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lblIp, 0, 0);
    layout->addWidget(lineEditIp, 0, 1);
    layout->addWidget(lblSsid, 1, 0);
    layout->addWidget(lineEditSsid, 1, 1);
    layout->addWidget(lblPassword, 2, 0);
    layout->addWidget(lineEditPassword, 2, 1);
    layout->addWidget(container, 3, 1);
    layout->addWidget(btnConnect, 5, 0, 1, 2);
    layout->addWidget(groupBox, 6, 0, 1, 2);
    setLayout(layout);
}

void WifiConnectPage::initializePage()
{
    defaultIp       = "192.168.4.1";
    defaultSsid     = "";
    defaultPassword = "";

    QFile file("app.cfg");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    unsigned int c=0;
    while (!in.atEnd()) {
       QString line = in.readLine();
       switch (c)
       {
        case 0:
           defaultSsid = line;
           break;
        case 1:
           defaultPassword = line;
           break;
        case 2:
           defaultIp = line;
           break;
       }
       ++c;
    }

    lineEditSsid->setText(defaultSsid);
    lineEditPassword->setText(defaultPassword);
    lineEditIp->setText(defaultIp);

}
/*
bool WifiConnectPage::isComplete() const
{
    // loop through field("status") go find connection string
       return true;
}
*/
ResourceSelectPage::ResourceSelectPage(QWidget *parent)
    : QWizardPage(parent)
{
    setTitle(tr("UDP/CoAP DISCOVER"));
    setSubTitle(tr("Register to UDP & CoAP Resources"));

    QLabel *lblUdp = new QLabel("UDP");
    lvUdpResources = new QListWidget();
    lvUdpResources->addItem("atari_tia");
    registerField("udpResources*", lvUdpResources);

    QLabel *lblCoap = new QLabel("CoAP");
    lvCoapResources = new QListWidget();
    lvCoapResources->addItem("/atari_tia");
    lvCoapResources->addItem("/atari_pokey");
    lvCoapResources->addItem("/commodore_sid");
    registerField("coapResources*", lvCoapResources);

    QGridLayout *layout = new QGridLayout;
    layout->setColumnMinimumWidth(0, 20);
    layout->addWidget(lblUdp, 0, 0);
    layout->addWidget(lvUdpResources, 1, 0);
    layout->addWidget(lblCoap, 2, 0);
    layout->addWidget(lvCoapResources, 3, 0);
    setLayout(layout);

}

void ResourceSelectPage::initializePage()
{
    bool isSave = field("save").toBool();
    if (isSave)
    {
        QString networkSsid = field("ssid").toString();
        QString networkPassword = field("password").toString();
        QFile file("config.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QTextStream out(&file);
        out << networkSsid << "\n" << networkPassword;
    }
}

