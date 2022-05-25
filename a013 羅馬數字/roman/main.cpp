#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string l1="",l2="";
    cin>>l1>>l2;
    int n1=0,n2=0;
    for (int i=0;i<l1.length();i++)
    {
    char x=l1[i];
    if(x=='I')
        n1=n1+1;
    else if(x=='V')
        n1=n1+5;
    else if(x=='X')
        n1=n1+10;
    else if(x=='L')
        n1=n1+50;
    else if(x=='C')
        n1=n1+100;
    else if(x=='D')
        n1=n1+500;
    else if(x=='M')
        n1=n1+1000;
    }
    for (int i=0;i<l2.length();i++)
    {
    char x=l2[i];
    if(x=='I')
        n2=n2+1;
    else if(x=='V')
        n2=n2+5;
    else if(x=='X')
        n2=n2+10;
    else if(x=='L')
        n2=n2+50;
    else if(x=='C')
        n2=n2+100;
    else if(x=='D')
        n2=n2+500;
    else if(x=='M')
        n2=n2+1000;
    }
    cout<<n1<<endl;
    cout<<n2;
    int c= abs(n2-n1);
    int c2=c;
    int nt[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string st[13]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string s="";
    for (int i=0;i<13;i++)
        {
        if(c%nt[i]!=0)
        {
            for(int j=0;j<c/nt[i];j++)
                s+=st[i];
        }
        else if(nt[i]==1)
            {
                for(int j=0;j<c/nt[i];j++)
                    s+=st[i];
            }
        c = c%nt[i];
        }
    if(c2==0)
        cout<<"zero";
    else
        cout<<s;


}
