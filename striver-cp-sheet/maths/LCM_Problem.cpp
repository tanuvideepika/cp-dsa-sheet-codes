//https://codeforces.com/problemset/problem/1389/A

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

//lowest multiple can be *2
//lowest value can be for a*2
//if a*2 is not in range then a+x * 2+y 
//will also not be in the range
//lcm for a, a*2 will be a*2

int32_t main(){

    int t;cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(2*a<=b){
            cout<<a<<" "<<(2*a)<<endl;
        } else {
            cout<<-1<<" "<<-1<<endl;
        }
    }
    return 0;
}
