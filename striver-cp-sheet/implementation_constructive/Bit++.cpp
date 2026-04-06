//https://codeforces.com/problemset/problem/282/A

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool containsAdd(string &s){
    for(auto &x:s){
        if(x=='+')return true;
    }
    return false;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        if(containsAdd(s)){
            ans++;
        }else{
            ans--;
        }
    }

    cout<<ans<<endl;

    return 0;
}
