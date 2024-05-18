//
// Created by 서준혁 on 3/13/24.
//
#include <iostream>



using namespace std;
int n,m, sy, sx,p, cnt=0;
int mp[54][54];
bool visited[54][54];


int dy[4]= {1,0,-1,0};
int dx[4]= {0,1,0,-1};
int DFS(int y, int x, int d, int p)
{

    if(y<0||x<0||y>=n||x>=m) return 0;
    if(p<=0||visited[y][x]) return 0;
    visited[y][x]= true;
    int ret= mp[y][x]+ DFS(y+dy[d], x+dx[d], d, p-1);
    int nd= (d+1)%4;
    ret= max(ret, mp[y][x]+DFS(y+dy[nd], x+dx[nd], nd, p-2));
    nd= (d+3)%4;
    ret= max(ret, mp[y][x]+DFS(y+dy[nd], x+dx[nd],nd, p-2));
    visited[y][x]= false;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n; i++)
        for(int j =0; j<m; j++)
            cin>>mp[i][j];
    cin>>sy>>sx>>p;
    visited[sy][sx]= true;
    for(int d=0; d<4; d++)
        cnt= max(cnt, mp[sy][sx]+ DFS(sy+dy[d], sx+dx[d], d, p));
    cout<<cnt;

}
