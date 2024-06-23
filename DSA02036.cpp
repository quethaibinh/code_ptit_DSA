#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n, a[1000006];
vector<vector<int>> v;
void tryy(int bd, int sum, vector<int> vc){
    for(int j = bd; j < n; j ++){
        vc.push_back(a[j]);
        if((sum + a[j]) % 2 != 0){
            v.push_back(vc);
        }
        tryy(j + 1, sum + a[j], vc);
        vc.pop_back();
    }
}

bool cmp(int a, int b){
    return a > b;
}
bool cmp2(vector<int> a, vector<int> b){
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
        sort(a, a + n, cmp);
        tryy(0, 0, {});
        sort(v.begin(), v.end(), cmp2);
        for(auto x : v){
            for(int i = 0; i < x.size(); i ++) cout << x[i] << ' ';
            cout << '\n';
        }
        v.clear();
    } 

    return 0;
}