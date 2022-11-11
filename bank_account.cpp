#include "BankAccount.h"
int BankAccount::deposit(double amount) {
	setBalance(balance += amount);
	return this->balance;
}
int BankAccount::withdraw(double amount) {
	if (balance < amount) {
		cout << " This is more than what you can withdraw" << endl;
	}
	else
		setBalance(balance -= amount);
	return this->balance;
}
