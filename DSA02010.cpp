#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n, k;
int a[1000006];
vector<vector<int>> v;
void tryy(int bd, int sum, vector<int> vc){
    for(int i = bd; i < n; i ++){
        if(sum + a[i] <= k){
            vc.push_back(a[i]);
            if(sum + a[i] == k) v.push_back(vc);
            else tryy(i, sum + a[i], vc);
            vc.pop_back();
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
        for(int i = 0; i < n; i ++) cin >> a[i];
        sort(a, a + n);
        tryy(0, 0, {});
        if(v.size() == 0) cout << -1 << '\n';
        else{
            for(auto x : v){
                cout << "[";
                for(int i = 0; i < x.size(); i ++){
                    if(i == x.size() - 1) cout << x[i];
                    else cout << x[i] << ' ';
                }
                cout << "]";
            }
        }
        cout << '\n';
        v.clear();
    }

    return 0;
}