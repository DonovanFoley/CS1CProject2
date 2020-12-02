#ifndef EXECUITIVECLASS_H
#define EXECUITIVECLASS_H
#include <QString>

class RegularMember
{
  public:
    //***Modifiers***//
    void setFirstName(QString name)
    {
        firstName = name;
    };
    /**********************************************************************
     void setFirstName - sets the member's first name
                         Parameters:
                                   name - member's first name
    ***********************************************************************/
    void setLastName(QString name)
    {
        lastName = name;
    };
    /**********************************************************************
     void setLastName - sets the member's last name
                         Parameters:
                                   name - member's last name
    ***********************************************************************/
    void setID(QString ID)
    {
        id = ID.toInt();
    };
    /**********************************************************************
     void setID - sets the member's ID
                         Parameters:
                                   ID - member's ID
    ***********************************************************************/
    void setCost(QString newCost)
    {
        cost = newCost.toInt();
    };
    /**********************************************************************
     void setCost - sets the member's cost of membership renewal
                         Parameters:
                                   newCost - member's renewal cost
    ***********************************************************************/

    //***Acessors***//
    QString getFirstName()
    {
        return firstName;
    };
    /**********************************************************************
     QString getFirstName - returns member's first name
                         Parameters:
                                   none
    ***********************************************************************/
    QString getLastName()
    {
        return lastName;
    };
    /**********************************************************************
     QString getLastName - returns member's last name
                         Parameters:
                                   none
    ***********************************************************************/
    int getID()
    {
        return id;
    };
    /**********************************************************************
     QString getID - returns member's ID
                         Parameters:
                                   none
    ***********************************************************************/
    int getCost()
    {
        return cost;
    };
    /**********************************************************************
     QString getCost - returns member's membership cost
                         Parameters:
                                   none
    ***********************************************************************/

  private:
    QString firstName;  //member's first name
    QString lastName;   //member's last name

    int id;             //member's ID
    double cost;        //member's membership cost
};

class ExecutiveMember : public RegularMember
{
  public:
    //***Modifiers***//

    void setRebate(double newRebate)
    {
        rebate = newRebate;
    };
    /**********************************************************************
     void setRebate - sets the executive member's rebate
                         Parameters:
                                   newRebate - member's rebate
    ***********************************************************************/

    //***Acsessors***//
    double getRebate()
    {
        return rebate;
    };
    /**********************************************************************
     QString getRebate - returns executive member's rebate
                         Parameters:
                                   none
    ***********************************************************************/

  private:

    double rebate;     //executive member's rebate
};


#endif // EXECUITIVECLASS_H
