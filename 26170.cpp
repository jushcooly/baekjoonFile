//
// Created by 서준혁 on 3/13/24.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int mp[5][5];
const int dy[]= {0,-1,0,1};
const int dx[]= {-1,0,1, 0};
void dfs(int y,int x,int cnt ,int &ap, vector<int>&ans)
{
    if(ap==3)
        ans.push_back(cnt);
    for(int i =0; i<4; i++)
    {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(nx<0||nx>=5||ny<0||ny>=5) continue;
        if(mp[ny][nx]==-1) continue;
        bool ok = false;
        if(mp[ny][nx]==1)
        {
            ok= true;
            ++ap;

        }
        int num = mp[y][x];
        mp[y][x]=-1;
        dfs(ny,nx, cnt+1, ap,ans);
        mp[y][x]= num;
        if(ok)
            --ap;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i =0; i<5; i++)
        for(int j=0; j<5; j++)
            cin>>mp[i][j];
    int y,x;
    cin>>y>>x;
    int ap=0;
    vector<int>ans;
    if(mp[y][x]==1)
        ap++;
    dfs(y,x, 0, ap, ans);
    if(ans.size()==0)
        cout<<-1<<'\n';
    else{
        sort(ans.begin(), ans.end());
        cout<<ans[0]<<'\n';

    }
    return 0;

}

