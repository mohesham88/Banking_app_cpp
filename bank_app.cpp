

#include "headers.h"
#include<iostream>

// Client
Client::Client(){
    set_name("");
    set_phone("");
    set_address("");
}

Client::Client(string n, string p, string ad){
    set_name(n);
    set_phone(p);
    set_address(ad);
}
void Client::set_name(string n){name = n;}   
void Client::set_phone(string ph){ phone = ph;}
void Client::set_address(string ad){address = ad;}
string Client::get_name(){return name;}   
string Client::get_phone(){return phone;}
string Client::get_address(){return address;}



// Bank account
void SavingsBankAccount::set_minimumbalance(double mini_bal){
    this->minimumBalance = mini_bal;
}

void SavingsBankAccount::withdraw(double amount){
    if (balance < amount){
        cout << "This is more than what you can withdraw\n";
    }
    else if(balance - amount < minimumBalance){
        cout << "your account should have a balance more than the minimum balance\n";
    }
    else{
        balance -= amount;
    }

}

void SavingsBankAccount::deposit(double amount){
    if(amount >= 100){
        balance += amount;
    }
    else{
        cout << "you can't deposit less than 100 L.E\n";
    }
}

// bank app

int BankingApplication::load(){
    ifstream file;
    file.open("database.txt",ios::in);
    string line;
    int acc_num = 0;

    while(getline(file , line)){
        
        string s = "";
        stringstream ss;
        ss << line;
        string name = "",ad = "",ph = "",d = "",ID = "";

        while(s != ","){
            name += s;
            ss >> s;
            if(name != "")
                name += " ";
        }
        
        ss >> s;        // after comma ,
        ad = s;
        ss >> s;        // comma ,
        ss >> s;        // phone
        ph = s;
        ss >> s;        // comma
        ss >> s;        // balance
        d = s;
        double bal = stod(d);
        ss >> s;        // comma
        ss >> s;        // ID
        ID = s;
        ss >> s;        // comma 
        ss >> s;        // account type
        string account_type = s;  



        



        BankAccount *bank;
        if(account_type == "saving"){
            bank = new SavingsBankAccount;
            bank->set_balance(bal);
            bank->set_id(ID);
        }
        else{
            bank = new BankAccount;
            bank->set_balance(bal);
            bank->set_id(ID);
        }

        
        acc_num++;
        Client *c = new Client(name,ph,ad);
        c->set_account_type(account_type);
        v.push_back(make_pair(c,bank));
        //mp.insert(make_pair(c,bank));
    
    }
    
  
    file.close();
    return acc_num;

    



}



void BankingApplication::creat_account(){
    //Client* c;
    BankAccount* b = new BankAccount;
    string name,ph, adr;
    cout << "Please Enter Client Name ====> ";
    getline(cin,name);
    cout << "Please enter Client Address ====> ";
    getline(cin,adr);
    cout << "Please Enter Client Phone ====> ";
    getline(cin,ph);

    Client *c = new Client(name,ph,adr);
    string account_type = "basic";
    cout << "What Type of Account Do You Like? (1) Basic (2) Saving : ";
    int choice;
    cin >> choice;
    cout << "Please Enter the Statrting Balance ====> ";
    double bal;
    cin >> bal;
    if(choice == 1){
        b->set_balance(bal);
    }
    else{
        SavingsBankAccount sv;
        if(bal < sv.get_min()){
            cout << "You can't make an account with a balance less than the minimum balance required \n";
            return;
        }
        b = &sv;
        b->set_balance(bal);
        account_type = "saving";
        
    }

   


    int id = load() + 1;

    string n = to_string(id);

    string ID = "FCAI-" + n;
    
    b->set_id(ID);
    //mp.insert(make_pair(new Client(name,ph,adr),b)); 
    v.push_back(make_pair(new Client(name,ph,adr),b)); 


    c->set_account_type(account_type);

    ofstream file;
    file.open("database.txt", ios::app);

    file  << c->get_name() << " , "
        << c->get_address() << " , "
        << c->get_phone() << " , "
        << b->get_balance() << " , " << b->get_id() << " , " << account_type
        <<"\n";




    file.close();


    
}



void BankingApplication::display_accounts(){


    for(auto p : v){
        cout << p.first->get_name() << ' ' << p.first->get_phone() << ' ' << p.first->get_address() << ' ' << p.second->get_balance() << ' ' << p.second->get_id() << ' ' << p.first->get_account_type() << endl;
    }


}

void BankingApplication::withdraw_money(){

    load();
    string user_id;
    cout << "Please Enter Account ID (e.g., FCAI-015) =========> ";
    cin >> user_id;
    bool found = false;
    ofstream file;
    file.open("database.txt", ios::trunc);
    for(auto p : v){
        if(p.second->get_id() == user_id){
            found = true;
            double amnt;
            cout << "enter how much money to withdraw : ";
            cin >> amnt;
            p.second->withdraw(amnt);
            cout << "your current balance is = " << p.second->get_balance() << endl;
        }

        file  << p.first->get_name() << " , "
            << p.first->get_address() << " , "
            << p.first->get_phone() << " , "
            << p.second->get_balance() << " , " << p.second->get_id() << " , " << p.first->get_account_type() <<
            "\n";


            


    }

  

        if(!found){
            cout << "ID was not found\n";
        }
        file.close();


} 

void BankingApplication::deposit_money(){

    load();
    string user_id;
    cout << "Please Enter Account ID (e.g., FCAI-015) =========> ";
    cin >> user_id;
    bool found = false;
    ofstream file;
    file.open("database.txt", ios::trunc);
        for(auto p : v){
        if(p.second->get_id() == user_id){
            found = true;
            double amnt;
            cout << "enter how much money to depsit : ";
            cin >> amnt;
            p.second->deposit(amnt);
            cout << "your current balance is = " << p.second->get_balance() << endl;
        }

        file  << p.first->get_name() << " , "
            << p.first->get_address() << " , "
            << p.first->get_phone() << " , "
            << p.second->get_balance() << " , " << p.second->get_id() << " , " << p.first->get_account_type() <<
            "\n";


            


        }



        if(!found){
            cout << "ID was not found\n";
        }
        file.close();

}


void BankingApplication:: run(){
    int choice;
    cout << "*** Welcome to FCAI Banking Application ***\n";
    cout << "1. Create a New Account\n" << "2. List Clients and Accounts\n" 
        << "3. Withdraw Money\n" << "4. Deposit Money\n";
    cout << "Please Enter Choice =====> ";
    cin >> choice;
    cin.ignore();
    if (choice == 1){
        
        creat_account();
    }
    else if(choice == 2){
        load();
        display_accounts();
    }
     else if (choice == 3){
        withdraw_money();
    }
    else if(choice == 4){
        deposit_money();
    }
 

}
