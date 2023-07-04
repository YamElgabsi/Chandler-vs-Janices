#include "../Headers/Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include <QDir>
#include "../Headers/Game.h"

extern Game * game;

double Enemy::speed = 1.0;

Enemy::Enemy(QGraphicsItem *parent): MyQObjectModel(parent){
    speed += 0.1;
    //set random x position
    int random_number = rand() % (WIDTH - 100);
    setPos(random_number,0);

    // drew the enemy
    QString filePath = QDir::currentPath() + "/../Resources/Images/Enemy.png";
    setPixmap(QPixmap(filePath));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Enemy::move(){
    // move enemy down
    setPos(x(),y()+5*speed);

    // destroy enemy when it goes out of the screen
    if (pos().y() > HEIGHT){
        //decrease the health
        game->health->decrease();

        // play background music
        QMediaPlayer* music = new QMediaPlayer();
        QString filePath = QDir::currentPath() + "/../Resources/Sounds/EnemyPass.wav";
        QUrl url = QUrl::fromLocalFile(filePath);
        music->setMedia(url);
        music->setVolume(100); // Set the volume level (0-100)
        music->play();

        scene()->removeItem(this);
        delete this;
    }
}
