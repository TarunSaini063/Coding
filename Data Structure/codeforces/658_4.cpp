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
vector<int> ans;
string s1, s2;
void solve(int start, int end, int cnt, int end2) {
	if (end2 < 0) return;
	char ends1, ends2;
	ends1 = s1[end];
	if (cnt % 2 == 1) ends1 = '1' + '0' - ends1;
	ends2 = s2[end2];
	if (ends2 == ends1) {
		if (end <= start) end++;
		else end--;
		solve(start, end, cnt, end2 - 1);
	}
	else {
		char starts1 = s1[start];
		if (cnt % 2 == 1) starts1 = '1' + '0' - starts1;
		if (starts1 == s2[end2]) {
			s1[start] = '1' + '0' - s1[start];
			ans.pb(1);
		}
		ans.pb(abs(start - end) + 1);
		cnt++;
		end2--;
		swap(start, end);
		if (end < start) end++;
		else end--;
		solve(start, end, cnt, end2);
	}
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
		cin >> s1 >> s2;
		ans.clear();
		solve(0, n - 1, 0, n - 1);
		cout << sz(ans) << ' ';
		for (auto i : ans) cout << i << " ";
		cout << "\n";
	}
	return 0;
}