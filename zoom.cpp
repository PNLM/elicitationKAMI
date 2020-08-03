#include "zoom.h"
#include <QFocusEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"


zoom::zoom(QWidget *parent )
{

    this->setParent(parent);
}
void zoom::focusInEvent(QFocusEvent* e)

{
    QToolButton::focusInEvent(e);
}


void zoom::focusOutEvent(QFocusEvent* e)
{
    if (e->type() == QEvent::FocusOut)
    {
        this->hide();
    }
}
