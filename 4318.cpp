//
// Created by 서준혁 on 2/16/24.
//
#include <iostream>
using namespace std;
long long s,x,y,dx,dy;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(1)
    {
        cin>>s>>x>>y>>dx>>dy;
        if(!s) break;
        int ret=0;
        while(ret<2001)
        {
            if(x%(2*s)>s&&(y+s)%(2*s)>s) break;
            if((x+s)%(2*s)>s&&y%(2*s)>s) break;
            ret++;
            x+=dx;
            y+=dy;

        }
        if(ret<2001) cout<< "After "<<ret<<" jumps the flea lends at ("<<x<<", "<<y<<").\n";
        else cout<<"The flea cannot escape from black squares\n";
    }
}
