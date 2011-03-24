#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QSettings>

namespace Ui {
    class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    void writeSettings();
    void readSettings();
    int getNbMots();
    bool getParTaille();
    bool getParPolice();
    int getPrCentATester();
    int nbMaxRequete();
    void closeEvent(QCloseEvent *event);

public slots:
    void click_close();

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
