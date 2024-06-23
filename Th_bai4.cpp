#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n, k;
int a[100005];
vector<vector<int>> v;
void in(){
    vector<int> vc;
    bool checkt = false;
    for(int i = k; i <= n; i ++){
        bool check = true;
        for(int j = 0; j < k; j ++){
            if(a[i - j] != 0) check = false;
        }
        if(check && checkt) return;
        if(check && !checkt) checkt = true; 
    }
    if(checkt){
        for(int i = 1; i <= n; i ++) vc.push_back(a[i]);
        v.push_back(vc);
    }
}
void tryy(int i){
    for(int j = 0; j <= 1; j ++){
        a[i] = j;
        if(i == n) in();
        else tryy(i + 1);
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
        tryy(1);
        cout << v.size() << '\n';
        for(auto x : v){
            for(auto y : x) cout << y << ' ';
            cout << '\n';
        }
        cout << '\n';
        v.clear();
    }

    return 0;
}