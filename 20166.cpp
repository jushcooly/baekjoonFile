//
// Created by 서준혁 on 3/14/24.
//
#include<iostream>
#include<string>
#include<map>
using namespace std;
const int dy[]= {-1,-1,-1,0,0,1,1,1};
const int dx[]={-1,0,1,-1,1,-1,0,1};

string mp[11];
int n,m,k;
map<string,int> cases;
void dfs(int y,int x, int depth, string s)
{
    if(depth==5) return;
    cases[s]++;
    for(int i =0; i<8; i++)
    {
        int ny= y+dy[i];
        int nx = x+dx[i];

        if(ny<0) ny = n-1;
        if(nx<0)nx = m-1;
        if(ny>=n) ny=0;
        if(nx>=m) nx=0;

        dfs(ny, nx, depth+1,s+mp[ny][nx]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for(int i =0; i<n; i++) cin>>mp[i];
    for(int i =0; i<n; i++)
    {
        for(int j =0; j<n; j++){
            string st= "";
            dfs(i,j,0,st+mp[i][j]);

        }
    }
    while(k--){
        string s;
        cin>>s;
        cout<<cases[s]<<'\n';
    }
}
