//
// Created by 서준혁 on 2/20/24.
//
#include<iostream>
using namespace std;
double p[4];
const int dy[]= {0,0,1,-1};
const int dx[]= {1, -1, 0, 0};
int n;
bool visited[30][30];


double solve(int y,int x,int cnt)
{
    if(cnt==n)
        return 1.0;
    double res=0.0;

    visited[y][x]= true;
    for(int i=0;i<4; i++)
    {
        int ny=y+dy[i],nx= x+dx[i];

        if(visited[ny][nx]) continue;
        res= res+p[i]*solve(ny,nx,cnt+1);
    }
    visited[y][x]= false;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i =0; i<4; i++)
    {
        int a;
        cin>>a;
        p[i]= a/100.0;


    }
    double ans = solve(14,14,0);
    cout.precision(10);
    cout<<fixed<<ans;

}