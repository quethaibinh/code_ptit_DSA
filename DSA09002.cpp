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

    int n; cin >> n;
    vector<string> v(n + 1);
    vector<pair<int, int>> kq;
    cin.ignore();
    for(int i = 1; i <= n; i ++){
        getline(cin, v[i]);
    }
    for(int i = 1; i <= n; i ++){
        vector<int> check;
        string token;
        stringstream ss(v[i]);
        while(ss >> token) check.push_back(stoi(token));
        for(int j : check){
            // cout << j << ' ';
            if(j > i) kq.push_back({i, j});
        }
        // cout << '\n';
    }
    for(auto x : kq) cout << x.first << ' ' << x.second << '\n';

    return 0;
}