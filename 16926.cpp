//
// Created by 서준혁 on 2/1/24.
//
#include<iostream>
using namespace std;
int n,m,r;
int mp[304][304];
void solve(int trial)
{
    if(trial>r) return;
    int center = min(n,m)/2;
    for(int i = 0; i<center; i++)
    {
        int y = i; int x = i;
        int val = mp[y][x];
        while(y<n-1-i)
        {
            int nx = mp[y+1][x];
            mp[y+1][x]= val;
            val = nx;
            y++;

        }
        while(x<m-1-i)
        {
            int nx = mp[y][x+1];
            mp[y][x+1] = val;
            val = nx;
            x++;
        }
        while(y>i)
        {
            int nx = mp[y-1][x];
            mp[y-1][x]= val;
            val = nx;
            y--;
        }
        while(x>i)
        {
            int nx = mp[y][x-1];
            mp[y][x-1] = val;
            val = nx;
            x--;

        }
    }
    solve(trial+1);

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>r;
    for(int i =0; i<n;i++)
    {
        for(int j =0; j<m; j++)
        {
            cin>>mp[i][j];
        }
    }
    solve(1);
    for(int i=0; i<n; i++)
    {
        for(int j =0; j<m; j++)
        {
            cout<<mp[i][j]<<' ';
        }
        cout<<'\n';
    }
}