#ifndef BULLET_H
#define BULLET_H

#include "GameMacros.h"
#include "Game.h"
#include "MyQObjectModel.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bullet: public MyQObjectModel{
Q_OBJECT
public:
    Bullet(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // BULLET_H
