#include "closedialog.h"
#include <QVBoxLayout>
#include <QLabel>

CloseDialog::CloseDialog(QWidget *parent): QDialog(parent)
{
   mAcceptButton = new QPushButton("Обязательно приду");
   connect(mAcceptButton, &QPushButton::clicked, this, &CloseDialog::accept);

   QVBoxLayout *vLayout = new QVBoxLayout;
   vLayout->addWidget(new QLabel("Приходите ещё"));
   vLayout->addStretch();
   vLayout->addWidget(mAcceptButton);
   setLayout(vLayout);
}
