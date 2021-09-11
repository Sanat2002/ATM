#include <bits/stdc++.h>
using namespace std;

class login
{
    map<string, string> oweners;
    map<string, string> customers;
    map<string, string>::iterator it;

public:
    login()
    {
        oweners["Sanat Thakur"] = "1234";
        oweners["Anmol Choudhary"] = "1234";
        customers["Sed"] = "00";
        customers["Alex"] = "11";
    }

    bool search_oweners(string o_name, string o_pass)
    {
        bool o_found = false;
        auto it = oweners.find(o_name);
        if (it != oweners.end())
        {
            if (it->second == o_pass)
            {
                cout << "Successfully Login\n";
                o_found = true;
            }
            else
            {
                cout << "Password is incorrect\n";
            }
        }
        else
        {
            cout << "Owener not found\n";
        }
        return o_found;
    }

    bool search_customers(string c_name, string c_pass)
    {
        bool c_found = false;
        auto it = customers.find(c_name);
        if (it != customers.end())
        {
            if (it->second == c_pass)
            {
                cout << "Successfully Login\n";
                c_found = true;
            }
            else
            {
                cout << "Password is incorrect\n";
            }
        }
        else
        {
            cout << "Customer not found\n";
        }
        return c_found;
    }

    void register_customer()
    {
        string reg_cust_name, reg_cust_pass;
        cout << "Enter Your Name and password\n";
        getchar();
        getline(cin, reg_cust_name);
        getline(cin, reg_cust_pass);
        customers.insert({reg_cust_name, reg_cust_pass});
        cout << "Successfully Registered\n";
    }
};

class Cab
{

protected:
    map<string, int> availCab;
    map<string, int> CabPrice;

public:
    Cab()
    {
        availCab.insert(pair<string, int>("Nano", 10));
        availCab.insert(pair<string, int>("thar", 3));
        availCab.insert(pair<string, int>("creta", 4));
        availCab.insert(pair<string, int>("verna", 5));
        availCab.insert(pair<string, int>("supra", 1));
        CabPrice.insert(pair<string, int>("Nano", 1000));
        CabPrice.insert(pair<string, int>("thar", 5000));
        CabPrice.insert(pair<string, int>("creta", 4500));
        CabPrice.insert(pair<string, int>("verna", 3000));
        CabPrice.insert(pair<string, int>("supra", 45000));
    }

    void RateAndAvail()
    {
        showavailCab();
        showCabRate();
    }
    void showavailCab()
    {
        cout << "Below are the name of the cabs and their quantity ->\n";
        for (auto const &pair : availCab)
        {
            std::cout << ":-" << pair.first << " , " << pair.second << "\n";
        }
    }
    void showCabRate()
    {
        cout << "Below are the name of the cabs and their price ->\n";
        for (auto const &pair : CabPrice)
        {
            std::cout << ":-" << pair.first << " , " << pair.second << "\n";
        }
    }
};

class customer : public Cab
{
    string book_cab_name, return_cab_name;
    int book_cab_no, payed_amount, amount_to_pay;
    map<string, int> cust_booked_cab;
    map<string, int>::iterator itr2;

public:
    void book_cab()
    {
        showavailCab();
        cout << "Enter the cab name for booking or to exit (e)\n";
        cin >> book_cab_name;
        auto it = availCab.find(book_cab_name);
        if (it != availCab.end() && it->second > 0)
        {
        ch_no:
            cout << "No. of this cab you want to book...?\n";
            cin >> book_cab_no;

            if (book_cab_no > 0 && book_cab_no <= it->second)
            {
                auto itr1 = CabPrice.find(book_cab_name);
                string pre_price_cab = to_string(itr1->second);

                amount_to_pay = book_cab_no * stoi(pre_price_cab);

            rep_pay:
                cout << "Pay Amount -> " << amount_to_pay << " or to cancle payment(-1)\n";
                cin >> payed_amount;

                if (payed_amount == amount_to_pay)
                {
                    it->second -= book_cab_no;
                    cout << "Cab booked successfully\n";

                    auto itr = cust_booked_cab.find(book_cab_name + " " + pre_price_cab);
                    if (itr != cust_booked_cab.end())
                    {
                        itr->second += book_cab_no;
                    }
                    else
                    {
                        cust_booked_cab.insert({book_cab_name + " " + pre_price_cab, book_cab_no});
                    }
                }
                else if (payed_amount == -1)
                {
                    cout << "Payment Cancled!!!\n";
                    book_cab();
                }
                else
                {
                    cout << "Please pay the exact amount\n";
                    goto rep_pay;
                }
            }
            else
            {
                cout << "Please choose valid no. of cabs and atleast 1 cab\n";
                goto ch_no;
            }
        }
        else if (it != availCab.end() && it->second == 0)
        {
            cout << "Sorry this cab is not available at this moment...\n";
            book_cab();
        }
        else if (book_cab_name == "e")
        {
            cout << "Exited...\n";
        }
        else
        {
            cout << "Invalid input\n";
            book_cab();
        }
    }

