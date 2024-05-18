//
// Created by 서준혁 on 1/28/24.
//
#include<iostream>
using namespace std;
#define INF 987654321
int n, mp[2004][2004];//(좌표 0, 0이 1000, 1000)
const int dy[]= {1, 0, -1, 0};
const int dx[]= {0, 1, 0, -1};  int y =1000, x=1000, t=1, ans =INF;
    void solve(int move, int dir)
    {
        while(move--)
        {
            t++;
            int ny = y+dy[dir];
            int nx = x+dx[dir];
            if(mp[ny][nx])
            {
                ans =min(ans, t-mp[ny][nx]);
            }
            mp[ny][nx]= t;
            y= ny;
            x= nx;

        }
    }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    mp[y][x]=1;
    for(int i =0; i<n; i++)
    {
        char cD;
        int move, iD;
        cin>>cD>>move;
        if(cD=='N') iD=0;
        if(cD=='E') iD=1;
        if(cD=='S') iD=2;
        if(cD=='W') iD=3;
        solve(move, iD);
    }
    if(ans==INF) cout<<-1<<'\n';
    else cout<<ans<<'\n';

}
