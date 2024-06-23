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
        int v, e; cin >> v >> e;
        vector<pair<int, int>> V(e + 1);
        vector<int> kq[1000];
        for(int i = 1; i <= e; i ++){
            cin >> V[i].first >> V[i].second;
            kq[V[i].first].push_back(V[i].second);
        }
        for(int i = 1; i <= v; i ++){
            cout << i << ": ";
            for(int j = 0; j < kq[i].size(); j ++) cout << kq[i][j] << ' ';
            cout << '\n';
        }
    }

    return 0;
}