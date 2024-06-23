#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;


int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int t; cin >> t;
    while(t --){
        int n; cin >> n;
        map<int, int> vis;
        queue<pair<int, int>> q;
        q.push({n, 0});
        vis[n] = 1;
        while(!q.empty()){
            pair<int, int> tmp = q.front(); q.pop();
            if(tmp.first == 1){
                cout << tmp.second << '\n';
                break;
            }
            for(int i = 2; i <= sqrt(tmp.first); i ++){
                if(tmp.first % i == 0 && !vis[tmp.first / i]){
                    vis[tmp.first / i] = 1;
                    q.push({tmp.first / i, tmp.second + 1});
                }
            }
            if(!vis[tmp.first - 1]){
                vis[tmp.first - 1] = 1;
                q.push({(tmp.first - 1), tmp.second + 1});
            }
        }
    }

    return 0;
}