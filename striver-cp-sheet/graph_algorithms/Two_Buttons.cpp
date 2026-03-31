//https://codeforces.com/problemset/problem/520/B

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

/*
why recursion dp didn't work?
for 4 6
before completing recursion call for 4, we get another call for 4 from
its children, thus there is a cycle existing here.

dfs with visited array worked until we made sure we did vis[n] false
before returning from call. But it gave tle

bfs will give shortest path, thus we added it in a queue with n and steps
thus without needing an actual graph, we solved this. Dry run was
important for understanding this problem

*/

int solve(int n,int m, vector<bool> &vis){
    if(n>=m)return (n-m);

    if(vis[n]==true)return 1e7;
    vis[n]=true;

    //red button
    int temp1=solve(n*2, m, vis)+1;
    //blue button
    int temp2=1e7;
    if(n-1>0)
    temp2=solve(n-1,m, vis)+1;

    vis[n]=false;

    return min(temp1, temp2);
}

int bfs(int n, int m){

    queue<pair<int,int>> q;
    vector<bool> vis(1e7,0);

    q.push({n,0});
    vis[n]=true;
    while(!q.empty()){

        int fro=q.front().first;
        int steps=q.front().second;
        q.pop();

        //action with this node
        if(fro==m)return steps;

        //children
        if(fro-1>0 && vis[fro-1]==false){
            vis[fro-1]=true;
            q.push({fro-1, steps+1});
        }

        if(fro*2<vis.size() && vis[fro*2]==false){
            vis[fro*2]=true;
            q.push({fro*2,steps+1});
        }

    }
    return -1;
}

int32_t main(){

    int n,m;
    cin>>n>>m;
    //vector<bool> vis(1e7,0);
    //cout<<solve(n,m,vis)<<endl;

    cout<<bfs(n,m)<<endl;

    return 0;
}
