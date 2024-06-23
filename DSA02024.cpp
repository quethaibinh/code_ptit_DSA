#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n, a[1000006], a1[1000006];
vector<vector<int>> vx;
void in(){
    vector<int> v;
    v.push_back(-1);
    for(int i = 0; i < n; i ++){
        if(a[i] && a1[i] > v[v.size() - 1]) v.push_back(a1[i]);
        else if(a[i] && a1[i] <= v[v.size() - 1]) return;
    }
    v.erase(v.begin());
    if(v.size() >= 2){
        vx.push_back(v);
    }
}
void tryy(int i){
    for(int j = 0; j <= 1; j ++){
        a[i] = j;
        if(i == n - 1) in();
        else tryy(i + 1);
    }
}

bool cmp(vector<int> a, vector<int> b){
    string ax = "", bx = "";
    for(int i = 0; i < a.size(); i ++) ax += to_string(a[i]) + ' ';
    for(int i = 0; i < b.size(); i ++) bx += to_string(b[i]) + ' ';
    ax.pop_back();
    bx.pop_back();
    return ax < bx;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif       

    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a1[i];
    tryy(0);
    sort(vx.begin(), vx.end(), cmp);
    for(auto x : vx){
        for(auto y : x) cout << y << ' ';
        cout << '\n';
    }
    
    return 0;
}