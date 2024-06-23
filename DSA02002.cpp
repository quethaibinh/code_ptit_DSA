#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<vector<int>> v;
void solve(int a[], int n){
    while(1){
        vector<int> vx;
        for(int i = 0; i < n; i ++) vx.push_back(a[i]);
        v.push_back(vx);
        if(n == 1) return;
        for(int i = 0; i < n - 1; i ++) a[i] += a[i + 1];
        n -= 1;
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
        int n;
        cin >> n;
        int a[n];
        for(auto &x : a) cin >> x;
        // for(auto x : a) cout << x << ' ';
        solve(a, n);
        for(int i = n - 1; i >= 0; i --){
            cout << '[';
            for(int j = 0; j < v[i].size(); j ++){
                if(j != v[i].size() - 1) cout << v[i][j] << ' ';
                else cout << v[i][j];
            }
            cout << "] ";
        }
        cout << '\n';
        v.clear();
    }                        
    
    return 0;
}