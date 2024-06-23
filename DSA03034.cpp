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
        int m, n, k;
        bool check = false;
        map<int, int> mp1, mp2, mp3;
        cin >> m >> n >> k;
        int a[m + 1], b[n + 1], c[k + 1];
        for(int i = 1; i <= m; i ++){
            cin >> a[i];
            mp1[a[i]] ++;
        }
        for(int i = 1; i <= n; i ++){
            cin >> b[i];
            mp2[b[i]] ++;
        }
        for(int i = 1; i <= k; i ++){
            cin >> c[i];
            mp3[c[i]] ++;
        }
        for(auto x : mp1){
            if(mp2.find(x.first) != mp2.end() && mp3.find(x.first) != mp3.end()){
                check = true;
                for(int i = 0; i < min(x.second, min(mp2[x.first], mp3[x.first])); i ++){
                    cout << x.first << ' ';
                }
            }
        }
        if(!check) cout << "NO";
        cout << '\n';
    }

    return 0;
}