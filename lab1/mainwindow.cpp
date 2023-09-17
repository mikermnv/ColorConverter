#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "module.h"
#include <QGridLayout>
#include <QPalette>
#include <QColorDialog>
#include <QObject>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QObject::connect(pbColor, SIGNAL(clicked()), this, SLOT(on_pbColor_clicked()));
    QObject::connect(m1, SIGNAL(changed()), this, SLOT(changeColor1()));
    QObject::connect(m2, SIGNAL(changed()), this, SLOT(changeColor2()));
    QObject::connect(m3, SIGNAL(changed()), this, SLOT(changeColor3()));
    QObject::connect(m4, SIGNAL(changed()), this, SLOT(changeColor4()));
    QObject::connect(m5, SIGNAL(changed()), this, SLOT(changeColor5()));
    QObject::connect(m6, SIGNAL(changed()), this, SLOT(changeColor6()));
    QObject::connect(m1, SIGNAL(sliderMoved()), this, SLOT(changeColor1()));
    QObject::connect(m2, SIGNAL(sliderMoved()), this, SLOT(changeColor2()));
    QObject::connect(m3, SIGNAL(sliderMoved()), this, SLOT(changeColor3()));
    QObject::connect(m4, SIGNAL(sliderMoved()), this, SLOT(changeColor4()));
    QObject::connect(m5, SIGNAL(sliderMoved()), this, SLOT(changeColor5()));
    QObject::connect(m6, SIGNAL(sliderMoved()), this, SLOT(changeColor6()));
    QPalette p = QPalette();
    p.setBrush(QPalette::Window, Qt::black);
    wColor->setAutoFillBackground(true);
    wColor->setPalette(p);
    ui->setupUi(this);
    QGridLayout* l = new QGridLayout;
    QLabel* lYourColor = new QLabel;
    lYourColor->setAlignment(Qt::AlignCenter);
    lYourColor->setText("Your color:");
    pbColor->setText("Choose color");
    lYourColor->setGeometry(0,0,2,2);
    m1->setType(type::RGB);
    m2->setType(type::CMYK);
    m3->setType(type::HLS);
    m4->setType(type::HSV);
    m5->setType(type::LAB);
    m6->setType(type::XYZ);
    l->addWidget(lYourColor, 0, 1, 1, 2);
    l->addWidget(wColor, 1, 1, 2, 2);
    l->addWidget(pbColor, 1, 4, 2, 1);
    l->addWidget(m1, 3, 0, 4, 2);
    l->addWidget(m2, 3, 2, 4, 2);
    l->addWidget(m3, 3, 4, 4, 2);
    l->addWidget(m4, 3, 6, 4, 2);
    l->addWidget(m5, 3, 8, 4, 2);
    l->addWidget(m6, 3, 10, 4, 2);
    ui->centralwidget->setLayout(l);
}

void MainWindow::on_pbColor_clicked(){
    color = QColorDialog::getColor();
    setColors();
    setwColor();
}

void MainWindow::changeColor1(){
    m2->IsRecalc=false;
    m3->IsRecalc=false;
    m4->IsRecalc=false;
    m5->IsRecalc=false;
    m6->IsRecalc=false;
    m2->IsSliderRecalc=false;
    m3->IsSliderRecalc=false;
    m4->IsSliderRecalc=false;
    m5->IsSliderRecalc=false;
    m6->IsSliderRecalc=false;
    color = m1->getColor();
    m2->setColor(color);
    m3->setColor(color);
    m4->setColor(color);
    m5->setColor(color);
    m6->setColor(color);
    setwColor();
}

void MainWindow::changeColor2(){
    m1->IsRecalc=false;
    m3->IsRecalc=false;
    m4->IsRecalc=false;
    m5->IsRecalc=false;
    m6->IsRecalc=false;
    m1->IsSliderRecalc=false;
    m3->IsSliderRecalc=false;
    m4->IsSliderRecalc=false;
    m5->IsSliderRecalc=false;
    m6->IsSliderRecalc=false;
    color = m2->getColor();
    m1->setColor(color);
    m3->setColor(color);
    m4->setColor(color);
    m5->setColor(color);
    m6->setColor(color);
    setwColor();
}

void MainWindow::changeColor3(){
    m1->IsRecalc=false;
    m2->IsRecalc=false;
    m4->IsRecalc=false;
    m5->IsRecalc=false;
    m6->IsRecalc=false;
    m1->IsSliderRecalc=false;
    m2->IsSliderRecalc=false;
    m4->IsSliderRecalc=false;
    m5->IsSliderRecalc=false;
    m6->IsSliderRecalc=false;
    color = m3->getColor();
    m1->setColor(color);
    m2->setColor(color);
    m4->setColor(color);
    m5->setColor(color);
    m6->setColor(color);
    setwColor();
}

void MainWindow::changeColor4(){
    m1->IsRecalc=false;
    m2->IsRecalc=false;
    m3->IsRecalc=false;
    m5->IsRecalc=false;
    m6->IsRecalc=false;
    m1->IsSliderRecalc=false;
    m2->IsSliderRecalc=false;
    m3->IsSliderRecalc=false;
    m5->IsSliderRecalc=false;
    m6->IsSliderRecalc=false;
    color = m4->getColor();
    m1->setColor(color);
    m2->setColor(color);
    m3->setColor(color);
    m5->setColor(color);
    m6->setColor(color);
    setwColor();
}

void MainWindow::changeColor5(){
    m1->IsRecalc=false;
    m2->IsRecalc=false;
    m3->IsRecalc=false;
    m4->IsRecalc=false;
    m6->IsRecalc=false;
    m1->IsSliderRecalc=false;
    m2->IsSliderRecalc=false;
    m3->IsSliderRecalc=false;
    m4->IsSliderRecalc=false;
    m6->IsSliderRecalc=false;
    color = m5->getColor();
    m1->setColor(color);
    m2->setColor(color);
    m3->setColor(color);
    m4->setColor(color);
    m6->setColor(color);
    setwColor();
}

void MainWindow::changeColor6(){
    m1->IsRecalc=false;
    m2->IsRecalc=false;
    m3->IsRecalc=false;
    m4->IsRecalc=false;
    m5->IsRecalc=false;
    m1->IsSliderRecalc=false;
    m2->IsSliderRecalc=false;
    m3->IsSliderRecalc=false;
    m4->IsSliderRecalc=false;
    m5->IsSliderRecalc=false;
    color = m6->getColor();
    m1->setColor(color);
    m2->setColor(color);
    m3->setColor(color);
    m4->setColor(color);
    m5->setColor(color);
    setwColor();
}

void MainWindow::setColors(){
    m1->setColor(color);
    m2->setColor(color);
    m3->setColor(color);
    m4->setColor(color);
    m5->setColor(color);
    m6->setColor(color);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setwColor(){
    QPalette p = QPalette();
    p.setBrush(QPalette::Window, color);
    wColor->setAutoFillBackground(true);
    wColor->setPalette(p);
}
