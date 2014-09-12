/********************************************************************
    Copyright (c) 2013-2014 - QSanguosha-Hegemony Team

    This file is part of QSanguosha-Hegemony.

    This game is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3.0 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    See the LICENSE file for more details.

    QSanguosha-Hegemony Team
    *********************************************************************/

#ifndef LOBBYSCENE_H
#define LOBBYSCENE_H

#include "clientstruct.h"

#include <QGraphicsScene>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QPushButton>

class QMainWindow;
class Tile;
class Title;

class LobbyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit LobbyScene(QMainWindow *parent = 0);
    void adjustItems();
    void adjustRoomTiles();

signals:
    void roomSelected();
    void createRoomClicked();

public slots:
    void setRoomList(const QVariant &data);

private slots:
    void speakToServer();

    void onRoomTileClicked();
    void onCreateRoomClicked();

private:
    QWidget *chatWidget;
    QLineEdit *chatLineEdit;
    QTextEdit *chatBox;

    QGraphicsPixmapItem *userAvatarItem;
    Title *userNameItem;

    QWidget *buttonBox;
    QPushButton *refreshButton;
    QPushButton *exitButton;

    Title *roomTitle;

    //QList<HostInfoStruct *> rooms;
    QList<Tile *> roomTiles;
    Tile *createRoomTile;

    static int SCENE_PADDING;
    static int SCENE_MARGIN_TOP;
};

#endif // LOBBYSCENE_H
