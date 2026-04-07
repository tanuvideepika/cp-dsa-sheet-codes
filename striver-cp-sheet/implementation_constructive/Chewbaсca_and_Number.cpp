//https://codeforces.com/contest/514/problem/A

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main(){

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    string s; cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        int num=s[i]-'0';
        if(i==0 && num==9){
            //no inversion if first digit can be zero
            //no inversion to 1 also just no inversion at all
            continue;
        }

        if(num>=5){
            s[i]='0'+(9-num);
        }
    }

    cout<<s<<endl;

    return 0;
}
