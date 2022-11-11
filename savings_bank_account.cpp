#include "savingaccount.h"
int SavingAcount::minimumBalance(double amount) {
	if (amount < 100)
	{
		cout << "sorry, you have to make deposits that are not less than 100 a time." << endl;
		return 0;

	}
	else
	{
		BankAccount::setBalance(amount);
		return 1;
	}
}

void SavingAcount::deposit(double amoun) {
	int a;
	a = minimumBalance(amoun);
	if (a == 1) {
		BankAccount::deposit(amoun);
	}
}
void SavingAcount::withdraw(double amoun)
{
	BankAccount::withdraw(amoun);
}
