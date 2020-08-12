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
int atoi(const string A) {
	string s = "0";
	int n = A.size(), i = 0, sn = 1;
	while (i < n && (A[i] == '0')) i++;
	if (i < n && A[i] == '-') sn = -1, i++;
	else if (i < n && A[i] == '+') sn = 1, i++;
	while (i < n) {
		if ((A[i] < '0' || A[i] > '9')) break;
		else s += A[i++];
	}
	long long int ans = 0;
	for (char c : s) {
		ans = ans * 10 + c - '0';
		if (ans * sn > INT_MAX) return INT_MAX;
		if (ans * sn < INT_MIN) return INT_MIN;
	}
	return (int)ans * sn;
}
int solve(string A) {
	int n = A.size(), rem = 0, fl = 0, len = n;
	if (A == "0" || A == "1") return 0;
	while (true) {
		int p = 0;
		while (p < len && A[p] == '0')p++;
		int rem = 0, k = 0;
		for (int i = p; i < len; i++) {
			rem = rem * 10 + A[i] - '0';
			if (rem < 2 && i < len - 1) rem = rem * 10 + A[++i] - '0', A[k++] = '0';
			A[k++] = rem / 2 + '0';
			rem %= 2;

		}
		len = k;
		if (rem == 1) {
			if (len == 1 && A[0] == '0') return 1;
			return 0;
		}
	}
}
string add(string A, string B) {
	int n = A.size() - 1;
	int m = B.size() - 1, rem = 0, x;
	string ans = "";
	while (n >= 0) {
		if (n >= 0 && m >= 0) {
			x = (A[n] - '0') + (B[m] - '0') + rem;
			ans += to_string(x % 10);
			rem = x / 10;
			n--, m--;
		}
		else {
			x = (A[n] - '0') + rem;
			ans += to_string(x % 10);
			rem = x / 10;
			n--;
		}
	}
	if (rem) ans += to_string(rem);
	reverse(ans.begin(), ans.end());
	return ans;
}
string multiply(string A, string B) {
	int n = A.size();
	int m = B.size();
	int x = 0, k = 0;
	while (k < n && A[k] == '0')k++;
	if (k == n) return "0";
	A = A.substr(k);
	k = 0;
	while (k < m && B[k] == '0')k++;
	if (k == m) return "0";
	B = B.substr(k);
	string prev = "";
	// cout << A << " " << B << "\n";
	n = A.size();
	m = B.size();
	for (int i1 = m - 1; i1 >= 0; i1--) {
		int num = B[i1] - '0';
		int rem = 0;
		string curr = "";
		for (int i = 0; i < x; i++) curr += "0";
		for (int i = n - 1; i >= 0; i--) {
			int mul = (A[i] - '0') * num + rem;
			curr += (mul % 10) + '0';
			rem = mul / 10;
		}
		if (rem != 0)
			curr += to_string(rem);
		reverse(curr.begin(), curr.end());
		prev = add(curr, prev);
		x++;
	}
	return prev;
}
pair<int, int> fun(vector<string> arr, int id, int len) {
	int m = arr.size(), x = 0, cnt = 0;
	while (id < m) {
		x += arr[id].size();
		cnt++;
		if (x + cnt - 1 >= len) {
			if (x + cnt - 1 != len) {
				x -= arr[id].size();
				cnt--;
			}
			return make_pair(x, cnt);
		}
		id++;
	}
	return make_pair(x, cnt);
}
vector<string> fullJustify(vector<string> &A, int B) {
	vector<string> ans;
	int n = A.size();
	for (int i = 0; i < n;) {
		pair<int, int> p = fun(A, i, B);
		int x = p.first;
		int cnt = p.second;
		int space = B - x;
		int point = cnt - 1;
		string tmp = "";
		if (point == 0) {
			tmp += A[i++];
			string stmp = string(space, ' ');
			tmp += stmp;
		}
		else {
			vector<int> v;
			int ext = space % point;
			int eq = space / point;
			for (int j = 0; j < ext; j++) v.push_back(eq + 1);
			for (int j = ext; j < point; j++) v.push_back(eq);
			for (int j : v) {
				string stmp = string(j, ' ');
				tmp += A[i++] + stmp;
			}
			tmp += A[i++];
		}
		ans.push_back(tmp);
	}
	string last = ans.back();
	int sz = last.size();
	string modify = "";
	n = 0;
	while (n < sz) {
		if (last[n] == ' ') {
			modify += ' ';
			while (n < sz && last[n] == ' ')n++;
		}
		else modify += last[n++];
	}
	modify += string(B - modify.size(), ' ');
	ans.back() = modify;
	return ans;
}
string convert(string A, int B) {
	if (B == 1 || A == "") return A;
	string ans = "";
	int x = 2 * B - 1, fl = 1, n = A.size();
	for (int i = 0; i < B; i++) {
		fl = 1;
		for (int j = i; j < n;) {
			// cout << j << " ";
			ans += A[j];
			if (i == 0 || i == B - 1) {
				j += x - 1;
			}
			else {
				if (fl)j += x - (2 * i + 1);
				else j += 2 * i;
				fl = !fl;
			}
		}
		// cout << '\n';
	}
	return ans;
}
int solve1(int gnum, int mid_array, int mid) {
	int arr[32] = {0}, len = 2 * gnum, i = 0, ans = 0;
	cout << " aux " << mid_array << " gnum " << gnum << " mid " << mid << '\n';
	if (mid != 2) {
		len++;
		arr[gnum] = mid;
		mid = 1;
	}
	else mid = 0;
	arr[len - 1] = arr[0] = 1;
	while (mid_array) {
		arr[gnum + i + mid] = arr[gnum - i - 1] = mid_array & 1;
		mid_array >>= 1;
		i++;
	}
	for (i = 0; i < len; i++)
		ans += (1 << i) * arr[i];
	return ans;
}
int precal(int A) {
	int gnum = 0, tot = 1, curr = 0;
	while (tot < A) {
		gnum++;
		int tmp = 3 * (1 << (gnum - 1));
		curr = tot;
		tot += tmp;
	}
	cout << "gnum " << gnum << " tot " << curr << '\n';
	int pos_in_group = A - (curr + 1); //(4th position mean 3)
	cout << "pos_in_group " << pos_in_group << '\n';
	int mid = 2, mid_array = pos_in_group;
	if (pos_in_group + 1 > (1 << (gnum - 1))) {
		mid = (pos_in_group - (1 << (gnum - 1))) % 2;
		mid_array = (pos_in_group - (1 << (gnum - 1))) / 2;
	}
	cout << "after\ngnum " << gnum << " tot " << curr << '\n';
	cout << "pos_in_group " << pos_in_group << " mid " << mid << '\n';
	return solve1(gnum, mid_array, mid);
}
int main(void)
{
	FIO
	int n;
	cin >> n;
	// string s;
	// vector<string> arr;
	// while (n--) {
	// 	cin >> s;
	// 	arr.push_back(s);
	// }
	// int t;
	// cin >> t;
	// cin >> s;
	// auto v = convert(s, n);
	// for (auto i : v) cout << i << "\n";
	cout << precal(n) << "\n";
	return 0;
}