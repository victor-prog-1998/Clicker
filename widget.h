#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "clickwidget.h"
#include "closedialog.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget() override;
    virtual void closeEvent(QCloseEvent* event) override;
private:
    QPushButton *mStartButton;
    QPushButton *mStopButton;
    QLabel *mCorrectAnswersLabel;
    QLabel *mWrongAnswersLabel;
    ClickWidget *mClickWidget;
    CloseDialog *mCloseDialog;
    int mCorrectAnswersCounter = 0;
    int mWrongAnswersCounter = 0;
private slots:
    void startButtonSlot();
    void stopButtonSlot();
    void numberChangedSlot(bool isCorrect);
};

#endif // WIDGET_H
