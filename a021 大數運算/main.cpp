#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>
#include<stdbool.h>
#include<sstream>
#include<deque>
using namespace std;
bool fu=false;
string p(string n1,string n2)
{
    string s="";
    int l=0;bool ch=false;
    while(l<n1.length()||l<n2.length())
    {
        int t=0;
        if(l<n1.length()&&l<n2.length())
        {
            if(ch) {t++;ch=false;}
            t+=(n1[n1.length()-l-1]-48)+(n2[n2.length()-l-1]-48);
            if(t>=10) {ch=true;t-=10;}
            s=char(t+48)+s;
        }
        else if(l<n1.length())
        {
            if(ch) {t++;ch=false;}
            t += (n1[n1.length()-l-1]-48);
            if(t>=10) {ch=true;t-=10;}
            s=char(t+48)+s;
        }
        else
        {
            if(ch) {t++;ch=false;}
            t += (n2[n2.length()-l-1]-48);
            if(t>=10) {ch=true;t-=10;}
            s=char(t+48)+s;
        }
        l++;
    }
    if(ch){s='1'+s;}
    return s;
}


string m(string n1,string n2)
{
    fu=false;
    bool ch;
    string stemp="",s="";
    int l=0,temp=0,bm=0;
    if (n1.length()<n2.length()){bm=1;}
    else if(n1.length()==n2.length())
    {
        if(n1==n2){return "0";}
        for(int i=0;i<n1.length();i++)
        {
            if(n1[i]<n2[i])
                {bm++;break;}
            if(n1[i]>n2[i])
                {break;}
        }
    }
    if(bm==1){stemp=n2;n2=n1;n1=stemp;fu=true;}
    while(l<n1.length())
    {
        int t=0;
        if(l<n1.length()&&l<n2.length())
        {
            if(ch) {t--;ch=false;}
            t+=(n1[n1.length()-l-1]-48)-(n2[n2.length()-l-1]-48);
            if(t<0) {ch=true;t+=10;}
            s=char(t+48)+s;
        }
        else
        {
            if(ch) {t--;ch=false;}
            t+=(n1[n1.length()-l-1]-48);
            if(t!=0)s=char(t+48)+s;
        }
        l++;
    }
    return s;
}
int multi(string n1,string n2){
        int c=0;
        string str="0",str2="0";
        while(c<n2.length()){
            str="0";
            for(int x=0;x<n2[n2.length()-c-1]-48;x++){ str=p(str,n1);}
            for(int x=0;x<c;x++){str+="0";}
            str2=p(str2,str);
            c++;
        }
        cout<<str2;

}


string divi(string n1,string n2){
    string s1="",s2="";int c=0,t;string st="";

    if(n1.length()==n2.length())
    {
        if(n1==n2){return "1";}
        for(int i=0;i<n1.length();i++)
        {
            if(n1[i]<n2[i])
                {cout<<"0";break;}
        }
    }
    while(c<n1.length()){
        m(s2+n1[c],n2);
        if(fu){s2+=n1[c];st+="0";c++;continue;}
        else{
            s1=s2+n1[c];
            s2="";
            t=0;
            while(true){
                s1 = m(s1,n2);
                if(fu){s1 = m(n2,s1);;s2+=s1;break;}
                else {t++;}
            }
            c++;
        }
        st+=char(t+48);

    }
    return st;
}


int main()
{
    bool z=0;
    string in="";
    cin>>
    string dir,temp;
    stringstream ss(in);
    deque<string>x;
    while(getline(ss,dir,' '))
    {
        x.push_back(dir);
    }
    if(x[1]=="+"){ cout<<p(x[0],x[2]);}
    else if(x[1]=="-") {
        temp=m(x[0],x[2]);
        if(fu){cout<<"-";}
        cout<<temp;
    }
    else if(x[1]=="*") {multi(x[0],x[2]);}
    else if (x[1]=="/") {
            temp=divi(x[0],x[2]);
            for (int i=0;i<temp.length();i++){
                if(z){cout<<temp[i];}
                else if(temp[i]>48)
                {
                    z=1;cout<<temp[i];
                }
        }
    }
}
