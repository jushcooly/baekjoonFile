#include<iostream>
#include<vector>
using namespace std;
int originMp[9][9];
pair<int,int> mp[9][9];
vector<int> bulletList;
vector<int> visited;
int n,k;
int ans =0;
const int dy[]= {-1, 0, 1, 0};
const int dx[]= {0, 1, 0, -1};
void MakingMp(int y, int x)
{
    for(int i =0; i<4; i++)
    {
        int ny = y+dy[i];
        int nx =x+dx[i];
        if(mp[ny][nx].first>0||ny<0||ny>=n||nx<0||nx>=n) continue;
        mp[ny][nx]= {mp[y][x].first/4, mp[y][x].first/4};
    }
}
void simulating()
{
    int score =0;
    for(int i =0; i<visited.size(); i++)
    {
        int row = visited[i];
        int bullet = bulletList[i];

        for(int j =0; j<n; j++)
        {
            if(mp[row][j].second>=1)
            {
                if(mp[row][j].first>=10)
                {
                    score+=mp[row][j].first;
                    mp[row][j]= {0,0};
                    break;
                }
                else{
                    if(mp[row][j].second>bullet)
                    {
                        mp[row][j].second-=bullet;
                        break;
                    }
                    else{
                        score+=mp[row][j].first;
                        MakingMp(row, j);
                        mp[row][j]= {0, 0};
                        break;
                    }
                }
            }
        }
    }
    ans = max(ans, score);
}

void Init()
{
    for(int i =0; i<n; i++)
    {
        for(int j =0;j <n; j++)
        {
            mp[i][j].first= originMp[i][j];
            mp[i][j].second= mp[i][j].first;

        }
    }
}
void solve(int cnt)
{
    if(cnt==bulletList.size())
    {
        Init();
        simulating();
        return;

    }
    for(int i =0; i<n; i++)
    {
        visited.push_back(i);
        solve(cnt+1);
        visited.pop_back();
    }
}

int main()
{
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        for(int j =0;j <n; j++)
        {
            cin>>mp[i][j].first;
            mp[i][j].second = mp[i][j].first;
            originMp[i][j]= mp[i][j].first;

        }
        for(int i =0; i<k; i++)
        {
            int a;
            cin>>a;
            bulletList.push_back(a);
        }
    }
    solve(0);
    cout<<ans;
}