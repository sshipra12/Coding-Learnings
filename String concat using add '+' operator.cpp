#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str,s;
    cin>>str;

    //Case 1:
    s=str;  //this works

    //Case2:
    str=s[0]+s[1];     // this won't work since '+' means concatenate and it requires 
    str=""+s[0]+s[1];  //base string in which we want to add/concatenate
                       //in 2nd case, base string("") in which we are concatenating is not present/placed

    //Case3:
    str=str+s[0]+s[1];  //this works because we provide the base string (here 'str') which is present
                        // in which we want to add/concatenate

    cout<<str;
}
