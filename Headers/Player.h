#ifndef PLAYER_H
#define PLAYER_H

#include "GameMacros.h"
#include "MyQObjectModel.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Player:public MyQObjectModel{
Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
private:
    QMediaPlayer* bullet_sound;
};

#endif // PLAYER_H
