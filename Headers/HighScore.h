//
// Created by Yam Elgabsi on 03/07/2023.
//

#ifndef MYSNAJE_HIGHSCORE_H
#define MYSNAJE_HIGHSCORE_H


#include <QGraphicsTextItem>

class HighScore: public QGraphicsTextItem{
public:
    HighScore(QGraphicsItem * parent=0);
    void increase();
    int getScore();
private:
    int score;
};


#endif //MYSNAJE_HIGHSCORE_H
