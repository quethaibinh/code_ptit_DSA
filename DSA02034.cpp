#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n, used[100005];
string s;
int cuo;
void tryy(int i){
    for(int j = 1; j <= n; j ++){
        if(!used[j]){
            if(i != 1 && abs(j - (s[s.size() - 1] - '0')) == 1) continue;
            // cout << j << ' ' << (s[s.size() - 1] - '0') << '\n';
            used[j] = 1;
            s = s + char(j + '0');
            if(i == n) cout << s << '\n';
            else tryy(i + 1);
            cuo = j;
            s.pop_back();
            used[j] = 0;
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
        // cout << '\n';
    }    
    
    return 0;
}