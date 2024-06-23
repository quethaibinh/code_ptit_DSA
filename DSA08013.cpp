#include<bits/stdc++.h>

using namespace std;

struct Point {
    int x, y, steps;
};

bool isValid(int x, int y, int N, const vector<vector<char>>& grid) {
    return x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == '.';
}

int bfs(int startX, int startY, int endX, int endY, int N, const vector<vector<char>>& grid) {
    queue<Point> q;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    
    q.push({startX, startY, 0});
    visited[startX][startY] = true;
    
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        
        if (current.x == endX && current.y == endY) {
            return current.steps;
        }
        
        for (auto dir : directions) {
            int newX = current.x;
            int newY = current.y;
            
            while (true) {
                newX += dir[0];
                newY += dir[1];
                
                if (!isValid(newX, newY, N, grid) || visited[newX][newY]) {
                    break;
                }
                
                if (!visited[newX][newY]) {
                    q.push({newX, newY, current.steps + 1});
                    visited[newX][newY] = true;
                }
            }
        }
    }
    
    return -1; // Just in case there's no path (although the problem guarantees there's always a valid path)
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 

    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<vector<char>> grid(N, vector<char>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> grid[i][j];
            }
        }
        
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        int result = bfs(a, b, c, d, N, grid);
        cout << result << endl;
    }
    
    return 0;
}



// code loi:
// #include<bits/stdc++.h>

// using namespace std;
// typedef pair<int, int> ii;
// #define ll long long
// const int MOD = 1e9 + 7;

// int n, s, t, x, y;
// int ans;
// bool check;
// char a[105][105];

// int dx[4] = {-1, 0, 1, 0};
// int dy[4] = {0, 1, 0, -1};

// void input(){
//     cin >> n;
//     check = false;
//     ans = 0;
//     for(int i = 0; i < n; i ++){
//         for(int j = 0; j < n; j ++){
//             cin >> a[i][j];
//         }
//     }
//     cin >> s >> t >> x >> y;
// }

// void BFS(int u, int v){
//     queue<pair<ii, ii>> q;
//     q.push({{u, v}, {0, 0}});
//     a[u][v] = 'X';
//     while(!q.empty()){
//         pair<ii, ii> tmp = q.front(); q.pop();
//         if(tmp.first.first == x && tmp.first.second == y){
//             check = true;
//             ans = tmp.second.second + 1;
//             break;
//         }
//         for(int i = 0; i < 4; i ++){
//             int cnt = tmp.second.second;
//             int x1 = tmp.first.first + dx[i];
//             int y1 = tmp.first.second + dy[i];
//             int stage = tmp.second.first;
//             if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && a[x1][y1] != 'X'){
//                 if(stage == 0){
//                     if(i == 0 || i == 2) stage = 1;
//                     else stage = 2;
//                 }
//                 else{
//                     if(stage == 1 && (i == 1 || i == 3)){
//                         // cout << x1 - dx[i] << ' ' << y1 - dy[i] << '\n';
//                         cnt ++;
//                         stage = 2;
//                     }
//                     if(stage == 2 && (i == 0 || i == 2)){
//                         // cout << x1 - dx[i] << ' ' << y1 - dy[i] << '\n';
//                         cnt ++;
//                         stage = 1;
//                     }
//                 }
//                 a[x1][y1] = 'X';
//                 q.push({{x1, y1}, {stage, cnt}});
//             }
//         }
//     }
// }

// int main(){
    
//     #ifndef ONLINE_JUDGE
//     freopen("nhap.txt", "r", stdin);
//     freopen("xuat.txt", "w", stdout);
//     #endif 
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);      

//     int t; cin >> t;
//     while(t --){
//         input();
//         if(s == x && t == y) cout << 0 << '\n';
//         else{
//             BFS(s, t);
//             if(check) cout << ans << '\n';
//             else cout << -1 << '\n';
//         }
//     }

//     return 0;
// }