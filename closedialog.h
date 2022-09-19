#ifndef CLOSEDIALOG_H
#define CLOSEDIALOG_H

#include <QDialog>
#include <QPushButton>

class CloseDialog : public QDialog
{
    Q_OBJECT
public:
    CloseDialog(QWidget* parent = nullptr);
private:
    QPushButton *mAcceptButton;
signals:
    void accepted();
};

#endif // CLOSEDIALOG_H
