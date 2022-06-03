#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QTimer>
#include <QMouseEvent>
#include "point.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseReleaseEvent (QMouseEvent *event){
    int size = arPoints.size();
    for(int i = 0; i < size; i++){
        Point *point = arPoints.at(i);
        if((*point).getIsDragged()){
            (*point).setIsDragged(false);
        }
    }
    repaint();
}
void MainWindow::mouseMoveEvent (QMouseEvent *event){
    int size = arPoints.size();
    bool existsDragged = false;
    for(int i = 0; i < size; i++){
        Point *point = arPoints.at(i);
        if((*point).getIsDragged()){
            (*point).setX((*point).getX()+((*event).x()-dx));
            (*point).setY((*point).getY()+((*event).y()-dy));
            existsDragged = true;
        }
    }
    if(existsDragged){
        dx = (*event).x();
        dy = (*event).y();
    }
    repaint();
}
void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    if(arPoints.size())
         for(int i = 0; i <(int)arPoints.size();i++){
             Point *point = arPoints.at(i);
             (*point).draw(&painter);
             if(i){
                 (*point).connectPoints(&painter,arPoints.at(i - 1));
             }
         }
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    int size = arPoints.size();
    QPoint clickPoint;
    clickPoint.setX((*event).x());
    clickPoint.setY((*event).y());
    bool doNotCreate = false;
    for(int i = 0; i < size; i++){
        Point *point = arPoints.at(i);
       if((*point).distance2(clickPoint) <= 5){
          (*point).setIsDragged(true);
          dx = (*event).x();
          dy = (*event).y();
          doNotCreate = true;
          break;
        }
     }
        if(!doNotCreate){
            Point *point = new Point((*event).x(),(*event).y());
            arPoints.push_back(point);
        }
        repaint();
    }  

