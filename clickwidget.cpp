#include "clickwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMouseEvent>

ClickWidget::ClickWidget(QWidget *parent) : QWidget(parent)
{
    mLabel = new QLabel;
    QFont font("Arial", 48, QFont::Bold);
    mLabel->setFont(font);
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addStretch();
    hLayout->addWidget(mLabel);
    hLayout->addStretch();

    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addStretch();
    vLayout->addLayout(hLayout);
    vLayout->addStretch();

    setLayout(vLayout);

    mTimer = new QTimer(this);
    connect(mTimer, &QTimer::timeout, this, &ClickWidget::timeoutSlot);
    mColors = {Qt::red, QColor("#ffaa00"), Qt::darkGreen, Qt::blue};
}

void ClickWidget::start()
{
    mTimer->start(2000);
    mNumber = generateNextNumber();
    mLabel->setNum(mNumber);
    mCounter = 0;
    setLabelColor(mColors[mColorIndex]);
}

void ClickWidget::stop()
{
    mTimer->stop();
    setLabelColor(Qt::black);
    mLabel->clear();
}

void ClickWidget::mousePressEvent(QMouseEvent *event)
{
    if(mTimer->isActive() && (event->button() == Qt::LeftButton))
        ++mCounter;
}

void ClickWidget::timeoutSlot()
{
    bool isCorrect = mCounter == mNumber;
    mNumber = generateNextNumber();
    mCounter = 0;
    mColorIndex = (mColorIndex < mColors.size() - 1) ? mColorIndex + 1 : 0;
    setLabelColor(mColors[mColorIndex]);
    mLabel->setNum(mNumber);
    emit numberChanged(isCorrect);
}

int ClickWidget::generateNextNumber()
{
    return mFrom + qrand() % (mTo - mFrom + 1);
}

void ClickWidget::setLabelColor(const QColor& color)
{
    mLabel->setStyleSheet(QString("color: %1;").arg(color.name()));
}
