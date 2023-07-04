//
// Created by Yam Elgabsi on 04/07/2023.
//

#ifndef CHANDLER_VS_JANICES_MYQOBJECTMODEL_H
#define CHANDLER_VS_JANICES_MYQOBJECTMODEL_H


#include <QObject>
#include <QGraphicsPixmapItem>

class MyQObjectModel: public QObject, public QGraphicsPixmapItem {
Q_OBJECT

public:
    MyQObjectModel(QGraphicsItem * parent=0);
};


#endif //CHANDLER_VS_JANICES_MYQOBJECTMODEL_H
