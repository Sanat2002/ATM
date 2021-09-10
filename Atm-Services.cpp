#include <bits/stdc++.h>
using namespace std;

class customer
{
    // add withdraw,deposit,change pin,money transfer,card(block or etc.),renew card, open new account
    int total_amount;

    void withdraw()
    {
        int withdraw_amount;
        cout << "Enter the withdraw amount: ";
        cin >> withdraw_amount;
        if (withdraw_amount > total_amount)
        {
            cout << total_amount << endl;
            total_amount = 0;
        }
        else
        {
            total_amount -= withdraw_amount;
            cout << "Available Balance: " << total_amount << endl;
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
