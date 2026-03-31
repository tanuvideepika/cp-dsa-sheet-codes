//https://codeforces.com/problemset/problem/1426/A

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
        int n,x; cin>>n>>x;
        if(n==1 || n==2){
            cout<<1<<endl;
        }else{
            n-=2;
            int ans=1+n/x+(n%x!=0);
            cout<<ans<<endl;
        }
    }

    return 0;
}
