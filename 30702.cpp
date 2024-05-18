//
// Created by 서준혁 on 3/27/24.
//
#include<iostream>
#include<string>
#include<queue>

using namespace std;
int n,m,cnt=1;
string mp1[52],mp2[52];
int vis1[52][52], vis2[52][52];
queue<pair<int,int>> q;


const int dy[]= {1,0,-1,0};
const int dx[]= {0,1,0,-1};
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i =0; i<n; i++) cin>>mp1[i];
    for(int i=0; i<n; i++) cin>>mp2[i];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(vis1[i][j]>0) continue;
            q.push({i,j});
            vis1[i][j]= cnt;
            while(q.size())
            {
                auto cur = q.front();
                q.pop();
                for(int k =0; k<4; k++)
                {
                    int ny= cur.first+dy[k];
                    int nx = cur.second+dx[k];
                    if(ny<0||nx<0||ny>=n||nx>=n) continue;
                    if(vis1[ny][nx]>0||mp1[ny][nx]!=mp1[cur.first][cur.second]) continue;
                    vis1[ny][nx]= cnt;
                    q.push({ny,nx});
                }
            }
            cnt++;
        }
    cnt=1;
    for(int i =0; i<n; i++)
        for(int j =0; j<m; j++)
        {
            if(vis2[i][j]>0) continue;
            q.push({i,j});
            vis2[i][j]= cnt;
            while(q.size())
            {
                auto cur = q.front();
                q.pop();
                for(int k =0; k<4; k++)
                {
                    int ny= cur.first+dy[k];
                    int nx = cur.second+dx[k];
                    if(ny<0||ny>=n||nx<0||nx>=n) continue;
                    if(vis2[ny][nx]>0||mp2[ny][nx]!=mp2[cur.first][cur.second]||vis1[ny][nx]!=vis1[cur.first][cur.second])
                        continue;
                    vis2[i][j]= cnt;
                    q.push({ny,nx});
                }
            }
            cnt++;
        }
    for(int i =0; i<n; i++)
    {
        for(int j =0; j<m; j++)
        {
            if(vis1[i][j]!=vis2[i][j]){
                cout<<"NO"<<'\n';
                return 0;
            }
        }
    }
    cout<<"YES"<<'\n';
}