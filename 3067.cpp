//
// Created by 서준혁 on 5/3/24.
//

#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
int T;
int n;
int a;
int m;
vector<int> coins;
int graph[10001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--)
    {
        coins.clear();
        memset(graph,0,sizeof(graph));
        cin>>n;
        for(int i =0; i<n; i++)
        {
            cin>>a;
            coins.push_back(a);


        }
        cin>>m;
        graph[0]=1;
        for(int i =0; i<n; i++)
        {
            for(int j = coins[i]; j<=m; j++)
            {
                graph[j]+=(graph[j-coins[i]]);

            }
        }
        cout<<graph[m]<<'\n';
    }

}