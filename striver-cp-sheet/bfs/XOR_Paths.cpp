//https://codeforces.com/contest/1006/problem/F

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool isK(vector<pair<int,int>> &tempPath, int k, vector<vector<int>> &a){
    int myxor=0;
    for(auto x:tempPath){
        int i=x.first, j=x.second;
        myxor^=a[i][j];
    }
    return myxor==k;
}

bool isVis(int a, int b, vector<pair<int,int>> &tempPath){
    for(auto x:tempPath){
        int i=x.first, j=x.second;
        if(i==a && j==b)return true;
    }
    return false;
}

/*
We tried finding all paths using bfs, written helper functions.
We do not need the entire path, just the xor.
Vis array wasn't needed as the directions were fixed and cannot 
form cycles.
Gave memory limit exceeded
*/

int bfs(vector<vector<int>> &a, int k, int n, int m){

    queue<vector<pair<int,int>>> q;
    vector<pair<int,int>> path;
    path.push_back({0,0});
    q.push(path);
    int ans=0;

    while(!q.empty()){
        vector<pair<int,int>>tempPath=q.front();
        q.pop();
        int i=tempPath.back().first;
        int j=tempPath.back().second;
        if(i==n-1 && j==m-1 && isK(tempPath,k,a)){
            ans++;
        }
        if(i+1<n && isVis(i+1,j, tempPath)==false){
            vector<pair<int,int>> newPath(tempPath);
            newPath.push_back({i+1,j});
            q.push(newPath);
        }
        if(j+1<m && isVis(i,j+1, tempPath)==false){
            vector<pair<int,int>> newPath(tempPath);
            newPath.push_back({i,j+1});
            q.push(newPath);
        }
    }

    return ans;
}

/*
this is also giving mle, optimised parts missing above
*/

int bfs2(vector<vector<int>> &a, int k, int n, int m){

    queue<pair<pair<int,int>, int>> q;
    pair<pair<int,int>, int> index={{0,0}, a[0][0]};
    q.push(index);
    int ans=0;

    while(!q.empty()){
        pair<pair<int,int>, int> tempPath=q.front();
        q.pop();
        int i=tempPath.first.first;
        int j=tempPath.first.second;
        int currxor=tempPath.second;
        if(i==n-1 && j==m-1 && k==currxor){
            ans++;
        }
        if(i+1<n){
            q.push({{i+1,j}, currxor^a[i+1][j]});
        }
        if(j+1<m){
            q.push({{i,j+1}, currxor^a[i][j+1]});
        }
    }

    return ans;
}

/*
We are using meet in the middle technique to divide the problem into two parts
middle is i+j == (n+m-2)/2 considering diagonal, every path needs to pass this
mp has [x][currnode] bcas y is constant here for a given x, acc to above eq.

Gave wrong ans for n=1,m=1 bcas I was doing i+j-2 == (n+m-2)/2
thinking its 1 based indexing, cleary sending 0 based values for i and j
*/

int bfs3(vector<vector<int>> &a, int k, int n, int m){

    queue<pair<pair<int,int>, int>> q;
    pair<pair<int,int>, int> index={{0,0}, 0};
    q.push(index);
    int ans=0;
    map<int,map<int,int>> mp;
    while(!q.empty()){
        pair<pair<int,int>, int> tempPath=q.front();
        q.pop();
        int i=tempPath.first.first;
        int j=tempPath.first.second;
        int currxor=tempPath.second;
        currxor^=a[i][j];
        //removed i+j-2 bcas i,j are 0 based only
        if( i+j == (n+m-2)/2 ){
            mp[i][currxor]++;
            //bcas i+1 or j+1 will not satify above criteria now
            continue;
        }
        if(i+1<n){
            q.push({{i+1,j}, currxor});
        }
        if(j+1<m){
            q.push({{i,j+1}, currxor});
        }
    }

    index={{n-1,m-1}, 0};
    q.push(index);

    while(!q.empty()){
        pair<pair<int,int>, int> tempPath=q.front();
        q.pop();
        int i=tempPath.first.first;
        int j=tempPath.first.second;
        int currxor=tempPath.second;
        if(i+j == (n+m-2)/2 ){
            ans+=mp[i][currxor^k];
            continue;
        }
        //doing later so that middle is not included twice
        currxor^=a[i][j];
        if(i-1>=0){
            q.push({{i-1,j}, currxor});
        }
        if(j-1>=0){
            q.push({{i,j-1}, currxor});
        }
    }

    return ans;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<int>> a(n+1, vector<int> (m+1,0));
    vector<vector<bool>> vis(n+1, vector<bool> (m+1,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    cout<<bfs3(a,k,n,m)<<endl;

    return 0;
}