    void show_booked_cabs()
    {
        if (cust_booked_cab.size() > 0)
        {
            for (itr2 = cust_booked_cab.begin(); itr2 != cust_booked_cab.end(); itr2++)
            {
                cout << "Car name with price for one day -> " << itr2->first << "\nNo. of Car " << itr2->second << endl;
            }
        }
        else
        {
            cout << "You don't have booked any cab yet...\n";
        }
    }

    void return_booked_cab()
    {
        show_booked_cabs();
        cout << "Enter the name of the cab you want to return and  the price at which you booked in single line with space or to exit(exit)\n";
        getchar();
        getline(cin, return_cab_name);

        auto it = cust_booked_cab.find(return_cab_name);
        if (it != cust_booked_cab.end())
        {
            auto itr = availCab.find(return_cab_name);
            itr->second += 1;
            it->second -= 1;
            if (it->second == 0)
            {
                cust_booked_cab.erase(return_cab_name);
            }
            cout << return_cab_name << " returned successfully\n";
        }
        else if (return_cab_name == "exit")
        {
            cout << "Exited...\n";
        }
        else
        {
            cout << "This Car is not booked...\n";
            return_booked_cab();
        }
    }
};

class owener : public Cab
{
public:
    void addCab()
    {
        cout << "Available cars \n\n";
        showavailCab();
        cout << "\n\n";
    tryagain:
        cout << "Select 1 for adding a new Cab or select 0 for update  no. of existing car? and -1 if want to exit\n";
        int s;
        cin >> s;
        if (s == 1)
        {
            cout << "Enter Car name\n";
            string carname;
            getchar();
            getline(cin, carname);
            cout << "Enter Number of cars you want to add\n";
            int qw;
            cin >> qw;
            cout << "Enter price of car\n";
            int price;
            cin >> price;
            availCab.insert(pair<string, int>(carname, qw));
            CabPrice.insert(pair<string, int>(carname, price));
            showCabRate();
            showavailCab();
        }
        else if (s == 0)
        {
        u_cab:
            cout << "Enter name of car you want to update no. of cars or to exit(exit)\n";
            string st = "";
            getchar();
            getline(cin, st);
            std::map<string, int>::iterator it = availCab.find(st);
            if (it != availCab.end())
            {
                cout << "Enter number of cars you want to add\n";
                int gq;
                cin >> gq;
                it->second += gq;
                showavailCab();
            }
            else if (st == "exit")
            {
                cout << "Exited!!!\n";
            }
            else
            {
                cout << "Cab not found\n";
                goto u_cab;
            }
        }
        else if (s == -1)
        {
            cout << "Exited...\n";
        }
        else
        {
            cout << "please Enter valid input\n";
            goto tryagain;
        }
    }
    void removeCab()
    {
        showavailCab();
    yo:
        cout << "Enter 1 for removal of cab or enter 0 for change in no. of cab or -1 to exit\n";
        int ss;
        cin >> ss;
        if (ss == 1)
        {
        cab_rem:
            cout << "Enter name of car you want to remove or to exit (exit)\n";
            string sf;
            getchar();
            getline(cin, sf);
            auto it = availCab.find(sf);
            auto itr = CabPrice.find(sf);
            if (it != availCab.end())
            {
                availCab.erase(sf);
                CabPrice.erase(sf);
                cout << "\n\n After removing cab\n\n";
                showavailCab();
            }
            else if (sf == "exit")
            {
                cout << "Exited...\n";
            }
            else
            {
                cout << "Please Enter the valid cab name\n";
                goto cab_rem;
            }
        }
        else if (ss == 0)
        {
        val_c_name:
            cout << "Enter name of car you want to remove\n";
            string sfs;
            getchar();
            getline(cin, sfs);
            std::map<string, int>::iterator it = availCab.find(sfs);

            if (it != availCab.end())
            {
            trytry:
                cout << "Enter no. of cars you want to remove \n";
                int as;
                cin >> as;
                if (it->second < as)
                {
                    cout << "please Enter valid input!!!\n";
                    goto trytry;
                }
                else
                {
                    it->second -= as;
                }
                cout << "After changing total no. of Cabs..\n";
                showavailCab();
            }
            else if (sfs == "exit")
            {
                cout << "Exited...";
            }
            else
            {
                cout << "Enter valid cab name...\n";
                goto val_c_name;
            }
        }
        else if (ss == -1)
        {
            cout << "Exited...\n";
        }
        else
        {
            cout << "Please Enter valid input...\n";
            goto yo;
        }
    }
    void changeRate()
    {
        showCabRate();
        cout << "Enter name of Cab you want to change rate or to exit (exit)\n";
        string ds;
        getchar();
        getline(cin, ds);
        std::map<string, int>::iterator it = CabPrice.find(ds);

        if (it != CabPrice.end())
        {
            cout << "Enter new price of Cab\n";
            int pp;
            cin >> pp;
            it->second = pp;
            cout << "Updated rates of cab\n";
            showCabRate();
        }
        else if (ds == "exit")
        {
            cout << "Exited...\n";
        }
        else
        {
            cout << "Enter valid car name\n";
            changeRate();
        }
    }
};

