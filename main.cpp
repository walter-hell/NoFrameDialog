/*******************************************************************************
 *  @Desc:
 *  @Api:
 *  @Author: hell
 *  @Filename: main.cpp
 *  @Modify Log: creater file 2017/12/5 by hell
 *
 *
 *  CopyRight 2017
*******************************************************************************/
#include "main_dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  noframe::MainDialog w;
  w.show();

  return a.exec();
}
