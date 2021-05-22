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
int n, s1, s2, a, b, s, x, z, y, k, d, o[4][2] = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main(void)
{
	FIO
	cin >> n >> s1 >> s2;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a > s1) x++;
		if (a < s1) s++;
		if (b > s2) y++;
		if (b < s2) z++;
	}
	if (s > k) k = s, d = 0;
	if (z > k) k = z, d = 2;
	if (x > k) k = x, d = 1;
	if (y > k) k = y, d = 3;
	cout << k << endl;
	cout << s1 + o[d][0] << ' ' << s2 + o[d][1] << '\n';
	return 0;
}