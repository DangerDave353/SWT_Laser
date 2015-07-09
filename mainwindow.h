#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



namespace Ui {
class MainWindow;
}

class Control;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Ui::MainWindow *getUi() const;
    void GuiLaserAN();
    void GuiLaserAUS();
    void GuiMove(bool LaserZustand, int x, int y);
    void GuiSetProgressBar(int max);
    void GuiAddProgressBar();
    void delay(double seconds);
    void setC(Control *value);
    void ResetProgressBar();
    void FehlerAusgabe(std::string Fehler);
    void SetStartButton(bool Enabled);

private:
    Ui::MainWindow *ui;
    int AltX, AltY;
    int NeuX, NeuY;
    Control *C;

public slots:
    void Start();
    void Auswahl();



};

#endif // MAINWINDOW_H
