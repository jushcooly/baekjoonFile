//
// Created by 서준혁 on 2/28/24.
//
#include<iostream>
using namespace std;
int n;
int num[11];
void dfs(int cnt, int nx) {
    if (cnt == n) {
        for (int i = 0; i < n; i++)
            cout << num[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        bool can = true;
        num[cnt] = i;
        for (int j = 0; j < cnt; j++) {
            if (num[j] == num[cnt]) {
                can = false;
            }
        }
        if (can) {
            if (num[cnt - 1] < num[cnt] && num[cnt] < nx)
                break;
        }
        if (can) {
            if (nx <= num[cnt]) {
                dfs(cnt + 1, num[cnt] + 1);
            } else {
                dfs(cnt + 1, nx);

            }
        }
    }
}
int main()
{
    cin>>n;
    dfs(0,0);

}