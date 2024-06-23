#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

struct xoay{
    int as[2][3];
};

void xoayTrai(xoay &a){
    int tmp = a.as[0][0];
    a.as[0][0] = a.as[1][0];
    a.as[1][0] = a.as[1][1];
    a.as[1][1] = a.as[0][1];
    a.as[0][1] = tmp;
}

void xoayPhai(xoay &a){
    int tmp = a.as[0][1];
    a.as[0][1] = a.as[1][1];
    a.as[1][1] = a.as[1][2];
    a.as[1][2] = a.as[0][2];
    a.as[0][2] = tmp;
}

bool ss(int a1[2][3], int a2[2][3]){
    for(int i = 0; i < 2; i ++){
        for(int j = 0; j < 3; j ++){
            if(a1[i][j] != a2[i][j]) return false;
        }
    }
    return true;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int t; cin >> t;
    while(t --){
        int a[2][3], dich[2][3];
        int ans = 0;
        xoay startt;
        for(int i = 0; i < 2; i ++){
            for(int j = 0; j < 3; j ++){
                cin >> a[i][j];
                startt.as[i][j] = a[i][j];
            }
        }
        for(int i = 0; i < 2; i ++)
            for(int j = 0; j < 3; j ++) cin >> dich[i][j];
        queue<pair<xoay, int>> q;
        q.push({startt, 0});
        while(!q.empty()){
            pair<xoay, int> tmp = q.front(); q.pop();
            if(ss(dich, tmp.first.as)){
                ans = tmp.second;
                break;
            }
            xoay x = tmp.first, y = tmp.first;
            xoayTrai(x);
            xoayPhai(y);
            q.push({x, tmp.second + 1});
            q.push({y, tmp.second + 1});
        }
        cout << ans << '\n';
    }

    return 0;
}