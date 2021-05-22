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
ll power(ll a, ll b){ll res=1;a=a%mod; while(b){if(b&1)res=(res*a)%mod; a=(a*a)%mod;b/=2;}return res;}
ll invmod(ll a){return power(a,mod-2);}
int main(void)
{
        FIO
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            vector<int> arr(n);
            for(auto &i : arr){
                cin>>i;
            }
            int ans = 3;
            if(arr[0]==n&&arr.back()==1) ans = 3;
            else if(arr[0]==1||arr.back()==n) ans = 1;
            else ans = 2;
            int fl = 0;
            for(int i = 1; i<n;i++){
                if(arr[i-1]>arr[i]){
                    fl = 1;
                }
            }
            if(fl == 0) ans = 0;
            cout<<ans<<"\n";
        }
        return 0;
}