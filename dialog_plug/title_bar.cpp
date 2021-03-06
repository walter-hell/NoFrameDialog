/*******************************************************************************
 *  @Desc:
 *  @Api:
 *  @Author: hell
 *  @Filename: title_bar.cpp
 *  @Modify Log: creater file 2017/12/6 by hell
 *
 *
 *  CopyRight 2017
*******************************************************************************/

#include <QLabel>
#include <QToolButton>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QMouseEvent>
#include <QEvent>
#include <QApplication>
#include <QDebug>
#include "title_bar.h"

noframe::TitleBar::
TitleBar(QWidget *parent) :
  QWidget(parent),
  _pressed(false)
{
  init();
}

noframe::TitleBar::
~TitleBar()
{

}

void noframe::TitleBar::
mouseDoubleClickEvent(QMouseEvent* event)
{
  Q_UNUSED(event);
  if(event->button() == Qt::LeftButton)
    emit _maxBtn->click();
}

void noframe::TitleBar::
mousePressEvent(QMouseEvent* event)
{
  event->ignore();
  QWidget* wind = this->window();
  if(wind->isTopLevel())
  {
    qDebug() << event->pos();
    if(event->button() == Qt::LeftButton)
    {
      //获取this控件所在的窗口
      QWidget *w = this->window();
      //将this控件下的坐标转换到窗口坐标
      QPoint p = this->mapTo(w, event->pos());
      if(p.x() <= 5 || p.y() <= 5 ||
         w->width() - p.x() <= 5 ||
         w->height() - p.y() <= 5)
      {
        return;
      }
      else
      {
        _pressed = true;
        _pressedPoint = event->pos();
        event->accept();
      }
    }
  }
}

void noframe::TitleBar::
mouseMoveEvent(QMouseEvent* event)
{
  if(_pressed)
  {
    QWidget* wind = this->window();
    wind->move(wind->pos() + event->pos() - _pressedPoint);
  }
  event->ignore();
}

void noframe::TitleBar::
mouseReleaseEvent(QMouseEvent* event)
{
  if(event->button() == Qt::LeftButton)
  {
    _pressed = false;
  }
  event->ignore();
}

bool noframe::TitleBar::
eventFilter(QObject* watched, QEvent* event)
{
  QWidget * widget = qobject_cast<QWidget*>(watched);
  if(widget)
  {
    switch (event->type()) {
    case QEvent::WindowTitleChange:
    {
      _title->setText(widget->windowTitle());
      return true;
    }
    case QEvent::WindowIconChange:
    {
      QIcon icon = widget->windowIcon();
      _icon->setPixmap(icon.pixmap(_icon->size()));
      return true;
    }
    case QEvent::WindowStateChange:
    case QEvent::Resize:
    {
      if(widget->isTopLevel())
      {
        bool max = widget->isMaximized();
        if(max)
        {
          _maxBtn->setToolTip(QString::fromUtf8("restore"));
          //          _maxBtn->setProperty("maxProperty", "restore");
          _maxBtn->setIcon(QIcon(":/images/restore.png"));
        }
        else
        {
          _maxBtn->setToolTip(QString::fromUtf8("maximize"));
          //          _maxBtn->setProperty("maxProperty", "max");
          _maxBtn->setIcon(QIcon(":/images/max.png"));
        }
        _maxBtn->setStyle(QApplication::style());
      }
      return true;
    }
    default:
      break;
    }
  }

  return QWidget::eventFilter(watched, event);
}

void noframe::TitleBar::
btnsClicked(QAbstractButton*btn )
{
  QWidget * window = this->window();
  if(window->isTopLevel())
  {
    if(btn == _minBtn)
    {
      window->showMinimized();
    }
    else if(btn == _maxBtn)
    {
      window->isMaximized() ? window->showNormal(): window->showMaximized();
    }
    else if(btn == _closeBtn)
    {
      window->close();
    }
  }

}


void noframe::TitleBar::init()
{
  _icon = new QLabel(this);
  _icon->setFixedSize(23,23);
  _icon->setScaledContents(true);

  _title = new QLabel(this);
  _title->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  _title->setObjectName(QString::fromUtf8("title_label"));

  _closeBtn = new QToolButton(this);
  _closeBtn->setFixedSize(25,25);
  _closeBtn->setObjectName(QString::fromUtf8("close_btn"));
  _closeBtn->setToolTip(QString::fromUtf8("close"));
  _closeBtn->setIcon(QIcon(":/images/close.png"));
  _closeBtn->setIconSize(QSize(25,25));

  _minBtn = new QToolButton(this);
  _minBtn->setFixedSize(25,25);
  _minBtn->setObjectName(QString::fromUtf8("min_btn"));
  _minBtn->setToolTip(QString::fromUtf8("minimize"));
  _minBtn->setIcon(QIcon(":/images/min.png"));
  _minBtn->setIconSize(QSize(25,25));

  _maxBtn = new QToolButton(this);
  _maxBtn->setFixedSize(25,25);
  _maxBtn->setObjectName(QString::fromUtf8("max_btn"));
  _maxBtn->setToolTip(QString::fromUtf8("maximize"));
  _maxBtn->setIcon(QIcon(":/images/max.png"));
  _maxBtn->setIconSize(QSize(25,25));

  QButtonGroup *btns = new QButtonGroup(this);
  btns->addButton(_minBtn);
  btns->addButton(_maxBtn);
  btns->addButton(_closeBtn);

  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->addWidget(_icon);
  layout->addSpacing(5);
  layout->addWidget(_title);
  layout->addStretch(0);
  layout->addWidget(_minBtn);
  layout->addWidget(_maxBtn);
  layout->addWidget(_closeBtn);
  layout->addSpacing(0);
  layout->setContentsMargins(5, 5, 5, 0);
  layout->setSpacing(0);

  setLayout(layout);

  connect(btns,
          (void (QButtonGroup:: *)(QAbstractButton *))
          &QButtonGroup::buttonClicked,
          this, &TitleBar::btnsClicked);
}
