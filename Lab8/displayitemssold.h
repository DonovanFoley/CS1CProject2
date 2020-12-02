#ifndef DISPLAYITEMSSOLD_H
#define DISPLAYITEMSSOLD_H

#include <QDialog>

namespace Ui {
class DisplayItemsSold;
}

class DisplayItemsSold : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayItemsSold(QWidget *parent = nullptr);
    ~DisplayItemsSold();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DisplayItemsSold *ui;

    void TableWidgetDisplay();
    /**********************************************************************
     void TableWidgetDisplay - prints a table that displayes expiring
                               members
                         Parameters:
                                    none
    ***********************************************************************/
};

#endif // DISPLAYITEMSSOLD_H
