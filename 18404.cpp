//
// Created by 서준혁 on 3/27/24.
//
#include<iostream>
#include<queue>

using namespace std;
int a,b,n,m,Y,X;
int road[504][504];
bool visited[504][504];
const int dy[]{-1,1,-2,2,-2,2,-1,1};
const int dx[]= {-2,-2,-1,-1,1,1,2,2};
queue<pair<int,int>>q;
int res[1001];
void solve(int y,int x)
{
    road[y][x]=0;
    visited[y][x]=true;
    q.push({y,x});
    while(q.size())
    {
        y= q.front().first;
        x= q.front().second;
        visited[y][x]= true;
        for(int i =0; i<8; i++)
        {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<=0||nx<=0||ny>n||nx>n||visited[ny][nx]) continue;
            visited[ny][nx]= 1;
            road[ny][nx]= road[y][x]+1;
            q.push({ny,nx});

        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>X>>Y;
    for(int i =0; i<m; i++)
    {
        cin>>a>>b;
        solve(X,Y);
        res[i]= road[a][b];
        memset(visited,0,sizeof(visited));
        memset(road,0,sizeof(road));


    }
    for(int i =0; i<m; i++)
    {
        cout<<res[i]<<" ";

    }
}