//
// Created by 서준혁 on 2/13/24.
//
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,Q;
int cmd, dy,dx, y,x, tot;
int mp[1004][1004];
bool vis[1004][1004];
void cmd3(int dy, int dx, int y, int x)
{
    if(mp[y][x])
    {
        return;
    }
    mp[y][x]= true;
    tot--;
    int ny = y+dy;
    int nx= x+dx;
    if(ny<=0||nx<=0||ny>n||nx>m) return;
    cmd3(dy,dx, ny,nx);

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>Q;
    tot= n*m;
    for(int i =0; i<Q; i++)
    {

        cin>>cmd;
         if(cmd==3)
        {
            cout<<tot<<'\n';
        }
        else if(cmd==2)
        {
            cin>>y>>x;
            cout<<mp[y][x]<<'\n';

        }
        else{
            cin>>dy>>dx>>y>>x;
            cmd3(dy,dx,y,x);

        }

    }

}