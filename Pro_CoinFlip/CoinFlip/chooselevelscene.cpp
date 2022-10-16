#include "chooselevelscene.h"
#include<QMenuBar>
#include<QPainter>
#include"mypushbutton.h"
#include<QDebug>
#include<QTimer>
#include<QLabel>
#include<QSoundEffect>

ChooseLevelScene::ChooseLevelScene(QWidget *parent)
    : QMainWindow{parent}
{
    //设置固定大小
    setFixedSize(320,588);

    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    setWindowTitle("选择关卡场景");

    //创建菜单栏
    QMenuBar *bar = menuBar();
    setMenuBar(bar);

    //创建开始菜单
    QMenu *startMenu = bar->addMenu("开始");

    //退出按钮实现
    QAction *quitAction = startMenu->addAction("退出");

    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    //选择按钮音效
    QSoundEffect *chooseSound = new QSoundEffect(this);
    chooseSound->setSource(QUrl::fromLocalFile(":/res/TapButtonSound.wav"));
    //返回按钮音效
    QSoundEffect *backSound = new QSoundEffect(this);
    backSound->setSource(QUrl::fromLocalFile(":/res/BackButtonSound.wav"));

  //返回按钮
   MyPushButton *backBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
   backBtn->setParent(this);
   backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());

  //点击返回
   connect(backBtn, &MyPushButton::clicked, [=](){
       //播放返回按钮音效
       backSound->play();
       //qDebug() << "点击了返回按钮";
       //告诉主场景 我返回了,主场景监听ChooseLevelScene的返回按钮
       //延时返回
       QTimer::singleShot(100,this,[=](){
            emit this->chooseSceneBack();
       });
   });

   //创建选择关卡的按钮
    for(int i = 0; i < 20; ++i){
        MyPushButton *menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25 + i%4 * 70, 130 + i/4 * 70);

        //监听每个按钮的点击事件
        connect(menuBtn, &MyPushButton::clicked,[=](){
            //播放选择音效
            chooseSound->play();

            QString str = QString("您选择的是第 %1 关").arg(i + 1);
            qDebug() << str;

            //进入到游戏场景
            this->hide();  //隐藏选关场景
            play = new PlayScene(i+1); //创建游戏场景
            //设置游戏场景的初始位置
            play->setGeometry(this->geometry());
            //显示游戏场景
            play->show();

            //监听游戏关卡的返回按钮信号
            connect(play, &PlayScene::chooseSceneBack, [=](){
                this->setGeometry(play->geometry());
                this->show();
                delete play;
                play = NULL;
            });
        });

        QLabel *label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(25 + i%4 * 70, 150 + i/4 * 70);
        //设置label上的文字对齐方式
        label->setAlignment(Qt::AlignHCenter | Qt::AlignHCenter);

        //设置让鼠标进行穿透  51号属性
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }

}


void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width() - pix.width())*0.5,30, pix.width(),pix.height(),pix);
}
