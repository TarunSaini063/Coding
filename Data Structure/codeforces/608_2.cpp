#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
int n, a[205], t[205], b, w, c;
string s;
int main(void)
{
	FIO
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'B')
			t[i] = 0, b++;
		else t[i] = 1, w++;
	}
	if (b % 2 & w % 2) {
		cout << -1;
		return 0;
	}
	b = !(b & 1);
	for (int i = 0; i < n - 1; i++) {
		if (t[i]^b) {
			t[i] ^= 1;
			t[i + 1] ^= 1;
			a[c++] = i + 1;
		}
	}
	cout << c << endl;
	for (int i = 0; i < c; i++) cout << a[i] << ' ';
	return 0;
}
