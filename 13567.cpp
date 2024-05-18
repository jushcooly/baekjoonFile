//
// Created by 서준혁 on 1/24/24.
//
#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int dx[]= {1, 0, -1, 0};
const int dy[]= {0, -1, 0, 1};

int n,m;
vector<pair<string, int>> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>m>>n;
    int y =0, x=0, dir =0;
    for(int i  =0; i<n; i++)
    {
        string s;
        int d;
        cin>>s>>d;
        if(s=="TURN"&&d==0) d= -1;
        if(s=="MOVE")
        {
            int nx = x+dx[dir]*d;
            int ny = y+dy[dir]*d;
            if(nx>=m||ny>=m||nx<0||ny<0)
            {
                cout<<-1; return 0;
            }
            x= nx; y= ny;
        }
        else if(s=="TURN")
        {
            int nd = dir+d;
            if(nd<0) nd=3;
            else if(nd>3) nd=0;

            dir= nd;
        }


    }
    cout<<x<<' '<<y;

}