//https://codeforces.com/contest/1355/problem/A

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int findDiff(int a){
    string temp=to_string(a);
    int mini=9,maxi=0;
    for(auto &x:temp){
        mini=min(mini, 1LL * (x-'0'));
        maxi=max(maxi, 1LL * (x-'0'));
        if(mini==0)return 0;
    }
    return mini*maxi;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int t;cin>>t;
    while(t--){

        int a,k;cin>>a>>k;
        k--;
        while(k--){
            int diff=findDiff(a);
            if(diff==0)break;//a will remain same after k iterations
            a+=diff;
        }
        cout<<a<<endl;
    }

    return 0;
}
