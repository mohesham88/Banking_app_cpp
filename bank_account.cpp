#include "bank_account.h"

Bank_account::Bank_account(int account_id,double balance){
        this->id = account_id;
        this->balance = balance;
}

Bank_account::Bank_account(){
    this->balance = 0;
}

void Bank_account::set_id(int id){
    this->id = id;
}
void Bank_account::set_balance(double balance){
    this->balance = balance;
}
int Bank_account::get_id(){
    return id;
}
double Bank_account::get_balance(){
    return balance;
}

void Bank_account::withdraw(double money){
    if(money <= balance){
        balance -= money;
    }
    else{
        cout << "Sorry. This is more than what you can withdraw.\n";
    }
}
void Bank_account::deposit(double money){
    balance += money;
}

