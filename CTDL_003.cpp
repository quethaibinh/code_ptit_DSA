#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<pair<int, pair<int, int>>> v;
vector<int> v1;
int n, w;
int a[10005], c[10005];
int Xopt[10005], X[10005], b;
float Fopt = 0, gk = 0, gt = 0;

void tryy(int i){
    for(int j = 1; j >= 0; j --){
        Xopt[i] = j;
        if(b - v[i].second.first * Xopt[i] >= 0){
            b -= v[i].second.first * Xopt[i];
            gt += v[i].first * Xopt[i];
            if(i != n) gk = gt + b * (v[i + 1].first * 1.0 / v[i + 1].second.first);
            if(gk >= Fopt){
                if(i == n && Fopt < gt){
                    memset(X, 0, sizeof(X));
                    Fopt = gt;
                    for(int i = 1; i <= n; i ++){
                        if(Xopt[i] == 1){
                            X[v[i].second.second] = 1;
                        }
                    }
                }
                else if(i != n) tryy(i + 1);
            }
            gt -= v[i].first * Xopt[i];
            b += v[i].second.first * Xopt[i];
        }
    }
}

bool cmp(pair<int, pair<int, int>> X1, pair<int, pair<int, int>> X2){
    return ((float)(X1.first) / X1.second.first) > ((float)(X2.first) / X2.second.first);
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif          

    cin >> n >> w;
    b = w;
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n; i ++) cin >> c[i];
    v.push_back({-1, {-1, 0}});
    for(int i = 0; i < n; i ++){
        v.push_back({a[i], {c[i], i + 1}});
    }
    sort(v.begin() + 1, v.end(), cmp);
    // for(auto x : v) cout << x.first << ' ' << x.second.first << '\n';
    tryy(1);
    cout << Fopt << '\n';
    for(int i = 1; i <= n; i ++) cout << X[i] << ' ';
    
    return 0;
}
