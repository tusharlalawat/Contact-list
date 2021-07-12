#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;
string fname, lname, phone_no;


bool is_digit(string s)
{
    bool check = true;
    for(int i=0; i<s.length(); i++)
    {
        if(!(int(s[i]) >= 48 && int(s[i]) <= 57)) 
        {
            check = false;
            break;
        }
    }
    return check;
}

void createAcc()
{
    ofstream Book("file.csv", ios::app);

    cout <<"Enter first name: ";
    cin >>fname;
    cout <<"Enter last name: ";
    cin >>lname;
    cout <<"Enter Phone number: ";
    cin >>phone_no;

    if(phone_no.length() == 10)
    {
        if(is_digit(phone_no) == true)
        {
            if(Book.is_open())
                Book <<fname <<" " <<lname <<" " <<phone_no <<endl;
            else
                cout <<"Error in opening file." <<endl;
        }
        else
            cout <<"Only digits are allowed!!" <<endl;
    }
    else
        cout <<"Please enter 10 digits number!!" <<endl;

    Book.close();
    cout <<"\n\n";
}

void search()
{
    bool found = false;
    ifstream searchFile("file.csv");
    string name;
    cout <<"Enter name you want to search: ";
    cin >>name;

    while (searchFile >>fname >>lname >>phone_no)
    {
        if(name == fname || name == lname)
        {
            cout <<"First name: " <<fname <<endl;
            cout <<"Last name: " <<lname <<endl;
            cout <<"Phone number: " <<phone_no <<endl;
            found = true;
            break;
        }
    }

    if(found == false)
        cout <<"No such contact found!!!" <<endl; 

    searchFile.close();
    cout <<"\n\n"; 
}

void display()
{
    fstream f;
    f.open("file.csv", ios::in);
    string line;
    int i = 0;
    if(f.is_open())
    {
        while(getline(f, line))
        {
            cout <<i+1 <<".)  " <<line <<endl;
            i++;
        }
    }
    if(i == 0)
        cout <<"Nothing to show, List is empty!!!" <<endl;
    
    f.close();
    cout <<"\n\n";
}

int main()
{
    int ch;
    cout <<"\n\n";
    cout <<"\t\t\t\t  ---------------------------------------" <<endl;
    cout <<"\t\t\t\t\t1.) Add contact." <<endl;
    cout <<"\t\t\t\t\t2.) Search Contact." <<endl;
    cout <<"\t\t\t\t\t3.) Display Contact list." <<endl;
    cout <<"\t\t\t\t\t4.) Exit." <<endl;
    cout <<"\t\t\t\t  ---------------------------------------" <<endl;
    
    while(ch != 4)
    {
        cout <<"Enter your choice: ";
        cin >>ch;
        // cout <<endl;
        switch (ch)
        {
            case 1:
                createAcc();
                break;

            case 2:
                search();
                break;

            case 3:
                display();
                break;
            
            case 4:
                cout <<"Thanks to use!!!" <<endl;
                break;

            default:
                cout <<"Invalid input, please choose valid operations!!!" <<endl;
        }
    }
    return 0;
} 
