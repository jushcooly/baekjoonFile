//
// Created by 서준혁 on 2/19/24.
//
#include <iostream>
#include<cmath>
#include<algorithm>
#include <opencl-c.h>

int solve(int y,int x)
{
    int n = max(abs(y),abs(x));
    int val = 2*n+1;
    val*=val;
    int dif= 2*n;
    if(y==n) return val -(n-x);
    val-=dif;
    if(x==-n) return val -(n-y);
    val-=dif;
    if(y==-n) return val-(x+n);
    val-=dif;
    return val -(y+n);

}
int getDigit(int val)
{
    return val?getDigit(val/10)+1:0;

}
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    int k =0;
    for(int i=r1; i<=r2; i++)
    {
        for(int j =c1; j<=c2; j++)
        {
            k= max(k, getDigit(solve(i,j)));

        }
    }
    for(int i =r1; i<=r2; i++)
    {
        for (int j = c1; j <= c2; ++j) {
            cout<<setw(k)<< solve(i,j)<<" ";

        }
    }
    cout<<"\n";
}