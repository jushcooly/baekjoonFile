#include <iostream>
#include<vector>
#include<string>

using namespace std;
struct Zombie{
    int y,x,dir;
};
int n;
string A;
int dir =0;
pair<int,int> p;
int dy[]= {1, 0, -1, 0};
int dx[]= {0, -1, 0, 1};
int mp[20][20];
vector<Zombie> zombies;
bool light[20][20];
bool enlightend[20][20];
bool ans = false;

void input()
{
    cin>>n;
    cin>>A;
    for(int i =0; i<n; i++)
    {
        string s;
        cin>>s;
        for(int j =0; j<s.size(); j++)
        {
            if(s[j]=='S')
            {
                light[i][j] = true;
            }
            else if(s[j]=='Z')
            {
                zombies.push_back({i,j,0});
                mp[i][j] =1;

            }
        }
    }
}
void lightingMp(int y,int x)
{
    const int ddy[]= {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    const int ddx[]= {-1, 0, 1, -1, 0, 1,-1, 0, 1};
    for(int i =0;i<9; i++)
    {
        enlightend[y+ddy[i]][x+ddx[i]]= true;
    }
}
void zombieMove(){
    for(int i =0; i<zombies.size(); i++)
    {
        int ny = zombies[i].y+dy[zombies[i].dir];
        int nx = zombies[i].x+dx[zombies[i].dir];
        if(ny<0||nx<0||ny>=n||nx>=n)
        {
            if(zombies[i].dir==0){
                zombies[i].dir=2;

            }
            else {
                zombies[i].dir=0;
            }
            continue;

        } zombies[i].y= ny;
        zombies[i].x =nx;
    }
    for(int i =0;i<n; i++)
    {
        for(int j =0; j<n; j++)
        {
            mp[i][j] =0;

        }
    }
    for(int i =0;i<zombies.size(); i++)
    {
        int cury = zombies[i].y;
        int curx= zombies[i].x;
        mp[cury][curx]= 1;

    }
}
void solve()
{
    p= {0,0};
    for(int i =0; i<A.size(); i++)
    {
        if(A[i]=='F')
        {
            int ny = p.first+dy[dir];
            int nx =p.second+dx[dir];
            if(ny>=0&&nx>=0&&ny<n&&nx<n)
            {
                p= {ny,nx};
                if(light[p.first][p.second])
                {
                    lightingMp(p.first, p.second);
                }
                if(mp[p.first][p.second]==1)
                {
                    if(!enlightend[p.first][p.second]&&!light[p.first][p.second])
                    {
                        ans =true;
                    }
                }
            }

        }
        else if(A[i]=='L')
        {
            dir--;
            if(dir<0)
            {
                dir=3;
            }

        }
        else if(A[i]=='R')
        {
            dir++;
            if(dir>3)
            {
                dir =0;
            }
        }
        zombieMove();
        if(mp[p.first][p.second]==1)
        {
            if(!enlightend[p.first][p.second]&&mp[p.first][p.second]!=2)
            {
                ans = true;
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    solve();
    if(ans) cout<<"Aaaaaah!";
    else cout<<"Phew...";
}