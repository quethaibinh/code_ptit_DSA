#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

void chuanhoa(string s1, vector<pair<ll, ll>> &hso_mu){
    string s = "";
    for(int i = 0; i < s1.size(); i ++){
        if(s1[i] >= '0' && s1[i] <= '9') s += s1[i];
        else s += ' ';
    }   
    string token;
    stringstream ss(s);
    vector<ll> v;
    while(ss >> token){
        v.push_back(stoll(token));
    }
    int hso, mu;
    for(int i = 0; i < v.size(); i ++){
        if(i % 2 == 0) hso = v[i];
        else{
            mu = v[i];
            hso_mu.push_back({hso, mu});
        }
    }
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    return a.second < b.second; 
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int t; cin >> t;
    cin.ignore();
    while(t --){
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        vector<pair<ll, ll>> hso_mu1, hso_mu2;
        chuanhoa(s1, hso_mu1);
        chuanhoa(s2, hso_mu2);
        sort(hso_mu1.begin(), hso_mu1.end(), cmp);
        sort(hso_mu2.begin(), hso_mu2.end(), cmp);
        
        vector<pair<ll, ll>> kq;
        int u = 0, d = 0;
        while(u < hso_mu1.size() && d <= hso_mu2.size()){
            if(hso_mu1[u].second < hso_mu2[d].second){
                kq.push_back(hso_mu1[u]);
                u ++;
            }
            else if(hso_mu1[u].second > hso_mu2[d].second){
                kq.push_back(hso_mu2[d]);
                d ++;
            }
            else{
                kq.push_back({(hso_mu1[u].first + hso_mu2[d].first), hso_mu1[u].second});
                u ++; d ++;
            }
        }
        while(u < hso_mu1.size()){
            kq.push_back(hso_mu1[u]);
            u ++;
        }
        while(d < hso_mu2.size()){
            kq.push_back(hso_mu2[d]);
            d ++;
        }
        sort(kq.begin(), kq.end(), cmp);
        for(int i = kq.size() - 1; i >= 0; i --){
            cout << kq[i].first << "*x^" << kq[i].second << ' ';
        }
        cout << '\n';
    }

    return 0;
}