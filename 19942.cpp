//
// Created by 서준혁 on 2/28/24.
//
#include <iostream>
#include<vector>
#include <algorithm>
#include<map>
using namespace std;
int n,mp,mf,ms,mv;
const int INF= 1e9+1;
int ret =INF;
struct Food{
    int p,f,s,v,c;
};
map<int,vector<vector<int>>>retV;
vector<Food> arr;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>mp>>mf>>ms>>mv;
    arr.resize(n);
    for(int i =0; i<n; i++)
        cin>>arr[i].p>>arr[i].f>>arr[i].s>>arr[i].v>>arr[i].c;
    for(int i=1; i<(1<<n); i++)
    {
        vector<int> v;
        int b=0, c=0, d=0,e=0,sum=0;
        for(int j =0; j<n; j++)
        {
            if(i&(1<<j))
            {
                v.push_back(j+1);
                b+=arr[i].p;
                c+=arr[i].f;
                d+=arr[i].s;
                e+=arr[i].v;
                sum+=arr[i].c;

            }
        }
        if(b>=mp&&c>=mf&&d>=ms&&e>=mv)
        {
            if(ret>=sum)
            {
                ret= sum;
                retV[ret].push_back(v);

            }
        }
    }
    if(ret==INF){
        cout<<-1; return 0;
    }
    sort(retV[ret].begin(), retV[ret].end());
    cout<<ret<<'\n';
    for(int b: retV[ret][0])
    {
        cout<<b<<' ';

    }
}
