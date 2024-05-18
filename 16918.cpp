//
// Created by 서준혁 on 2/13/24.
//
#include<iostream>
#include<algorithm>
using namespace std;
int r,c,n, mp[204][204];
const int dy[]= {-1, 1, 0, 0};
const int dx[]= {0, 0, -1, 1};
char cMp[204][204];
bool bMp[204][204];
void Input()
{
    cin>>r>>c>>n;
    for(int i =0; i<r; i++)
        for(int j =0; j<c; j++)
        {
            char c;
            cin>>c;
            if(c=='O') mp[i][j]=3;
        }
}
void solve( )
{
    for(int t =2; t<=n; t++)
    {
        if(t%2==0)
        {
            for(int i =0; i<r; i++)
            {
                for(int j =0; j<c; j++)
                {
                    if(!mp[i][j]) mp[i][j]= t+3;

                }
            }
        }
        else{
            memset(bMp, 0, sizeof(bMp));

            for(int i =0; i<r; i++)
            {
                for(int j =0; j<c; j++)
                {
                    if(mp[i][j]==t)
                    {
                        bMp[i][j] = true;
                       for(int dir =0; dir<4; dir++)
                       {
                           int ny= i+dy[dir];
                           int nx = j+dx[dir];
                           if(ny<0||nx<0||ny>=r||nx>=c) continue;
                           bMp[ny][nx] = true;

                       }
                    }
                }
            }
            for(int i =0; i<r; i++)
                for(int j =0; j<c; j++)
                {
                    if(bMp[i][j]) mp[i][j] =0;
                }
            }
        }

}
void Print()
{
    for(int i =0; i<r; i++)
    {
        for(int j =0; j<c; j++)
        {
            if(!mp[i][j]) cMp[i][j]= '.';
            else cMp[i][j]= 'O';
            cout<<cMp[i][j];
        }
        cout<<'\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Input();
    solve();
    Print();
}