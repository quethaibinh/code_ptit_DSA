#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n;
vector<string> v;
int vis[1005];
int ans;
int kq[1005];


void tryy(int i, int same){
    for(int j = 1; j <= n; j ++){
        if(!vis[j]){
            vis[j] = 1;
            kq[i] = j;
            vector<int> check(200, 0); // luu ma cua ki tu
        int cnt = 0;
        for(char i1 : v[kq[i - 1]]) check[i1] ++;
        for(char i1 : v[j]) check[i1] ++;
        for(int i = 'A'; i <= 'Z'; i ++)
            if(check[i] > 1) cnt ++;
            if(same + cnt < ans){
                if(i == n) ans = min(ans, same + cnt);
                else tryy(i + 1, same + cnt);
            }
            vis[j] = 0;
        }
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
    ans = INT_MAX;
    v.push_back("");
    for(int i = 1; i <= n; i ++){
        string s; cin >> s;
        v.push_back(s);
    }
    tryy(1, 0);
    cout << ans << '\n';

    return 0;
}