#include <bits/stdc++.h>
using namespace std;

class customeraccount{
    protected:
    map<string,int> customer_accounts;
    public:
    customeraccount(){
        customer_accounts["4500 1029 2938 2922"] = 10000;
        customer_accounts["4500 1029 2028 2910"] = 10000;
        customer_accounts["4500 1029 3038 1022"] = 10000;
    }

    bool check_account(string account_no){
        auto it = customer_accounts.find(account_no);
        if(it!=customer_accounts.end()){
            return true;
        }
        else{
            return false;
        }
    }
};

class customer : public customeraccount
{
    // add withdraw,deposit,change pin,money transfer,card(block or etc.),renew card, open new account
    int total_amount;
    int withdraw_amount;

    void withdraw(string c_account_no)
    {
        auto it = customer_accounts.find(c_account_no);
        if(it!=customer_accounts.end()){
        cout << "Enter the withdraw amount: ";
        cin >> withdraw_amount;
        if (withdraw_amount > it->second)
        {
            cout<<"Since the withdraw amount you entered is greater than your account balance, so total amount is withdrawn\n";
            cout<<"Amount withdrawn: " <<it->second<<endl;
            it->second = 0;
            cout<<"Available Balance: " <<it->second<<endl;
        }
        else
        {
            it->second -= withdraw_amount;
            cout << "Available Balance: " << it->second << endl;
        }

        }
    }

    void deposit()
    {
        int deposit_amount;
        cout << "Enter the deposit amount: ";
        cin >> deposit_amount;
        total_amount += deposit_amount;
        cout << "Available Balance: " << total_amount;
    }
};

class bankofficer
{
    // add amount etc
};

int main()
{

    return 0;
}