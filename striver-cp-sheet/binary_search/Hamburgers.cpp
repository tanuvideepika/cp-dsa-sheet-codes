//https://codeforces.com/contest/371/problem/C

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int nb,ns,nc;
int pb,ps,pc;
string recipe;
int Mymoney;

bool isPossible(int midi){
    //cout<<midi<<endl;
    int money=Mymoney;
    int b=0,s=0,c=0;
    for(auto &x:recipe){
        if(x=='B')b++;
        if(x=='S')s++;
        if(x=='C')c++;
    }

    b*=midi;s*=midi;c*=midi;
    //cout<<b<<" "<<s<<" "<<c<<endl;
    b-=nb;s-=ns;c-=nc;
    if(b>0){
        money-=(b*pb);
        //cout<<money<<endl;
        if(money<0)return false;
    }
    if(s>0){
        money-=(s*ps);
        //cout<<money<<endl;
        if(money<0)return false;
    }
    if(c>0){
        money-=(c*pc);
        //cout<<money<<endl;
        if(money<0)return false;
    }
    //cout<<"here"<<endl;
    return true;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin>>recipe;
    cin>>nb>>ns>>nc;
    cin>>pb>>ps>>pc;
    cin>>Mymoney;

    int left=0, right=1e13, ans=0;
    while(left<=right){
        int midi=left+(right-left)/2;
        if(isPossible(midi)){
            ans=midi;
            left=midi+1;
        }else{
            right=midi-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
