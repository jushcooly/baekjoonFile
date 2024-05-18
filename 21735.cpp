//
// Created by 서준혁 on 2/20/24.
//
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int n,m;
vector<int> v;
bool visited[104];
int solve(int cnt,int i,int res)
{
    if(cnt>m) return 0;
    if(cnt==m)
    {
        return res;

    }
    int ans=0;

    ans =max(solve(cnt+1,i+1,res+v[i+1]),solve(cnt+1,i+2,res/2+v[i+2]));




    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    v.resize(n+1);
    for(int i =1; i<=n; i++)
    {
        cin>>v[i];
    }
    cout<<solve(0,0,1);
}