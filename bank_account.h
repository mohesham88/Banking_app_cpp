#include "banking_application.h"


class Bank_account{
private:
    int id;
    double balance;
    Client client;
public:
    Bank_account();
    Bank_account(int account_id,double balance);
    void set_id(int id);
    void set_balance(double balance);
    int get_id();
    double get_balance();
    void withdraw(double money);
    void deposit(double money);
};