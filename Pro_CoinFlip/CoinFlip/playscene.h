#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <mycoin.h>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int levelNum);

    int levelIndex; //记录所选关卡

    //重写绘图事件
    void paintEvent(QPaintEvent *);

    int gameArray[4][4]; //二维数组 维护每隔关卡的具体数据

    MyCoin *coinBtn[4][4]; //维护数组按钮矩阵

    //是否胜利标志
    bool isWin;
signals:
    void chooseSceneBack();
};

#endif // PLAYSCENE_H
