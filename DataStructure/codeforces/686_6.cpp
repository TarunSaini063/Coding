#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define ar array
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
const int mxn = 2e5 + 1;
int mintree[mxn], maxtree[mxn], arr[mxn];
void buildmin(int l, int r, int node) {
	if (l == r) {
		mintree[node] = arr[l];
		return;
	}
	int mid = l + (r - l) / 2;
	buildmin(l, mid, 2 * node + 1);
	buildmin(mid + 1, r, 2 * node + 2);
	mintree[node] = min(mintree[2 * node + 1], mintree[2 * node + 2]);
}
void buildmax(int l, int r, int node) {
	if (l == r) {
		maxtree[node] = arr[l];
		return;
	}
	int mid = l + (r - l) / 2;
	buildmax(l, mid, 2 * node + 1);
	buildmax(mid + 1, r, 2 * node + 2);
	maxtree[node] = max(maxtree[2 * node + 1], maxtree[2 * node + 2]);
}
int getmin(int l, int r, int s, int e, int node) {
	if (s > e || s > r || e < l) return -1;
	if (e == l && s == r) return mintree[node];
	int mid = l + (r - l) / 2;
	int left = getmin(l, mid, s, min(e, mid), 2 * node + 1);
	int right = getmin(mid + 1, r, max(mid + 1, s), e, 2 * node + 2);
	return min(left, right);
}
int getmax(int l, int r, int s, int e, int node) {
	if (s > e || s > r || e < l) return -1;
	if (e == l && s == r) return maxtree[node];
	int mid = l + (r - l) / 2;
	int left = getmax(l, mid, s, min(e, mid), 2 * node + 1);
	int right = getmax(mid + 1, r, max(mid + 1, s), e, 2 * node + 2);
	return max(left, right);
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		unordered_map<int, vector<int>> mp;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			mp[arr[i]].pb(i);
		}
		buildmin(0, n - 1, 0);
		buildmax(0, n - 1, 0);
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			int leftmax = getmax(0, n - 1, 0, i, 0);
			int n1 = sz(mp[leftmax]), ridx;
			cout << " leftmax= " << leftmax;
			if (n1 >= 2) {
				ridx = upper_bound(all(mp[leftmax]), i) - mp[leftmax].begin();
				if (ridx == n1) {
					cout << " !rightmax\n";
					continue;
				}
				ridx = mp[leftmax][ridx];
				int lidx = lower_bound(all(mp[leftmax]), i) - mp[leftmax].begin();
				lidx = mp[leftmax][lidx];
				int rightmax = getmax(0, n - 1, ridx, n - 1, 0);
				cout << " rightmax= " << rightmax << " lidx= " << lidx << " ridx= " << ridx;
				if (leftmax != rightmax) { cout << "\n"; continue;}
				int min = getmin(0, n - 1, lidx + 1, ridx - 1, 0);
				cout << " min= " << min << "\n";
				if (leftmax == min) {
					ans.pb(lidx + 1);
					ans.pb(ridx - lidx + 1);
					ans.pb(n - ridx);
					break;
				}
			}
			cout << "\n";

		}
		if (sz(ans) == 3) {
			cout << "YES\n";
			for (int i : ans) cout << i << " ";
			cout << "\n";
		}
		else cout << "NO\n";
	}
	return 0;
}