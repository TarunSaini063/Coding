#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, a = 0, b = 0;
		cin >> n;
		string s;
		cin >> s;
		queue<pair<char, pair<int, int>>> q;
		vector<int>arr(n, 0);
		for (int i = 0; i < n; i++) {
			if (s[i] == 'A')q.push(mk('A', mk(i - 1, 2))), a++, arr[i] = 1;
			if (s[i] == 'B')q.push(mk('B', mk(i + 1, -2))), b++, arr[i] = -1;
		}
		while (!q.empty()) {
			auto p = q.front();
			q.pop();
			if (p.ff == 'A') {
				if (p.ss.ff >= 0) {
					if (s[p.ss.ff] == '-') {
						if (arr[p.ss.ff] != 0)
						{
							if (abs(arr[p.ss.ff]) == abs(p.ss.ss)) arr[p.ss.ff] = 0;
							continue;
						}
						arr[p.ss.ff] += p.ss.ss;
						p.ss.ss++;
						p.ss.ff--;
						q.push(p);
					}
				}
			}
			else {
				if (p.ss.ff < n) {
					if (s[p.ss.ff] == '-') {
						if (arr[p.ss.ff] != 0)
						{
							if (abs(arr[p.ss.ff]) == abs(p.ss.ss)) arr[p.ss.ff] = 0;
							continue;
						}
						arr[p.ss.ff] += p.ss.ss;
						p.ss.ss--;
						p.ss.ff++;
						q.push(p);

					}
				}
			}
		}
		for (int i : arr) {
			cout << i << " ";
			if (i < 0) b++;
			if (i > 0)a++;
		}
		if (a > b) cout << "A\n";
		else if (b > a) cout << "B\n";
		else cout << "Coalition government\n";
	}
	return 0;
}