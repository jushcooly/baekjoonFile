//
// Created by 서준혁 on 2/4/24.
//
#include<iostream>
#include<vector>
#include<algorithm>
int n,m;
int mp[504][504];
bool visited[504][504];
const int dy[]= {-1, 1, 0, 0};
const int dx[]= {0, 0, -1, 1};
int ans;
using namespace std;
void dfs(int y, int x, int depth, int sum)
{
    if(depth==3)
    {
        ans= max(ans, sum);
        return;
    }
    for(int i =0; i<4; i++)
    {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0||nx<0||ny>=n||nx>=m) continue;
        if(visited[ny][nx] ) continue;
        visited[ny][nx] = true;
        dfs(ny, nx, depth+1, sum+mp[ny][nx]);
        visited[ny][nx] = false;
    }
}
void case1(int r, int c) {
    int sum =0;
    sum= mp[r][c]+mp[r][c+1]+mp[r][c+2]+mp[r-1][c+1];
    ans = max(ans, sum);
}
void case2(int r, int c) {
    int sum =0;
    sum= mp[r][c]+mp[r][c+1]+mp[r][c+2]+mp[r+1][c+1];
    ans = max(ans, sum);
}
void case3(int r, int c) {
    int sum =0;
    sum= mp[r][c]+mp[r+1][c]+mp[r+2][c]+mp[r+1][c+1];
    ans = max(ans, sum);
}
void case4(int r, int c) {
    int sum =0;
    sum= mp[r][c]+mp[r-1][c+1]+mp[r][c+1]+mp[r+1][c+1];
    ans = max(ans, sum);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i =0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>mp[i][j];
        }
    }
    for(int i =0; i<n; i++)
    {
        for(int j =0; j<m; j++)
        {
            visited[i][j] = true;
            dfs(i,j,0, mp[i][j]);
            visited[i][j]= false;
            if(i-1>=0&&j+2<m) case1(i,j);
            if(i+1<n&&j+2<m) case2(i,j);
            if(i+2<n&&j+1<m) case3(i,j);
            if(i+1<n&&i-1>=0&&j+1<m) case4(i,j);

        }
    }
    cout<<ans;
    return 0;

}