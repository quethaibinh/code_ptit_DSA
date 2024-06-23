#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n, a[100][100];
vector<string> v;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
string s = "DLRU";
string sx = "";
void tryy(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < n){
        if(x == n - 1 && y == n - 1) v.push_back(sx);
        if(a[x][y]){
            a[x][y] = 0;
            for(int i = 0; i < 4; i ++){
                if(a[x + dx[i]][y + dy[i]]){
                    sx = sx + s[i];
                    tryy(x + dx[i], y + dy[i]);
                    sx.pop_back();
                }
            }
            a[x][y] = 1;
        }
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif      

    int t;
    cin >> t;
    while(t --){
        cin >> n;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++) cin >> a[i][j];
        }
        tryy(0, 0);
        if(v.size() == 0) cout << "-1\n";
        else{
            sort(v.begin(), v.end());
            for(auto x : v) cout << x << ' ';
            cout << '\n';
            v.clear();
        }
    }                   
    
    return 0;
}