#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define sz(v) (int)v.size();
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b){ll res=1;a=a%mod; while(b){if(b&1)res=(res*a)%mod; a=(a*a)%mod;b/=2;}return res;}
ll invmod(ll a){return power(a,mod-2);}
int main(void)
{
	FIO	
	const int nn = 5e6+1;
	bool visited[nn];
	vector<pair<int,int>>sum(nn);
	int n;
    cin>>n;
    vector<int>a(n);
    for(int &i : a)cin>>i;
	for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sm = a[i]+a[j];
            if(visited[sm])
            {
                if(sum[sm].first!=i && sum[sm].first!=j && sum[sm].second!=i && sum[sm].second!=j){
	                cout<<"YES\n";
	                cout<<sum[sm].first+1<<" "<<sum[sm].second+1<<" "<<i+1<<" "<<j+1<<"\n";
	                return 0;
                }
            }
            else
            {
                visited[sm]=true;
                sum[sm].first=i;
                sum[sm].second=j;
            }
        }
	}
    cout<<"NO\n";
	return 0;
}