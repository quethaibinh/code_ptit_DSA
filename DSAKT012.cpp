#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n, s, cnt_len;
int a[1000006];
bool check;
void tryy(int bd, int sum, int cnt){
    for(int j = bd; j < n; j ++){
        if(sum + a[j] <= s){
            if(sum + a[j] == s){
                check = true;
                cnt_len = min(cnt_len, cnt + 1);
                // cout << cnt << '\n';
            }
            else tryy(j + 1, sum + a[j], cnt + 1);
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
    
    cnt_len = INT_MAX;
    cin >> n >> s;
    for(int i = 0; i < n; i ++) cin >> a[i];
    tryy(0, 0, 0);
    if(check) cout << cnt_len;
    else cout << -1;

    return 0;
}