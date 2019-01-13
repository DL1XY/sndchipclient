#ifndef CONFIGWIZARD_H
#define CONFIGWIZARD_H

#include <QtWidgets>
#include <QWizard>

class QCheckBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QRadioButton;

class ConfigWizard:public QWizard
{
    Q_OBJECT
public:
    ConfigWizard(QWidget *parent = nullptr);

    void accept() override;
};

class IntroPage : public QWizardPage
{
    Q_OBJECT

public:
    IntroPage(QWidget *parent = nullptr);

private:
    QLabel *label;
};

class WifiConnectPage : public QWizardPage
{
    Q_OBJECT

public:
    WifiConnectPage(QWidget *parent = nullptr);

protected:
    void initializePage() override;

private:
    QString defaultSsid;
    QString defaultPassword;

    QLabel *lblSsid;
    QLabel *lblPassword;
    QLineEdit *lineEditSsid;
    QLineEdit *lineEditPassword;

    QGroupBox *groupBox;

    QPushButton * btnConnect;
    QTextEdit *textEditStatus;
    QCheckBox *cbSave;


};

class ResourceSelectPage : public QWizardPage
{
    Q_OBJECT

public:
    ResourceSelectPage(QWidget *parent = nullptr);

protected:
    void initializePage() override;
    //bool validatePage() override;

private:
    QListWidget *lvCoapResources;
    QListWidget *lvUdpResources;
};




#endif // CONFIGWIZARD_H
