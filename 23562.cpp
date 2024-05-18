//
// Created by 서준혁 on 1/30/24.
//
#include<iostream>
#include<string>
using namespace std;
#define INF 1e9
char mp[24][24];
int a,b;
int n,m;
int ans = INF;
int boardSize;
int squareSize=0;
int trashBlack=0;
int originBlack=0;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    cin>>a>>b;
    for(int i =0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>mp[i][j];
            if(mp[i][j]=='#')
            {
                originBlack++;
            }
        }
    }
    boardSize= min(n,m);
    while(boardSize>squareSize)
    {
        squareSize+=3;


        for(int y=0; y+squareSize<=n; y++) {
            for (int x = 0; x + squareSize <= m; x++) {
                int cost = 0;
                trashBlack= originBlack;
                for(int ny = y; ny<y+squareSize; ny++)
                {
                    for(int nx = x; nx<x+squareSize; nx++) {
                        if (mp[ny][nx] == '#') {
                            trashBlack--;
                        } else if (mp[ny][nx] == '.') {
                            cost += a;

                        }


                    }
                }
                cost+=trashBlack*b;


                for(int ny=y+squareSize/3; ny<y+2*squareSize/3; ny++)
                {
                    for(int nx= x+squareSize/3; nx< x+squareSize; nx++)
                    {
                        if(mp[ny][nx]=='#')
                            cost+=b;
                        else if(mp[ny][nx]=='.')
                            cost-=a;

                    }

                }
                ans = min(cost, ans);


            }
        }
    }
    cout<<ans;
}