int main()
{
    owener o;
    customer c;
    login l;
    char person_type, cust_select_opt, owe_select_opt;
    char l_or_r;
    string c_name, c_pass;
    string o_name, o_pass;
    bool owener_logged_in = false, customer_logged_in = false;

    while (true)
    {
        cout << "Welcome to Rental Service Please login!!!\n"
             << "Are you Owener or Customer(o/c)? or to exit(e)\n";
        cin >> person_type;

        if (person_type == 'o')
        {
            cout << "Enter Your name and password\n";
            getchar();
            getline(cin, o_name);
            getline(cin, o_pass);

            bool is_valid_owener = l.search_oweners(o_name, o_pass);
            if (is_valid_owener)
            {
                cout << "Owener Welcome to Rental Services\n";
                owener_logged_in = true;
            }
        }
        else if (person_type == 'c')
        {
            cout << "Login or Register(l/r)?\n";
            cin >> l_or_r;

            if (l_or_r == 'l')
            {
                cout << "Enter Your name and password\n";
                getchar();
                getline(cin, c_name);
                getline(cin, c_pass);

                bool is_valid_customer = l.search_customers(c_name, c_pass);
                if (is_valid_customer)
                {
                    cout << "Customer Welcome to Rental Services\n";
                    customer_logged_in = true;
                }
                else
                {
                    char want_reg;
                    cout << "Want to Register(y/n)?\n";
                    cin >> want_reg;

                    if (want_reg == 'y')
                    {
                        l.register_customer();
                    }
                    else if (want_reg == 'n')
                    {
                        cout << "Ok...\n";
                    }
                    else
                    {
                        cout << "Invalid Input\n";
                    }
                }
            }
            else if (l_or_r == 'r')
            {
                l.register_customer();
            }
            else
            {
                cout << "Invalid Input\n";
            }
        }
        else if (person_type == 'e')
        {
            break;
        }
        else
        {
            cout << "Invalid Input\n";
        }

        if (owener_logged_in)
        {
            while (true)
            {
                cout << "Want to Add Cab (a) , Remove Cab (r) , Change Rate (c), Show available Cabs (s) or Logout (l)\n";
                cin >> owe_select_opt;

                if (owe_select_opt == 'a')
                {
                    o.addCab();
                }
                else if (owe_select_opt == 'r')
                {
                    o.removeCab();
                }
                else if (owe_select_opt == 'c')
                {
                    o.changeRate();
                }
                else if (owe_select_opt == 's')
                {
                    o.RateAndAvail();
                }
                else if (owe_select_opt == 'l')
                {
                    break;
                }
                else
                {
                    cout << "Invalid Option\n";
                }
            }
        }
        else if (customer_logged_in)
        {
            while (true)
            {
                cout << "Want to Book Cab (b) , Show your Booked Cabs (s) , Return Booked Cabs (r) , Show available Cabs (c) or Logout (l)\n";
                cin >> cust_select_opt;

                if (cust_select_opt == 'b')
                {
                    c.book_cab();
                }
                else if (cust_select_opt == 's')
                {
                    c.show_booked_cabs();
                }
                else if (cust_select_opt == 'r')
                {
                    c.return_booked_cab();
                }
                else if (cust_select_opt == 'c')
                {
                    c.RateAndAvail();
                }
                else if (cust_select_opt == 'l')
                {
                    break;
                }
                else
                {
                    cout << "Invalid Option\n";
                }
            }
        }
    }
    return 0;
}