#include<bits/stdc++.h>

using namespace std;
using ll = long long;

vector<pair<ll, ll>> v;

int solve(ll x);

int main()
{
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)cin >> v[i].first >> v[i].second;
    ll l = 0, r = (ll)1e10;
    ll ans = (ll)1e10;

    while (l <= r)
    {
        ll m = (l + r) / 2;
        int ret = solve(m);
        if (ret <= 0)
            l = m + 1;
        else {
            ans = m;
            r = m - 1;
        }
    }
    cout << ans;
    return 0;
}
int solve(ll x)
{
    ll l = -(ll)1e9, r=(ll)1e9;
    for(int i=0;i<v.size();i++)
        for (int j = i + 1; j < v.size(); j++) {
            ll a = x - abs(v[i].first - v[j].first) - abs(v[i].second - v[j].second);
            if (a < 0)return 0;
            a /= 2;
            ll s = min(v[i].second, v[j].second) - a;
            ll e = max(v[i].second, v[j].second) + a;
            if (e < l || r < s)return 0;
            if (l <= s && s <= r)
                l = s;
            else if (l <= e && e <= r)
                r = e;
        }
    return 1;
}