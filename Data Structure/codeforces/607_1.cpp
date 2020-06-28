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
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		if (n >= 2) {
			if (s.substr(n - 2, 2) == "po") {
				cout << "FILIPINO\n";
				continue;
			}
		}
		if (n >= 4) {
			if (s.substr(n - 4, 4) == "desu" || s.substr(n - 4, 4) == "masu") {
				cout << "JAPANESE\n";
				continue;
			}
		}
		if (n >= 5) {
			if (s.substr(n - 5, 5) == "mnida") {
				cout << "KOREAN\n";
			}
		}
	}
	return 0;
}