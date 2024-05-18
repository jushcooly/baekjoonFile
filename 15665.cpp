//
// Created by 서준혁 on 2/20/24.
//
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int n,m;
vector<int> v;
vector<int>curV;

void solve( int cnt)
{
    if(cnt==m)
    {
        for(int i =0; i<m; i++){
            cout<<curV[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    int tmp=-1;
    for(int i =0; i<n; i++)
    {
        if(tmp!=v[i])
        {
            curV.push_back(v[i]);
            tmp= v[i];
            solve(cnt+1);
            curV.pop_back();

        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;v.resize(n);
    for(int i =0; i<n; i++) cin>>v[i];
    sort(v.begin(), v.end());
    solve(0);


}
