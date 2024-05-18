//
// Created by 서준혁 on 1/28/24.
//
#include<iostream>
#include<string>
#include <cstring>
using namespace std;
int tc;
int n,m;
int mp[24][24];
int cMp[24][24];
bool okay = true;
const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[]= {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>tc;
    string s;
    while(tc--)
    {
        cin>>n>>m;
        memset(mp, 0, sizeof(mp));
        for(int i =0; i<n; i++)
        {
            cin>>s;
            for (int j = 0; j < m; ++j) {
                cMp[i][j] = s[j];
                if(cMp[i][j]!='F')
                {
                    cMp[i][j]= s[j]-'0';
                }
            }

        }
        for(int i =0;i <n; i++)
        {
            for(int j =0;j<m; j++)
            {
                if(cMp[i][j]=='F')
                {
                    mp[i][j]= 'F';
                    for(int k =0; k<8; k++)
                    {
                        int ny = i+dy[k];
                        int nx = j+dx[k];
                        if(ny<0||nx<0||ny>=n||nx>=m) continue;
                        mp[ny][nx]++;
                    }
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                cout<<mp[i][j];
                if(mp[i][j]!=cMp[i][j])
                {
                    okay = false;
                }
            }
            cout<<'\n';
        }
        if(okay) cout<<"Well done Clark!"<<'\n';
        else cout<<"Please sweep the mine again!"<<'\n';
        okay = true;
    }

}
