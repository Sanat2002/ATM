#include<iostream>
#include<windows.h>

using namespace std;

class Clock{
    int h,m,s;
    int s_h=0,s_m=0,s_s=0;
    public:
    void settime();
    void startclock();
    void setalarm(int a,int b,int c);
};

void Clock :: settime(){
    cout<<"Enter the hours: "<<endl;
    cin>>h;
    cout<<"Enter the minutes: "<<endl;
    cin>>m;
    cout<<"Enter the seconds: "<<endl;
    cin>>s;
}

void Clock :: startclock(){
    while(true){
        system("cls"); // used to clear screen available in windows.h header file
        if(s<59){
            s++;
        }
        else if(s==59){
            s=0;
            m++;
        }
        if(m==60){
            m=0;
            h++;
        }
        if(h==24){
            m=0;
            h=0;
        }
        if(s_h!=0 || s_m!=0 || s_s!=0){
            if(s_h == h && s_m == m && s_s==s){
                cout<<"Alarm Beepsss...."<<endl;
            }
        }
        if(h<10){
            cout<<"0"<<h<<" : ";
        }
        else{
            cout<<h<<" : ";
        }
        if(m<10){
            cout<<"0"<<m<<" : ";
        }
        else{
            cout<<m<<" : ";
        }
        if(s<10){
            cout<<"0"<<s<<endl;
        }
        else{
            cout<<s<<endl;
        }
        Sleep(1000); // this is the function in cpp(windows.h -> header file) to stop the execution as in python
    }
}

void Clock :: setalarm(int a,int b, int c){
    s_h=a;
    s_m=b;
    s_s=c;
}

int main(){
    Clock c;
    c.settime();
    c.setalarm(2,3,45);
    c.startclock();
}