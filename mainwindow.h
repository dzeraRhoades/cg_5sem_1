#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include<qwt-git/

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_horizontalSlider_sliderMoved(int position);

private:
    void resizeEvent(QResizeEvent *event) override;
    void drawGraphic(int a);

private:
    Ui::MainWindow *ui;




};
#endif // MAINWINDOW_H
