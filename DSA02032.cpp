#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n, x;
int a[1000006];
vector<vector<int>> v;

void tryy(int sum, int bd, vector<int> vc){
    for(int j = bd; j < n; j ++){
        if(sum + a[j] <= x){
            vc.push_back(a[j]);
            if(sum + a[j] == x){
                // sort(vc.begin(), vc.end());
                v.push_back(vc);
                return;
            }
            tryy(sum + a[j], j, vc);
            vc.pop_back();
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
        cin >> n >> x;
        for(int i = 0; i < n; i ++) cin >> a[i];
        sort(a, a + n);
        tryy(0, 0, {});
        if(v.size() != 0){
            cout << v.size() << ' ';
            for(auto X : v){
                cout << "{";
                for(int i = 0; i < X.size(); i ++){
                    if(i != X.size() - 1) cout << X[i] << ' ';
                    else cout << X[i];
                }
                cout << "} ";
            }
        }
        else cout << -1;
        v.clear();
        cout << '\n';
    } 

    return 0;
}