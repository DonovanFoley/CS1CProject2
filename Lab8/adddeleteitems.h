#ifndef ADDDELETEITEMS_H
#define ADDDELETEITEMS_H

#include <QDialog>

namespace Ui {
class AddDeleteItems;
}

class AddDeleteItems : public QDialog
{
    Q_OBJECT

public:
    explicit AddDeleteItems(QWidget *parent = nullptr);
    ~AddDeleteItems();

private slots:
    void on_pushButton_Add_clicked();

    void on_pushButton_Delete_clicked();

    void on_radio_Stock_toggled(bool checked);

    void on_pushButton_Edit_clicked();

private:
    bool inStock;     //represents if item is in stock or not

    Ui::AddDeleteItems *ui;
};

#endif // ADDDELETEITEMS_H
