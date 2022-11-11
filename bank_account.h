#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include "Client.h"

using namespace std;
class BankAccount
{
protected:

	string Id;
	static int counter;
	double balance;
	Client* ptr;

public:

	int deposit(double amount);
	int withdraw(double amount);



	void setptr(Client* i) {
		ptr = i;
	}

	void setId(string Id) {
		
		counter++;
		stringstream st;
		st << counter;
		string a = st.str();
		string b = "FCAI-";
		string f = b + a;
		Id = f ;
		this->Id = Id;
	}
	void setBalance(double balance) {
		this->balance = balance;
	}
	string getId() {
		return this->Id;
	}

	double getBalance() {
		return this->balance;
	}
	BankAccount( double balance = 0) {
		string id;
		setId(id);
		setBalance(balance);
	}
	 
};
