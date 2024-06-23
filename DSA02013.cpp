#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, p, s;
int cnt;
vector<vector<int>> v;
int nt[205];
void snt(){
    for(int i = 2; i <= 200; i ++) nt[i] = 1;
    for(int i = 2; i <= sqrt(200); i ++){
        if(nt[i]){
            for(int j = i * i; j <= 200; j += i){
                nt[j] = 0;
            }
        }
    }
}

void tryy(int i, int bd, int curSum, vector<int> vec){
    for(int j = bd; j <= 200; j ++){
        if(nt[j]){
            // cout << j << '\n';
            // break;
            vec.push_back(j);
            curSum += j;
            if(i == n && curSum == s){
                cnt ++;
                v.push_back(vec);
            }
            else if (curSum < s) tryy(i + 1, j + 1, curSum, vec);
            vec.pop_back();
            curSum -= j;
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

    snt();
    // for(int i = 1; i <= 200; i ++) cout << nt[i] << ' ';
    int t; cin >> t;
    while(t --){
        cin >> n >> p >> s;
        cnt = 0;
        v.clear();
        tryy(1, p + 1, 0, {});
        cout << cnt << '\n';
        for(auto i : v){
            for(auto j : i) cout << j << ' ';
            cout << '\n';
        }
    }

    return 0;
}