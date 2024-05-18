//
// Created by 서준혁 on 1/30/24.
//

#include<iostream>
#include<queue>
using namespace std;
int n,m, ey, ex;
int mp[1002][1002];
int visited[1002][1002];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
void bfs(int y, int x)
{
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x]= 1;
    while(q.size())
    {
        int qy = q.front().first;
        int qx = q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int ny = qy+dy[i];
            int nx = qx+dx[i];
            if(ny<0||nx<0||ny>=n||nx>=m) continue;
            if(!visited[ny][nx]&mp[ny][nx])
            {
                visited[ny][nx]= visited[qy][qx]+1;
                q.push({ny,nx});

            }
        }
    }
}
int main()
{
    cin>>n>>m;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i =0; i<n; i++)
    {
        for(int j =0; j<m; j++)
        {
            cin>>mp[i][j];
            if(mp[i][j]==2)
            {
                ey= i;
                ex= j;
            }


        }
    }
    bfs(ey, ex);
    for(int i =0; i<n; i++)
    {
        for(int j =0; j<m; j++)
        {
            if(mp[i][j]==0)
            {
                cout<<0<<' ';

            }
            else{
                cout<<visited[i][j]-1<<' ';
            }
        }
        cout<<'\n';
    }


}
