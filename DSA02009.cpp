#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n, k, x;
int used[1000006], a[1000006];
bool check;
void tryy(int cnt, int sum){
    if(cnt == k || check){
        check = true;
        return;
    }
    for(int j = 0; j < n; j ++){
        if(!used[j]){
            used[j] = 1;
            if(sum + a[j] <= x){
                if(sum + a[j] == x) tryy(cnt + 1, 0);
                else tryy(cnt + 1, sum + a[j]);
            }
            used[j] = 0;
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
    
    int t;
    cin >> t;
    while(t --){
        cin >> n >> k;
        int sum = 0;
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            sum += a[i];
        }
        if(sum % k == 0){
            x = sum / k;
            tryy(0, 0);
            if(check) cout << 1;
            else cout << 0;
        }
        else{
            cout << 0;
        }
        cout << '\n';
    }

    return 0;
}