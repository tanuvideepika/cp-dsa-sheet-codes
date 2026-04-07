//https://codeforces.com/contest/912/problem/B

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void maxXorSum(int n, int k) {

    if(k==1){
        cout<<n<<endl;
        return;
    }

    //We'll take the the number that is all set
    //1111111
    //we just need 2 numbers, n and a number thats all set
    //till msb of n, since we can take <=k

    int ans=0, fact=0;
    while(n>0){
        ans+=pow(2,fact++);
        n>>=1;
    }
    cout<<ans<<endl;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n,k;cin>>n>>k;
    maxXorSum(n,k);

    return 0;
}