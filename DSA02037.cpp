#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n, a[1000006];
vector<vector<int>> v;
bool check_nt(int n){
    if(n == 0 || n == 1) return false;
    for(int i = 2; i <= sqrt(n); i ++){
        if(n % i == 0) return false;
    }
    return true;
}

void tryy(int bd, int sum, vector<int> vc){
    for(int j = bd; j < n; j ++){
        vc.push_back(a[j]);
        if(check_nt(sum + a[j])) v.push_back(vc);
        tryy(j + 1, sum + a[j], vc);
        vc.pop_back();
    }
}

bool cmp1(int a, int b){
    return a > b;
}
bool cmp(vector<int> a, vector<int> b){
    return a < b;
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
        for(int i = 0; i < n; i ++) cin >> a[i];
        sort(a, a + n, cmp1);
        tryy(0, 0, {});
        sort(v.begin(), v.end(), cmp);
        for(auto x : v){
            for(int i = 0; i < x.size(); i ++) cout << x[i] << ' ';
            cout << '\n';
        }
        v.clear();
    }    

    return 0;
}