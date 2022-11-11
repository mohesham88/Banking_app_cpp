#pragma once
#include<iostream>
#include<string>
#include "BankAccount.h"

using namespace std;
class SavingAcount : BankAccount
{

public:

	int minimumBalance(double amount);
	void deposit(double amoun);
	void withdraw(double amoun);
	SavingAcount(string ID, double amount) {
		int a;
		a = minimumBalance(amount);
		if (a == 1) {
			string ID;
			BankAccount::setId( ID);
		}

	}
};
