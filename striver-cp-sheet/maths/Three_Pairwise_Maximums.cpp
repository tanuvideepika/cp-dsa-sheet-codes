//https://codeforces.com/problemset/problem/1385/A

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
        vector<int> data(3);
        for(int i=0;i<3;i++){
            cin>>data[i];
        }
        sort(data.begin(), data.end());
        int x=data[0], y=data[1], z=data[2];
        //3 same
        if(x==y && y==z){
            cout<<"YES"<<endl;
            cout<<x<<" "<<x<<" "<<x<<endl;
        }
        //2 same
        else if(x==y){
            cout<<"NO"<<endl;
        }
        else if(y==z){
            cout<<"YES"<<endl;
            cout<<x<<" "<<x<<" "<<z<<endl;
        }
        //none same
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
