#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n;
vector<string> v;
set<string> se;

void tryy(int i, int bd, vector<string> vs){
    for(int j = bd; j <= n; j ++){
        // cout << v[j] << '\n';
        vs.push_back(v[j]);
        string s;
        for(auto k : vs) s += k;
        // cout << s << '\n';
        se.insert(s);
        if(i == n) break;
        else tryy(i + 1, j + 1, vs);
        vs.pop_back();
    }
}


int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    cin >> n;
    v.push_back("");
    for(int i = 1; i <= n; i ++){
        string s;
        cin >> s;
        v.push_back(s);
    }
    // for(auto x : v) cout << x << ' ';
    tryy(1, 1, {});
    for(auto x : se) cout << x << '\n';

    return 0;
}