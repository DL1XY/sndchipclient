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
    setSubTitle(tr("SSID, Password and a stable connection are required to continue. Check network status output for details."));
  //  setPixmap(QWizard::LogoPixmap, QPixmap(":/images/logo1.png"));


    lblSsid = new QLabel(tr("&SSID:"));
    lineEditSsid = new QLineEdit(defaultSsid);
    lblSsid->setBuddy(lineEditSsid);


    lblPassword = new QLabel(tr("&Password:"));
    lineEditPassword = new QLineEdit(defaultPassword);
    lblPassword->setBuddy(lineEditPassword);
    lineEditPassword->setEchoMode(QLineEdit::Password);

    btnConnect = new QPushButton("&Connect");
    textEditStatus = new QTextEdit();
    cbSave = new QCheckBox("Save WiFi configuration");
    cbSave->setChecked(true);
    textEditStatus->setReadOnly(true);
    textEditStatus->setText("Not connected");
    groupBox = new QGroupBox(tr("Connection Status"));

    registerField("ssid*", lineEditSsid);
    registerField("password*", lineEditPassword);
    //registerField("connect*", btnConnect);
    registerField("save", cbSave);
    registerField("status", textEditStatus);

    QVBoxLayout *groupBoxLayout = new QVBoxLayout;
    groupBoxLayout->addWidget(textEditStatus);

    groupBox->setLayout(groupBoxLayout);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lblSsid, 0, 0);
    layout->addWidget(lineEditSsid, 0, 1);
    layout->addWidget(lblPassword, 1, 0);
    layout->addWidget(lineEditPassword, 1, 1);
    layout->addWidget(cbSave, 2, 1);
    layout->addWidget(btnConnect, 4, 0, 1, 2);
    layout->addWidget(groupBox, 5, 0, 1, 2);
    setLayout(layout);
}

void WifiConnectPage::initializePage()
{

    defaultSsid = "";
    defaultPassword = "";

    QFile file("config.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    unsigned int c=0;
    while (!in.atEnd()) {
       QString line = in.readLine();
       if (c == 0)
           defaultSsid = line;
       else if (c == 1)
           defaultPassword = line;
       ++c;
    }

    lineEditSsid->setText(defaultSsid);
    lineEditPassword->setText(defaultPassword);

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

