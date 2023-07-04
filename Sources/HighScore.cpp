//
// Created by Yam Elgabsi on 03/07/2023.
//
#include <QFile>
#include <QTextStream>
#include "QFont"
#include "QDebug"


#include "../Headers/HighScore.h"

HighScore::HighScore(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score

    // Create a QFile object and specify the file path
    QFile file("../Resources/HighScore");

    // Check if the file can be opened for reading
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open the file.";
        exit(1);
    }

    // Create a QTextStream object to read from the file
    QTextStream in(&file);

    // Read the entire file content
    QString fileContent = in.readAll();

    bool ok;
    int number = fileContent.toInt(&ok);

    score = number;

    // draw the text
    setPlainText(QString("High Score: ") + QString::number(score));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}

void HighScore::increase(){
    score++;
    setPlainText(QString("High Score: ") + QString::number(score));

    // Open the file in write mode
    QFile file("../Resources/HighScore");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        exit(1);
    }

    // Create a QTextStream to write to the file
    QTextStream out(&file);

    // Convert the integer to a QString and write it to the file
    out << QString::number(score);

    // Close the file
    file.close();
}

int HighScore::getScore(){
    return score;
}