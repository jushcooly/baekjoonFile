//
// Created by 서준혁 on 2/3/24.
//
#include<iostream>
#include <string>

using namespace std;
int n;
int ans;

struct Board {
    int mp[24][24];
    void rotate() {
        int temp[24][24];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = mp[n - j - 1][i];
            }
        }
        memcpy(mp,  temp, sizeof(mp));
    }

    void move() {
        int temp[24][24];
        for (int i = 0; i < n; i++) {
            int c = -1, chk = 0;
            for (int j = 0; j < n; j++) {
                if (mp[i][j] == 0) continue;
                if (chk && mp[i][j] == temp[i][c]) temp[i][c] *= 2, chk = 0;
                else temp[i][++c] = mp[i][j], chk = 1;
            }
            for(c++; c<n; ++c) temp[i][c]=0;

        }
        memcpy(mp, temp, sizeof(mp));

    }

    void getMax() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, mp[i][j]);

            }
        }
    }
};
void solve( Board b, int here)
{
    if(here==5) {
        b.getMax();
        return;
    }
    for(int i =0; i<4; i++)
    {
        Board bb= b;
        bb.move();
        solve(bb, here+1);
        b.rotate();
    }
    return;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    Board b;
    for(int i =0; i<n;i++)
    {
        for(int j =0; j<n; j++) cin>>b.mp[i][j];
    }
    solve(b, 0);
    cout<<ans<<'\n';

}
