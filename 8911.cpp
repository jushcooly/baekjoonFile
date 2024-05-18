//
// Created by 서준혁 on 1/24/24.
//
#include<iostream>
#include <string>
#include<cmath>
using namespace std;
const int dy[]= {1,0, -1, 0};
const int dx[] = {0, -1, 0, 1};
int tc;
string s;
bool visited[504][504];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>tc;
    while(tc--)
    {
        cin>>s;
        int y =0, x=0, dir=0, maxX=0, maxY=0, minY= 0, minX= 0;
        for(int i =0; i<s.size(); i++)
        {
            if(s[i]=='F')
            {
                int ny = y+dy[dir];
                int nx = x+dx[dir];
                    x= nx, y = ny;
                    maxX= max(x, maxX), maxY= max(y, maxY);
                    minX= min(x, minX), minY= min(y, minY);
            }
            else if(s[i]=='L')
            {
                int nd= dir+1;
                if(nd>3) nd=0;
                dir =nd;
            }
            else if(s[i]=='R')
            {
                int nd = dir-1;
                if(nd<0) nd= 3;
                dir= nd;
            }
            else
            {
                int ny= y- dy[dir];
                int nx = x-dx[dir];
                x= nx;
                y = ny;
                maxX= max(x, maxX), maxY= max(y, maxY);
                minX= min(x, minX), minY= min(y, minY);
            }


        }
        int h= abs(maxX)+abs(minX);
        int w= abs(maxY)+abs(minY);
        cout<<h*w<<'\n';

    }

}