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
int mat[65][65], arr[65][65], qu;
set<string> s;
int fun(int r1, int c1, int r2, int c2)
{
	int x = 0;
	for (int i = r1; i <= r2; i++)
	{
		for (int j = c1; j <= c2; j++) x += (arr[i][j] == 1);
	}
	return x;
}
void solve(int r1, int c1, int r2, int c2, int val)
{
	if (r1 > r2 || c1 > c2) return;
	int x;
	string dup = to_string(r1) + "-" + to_string(c1) + "-" + to_string(r2) + "-" + to_string(c2);
	if (s.find(dup) != s.end()) return;
	s.insert(dup);
	if (val == 0) return;
	// cout << dup << '\n';
	if (r1 == r2 && c1 == c2) mat[r1][c1] = val;
	else
	{
		if (r1 != r2) {
			dup = to_string(r1) + "-" + to_string(c1) + "-" + to_string((r1 + r2) / 2) + "-" + to_string(c2);
			if (s.find(dup) == s.end()) {
				cout << 1 << " " << r1 << ' ' << c1 << ' ' << (r1 + r2) / 2 << ' ' << c2 << endl;;
				cout.flush();
				cin >> x;
				if (x == -1) exit(0);
				// qu++;
				// x = fun(r1, c1, (r1 + r2) / 2, c2);
				// cout << x << '\n';
				// cout.flush();
				solve(r1, c1, (r1 + r2) / 2, c2, x);
				solve((r1 + r2) / 2 + 1, c1, r2, c2, val - x);
			}
		}
		if (c1 != c2) {
			dup = to_string(r1) + "-" + to_string(c1) + "-" + to_string(r2) + "-" + to_string((c1 + c2) / 2);
			if (s.find(dup) == s.end()) {
				cout << 1 << " " << r1 << ' ' << c1 << ' ' << r2 << ' ' << (c1 + c2) / 2 << endl;
				cout.flush();
				// qu++;
				cin >> x;
				if (x == -1) exit(0);
				// x = fun(r1, c1, r2 , (c1 + c2) / 2);
				// cout << x << '\n';
				// cout.flush();
				solve(r1, c1, r2, (c1 + c2) / 2, x);
				solve(r1, (c1 + c2) / 2 + 1, r2, c2, val - x);
			}
		}
	}
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, p;
		cin >> n >> p;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				mat[i][j] = 0;
		cout << 1 << " " << 1 << ' ' << 1 << ' ' << n << ' ' << n << endl;;
		cout.flush();
		cin >> p;
		// qu++;
		// p = fun(1, 1, n, n);
		// cout << p << '\n';
		// cout.flush();
		s.clear();
		solve(1, 1, n, n, p);
		cout << 2 << '\n';
		cout.flush();
		// int fl = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++) {
				cout << mat[i][j] << ' ';
				// if (mat[i][j] != arr[i][j]) fl = 1;
				// mat[i][j] = 0;
				cout.flush();

			}
			cout << '\n';
		}
		cin >> p;
		if (p == -1) exit(0);

		// cout << "total queries " << qu << '\n';
		// if (fl) cout << "Not matched\n";
		// else cout << "matched\n";
	}
	return 0;
}