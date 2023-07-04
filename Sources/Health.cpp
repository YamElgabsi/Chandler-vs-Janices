#include "../Headers/Health.h"
#include <QFont>
#include <QGraphicsScene>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
    if(health == 0) exit(0);

}

int Health::getHealth(){
    return health;
}

