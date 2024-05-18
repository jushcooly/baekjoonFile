//
// Created by 서준혁 on 2/28/24.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
typedef long long ll;
ll n= 1ll<<11, diff=-1;
string res;

string s;
int sz;
vector<int> perm(10);
ll calc(string s,string tmp)
{
    int SZ= s.size();
    ll p =1;
    for(int i =0; i<SZ; i++) p*=10;
    ll st= stoll(s);
    ll Tmp = stoll(tmp);
    ll cal= abs(st-Tmp);
    return min(cal,p-cal);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>s;
    sz= s.size();

    for(int i =0; i<10; i++) perm[i]= i;
    while(1)
    {

        string tmp;
        for(int i =0; i<sz; i++){
            tmp+=(char)('0'+perm[i]);

        }
        ll d= calc(s,tmp);
        if(diff<d)
        {
            diff= d;
            ll t = stoll(tmp);
            res = tmp;
            n= t;


        }
        else if(diff==d)
        {
            ll t = stoll(tmp);
            if(t<n)
            {
                res= tmp;
                n=t;
            }
        }
        if(!next_permutation(perm.begin(), perm.end()))
            break;
    }
    cout<<res<<'\n';



}