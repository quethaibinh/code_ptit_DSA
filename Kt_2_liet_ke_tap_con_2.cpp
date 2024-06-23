#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, k;
vector<string> v;
set<string> se;

void tryy(int i, int bd, vector<string> vc){
    for(int j = bd; j <= n; j ++){
        vc.push_back(v[j]);
        if(i == k){
            string s;
            for(auto x : vc) s += x;
            se.insert(s);
        }
        else tryy(i + 1, j + 1, vc);
        vc.pop_back();
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    cin >> n >> k;
    v.push_back("");
    for(int i = 1; i <= n; i ++){
        string s; cin >> s;
        v.push_back(s);
    }
    tryy(1, 1, {});
    for(auto x : se) cout << x << '\n';

    return 0;
}