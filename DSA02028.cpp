#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n, k, s, dem;
int a[100005], used[100005];
void tryy(int sum, int cnt){
    if(cnt == k){
        dem += 1;
        return;
    }
    for(int i = 1; i <= n; i ++){
        if(!used[i]){
            used[i] = 1;
            if(sum + a[i] <= s){
                if(sum + a[i] == s) tryy(0, cnt + 1);
                else tryy(sum + a[i], cnt);
            }
            used[i] = 0;
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

    int tong = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        tong += a[i];
    }
    if(tong % k == 0){
        s = tong / k;
        tryy(0, 0);
        cout << dem;
    }
    else cout << 0;

    return 0;
}