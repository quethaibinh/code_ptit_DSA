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
        int n; cin >> n;
        queue<string> q;
        vector<string> v;
        q.push("6");
        q.push("8");
        while(!q.empty()){
            string tes = q.front(); q.pop();
            if(tes.size() == n + 1) break;
            v.push_back(tes);
            q.push(tes + "6");
            q.push(tes + "8");
        } 
        reverse(v.begin(), v.end());
        for(auto i : v) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}