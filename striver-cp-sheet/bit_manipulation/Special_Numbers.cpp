//https://codeforces.com/problemset/problem/1594/B

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int mod=1e9+7;

int mypow(int a, int b, int m){
    int ans = 1;
    while(b){
        if (b&1) ans = (ans*a) % m;
        b /= 2;
        a = (a*a) % m;
    }
    return ans;
}

/*
considering combinations as 2 powers decimal number
for base case we have n=2 for which all numbers are special
we are using binary form to get combination of power and introducing our own base
we know for k, n=2, kth element is k.
here kth element is combination of powers of base n we decide.
*/

void solve(int n, int k){

    int ans=0;
    int j=0;
    while(k){
        int last=k&1;
        ans=(ans%mod+last*mypow(n,j,mod))%mod;
        j++;
        k>>=1;
    }
    cout<<ans<<endl;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int t;cin>>t;
    while(t--){

        int n,k;cin>>n>>k;
        solve(n,k);
    }

    return 0;
}
