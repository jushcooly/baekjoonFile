//
// Created by 서준혁 on 2/19/24.
//
#include <iostream>
using namespace std;
typedef long long ll;
ll n,money, wage, G;
typedef struct{
    bool key =false;
    bool buy= false;
    ll p;
}land;
land mp[104];
pair<int,ll> gold[104];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin>>n>>money>>wage>>G;
    for(int i =0; i<G; i++)
    {
        int cmd;
        ll x;
        cin>>cmd>>x;
        gold[i]= {cmd,x};
    }
    for(int i=0; i<4*n-4; i++)
    {
        if(i%(n-1)==0) continue;
        char c[10];
        cin>>c;
        if(c[0]=='G')
        {
            mp[i].key =true;

        }
        else{
            ll l;
            cin>>l;
            mp[i].p= l;
        }
    }
    int cur =0,turn,idx=0,keyMove, island=-0;
    ll bankMoney =0;
    bool isMove =false;
    cin>>turn;
    while(turn--)
    {
        if(island)
        {
            island--;
            int d1, d2;
            cin>>d1>>d2;
            if(d1==d2) island=0;
            continue;


        }
        if(isMove)
        {
            cur+=keyMove;
            isMove= false;
            turn++;
        }

        else{
            int d1, d2;
            cin>>d1>>d2;
            cur+=d1+d2;

        }
        if(cur>=4*n-4)
        {
            while(cur>=4*n-4)
            {
                cur-=4*n-4;
                money+=wage;

            }
        }
        if(cur==0);
        else if(cur==n-1)
        {
            island=3;

        }
        else if(cur==2*n-2)
        {
            money+=bankMoney;
            bankMoney=0;
        }
        else if(cur==3*n-3)
        {
            cur=0;
            money+=wage;

        }
        else{
            if(mp[cur].key){
                pair<int,ll> curKey= gold[idx];
                idx= (idx+1)%G;
                if(curKey.first==1){
                    money+=curKey.second;

                }
                else if(curKey.first==2)
                {
                    money-=curKey.second;
                    if(money<0)
                    {
                        cout<<"LOSE";
                        return 0;
                    }

                }
                else if(curKey.first==3)
                {
                    money-=curKey.second;
                    if(money<0){
                        cout<<"LOSE";
                        return 0;
                    }
                    bankMoney+=curKey.second;

                }
                else{
                    isMove= true;
                    keyMove=curKey.second;

                }
            }
            else{
                if(!mp[cur].buy)
                {   if(money<mp[cur].p)
                    {
                        cout<<"LOSE";
                        return 0;
                    }    else{
                        mp[cur].buy= true;
                        money-=mp[cur].p;

                    }

                }

            }
        }
    }
    for(int i=0; i<4*n-4; i++)
    {
        if(i%(n-1)==0) continue;
        if(!mp[i].key&&!mp[i].buy)
        {
            cout<<"LOSE";
            return 0;
        }
    }
    cout<<"WIN";
}