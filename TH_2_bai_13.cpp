#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int r[100006];
void init(){
    for(int i = 1; i <= 100000; i ++){
        r[i] = i;
    }
}

int get(int u){
    if(u == r[u]) return u;
    return r[u] = get(r[u]);
}

void uni(int u, int v){
    u = get(u);
    v = get(v);
    if(u == v) return;
    r[u] = v;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int q; cin >> q;
    init();
    while(q --){
        int x, y, t; cin >> x >> y >> t;
        if(t == 1){
            uni(x, y);
        }
        else{
            if(get(x) == get(y)) cout << 1 << '\n';
            else cout << '0' << '\n';
        }
    }

    return 0;
}