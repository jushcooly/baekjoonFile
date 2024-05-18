#include <iostream>
#include <queue>
using namespace std;

int r, c, mp[102][102], visited[102][102], boundaries[102][102];

int dy[] = {0, 1, 1, 0, -1, -1};
int dx1[] = {1, 1, 0, -1, 0, 1};
int dx2[] = {1, 0, -1, -1, -1, 0};

bool ok(int nx, int ny) {
    return nx > 0 && ny > 0 && nx <= c && ny <= r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;

    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= r; j++) {
            cin >> mp[i][j];
        }
    }

    int ans = 0;

    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= r; j++) {
            if (mp[i][j] == 1 && !visited[i][j]) {

                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = 1;

                while (!q.empty()) {
                    int a = q.front().first;
                    int b = q.front().second;
                    q.pop();

                    for (int k = 0; k < 6; k++) {
                        int nx = a + dy[k];
                        int ny;
                        if (a % 2 == 0) ny = b + dx2[k];
                        else ny = b + dx1[k];

                        if (ok(nx, ny) && mp[nx][ny] && !visited[nx][ny]) {
                            visited[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    boundaries[0][0] = 1;

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int k = 0; k < 6; k++) {
            int nx = a + dy[k];
            int ny;
            if (nx % 2) ny = b + dx1[k];
            else ny = b + dx2[k];

            if (nx >= 0 && nx <= c + 1 && ny >= 0 && ny <= r + 1 && !mp[nx][ny] && !boundaries[nx][ny]) {
                boundaries[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 1; i <= c; i++) {
        for (int j = 1; j <= r; j++) {
            if (!mp[i][j]) {
                for (int k = 0; k < 6; k++) {
                    int nx = i + dy[k];
                    int ny;
                    if (nx % 2) ny = j + dx1[k];
                    else ny = j + dx2[k];

                    if (boundaries[nx][ny]) ans++;
                }
            }
        }
    }

    cout << ans;

    return 0;
}
