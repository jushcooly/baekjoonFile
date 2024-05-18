 //
// Created by 서준혁 on 2/28/24.
//
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int n;
ll lis[]= {9,8,7,6,5,4,3,2,1,0};
bool visited[11];
vector<ll> res, sequence;
void dfs(int depth, int idx, int cnt)
{
    if(depth==cnt)
    {
        ll sum=0;
        for(auto num:sequence)
        {
            sum+=num;
            sum*=10;

        }
        sum/=10;
        res.push_back(sum);
        return;
    }
    for(int i =idx; i<10; i++)
    {
        if(!visited[i])
        {
            visited[i]= true;
            sequence.push_back(lis[i]);
            dfs(depth+1, idx+1, cnt);
            sequence.pop_back();
            visited[i]= false;

        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    if(n>=1024) {cout<<-1; return 0;}
    for(int i =1; i<=9; i++)
    {
        dfs(0,0,i+1);

    }
    sort(res.begin(), res.end());
    cout<<res[n-1];

}