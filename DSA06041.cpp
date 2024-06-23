#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif        

    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        int a[n + 1] = {};
        for(int i = 1; i <= n; i ++) cin >> a[i];
        sort(a + 1, a + n + 1);
        int max_f = 0, ans, cnt = 0;
        for(int i = 1; i <= n; i ++){
            if(a[i] == a[i - 1]) cnt += 1;   
            else cnt = 1;
            if(cnt > max_f){
                max_f = cnt;
                ans = a[i];
            }
        }
        if(max_f > n / 2) cout << ans;
        else cout << "NO";
        cout << '\n';
    }

    return 0;
}