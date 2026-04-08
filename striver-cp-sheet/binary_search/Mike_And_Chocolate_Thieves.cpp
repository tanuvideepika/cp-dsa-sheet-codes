//https://codeforces.com/contest/689/problem/C

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int isPossible(int midi, int m){
    //a*r^3=midi
    //we are iterating over midi and r so a is fixed here
    //for 3 unknowns we need to iterate over 2 and find the 3rd
    int ways=0;
    for(int r=2;r*r*r<=midi;r++){
        ways+=midi/(r*r*r); //adding a
    }
    return ways;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int t;t=1;
    while(t--){

        int m;cin>>m;

        int left=8,right=1e18,ans=-1;
        while(left<=right){
            int midi=left+(right-left)/2;
            int ways=isPossible(midi,m);
            if(ways>=m){
                if(ways==m)ans=midi;
                right=midi-1;
            }else{
                left=midi+1;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}