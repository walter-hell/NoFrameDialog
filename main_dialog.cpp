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

#ifdef Q_OS_WIN
#include <qt_windows.h>
#include <windowsx.h>
#endif

#include "main_dialog.h"
#include "title_bar.h"

noframe::MainDialog::
MainDialog(QWidget *parent) :
  QDialog(parent),
  _borderWidth(5)
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
