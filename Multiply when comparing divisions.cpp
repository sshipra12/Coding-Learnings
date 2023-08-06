#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num,numerator,denominator;

    num = 1;
    numerator = 5*25;
    denominator = 100;

    //Case1:
    if(num>=(numerator/denominator))  //is 1 >= 1.25 , but due to int type conversion 1.25 will convert to 1
                                      // and this will become true , which is not correct
        cout<<"Yes";

    //Case2:
    if(num*denominator>=numerator)   //here comparison is like this 100 >= 125 and this becomes false, which is accurate
        cout<<"Yes";
}
