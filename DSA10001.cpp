#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;

int n, m;
char a[505][505];
int vis[505][505];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct State {
    int x, y, direction, turns;
};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '*' && !vis[x][y];
}

void solve(int startX, int startY, int targetX, int targetY) {
    queue<State> q;

    // Initialize BFS queue with all four possible directions from the start
    for (int d = 0; d < 4; ++d) {
        int nx = startX + dx[d];
        int ny = startY + dy[d];
        if (isValid(nx, ny)) {
            q.push({nx, ny, d, 0});
            vis[nx][ny] = 1;
        }
    }

    bool found = false;

    while (!q.empty()) {
        State cur = q.front(); q.pop();

        if (cur.x == targetX && cur.y == targetY) {
            found = true;
            break;
        }

        for (int d = 0; d < 4; ++d) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];
            int newTurns = cur.turns + (d != cur.direction);

            if (isValid(nx, ny) && newTurns <= 2) {
                vis[nx][ny] = 1;
                q.push({nx, ny, d, newTurns});
            }
        }
    }

    if (found) cout << "YES\n";
    else cout << "NO\n";
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        int startX, startY, targetX, targetY;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                if (a[i][j] == 'S') {
                    startX = i;
                    startY = j;
                }
                if (a[i][j] == 'T') {
                    targetX = i;
                    targetY = j;
                }
            }
        }
        solve(startX, startY, targetX, targetY);
    }

    return 0;
}
