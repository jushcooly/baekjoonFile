//
// Created by 서준혁 on 1/31/24.
//
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
struct A{
    string shape, color, background;
};
struct B
{
    int a,b,c;
};
vector<A> group;
vector<B> v;
int visited[104];
bool G= false;

int n, ans;
string say;
bool Same(string a, string b, string c)
{
    if((a==b)&&(b==c)&&(c==a)) return true;
    return false;
}
bool NotSame(string a, string b, string c)
{
    if((a!=b)&&(b!=c)&&(c!=a)) return true;
    return false;
}
void preSet()
{
    for(int i =1; i<=9; i++)
    {
        for(int j =i+1; j<=9; j++)
        {
            for(int k =j+1; k<=9; k++)
            {
                bool ok = true;
                if((!(Same(group[i].shape, group[j].shape, group[k].shape))&&(
                        !NotSame(group[i].shape, group[j].shape, group[k].shape))))
                    ok=  false;

                if((!(Same(group[i].color, group[j].color, group[k].color))&&
                (!NotSame(group[i].color, group[j].color, group[k].color))))
                    ok= false;

                if((!(Same(group[i].background, group[j].background, group[k].background))&&(
                        !NotSame(group[i].background, group[j].background, group[k].background))))
                    ok= false;
               if(ok)
               {
                   v.push_back({i,j,k});
               }

            }
        }
    }
}
bool GetHap(int a, int b, int c)
{
    for(int i =0; i<v.size(); i++)
    {
        if((v[i].a==a)&&(v[i].b==b)&&(v[i].c==c)&&(!visited[i]))
        {
            visited[i]= true;
            return true;
        }


    }
    return false;
}
bool GetGyul()
{
    for(int i =0; i<v.size(); i++)
    {
        if(!visited[i]) return false;

    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    group.resize(10);
    for(int i =1; i<=9; i++)
    {
        cin>>group[i].shape;
        cin>>group[i].color;
        cin>>group[i].background;

    }
    preSet();
    cin>>n;
    for(int i =0; i<n; i++)
    {
        cin>>say;
        if(say=="H")
        {
            int a,b,c;cin>>a>>b>>c;

            int threeNim[3]= {a,b,c};
            sort(threeNim, threeNim+3);
            bool right = GetHap(threeNim[0], threeNim[1], threeNim[2]);
            if(right) ans++;
            else ans--;
        }
        else if(say=="G")
        {
            bool right = GetGyul();
            if(right&&!G)
                G= true, ans+=3;
            else ans--;
        }

    }
    cout<<ans;
}