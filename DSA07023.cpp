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
    cin.ignore();
    while(t --){
        string s; getline(cin, s);
        string token;
        vector<string> v;
        stringstream ss(s);
        while(ss >> token) v.push_back(token);
        reverse(v.begin(), v.end());
        for(string x : v) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}