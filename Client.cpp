
#include "Client.h"
void Client::setName(string name) {
    if (checkname(name) == true) {
        this->name = name;
    }
    else
        cout << "invalide name";
}
void Client::setAddress(string address) {
    this->address = address;
}
void Client::setNumber(int phone) {
    this->phone = phone;
}
void Client::set_account_Id() {
    string id;
    this->client_account->setId(id);
}
void Client::set_balance(double balance) {
    this->client_account->setBalance(balance);
}
void Client::setId() {
    string Id;
    counter++;
    stringstream st;
    st << counter;
    string a = st.str();
    string b = "FCAI-";
    string f = b + a;
    Id = f;
    this->Id = Id;
}
void Client::setBalance(double balance) {
    this->balance = balance;
}
string Client::getid() {
    return this->Id;
}
double Client::getbalance() {
    return this->balance;
}
