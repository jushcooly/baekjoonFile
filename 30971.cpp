//
// Created by 서준혁 on 2/27/24.
//
#include<iostream>
#include<vector>
using namespace std;
vector<bool> visited;


int ans=-1;


int n,k;
int a[11], b[11], c[11];
void dfs(int n,int k, vector<int>& sequence)
{
    if(sequence.size()==n)
    { int res=0;
        for(int i =1; i<n; i++)
        {
            if(c[sequence[i]]*c[sequence[i-1]]<=k){
                res+=a[sequence[i-1]]*b[sequence[i]];

            }
            else{
                res-=50000000;
                break;
            }
        }
        ans= max(ans,res);
        return;

    }
    for(int i =0; i<n; i++)
    {
        if(!visited[i])
        {
            visited[i]= true;
            sequence.push_back(i);
            dfs(n,k,sequence);
            sequence.pop_back();
            visited[i]= false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i =0; i<n; i++)
        cin>>a[i];
    for(int i =0; i<n; i++)
        cin>>b[i];
    for(int i =0; i<n; i++)
        cin>>c[i];
    vector<int> v;
    dfs(n,k,v);
    cout<<ans;


}