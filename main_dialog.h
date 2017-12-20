/*******************************************************************************
 *  @Desc:
 *  @Api:
 *  @Author: hell
 *  @Filename: main_dialog.h
 *  @Modify Log: creater file 2017/12/5 by hell
 *
 *
 *  CopyRight 2017
*******************************************************************************/
#ifndef MAIN_DIALOG_H
#define MAIN_DIALOG_H

#include <QDialog>

namespace noframe {


class MainDialog : public QDialog
{
  Q_OBJECT

public:
  explicit MainDialog(QWidget *parent = 0);
  ~MainDialog();
  
private:
  void init();
  void loadStyleSheet();

};

}
#endif // MAIN_DIALOG_H
