//https://codeforces.com/contest/287/problem/B

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

/*
taking max midi splitters
(k) , (k-1) , (k-2) , .... , (k-(midi-1)) splitters are used then
(k-1) + (k-2) + (k-3) + .... + (k-(midi-1)-1) + 1 = total pipes made
using ap sum and deductions (a+l)*n/2
((2*k-midi-1)*midi/2)+1 is obtained
*/

bool isPossible(int n, int k, int midi){
    int temp=((2*k-midi-1)*midi/2)+1;
    return temp>=n;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n,k;cin>>n>>k;

    //kept left=1 that was not lowest
    int left=0, right=k, ans=-1;
    while(left<=right){
        int midi=left+(right-left)/2;
        if(isPossible(n,k,midi)){
            ans=midi;
            right=midi-1;
        }else{
            left=midi+1;
        }
    }

    cout<<ans<<endl;

    return 0;
}
