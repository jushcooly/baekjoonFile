//
// Created by 서준혁 on 2/28/24.
//
#include<iostream>
#include<cmath>
#include<set>
using namespace std;
bool visited[9001];
int arr[14];
set<int> s;
int n,m;

void Init()
{
    visited[0]=true; visited[1]= true;
    for(int i =2; i<=sqrt(9001); i++)
        for(int j =2*i; j<9001; j+=i)
            if(!visited[j]) visited[j] = true;

}
void dfs(int cnt, int idx, int sum)
{
    if(cnt==m)
    {
        if(!visited[sum])
        {
            s.insert(sum);
            return;
        }
        for(int i = idx; i<n; i++)
            dfs(cnt+1,i+1,sum+arr[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    Init();
    for(int i =0; i<n; i++) cin>>arr[i];
    dfs(0,0,0);
    for(auto &i :s)
        cout<<i<<' ';
    if(!s.size()) cout<<-1<<'\n';

}