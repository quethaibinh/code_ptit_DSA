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
        q.push("1");
        int cnt = 0;
        while(!q.empty()){
            string tex = q.front(); q.pop();
            cnt ++;
            cout << tex << ' ';
            if(cnt == n) break;
            q.push(tex + "0");
            q.push(tex + "1");
        }
        cout << '\n';
    }

    return 0;
}