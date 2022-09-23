#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include<string>
#include<iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawGraphic(5);
    ui->horizontalSlider->setRange(0, 15);
    ui->horizontalSlider->setValue(5);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    int width = event->size().width();
    int height = event->size().height();

    std::cout<<width<<" "<<height<<std::endl;
    ui->widget->setGeometry(0, 0, width, height-100);
    ui->label->setGeometry(width/2, height-50, 16, 21);
    ui->horizontalSlider->setGeometry(width/2-120, height-80, 240, 20);
}

void MainWindow::drawGraphic(int a)
{
    //int a = 5;
    double h = 0.001;
    QVector<double> x(0), y(0); // строить будем до 360 градусов
    QVector<double> _x(0), _y(0);
    for (double i=-a; i<=a; i+=h)
    {
      x.push_back(i);
      double value = cbrt(i);
      y.push_back(pow((pow(a, (double)2/3)-pow(value, 2)), (double)3/2));
    }
    for (double i=-a; i<=a; i+=h)
    {
      double value = cbrt(i);
      _x.push_back(i);
      _y.push_back(-pow((pow(a, (double)2/3)-pow(value, 2)), (double)3/2));
    }
    // создаем график и добавляем данные:
    //ui->widget->showMaximized();
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    ui->widget->addGraph();
    ui->widget->graph(1)->setData(_x, _y);
    // задаем имена осей координат
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    // задаем размеры осей
    ui->widget->xAxis->setRange(-a-5, a+5);
    ui->widget->yAxis->setRange(-a-5, a+5);
    ui->widget->replot();
}



void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    drawGraphic(position);
    ui->label->setText(QString(std::to_string(position).c_str()));
}
