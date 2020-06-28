#include<bits/stdc++.h>
using namespace std;
int n, ans, cnt;
int a[100000];
set<int> s, v;
int main()
{
	int f = 1, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if (!s.size())cnt++, v.clear();
		if (x > 0 && !s.count(x) && !v.count(x))s.insert(x), v.insert(x);
		else if (x < 0 && s.count(-x))s.erase(-x);
		else f = -1;
		a[cnt]++;
	}
	if (s.size() || f == -1)cnt = -1;
	cout << cnt << endl;
	for (int i = 1; i <= cnt; i++)cout << a[i] << " ";
	return 0;
}
