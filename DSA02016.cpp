#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n, cnt;
int used[1000006], cheo1[1000006], cheo2[1000006];
void tryy(int i){
    for(int j = 1; j <= n; j ++){
        if(!used[j] && !cheo1[i + j - 1] && !cheo2[n + i - j]){
            used[j] = 1;
            cheo1[i + j - 1] = 1;
            cheo2[n + i - j] = 1;
            if(i == n) cnt ++;
            else tryy(i + 1);
            used[j] = 0;
            cheo1[i + j - 1] = 0;
            cheo2[i - j + n] = 0;
        }
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif              

    int t;
    cin >> t;
    while(t --){
        cin >> n;
        tryy(1);
        cout << cnt << '\n';
        cnt = 0;
    }           
    
    return 0;
}