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
const int mxn = 1025;
int mat[mxn][mxn], treeBit[mxn][mxn], n;

void update(int x1, int y1, int val) {
	for (int i = x1; i <= n; i += i & -i) {
		for (int j = y1; j <= n; j += j & -j) {
			treeBit[i][j] += val;
		}
	}
}

int sum(int x1, int y1) {
	int sm = 0;
	for (int i = x1; i > 0; i -= i & -i) {
		for (int j = y1; j > 0; j -= j & -j) {
			sm += treeBit[i][j];
		}
	}
	return sm;
}

void upd(int x1, int y1, int val) {
	update(x1 + 1, y1 + 1, val - mat[x1][y1]);
	mat[x1][y1] = val;
}

int get(int x1, int y1, int x2, int y2) {
	x1++, y1++, x2++, y2++;
	return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
}

int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--) {
		int  x1, x2, y1, y2, val;
		cin >> n;
		memset(mat, 0, sizeof(mat));
		memset(treeBit, 0, sizeof(treeBit));
		string s;
		while (true) {
			cin >> s;
			if (s == "END") break;
			if (s == "SET") {
				cin >> x1 >> y1 >> val;
				upd(x1, y1, val);
			}
			if (s == "SUM") {
				cin >> x1 >> y1 >> x2 >> y2;
				cout << get(x1, y1, x2, y2) << "\n";
			}
		}
	}
	return 0;
}