#include "../Headers/Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "../Headers/Enemy.h"
#include <QMediaPlayer>
#include <QDir>
#include <QMediaContent>

Game::Game(QWidget *parent){


    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,WIDTH,HEIGHT); // make the scene 800x600 instead of infinity by infinity (default)
    QString bGfilePath = QDir::currentPath() + "/../Resources/Images/BG.jpg";
    setBackgroundBrush(QBrush(QImage(bGfilePath)));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WIDTH,HEIGHT);

    // create the player
    player = new Player();

    player->setPos(WIDTH/2,HEIGHT-100); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);
    highScore = new HighScore();
    scene->addItem(highScore);
    highScore->setPos(highScore->x(),highScore->y()+50);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(3*1000);

    // play background music
    QMediaPlayer* music = new QMediaPlayer();
    QString filePath = QDir::currentPath() + "/../Resources/Sounds/BG.mp3";
    QUrl url = QUrl::fromLocalFile(filePath);
    music->setMedia(url);
    music->setVolume(25); // Set the volume level (0-100)
    music->play();
    show();
}
