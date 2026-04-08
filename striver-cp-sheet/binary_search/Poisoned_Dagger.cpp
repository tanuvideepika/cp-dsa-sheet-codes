//https://codeforces.com/problemset/problem/1613/C

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

        int n,k;cin>>n>>k;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        int left=1,right=k,ans=k;
        while(left<=right){
            int midi=left+(right-left)/2;

            int cost=0;
            for(int i=0;i<n-1;i++){
                int temp=nums[i+1]-nums[i];
                cost+=min(midi, nums[i+1]-nums[i]);
            }
            //for n-1 index
            cost+=(midi);
            if(cost>=k){
                ans=midi;
                right=midi-1;
            }else{
                left=midi+1;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}