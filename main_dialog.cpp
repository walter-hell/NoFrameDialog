/*******************************************************************************
 *  @Desc:
 *  @Api:
 *  @Author: hell
 *  @Filename: main_dialog.cpp
 *  @Modify Log: creater file 2017/12/5 by hell
 *
 *
 *  CopyRight 2017
*******************************************************************************/

#include <QMouseEvent>
#include <QVBoxLayout>
#include <QDebug>
#include <QIcon>

#include "main_dialog.h"
#include "./dialog_plug/title_bar.h"
#include "./dialog_plug/frameless_helper.h"

noframe::MainDialog::
MainDialog(QWidget *parent) :
  QDialog(parent)
{
  init();
}

noframe::MainDialog::
~MainDialog()
{
}

void noframe::MainDialog::init()
{
  setObjectName(QString::fromUtf8("main_dialog"));
  setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
//  setAttribute(Qt::WA_TranslucentBackground, true);
  resize(600,400);

  TitleBar *titleBar = new TitleBar(this);
  installEventFilter(titleBar);

  setWindowIcon(QIcon(":/images/app_icon.png"));
  setWindowTitle(QString::fromUtf8("Custom Window"));

  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addWidget(titleBar);
  layout->addStretch();
  layout->setSpacing(0);
  layout->setContentsMargins(0,0,0,0);
  setLayout(layout);

  loadStyleSheet();

  FramelessHelper *pHelper = new FramelessHelper(this);
  pHelper->activateOn(this);  //激活当前窗体
  pHelper->setTitleHeight(titleBar->height());  //设置窗体的标题栏高度
  pHelper->setWidgetMovable(true);  //设置窗体可移动
  pHelper->setWidgetResizable(true);  //设置窗体可缩放
  pHelper->setRubberBandOnMove(true);  //设置橡皮筋效果-可移动
  pHelper->setRubberBandOnResize(true);  //设置橡皮筋效果-可缩放
}


void noframe::MainDialog::
loadStyleSheet()
{
  QFile file(":/qss/main_dialog.qss");
  if(file.open(QFile::ReadOnly))
  {
    QString style = QLatin1String(file.readAll());
    qDebug() << style;
    this->setStyleSheet(style);

  }
}
