#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;
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
        int n; cin >> n;
        vector<pair<int, int>> pa(n + 1);
        int maxx  = 0;
        for(int i = 1; i <= n; i ++){
            int x; cin >> x;
            cin >> pa[i].first >> pa[i].second;
            maxx = max(maxx, pa[i].first);
        }
        sort(pa.begin() + 1, pa.end(), cmp);
        int check[maxx + 1];
        pair<int, int> ans = {0, 0};
        memset(check, 0, sizeof(check));
        // for(auto x : pa) cout << x.first << ' ' << x.second << '\n';
        for(int i = 1; i <= n; i ++){
            for(int j = pa[i].first; j >= 1; j --){
                if(!check[j]){
                    check[j] = 1;
                    ans.first ++;
                    ans.second += pa[i].second;
                    break;
                }
            }
        }
        cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}