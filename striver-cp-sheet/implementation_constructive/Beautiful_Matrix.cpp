//https://codeforces.com/problemset/problem/263/A

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int32_t main(){

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int x=0,y=0;
    int temp=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>temp;
            if(temp==1){
                //i was trying to break here
                //gave error bcas there were input remaining
                x=i;y=j;
            }
        }
    }

    int ans=abs(2-x)+abs(2-y);

    cout<<ans<<endl;

    return 0;
}
