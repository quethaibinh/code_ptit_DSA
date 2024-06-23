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
        int q; cin >> q;
        vector<int> v;
        while(q --){
            int n; cin >> n;
            if(n == 1){
                cout << v.size() << '\n';
            }
            if(n == 2){
                cout << (!v.size() ? "YES\n": "NO\n");
            }
            if(n == 3){
                int tex; cin >> tex;
                v.push_back(tex);
            }
            if(n == 4){
                if(v.size()) v.erase(v.begin());
            }
            if(n == 5){
                cout << (!v.size() ? -1 : v[0]);
                cout << '\n';
            }if(n == 6){
                cout << (!v.size() ? -1 : v[v.size() - 1]);
                cout << '\n';
            }
        }
    }

    return 0;
}