#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int n, m;
int a[1005][1005];
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++) cin >> a[i][j];
    }
}

void DFS(int i, int j){
    a[i][j] = 0;
    for(int k = 0; k < 8; k ++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(a[i1][j1] && i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= m) DFS(i1, j1);
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int t; cin >> t;
    while(t --){
        input();
        int cnt = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                if(a[i][j]){
                    DFS(i, j);
                    cnt ++;
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}