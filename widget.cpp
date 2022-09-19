#include "widget.h"
#include <QSplitter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFrame>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(400, 300);
    mStartButton = new QPushButton("Старт");
    mStopButton = new QPushButton("Стоп");
    mCorrectAnswersLabel = new QLabel("0");
    mWrongAnswersLabel = new QLabel("0");
    mClickWidget = new ClickWidget;
    mCloseDialog = new CloseDialog(this);

    connect(mStartButton, &QPushButton::clicked, this, &Widget::startButtonSlot);
    connect(mStopButton, &QPushButton::clicked, this, &Widget::stopButtonSlot);
    connect(mClickWidget, &ClickWidget::numberChanged, this, &Widget::numberChangedSlot);

    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(mStartButton);
    topLayout->addWidget(mStopButton);
    topLayout->addStretch();

    QFormLayout *scoreLayout = new QFormLayout;
    scoreLayout->addRow("Правильных ответов:", mCorrectAnswersLabel);
    scoreLayout->addRow("Неправильных ответов:", mWrongAnswersLabel);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addLayout(scoreLayout);
    bottomLayout->addStretch();

    QFrame *line1 = new QFrame;
    line1->setFrameShape(QFrame::HLine);
    QFrame *line2 = new QFrame;
    line2->setFrameShape(QFrame::HLine);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(line1);
    mainLayout->addWidget(mClickWidget);
    mainLayout->addWidget(line2);
    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);
}

Widget::~Widget()
{

}

void Widget::closeEvent(QCloseEvent *event)
{
   if(!mCloseDialog->exec())
       event->ignore();
}

void Widget::startButtonSlot()
{
    mCorrectAnswersCounter = mWrongAnswersCounter = 0;
    mCorrectAnswersLabel->setNum(0);
    mWrongAnswersLabel->setNum(0);
    mClickWidget->start();
}

void Widget::stopButtonSlot()
{
    mClickWidget->stop();
}

void Widget::numberChangedSlot(bool isCorrect)
{
  if(isCorrect)
    mCorrectAnswersLabel->setNum(++mCorrectAnswersCounter);
  else
    mWrongAnswersLabel->setNum(++mWrongAnswersCounter);
}
