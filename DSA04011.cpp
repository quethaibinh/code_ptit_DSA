#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll poww(int n){
    ll lt = 1;
    for(int i = 0; i < n; i ++) lt *= 2;
    return lt;
}

string tong(string s1, string s2){
    int du = 0;
    string sum = "";
    while(s1.size() < s2.size()) s1 = '0' + s1;
    while(s2.size() < s1.size()) s2 = '0' + s2;
    for(int i = s2.size() - 1; i >= 0; i --){
        int cur_s = (s1[i] - '0') + (s2[i] - '0') + du;
        sum = char(cur_s % 10 + '0') + sum;
        du = cur_s / 10;
    }
    if(du != 0) sum = '1' + sum;
    return sum;
}

string tich(string s1, string s2){
    string kq = "";
    for(int i = s1.size() - 1; i >= 0; i --){
        string cur_t = "";
        int x = s1[i] - '0';
        int du = 0;
        for(int j = s2.size() - 1; j >= 0; j --){
            cur_t = char((x * (s2[j] - '0') + du) % 10 + '0') + cur_t;
            du =  (x * (s2[j] - '0') + du) / 10;
        }
        if(du != 0) cur_t = char(du + '0') + cur_t;
        for(int j = s1.size() - 1 - i; j > 0; j --){
            cur_t = cur_t + '0';
        }
        kq = tong(kq, cur_t);
        // cout << kq << ' ' << cur_t << '\n';
    }
    return kq;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif        

    int t;
    cin >> t;
    while(t --){
        string s1, s2, s1_t = "", s2_t = "";
        cin >> s1 >> s2;
        for(int i = 0; i < s1.size(); i ++){
            if(s1[i] == '1') s1_t = tong(s1_t, to_string(poww(s1.size() - 1 - i)));
        }
        for(int i = 0; i < s2.size(); i ++){
            if(s2[i] == '1') s2_t = tong(s2_t, to_string(poww(s2.size() - 1 - i)));
        }
        // cout << s1_t << ' ' << s2_t << '\n';
        cout << tich(s1_t, s2_t) << '\n';
        // tich(s1_t, s2_t);
    }

    return 0;
}