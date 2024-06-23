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
            string s1 = q.front(); q.pop();
            string s2 = s1;
            reverse(s2.begin(), s2.end());
            v.push_back(s1 + s2);
            cout << s1 + s2 << ' ';
            if(v.size() == n) break;
            q.push(s1 + "6");
            q.push(s1 + "8");
        }
        cout << '\n';
    }

    return 0;
}