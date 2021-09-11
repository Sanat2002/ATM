#include<bits/stdc++.h>
using namespace std;

class Bank{
    private:
    string add,acc_type;
    int d_amount;
    int w_amount;
    vector<pair<string,int>> acc;
    vector<pair<string,int>> :: iterator it;

    public:
    void openaccount(string name){
        cout<<"Enter your address : ";
        getline(cin,add);
        cout<<"Enter amount for deposit : ";
        cin>>d_amount;
        acc.push_back(make_pair(name,d_amount));
        cout<<"Your account have been created!!!"<<endl;
    }

    void depositamount(string name){
        for(it = acc.begin();it<acc.end();it++){
            if((*it).first == name){
                cout<<"Enter amount to deposit : ";
                cin>>d_amount;
                (*it).second+=d_amount;
                cout<<"Amount deposited"<<endl;
                cout<<"Available Balance : "<<(*it).second<<endl;
                break;
            }
            else if(it == (acc.end()-1)){
                cout<<"Account does not exist..."<<endl;
            }
        }
    }

    void withdrawamount(string name){
        for(it = acc.begin();it<acc.end();it++){
            if((*it).first == name){
                cout<<"Enter amount to withdraw : ";
                cin>>w_amount;
                if(w_amount>=(*it).second){
                (*it).second=0;
                }
                else{
                    (*it).second-=w_amount;
                }
                cout<<"Amount Withdrawed"<<endl;
                cout<<"Available Balance : "<<(*it).second<<endl;
                break;
            }
            else if(it == (acc.end()-1)){
                cout<<"Account does not exist..."<<endl;
            }
        }
    }

    void displayaccount(string name){
        for(it = acc.begin();it<acc.end();it++){
            if((*it).first == name){
                cout<<"Amount Holder's Name : "<<name<<endl;
                cout<<"Available Balance : "<<(*it).second<<endl;
                break;
            }
            else if(it == (acc.end()-1)){
                cout<<"Account does not exist..."<<endl;
            }
        }
    }

};


int main(){
    int x;
    Bank a_name;
    while(x!=5){
        cout<<"1> Open Account"<<endl;
        cout<<"2> Deposit Amount"<<endl;
        cout<<"3> Withdraw Amount"<<endl;
        cout<<"4> Display Account"<<endl;
        cout<<"5> Exit"<<endl;
        cout<<"Select any one of above"<<endl;
        cin>>x;
        if(x==1){
            cout<<"Enter Your Name : ";
            string s;
            getchar();
            getline(cin,s);
            a_name.openaccount(s);
        }   
        else if(x==2){
            cout<<"Enter Account Holder's Name : ";
            string s;
            getchar();
            getline(cin,s);
            a_name.depositamount(s);
        } 
        else if(x==3){
            cout<<"Enter Account Holder's Name : ";
            string s;
            getchar();
            getline(cin,s);
            a_name.withdrawamount(s);
        } 
        else if(x==4){
            cout<<"Enter Account Holder's Name : ";
            string s;
            getchar();
            getline(cin,s);
            a_name.displayaccount(s);
        } 
    }
return 0;
}