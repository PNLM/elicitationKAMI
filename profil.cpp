#include "profil.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <QSignalMapper>
#include <QProgressBar>
#include <QString>
#include <QGridLayout>
#include <QLabel>
#include <QFile>
#include <QTextStream>
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolButton>
#include "zoom.h"

int clickA =0;
Profil:: Profil(int ligne, int colonne, QString letter,int numero, int crit1, int crit2, int crit3, int crit4) :
     m_numero(numero), m_row(ligne),  m_col(colonne),m_letter(letter), m_crit1(crit1), m_crit2(crit2), m_crit3(crit3), m_crit4(crit4), m_clicked(0),m_state(0)
{

    std::vector<QString> criteriaT{"PHYSIQUE","PSYCHOSOCIAL","NUTRITIONNEL","COGNITIF"};
    setAcceptDrops(true);
    this->setMouseTracking(true);
    this->setStyleSheet("QToolButton{background-color:white;color: white;}");
    if (this->m_numero<7)
    { this->setStyleSheet("QToolButton{background-color:rgb(255, 249, 164);color:rgb(255, 249, 164);}");
    }

   std::vector<int> percentagesT {crit1,crit2,crit3,crit4};

     this->setLayout(new QVBoxLayout);
    for (int i=0; i<4;i++){
    }

    this->setMinimumSize(QSize(200, 120));
    this->setMaximumSize(QSize(200, 120));
    QLabel *label = new QLabel();
    label->setText(QString(letter));
    label->setStyleSheet("QLabel{font-size: 18px; color:rgb(115, 115, 115);}");


this->layout()->addWidget(label);
    label->setMaximumSize(QSize(205, 120));
    label->setAlignment(Qt::AlignRight);
}


void Profil::mouseMoveEvent(QMouseEvent *e)
{

    if (this->m_state==0)
    {
    if(e->buttons() & Qt::LeftButton)
    {


        MainWindow *par = ((MainWindow*)(parent()->parent()->parent()->parent()->parent()));

        QDrag *drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData;

        QPixmap *widgetPixmap = new QPixmap(this->size());
        this->render(widgetPixmap);
        drag->setMimeData(mimeData);

        par->ui->label->setText("Faites glisser ce profil sur le profil à droite de l'emplacement désiré.");


    drag->setPixmap(*widgetPixmap);
    Qt::DropAction dropAction = drag->exec();}
}
}
    ;
void Profil::mousePressEvent(QMouseEvent *e)
{

    if (this->m_state==0)
    {

    if (e->buttons() & Qt::RightButton)


    {QPixmap pixmap = this->icon().pixmap(QSize(400,200));
        MainWindow *par = ((MainWindow*)(parent()->parent()->parent()->parent()->parent()));

        zoom *img = new zoom(par);

        img->setStyleSheet("QToolButton{background-color:white;color: white;}");
        img->setIcon(pixmap);
        QRect geo = this->geometry();
        geo.adjust(-20,5,-20,5);
        img->setGeometry(geo);
        img->setMinimumSize(QSize(320,200));
        img->setIconSize(QSize(400,200));
        img->setFocus();

        if(clickA==0)

   {img->show();
 QObject::connect(img, SIGNAL(clicked()),img , SLOT(hide()));
        clickA=1;
        }
        else if (clickA==1)
        {clickA=0;}

}}}

void Profil::dragMoveEvent(QDragMoveEvent *event)
{

    event->accept();
                event->setDropAction(Qt::MoveAction);

        }

void Profil::dropEvent(QDropEvent *event)
{

MainWindow *par = ((MainWindow*)(parent()->parent()->parent()->parent()->parent()));

Profil *a= qobject_cast<Profil*>(event->source());
par->connexionProfil(this,a);

event->acceptProposedAction();
}

void Profil::dragEnterEvent(QDragEnterEvent *event)
{
event->accept();

}
