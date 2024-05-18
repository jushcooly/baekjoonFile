//
// Created by 서준혁 on 2/21/24.
//
#include<iostream>
#include <string.h>
#include <string>
using namespace std;
int t;
bool flag= false;
string s;
int mp[9][9];
vector<pair<int,int>> zeros;

bool WritingAns(pair<int,int> zero, int num)
{
    int y = zero.first/3;
    int x= zero.second/3;
    for(int i =0; i<9; i++)
    {
        if(zero.first!=i&&mp[i][zero.second]==num) return false;
    }
    for(int j =0; j<9; j++)
    {
        if(zero.first!=j&&mp[zero.first][j]==num) return false;

    }
    for(int i= 3*y; i<3*y+3; i++)
    {
        for(int j =3*x; j<3*x+3; j++)
        {
            if(!(zero.first==i&&zero.second==j)&&mp[i][j]==num) return false;

        }
    }
    return true;
}

void solve(int m)
{
    if(m==zeros.size())
    {
        bool chk= true;
        for(int y=0; y<3; y++)
        {
            for(int x=0; x<3; x++)
            {
                bool ok[10];
                memset(ok,false,sizeof(ok));
                for(int i=3*y; i<3*y+3; i++)
                {
                    for(int j =3*x; j<3*x+3; j++)
                    {
                        if(!ok[mp[i][j]]) ok[mp[i][j]]= true;
                        else chk= false;

                    }
                }

            }
        }
        if(!chk){
            flag =false;
            return;
        }
        for(int i=0; i<9; i++){
            for(int j =0;j<9; j++)
            {
                cout<<mp[i][j];
            }
            cout<<'\n';
        }
        flag= true;
        return;
    }
    pair<int,int> zero= zeros[m];
    for(int num=1; num<=9; num++)
    {
        if(WritingAns(zero,num)) solve(m+1);
        if(flag) return;
        mp[zero.first][zero.second]=0;

    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        flag =false;
        for(int i=0;i<9;i++)
        {
            cin>>s;
            for(int j=0;j<s.size(); j++)
            {
                mp[i][j]= s[j]-'0';
                if(!mp[i][j])
                {
                    zeros.push_back({i,j});
                }
            }
        }
        solve(0);
        if(!flag) cout<<"Could not complete this grid.\n";
        cout<<'\n';
    }
}