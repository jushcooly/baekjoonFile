//
// Created by 서준혁 on 2/1/24.
//
#include<iostream>
#include<vector>
using namespace std;
int B, n, m;
int ans=0;
bool mp[104][104];
int isWorker[104][104];
const int dy[]= {-1, 0, 1, 0};
const int dx[]= {0, 1, 0, -1};
struct Worker{
    int y, x, fullTime, t;
    bool isWorking= false;

};

vector<Worker> v;
void Working(int y, int x)
{
    for(int i =0; i<4; i++)
    {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0||nx<0||ny>=B||nx>=B) continue;
        if(isWorker[ny][nx]&&v[isWorker[ny][nx]].isWorking==false)
        {

            mp[y][x] =0;
            m--;
            ans++;
            v[isWorker[ny][nx]].isWorking= true;
            break;

        }

    }
}
void MachineWorking()
{
    if(mp[B-1][0])
    {
        m--;
        mp[B-1][0]= false;
    }
    for(int i =1; i<B; i++) {
        mp[B-1][i-1]= mp[B-1][i];

    }
    for(int i = B-2; i>=0; i--) mp[i+1][B-1]= mp[i][B-1];
    for(int i =B-2; i>=0; i--) mp[0][i+1] = mp[0][i];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>B>>n>>m;
    v.resize(n+1);
    for(int i =1; i<=n; i++)
    {
        cin>>v[i].y;
        cin>>v[i].x;
        cin>>v[i].fullTime;
        v[i].t= v[i].fullTime;
        v[i].isWorking= false;
        isWorker[v[i].y][v[i].x] = i;


    }
    int gift = m;
    while(m)
    {
        MachineWorking();
        if(gift>0){
            mp[0][0]= true;
            gift--;
        }
        else mp[0][0]= false;

        for(int i =0; i<B; i++)
        {
            if(mp[B-1][i]) Working(B-1, i);

        }
        for(int i =B-2; i>=0; i--)
        {

            if(mp[i][B-1]) Working(i, B-1);
        }
        for(int i =B-2; i>=0; i--)
        {
            if(mp[0][i]) Working(0, i);

        }

        for(int i =1; i<=n; i++)
        {
            if(v[i].isWorking)
            {
                v[i].t--;
                if(v[i].t==0)
                {
                    v[i].isWorking= false;
                    v[i].t= v[i].fullTime;

                }
            }
        }
    }
    cout<<ans;


}