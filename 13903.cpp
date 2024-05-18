//
// Created by 서준혁 on 3/28/24.
//
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
const int INF=987654321;
int R,C,N;
int dx[11];
int dy[11];
int mp[1001][1001];
int chk[1001][1001];
int ans= INF;
queue<pair<pair<int,int>,int>> q;
void bfs()
{
    while(q.size())
    {
        int x= q.front().first.first;
        int y= q.front().first.second;
        int cnt= q.front().second;
        q.pop();
        if(x==R)ans= min(ans,cnt);
        for(int i =0; i<N; i++)
        {
            int xx= x+dx[i];
            int yy= y+dy[i];
            if(xx<1||xx>R||yy<1||yy>C) continue;
            if(chk[xx][yy]==1) continue;
            if(mp[xx][yy]==1)
            {
                chk[xx][yy]=1;
                q.push({{xx,yy},cnt+1});
            }
        }

    }
}
void solve()
{
    for(int i =1; i<=C; i++)
    {
        if(mp[1][i]==1)
        {
            q.push({{1,i},0});

        }
    }
    bfs();
    if(ans==INF) cout<<-1;
    else cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>R>>C;
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
        {
            cin>>mp[i][j];
        }
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>dx[i]>>dy[i];
    solve();
    return 0;

}

