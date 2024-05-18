//
// Created by 서준혁 on 2/18/24.
//
#include<iostream>
#include<string>
using namespace std;
int R,C;
int num =0;
string ans;
pair<int,int> charPos;
const int dy[]= {-1, 0, 1, 0};
const int dx[]= {0, -1, 0, 1};
string s;   char mp[16][16];
bool Finished()
{
    for(int i =0; i<R; i++)
    {
        for(int j =0; j<C; j++)
        {
            if(mp[i][j]=='b') return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(1)
    {

        cin>>R>>C;
        if(!R) return 0;

        memset(mp, 0, sizeof(mp));
        num++;

        for(int i =0; i<R; i++)
        {
            for(int j =0; j<C; j++)
            {
                cin>>mp[i][j];
                if(mp[i][j]=='W'||mp[i][j]=='w')
                {
                    charPos= {i,j};
                }
            }
        }
        cin>>s;
        for(int i =0;i<s.size(); i++)
        {
            pair<int,int> movePos;
            pair<int,int> boxMovePos;
            if(Finished())
            {
                ans= "complete";
                break;
            }
            if(s[i]=='L')
            {
                movePos= {charPos.first+dy[1], charPos.second+dx[1]};
                boxMovePos= {movePos.first+dy[1], movePos.second+dy[1]};
            }
            else if(s[i]=='U')
            {
                movePos= {charPos.first+dy[0], charPos.second+dx[0]};
                boxMovePos= {movePos.first+dy[0], movePos.second+dx[0]};

            }
            else if(s[i]=='D')
            {
                movePos= {charPos.first+dy[2], charPos.second+dx[2]};
                boxMovePos= {movePos.first+dy[2], movePos.second+dx[2]};
            }
            else if(s[i]=='R')
            {
                movePos= {charPos.first+dy[3], charPos.second+dx[3]};
                boxMovePos= {movePos.first+dy[3], movePos.second+dx[3]};
            }
            if(mp[movePos.first][movePos.second]=='.'||mp[movePos.first][movePos.second]=='+')
            {
                if(mp[charPos.first][charPos.second]=='w')
                    mp[charPos.first][charPos.second]='.';
                else if(mp[charPos.first][charPos.second]=='W')
                    mp[charPos.first][charPos.second]='+';
                if(mp[movePos.first][movePos.second]=='.')
                    mp[movePos.first][movePos.second]='w';
                else if(mp[movePos.first][movePos.second]=='+')
                    mp[movePos.first][movePos.second]= 'W';

                charPos= movePos;

            }

            if(mp[movePos.first][movePos.second]=='b'||mp[movePos.first][movePos.second]=='B')
            {
                if(mp[boxMovePos.first][boxMovePos.second]=='.'||mp[boxMovePos.first][boxMovePos.second]=='+')
                {
                    if(mp[boxMovePos.first][boxMovePos.second]=='.')
                        mp[boxMovePos.first][boxMovePos.second]= 'b';
                    else if(mp[boxMovePos.first][boxMovePos.second]=='+')
                        mp[boxMovePos.first][boxMovePos.second]= 'B';
                    if(mp[movePos.first][movePos.second]=='b')
                        mp[movePos.first][movePos.second]= '.';
                    else if(mp[movePos.first][movePos.second]=='B')
                        mp[movePos.first][movePos.second] ='+';
                    if(mp[charPos.first][charPos.second]=='w')
                        mp[charPos.first][charPos.second]= '.';
                    else if(mp[charPos.first][charPos.second]=='W')
                        mp[charPos.first][charPos.second]='+';
                    if(mp[movePos.first][movePos.second]=='.')
                        mp[movePos.first][movePos.second]= 'w';
                    else if(mp[movePos.first][movePos.second]=='+')
                        mp[movePos.first][movePos.second] ='W';
                    charPos= movePos;
                }

            }
            if(i==s.size()-1)
            {
                if(Finished())
                {
                    ans= "complete";
                    break;
                }
                else{
                    ans= "incomplete";
                    break;
                }
            }

        }
        cout<<"Game "<<num<<": "<<ans<<"\n";
        for(int i =0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                cout<<mp[i][j];
            }
            cout<<'\n';
        }




    }

}