#ifndef CLICKWIDGET_H
#define CLICKWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

class ClickWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ClickWidget(QWidget *parent = nullptr);
    void start();
    void stop();

signals:
    void numberChanged(bool);

public slots:
    virtual void mousePressEvent(QMouseEvent* event) override;
    void timeoutSlot();

private:
    QLabel *mLabel;
    QTimer *mTimer;
    int mNumber;
    int mCounter;
    int generateNextNumber();
    void setLabelColor(const QColor& color);
    const int mFrom = 3;
    const int mTo = 7;
    std::array<QColor, 4> mColors;
    size_t mColorIndex = 0;
};

#endif // CLICKWIDGET_H
