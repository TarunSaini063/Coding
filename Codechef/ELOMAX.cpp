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
	int t;
	cin >> t;
	while (t--)
	{
		int n, r, c, m, ans = 0, change;
		cin >> n >> m;
		vector<int> curr(n), rank(n, INT_MAX), rating(n, 0), rankday(n, -1), ratingday(n, -1);
		for (int &i : curr) cin >> i;
		vector < vector<pair<int, int>>> month(m, vector<pair<int, int>>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> change;
				curr[i] += change;
				if (curr[i] > rating[i]) {
					rating[i] = curr[i];
					ratingday[i] = j;
				}
				month[j][i].ff = curr[i];
				month[j][i].ss = i;
			}
		}
		for (int i = 0; i < m; i++) {
			sort(all(month[i]), greater<pair<int, int>>());
			int lastrank = -1, lastrating = -1;
			for (int j = 0; j < n; j++) {
				int player = month[i][j].ss;
				if (month[i][j].ff != lastrating) {
					lastrating = month[i][j].ff;
					lastrank = j;
				}
				if (rank[player] > lastrank) {
					rank[player] = lastrank;
					rankday[player] = i;
				}
			}
		}
		for (int i = 0; i < n; i++) ans += rankday[i] != ratingday[i];//, cout << ratingday[i] << " " << rankday[i] << '\n';
		cout << ans << "\n";
	}
	return 0;
}