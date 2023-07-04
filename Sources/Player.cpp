#include "../Headers/Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "../Headers/Bullet.h"
#include "../Headers/Enemy.h"
#include <QDir>

Player::Player(QGraphicsItem *parent): MyQObjectModel(parent){
    this->bullet_sound = new QMediaPlayer();
    QString filePath = QDir::currentPath()+"/../Resources/Sounds/SHOT.wav"; // Relative file path
    QUrl url = QUrl::fromLocalFile(filePath);
    bullet_sound->setMedia(url);
    bullet_sound->setVolume(100); // Set the volume level (0-100)

    // drew the player
    QString filePath2 = QDir::currentPath() + "/../Resources/Images/Player.png";
    setPixmap(QPixmap(filePath2));

}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-20,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < WIDTH)
        setPos(x()+20,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        //play bullet sound
        if(bullet_sound->state() == QMediaPlayer::PlayingState) bullet_sound->setPosition(0);
        else if(bullet_sound->state() == QMediaPlayer::StoppedState) bullet_sound->setPosition(0);

        bullet_sound->play();

        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
