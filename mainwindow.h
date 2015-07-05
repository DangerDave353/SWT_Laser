#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#include "control.h"
#include <QMainWindow>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Ui::MainWindow *getUi() const;

private:
    Ui::MainWindow *ui;
    int AltX, AltY;
    int NeuX, NeuY;


public slots:
    void Start();
    void Auswahl();
    void GuiLaserAN();
    void GuiLaserAUS();
    void GuiMove(bool LaserZustand, int x, int y);
    void GuiSetProgressBar(int max);
    void GuiAddProgressBar();


};

#endif // MAINWINDOW_H
