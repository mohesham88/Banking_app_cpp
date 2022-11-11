#pragma once
#include<iostream>
#include <string>
#include "BankAccount.h"
using namespace std;
class Client
{
private:
	string name;
	string address;
	int phone;
    string Id;
    double balance;
    static int counter;
	BankAccount* client_account;
    bool checkname(string name) {
        for (int i = 0; i < name.size(); i++) {
            if (!isalpha(name[i])) {
                return false;
            }
        }
        return true;
    }
public:
    
    
    void setId();
    void setBalance(double balance);
    void setName(string name);
    void setAddress(string address);
    void setNumber(int phone);
    void set_account_Id();
    void set_balance(double b);
    double getbalance();
    string getid();
    

    Client(string name = " ", string address = " ", int phone = 0) {
        string id;
        setName(name);
        setAddress(address);
        setNumber(phone);
        setId();
    }

 
};

