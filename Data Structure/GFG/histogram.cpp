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
int largestRectangleArea(vector<int> &A) {
	stack<int> s;
	int tot = A.size(), index = 0, ans = 0;
	vector<int> left;
	while (index < tot) {
		while (!s.empty() && A[s.top()] >= A[index]) {
			s.pop();
		}
		if (s.empty()) left.push_back(0);
		else left.push_back(s.top() + 1);
		s.push(index);
		index++;
		cout << left.back() << ' ';
	}
	cout << '\n';
	index = tot - 1;
	s = stack<int>();
	while (index >= 0)
	{
		int right = tot - 1;
		while (!s.empty() && A[s.top()] >= A[index]) {
			s.pop();
		}
		if (!s.empty())right = s.top() - 1;
		ans = max(ans, A[index] * (right - left[index] + 1));
		s.push(index);
		index--;
		cout << right << " ";
	}
	cout << '\n';
	return ans;
}


int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int>arr(n);
		for (int &i : arr) cin >> i;
		cout << largestRectangleArea(arr) << '\n';
	}
	return 0;
}