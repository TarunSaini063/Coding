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
const ll N = 55;
char en = '\n';
ll inf = 1e16;
ll n, m;
char arr[N][N];
ll dir[4][2] = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
bool valid(ll i, ll j) { return i >= 1 && i <= n && j >= 1 && j <= m; }
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (ll i = 1; i <= n; i++) {
			cin >> (arr[i] + 1);
		}
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= m; j++) {
				if (arr[i][j] == 'B') {
					for (ll k = 0; k < 4; k++) {
						ll ni = i + dir[k][0];
						ll nj = j + dir[k][1];
						if (valid(ni, nj) && arr[ni][nj] == '.')
							arr[ni][nj] = '#';
					}
				}
			}
		}
		queue<pair<int, int>> que;
		bool visited[n + 5][m + 5];
		memset(visited, false, sizeof(visited));
		if (arr[n][m] == '.') {
			que.push({n, m});
			visited[n][m] = true;
		}
		while (!que.empty()) {
			pair<int, int> curr = que.front();
			que.pop();
			for (ll k = 0; k < 4; k++) {
				ll ni = curr.ff + dir[k][0];
				ll nj = curr.ss + dir[k][1];
				if (valid(ni, nj) && !visited[ni][nj] && arr[ni][nj] != '#') {
					que.push({ni, nj});
					visited[ni][nj] = true;
				}
			}
		}
		bool good = true;
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= m; j++) {
				if ((arr[i][j] == 'G' && !visited[i][j]) or
				        (arr[i][j] == 'B' && visited[i][j])) {
					good = false;
					break;
				}
			}
		}
		cout << (good ? "Yes" : "No") << en;
	}
	return 0;
}