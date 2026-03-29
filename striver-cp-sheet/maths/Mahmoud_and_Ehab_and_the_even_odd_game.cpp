//https://codeforces.com/problemset/problem/959/A

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

//for playing optimally both players would try to remove
//entire number to 0 so that the opponent has no option

int32_t main(){

    int n;cin>>n;
    if(n%2==0){
        cout<<"Mahmoud"<<endl;
    }else{
        cout<<"Ehab"<<endl;
    }

    return 0;
}
