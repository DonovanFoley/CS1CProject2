#ifndef EXPIRINGMEMBERS_H
#define EXPIRINGMEMBERS_H

#include <QDialog>

namespace Ui {
class ExpiringMembers;
}

class ExpiringMembers : public QDialog
{
    Q_OBJECT

public:
    explicit ExpiringMembers(QWidget *parent = nullptr);
    ~ExpiringMembers();

private slots:

    void on_pushButton_clicked();

private:
    Ui::ExpiringMembers *ui;

    void TableWidgetDisplay();
    /**********************************************************************
     void TableWidgetDisplay - prints a table that displayes expiring
                               members
                         Parameters:
                                    none
    ***********************************************************************/

};

#endif // EXPIRINGMEMBERS_H
