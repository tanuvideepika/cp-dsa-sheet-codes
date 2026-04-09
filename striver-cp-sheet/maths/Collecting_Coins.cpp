//https://codeforces.com/problemset/problem/1294/A

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

        int a,b,c,n;cin>>a>>b>>c>>n;
        int temp1=n+a+b-2*c;//solved the 3eq, 3variable
        int temp2=n+b+c-2*a;
        int temp3=n+a+c-2*b;
        
        //do not count negatives
        if(temp1%3==0 && temp2%3==0 && temp3%3==0 && temp1>=0 && temp2>=0 && temp3>=0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
