//https://codeforces.com/contest/670/problem/D1
//https://codeforces.com/contest/670/problem/D2

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

//k needs to be reset after every isPossible

/*
the max val can be when a=1, b=1e9 and k=1e9. Now max a*midi value can be
b+k=1e9*2. Now we have an upper limit of ans=1e9*2. To be safer we put 
at 12 digits. Long long overflows around 1e18 so fine only.
*/

int countDigit(int n)
{
    string num = to_string(n);
    return num.length();
}

bool isPossible(int midi, vector<int> &a, vector<int> &b, int k){
    int total=0, n=a.size();
    for(int i=0;i<n;i++){
        //added this piece to set upper limit to solve integer overflow
        int temp1=countDigit(a[i]),temp2=countDigit(midi);
        if(temp1+temp2>12)return false;
    
        int need=a[i]*midi;
        int have=b[i];
        int more=need-have;
        int mini=0;
        total+=max(more,mini);
    }

    return total<=k;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n,k;cin>>n>>k;

    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];

    int left=0,right=1e10, ans=0;
    while(left<=right){
        int midi=left+(right-left)/2;
        if(isPossible(midi, a, b, k)){
            ans=midi;
            left=midi+1;
        }else{
            right=midi-1;
        }
    }

    cout<<ans<<endl;

    return 0;
}
