#include<bits/stdc++.h>

using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

vector<string> v;
ll solve(ll a, ll b, string x){
    if(x == "+") return a + b;
    if(x == "-") return a - b;
    if(x == "*") return a * b;
    if(x == "/") return a / b;
}

void tryy1(){
    stack<ll> st;
    for(ll i = 0; i < v.size(); i ++){
        if(v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/"){
            ll tes1 = st.top(); st.pop();
            ll tes2 = st.top(); st.pop();
            ll tes = solve(tes2, tes1, v[i]);
            st.push(tes);
        }
        else{
            ll x = stoll(v[i]);
            st.push(x);
            // cout << x << '\n';
        }
    }
    cout << st.top() << '\n';
}

void tryy2(){
    stack<ll> st;
    for(ll i = v.size() - 1; i >= 0; i --){
        if(v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/"){
            ll tes1 = st.top(); st.pop();
            ll tes2 = st.top(); st.pop();
            ll tes = solve(tes1, tes2, v[i]);
            st.push(tes);
        }
        else{
            ll x = stoll(v[i]);
            st.push(x);
        }
    }
    cout << st.top() << '\n';
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    ll t; cin >> t;
    while(t --){
        ll n; cin >> n;
        for(ll i = 1; i <= n; i ++){
            string s; cin >> s;
            v.push_back(s);
        }
        if(v[v.size() - 1] == "+" || v[v.size() - 1] == "-" || v[v.size() - 1] == "*" || v[v.size() - 1] == "/"){
            tryy1();
        }
        else tryy2();
        v.clear();
    }

    return 0;
}