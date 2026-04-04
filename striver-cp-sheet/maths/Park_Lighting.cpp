//https://codeforces.com/problemset/problem/1358/A

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"


int32_t main(){

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int t;cin>>t;
    while(t--){
       int n,m;
       cin>>n>>m;
       int row=(m/2)*n;
       //last row
       if(m%2==1){
        row+=n/2+(n%2==1);
       }
       cout<<row<<endl;
    }

    return 0;
}
