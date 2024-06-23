#include<bits/stdc++.h>
using namespace std;

void thn(int n, char a, char b, char c) {
	if (n == 1)cout << a << " -> " << c <<endl;
	else {
		thn((n - 1), a, c, b);
		cout << a << " -> " << c << endl;
		thn(n - 1, b, a, c);
	}
}
int main() {

    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif

	int n; cin >> n;
	thn(n, 'A', 'B', 'C');
}