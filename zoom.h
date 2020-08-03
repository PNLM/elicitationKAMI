#ifndef ZOOM_H
#define ZOOM_H
#include <QToolButton>
#include <QMainWindow>

class zoom :public QToolButton
{

    Q_OBJECT

public:
    zoom(QWidget *parent = nullptr);


    void focusInEvent(QFocusEvent* e) override;
    void focusOutEvent(QFocusEvent *e) override;


};

#endif // ZOOM_H
