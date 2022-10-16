#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>
#include<QSoundEffect>
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //配置主场景

    //设置固定大小
    setFixedSize(320,588);

    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    setWindowTitle("翻金币游戏主界面");

    //退出按钮实现
    connect(ui->actionQuit, &QAction::triggered, [=](){
        this->close();
    });

    //准备开始按钮的音效
    QSoundEffect *startSound = new QSoundEffect(this);
    startSound->setSource(QUrl::fromLocalFile(":/res/TapButtonSound.wav"));
    //开始按键
    MyPushButton *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->img_x = this->width() * 0.5 - startBtn->width() * 0.5;
    startBtn->img_y = this->height() * 0.7;
    startBtn->move(startBtn->img_x, startBtn->img_y);

    chooseScene = new ChooseLevelScene;
    connect(startBtn, &QPushButton::clicked, [=](){
        qDebug() << "点击了开始按钮";
        startSound->play(); //播放开始音效
        //做弹起特效
        startBtn->zoom1();
        startBtn->zoom2();

        //延时并进入到选择关卡的场景中
        QTimer::singleShot(100,this,[=](){
            //设置chooseScene场景的位置
            chooseScene->setGeometry(this->geometry());
            //自身隐藏
            this->hide();
            //显示选择关卡场景
            chooseScene->show();
        });
    });

    //监听选择关卡的返回按钮信号
    connect(chooseScene, &ChooseLevelScene::chooseSceneBack, [=](){
        //设置chooseScene场景的位置
        this->setGeometry(chooseScene->geometry());
        chooseScene->hide();
        this->show(); //重写显示主场景
    });


}

//设置背景图片
void MainScene::paintEvent(QPaintEvent *)
{
    //设置背景图片
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(), this->height(),pix);

    //画背景图标
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()* 0.5, pix.height() * 0.5); //图片缩放
    painter.drawPixmap(10,30,pix);
}

MainScene::~MainScene()
{
    delete ui;
}

