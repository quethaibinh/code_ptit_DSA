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
        queue<pair<int, int>> q;
        q.push({n, 0});
        while(!q.empty()){
            pair<int, int> tmp = q.front(); q.pop();
            int cnt = tmp.second;
            if(tmp.first == 1){
                cout << cnt << '\n';
                break;
            }
            if(tmp.first % 3 == 0) q.push({tmp.first/ 3, cnt + 1});
            if(tmp.first % 2 == 0) q.push({tmp.first / 2, cnt + 1});
            q.push({tmp.first - 1, cnt + 1});
        }
    }

    return 0;
}