#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string s;
    cin >> s;
    int n = s.size();
    n = 2 * n + 1;
    int l[n];
    l[0] = 0;
    l[1] = 1;
    int c = 1, r = 2, id = 0, ans = 1;
    for (int i = 2; i < n; i++)
    {
        int mir = 2 * c - i;
        l[i] = 0;
        if (i < r)
        {
            l[i] = min(l[mir], r - i);
        }
        while (i - l[i] - 1 >= 0 && i + l[i] + 1 < n && ((i + l[i] + 1) % 2 == 0 || s[(i + l[i] + 1) / 2] == s[(i - l[i] - 1) / 2]))
        {

            l[i]++;
        }
        if (ans < l[i]) {
            ans = l[i];
            id = i;
        }
        if (i + l[i] > r)
        {
            r = i + l[i];
            c = i;
        }
    }
    for (int i = 0; i < n; i++) cout << l[i] << " ";
    cout << endl;
    cout << s.substr((id - ans) / 2, ans) << '\n'; //max palindrome string
    return 0;
}