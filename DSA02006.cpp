#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n, k;
int a[100005], a1[100005];
vector<vector<int>> v;
void chot(){
    vector<int> vx;
    int sum = 0;
    for(int i = 1; i <= n; i ++){
        if(a[i]) sum += a1[i];
    }
    if(sum == k){
        for(int i = 1; i <= n; i ++){
            if(a[i]) vx.push_back(a1[i]);
        }
        sort(vx.begin(), vx.end());
        v.push_back(vx);
    }
}
void tryy(int i){
    for(int j = 1; j >= 0; j --){
        a[i] = j;
        if(i == n) chot();
        else tryy(i + 1);
    }
}

bool cmp(vector<int> a, vector<int> b){
    for(int i = 0; i < min(a.size(), b.size()); i ++){
        if(a[i] != b[i]) return a[i] < b[i];
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
        cin >> n >> k;
        for(int i = 1; i <= n; i ++) cin >> a1[i];
        tryy(1);
        if(v.size() == 0) cout << "-1";
        else{
            sort(v.begin(), v.end(), cmp);
            for(auto x : v){
                cout << '[';
                for(int i = 0; i < x.size(); i ++){
                    if(i != x.size() - 1) cout << x[i] << ' ';
                    else cout << x[i];
                }
                cout << "] ";
            }
        }
        cout << '\n';
        v.clear();
    }                       
    
    return 0;
}