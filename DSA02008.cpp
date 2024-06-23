#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n, k, used[1000006], a[105][105];
vector<vector<int>> v;
void tryy(int i, int sum, vector<int> vc){
    for(int j = 1; j <= n; j ++){
        if(!used[j]){
            used[j] = 1;
            if(sum + a[i][j] <= k){
                vc.push_back(j);
                if(i == n && sum + a[i][j] == k) v.push_back(vc);
                else tryy(i + 1, sum + a[i][j], vc);
                vc.pop_back();
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
     
    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++) cin >> a[i][j];
    }
    tryy(1, 0, {});
    cout << v.size() << '\n';
    for(auto x : v){
        for(int i = 0; i < x.size(); i ++) cout << x[i] << ' ';
        cout << '\n';
    }

    return 0;
}