#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n;
int a1[100005], a2[100005];
int used[10005];
vector<vector<int>> v1;
vector<string> v2;
void in1(){
    string s = "";
    for(int i = 1; i <= n; i ++) s.push_back(char(a1[i] - 1 + 'A'));
    v2.push_back(s);
    // for(int i = 1; i <= n; i ++) cout << a1[i];
    // cout << '\n';
}
void in2(){
    vector<int> vc;
    for(int i = 1; i <= n; i ++) vc.push_back(a2[i]);
    v1.push_back(vc);
}
void tryy(int i){
    for(int j = 1; j <= n; j ++){
        if(!used[j]){
            used[j] = 1;
            a1[i] = j;
            if(i == n) in1();
            else tryy(i + 1);
            used[j] = 0;
        }
    }
}
void tryy2(int i){
    for(int j = 1; j <= n; j ++){
        a2[i] = j;
        if(i == n) in2();
        else tryy2(i + 1);
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    cin >> n;
    tryy(1);
    tryy2(1);
    // for(auto x : v2) cout << x << '\n';
    // for(auto x : v1){
    //     for(auto y : x) cout << y;
    //     cout << '\n';
    // }
    for(auto x : v2){
        for(auto y : v1){
            cout << x;
            for(auto y1 : y) cout << y1;
            cout << '\n';
        }
    }

    return 0;
}