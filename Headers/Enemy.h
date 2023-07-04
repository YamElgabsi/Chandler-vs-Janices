#ifndef ENEMY_H
#define ENEMY_H

#include "GameMacros.h"
#include "MyQObjectModel.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy:public MyQObjectModel{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
    static double speed;

public slots:
    void move();
private:
};

#endif // ENEMY_H
