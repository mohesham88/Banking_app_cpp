#include<bits/stdc++.h>
using namespace std;

class Client{
private:
    string name;
    string phone;
    string address;
    string account_type;
public:
    Client();
    Client(string, string, string);
    void set_name(string n);
    void set_phone(string ph);
    void set_address(string ad);
    string get_name();  
    string get_phone();
    string get_address();
    void set_account_type(string s){
        account_type = s;
    }
    string get_account_type(){
        return account_type;
    }
};



class BankAccount{
protected:
	string id;
	static int counter;
	double balance;

public:
    BankAccount(){balance = 0;}
    BankAccount(double bal){balance = bal;}
    void set_id(string id){this->id = id;}
	void set_balance(double balance){this->balance = balance;}
	string get_id(){return id;}
	double get_balance(){return balance;}

    virtual  void deposit(double amount){
        set_balance(balance += amount);
    }
    virtual  void withdraw(double amount){
        	if (balance < amount) {cout << "This is more than what you can withdraw" << endl;}
            else
                {set_balance(balance -= amount);}
    }
};
int BankAccount:: counter = 0;





class SavingsBankAccount : public BankAccount{
private:
    double minimumBalance;
public:
    SavingsBankAccount() : BankAccount(0){this->minimumBalance = 1000;};
    SavingsBankAccount( double init_balance, double mini_balance):BankAccount(init_balance){
        if(init_balance >= mini_balance){
            this->balance = init_balance;
            this->minimumBalance = mini_balance;
        }
        else{
            cout << "The initial balance should not be less than the mini balance = " << minimumBalance << '\n';
        }
    };
    void set_minimumbalance(double);
    double get_min(){return minimumBalance;};
    void withdraw(double amount);
    void deposit(double amount);
    
};






class BankingApplication{
    //map<Client*,BankAccount*> mp;

    // to solve arrangement problem use vector of pairs instead of map

    vector<pair<Client*,BankAccount*>> v;




public:
    BankingApplication(){
        v.clear();
        //mp.clear();
    };
    void creat_account();
    void display_accounts();
    int load();
    void withdraw_money();
    void deposit_money(); 
    void run();
/*     ~BankingApplication(){
    
    } */

}; 



