#ifndef GAME_H
#define GAME_H

#include "GameMacros.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "../Headers/Player.h"
#include "../Headers/Score.h"
#include "../Headers/Health.h"
#include "HighScore.h"

class Game: public QGraphicsView{

public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    HighScore * highScore;
    Health * health;


};

#endif // GAME_H
