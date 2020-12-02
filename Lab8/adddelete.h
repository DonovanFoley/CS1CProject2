#ifndef ADDDELETE_H
#define ADDDELETE_H

#include <QDialog>

namespace Ui {
class AddDelete;
}

class AddDelete : public QDialog
{
    Q_OBJECT

public:
    explicit AddDelete(QWidget *parent = nullptr);
    ~AddDelete();

private slots:

    void on_radio_Executive_toggled(bool checked);

    void on_pushButton_Add_clicked();

    void on_pushButton_Delete_clicked();

private:
    QString membership;     //represents membership type

    Ui::AddDelete *ui;
};

#endif // ADDDELETE_H
