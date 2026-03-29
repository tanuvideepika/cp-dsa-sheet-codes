//https://codeforces.com/problemset/problem/1296/A

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

//o+o=e
//for conversion we atleast need 1o and 1e

int32_t main(){

    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        int e=0,o=0;
        bool ans=false;
        for(int i=0;i<n;i++){
            int num;cin>>num;
            if(num%2==0){
                e++;
            }else{
                o++;
            }
        }
        if(o%2==0 && o!=0 && e>0){
            ans=true;
        }
        if(o%2!=0)ans=true;

        ans?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }

    return 0;
}
