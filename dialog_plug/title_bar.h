/*******************************************************************************
 *  @Desc:
 *  @Api:
 *  @Author: hell
 *  @Filename: title_bar.h
 *  @Modify Log: creater file 2017/12/6 by hell
 *
 *
 *  CopyRight 2017
*******************************************************************************/
#ifndef TITLE_BAR_H
#define TITLE_BAR_H

#include <QWidget>

class QLabel;
class QToolButton;
class QAbstractButton;

namespace noframe {

class TitleBar : public QWidget
{
  Q_OBJECT

public:
  explicit TitleBar(QWidget *parent = 0);
  ~TitleBar();

protected:
  void mouseDoubleClickEvent(QMouseEvent *event);
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
  bool eventFilter(QObject *watched, QEvent *event);

private:
  void btnsClicked(QAbstractButton *);

private:
  void init();

private:
  QLabel *_icon;
  QLabel *_title;
  QToolButton *_minBtn;
  QToolButton *_maxBtn;
  QToolButton *_closeBtn;

  bool _pressed;
  QPoint _pressedPoint;
};

}
#endif // TITLE_BAR_H
