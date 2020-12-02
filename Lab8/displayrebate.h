#ifndef DISPLAYREBATE_H
#define DISPLAYREBATE_H

#include <QDialog>

namespace Ui {
class DisplayRebate;
}

class DisplayRebate : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayRebate(QWidget *parent = nullptr);
    ~DisplayRebate();

private slots:

private:
    Ui::DisplayRebate *ui;

    void TableWidgetDisplay();
    /**********************************************************************
     void TableWidgetDisplay - prints a table that displayes the rebate of
                               executive members
                         Parameters:
                                    none
    ***********************************************************************/
};

#endif // DISPLAYREBATE_H
