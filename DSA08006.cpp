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

    queue<ll> q;
    int check[101];
    memset(check, 0, sizeof(check));
    q.push(9);
    int cnt = 0;
    while(!q.empty()){
        cnt ++;
        ll res = q.front(); q.pop();
        for(int i = 1; i <= 100; i ++){
            if(!check[i] && res % i == 0){
                check[i] = res;
            }
        }
        if(cnt == 1e5) break;
        q.push(res * 10);
        q.push(res * 10 + 9);
    }
    // for(int i = 1; i <= 100; i ++) cout << check[i] << '\n';
    int t; cin >> t;
    while(t --){
        int n; cin >> n;
        cout << check[n] << '\n';
    }

    return 0;
}