#include <bits/stdc++.h>
using namespace std ;
typedef unsigned long long ull ;
typedef long long ll ;
typedef pair < ll, ll > P ;
const ll Maxn = 2e5 + 10;
const int Mod = 1e9 + 7  ;
const int INF = 0x3f3f3f3f ;

ll n, t ;
vector < ll > ve;
ll T[Maxn << 4] , ans, sum[Maxn << 1], a[Maxn] ;

ll getId(ll x){
    return lower_bound(ve.begin(), ve.end(), x) - ve.begin() + 1 ;
}

void Updata (ll p, ll v, ll ri, ll l , ll r){
    T[ri] += v ;
    if (l == r) return ;
    ll Mid = (l + r) >> 1 ;
    if (p <= Mid) Updata(p, v, ri << 1 , l, Mid) ;
    else Updata(p, v, ri << 1 | 1, Mid + 1, r) ;
}

void lessSum(ll pos, ll ri, ll l, ll r){
    if (l == r) return ;
    ll Mid = (l + r) >> 1 ;
    if (pos <= Mid) lessSum(pos, ri << 1, l, Mid) ;
    else {
        ans += T[ri << 1] ;
        lessSum(pos, ri << 1 | 1, Mid + 1, r) ;
    }
}

int main() {
    cin >> n >> t ;
    for (ll i = 1; i <= n; i++){
        cin >> a[i] ;
        sum[i] = sum[i - 1] + a[i] ;
        ve.push_back(sum[i]) ;
    }
    if (n == 1) {
        if (a[1] < t) cout << 1 << endl ;
        else cout << 0 << endl ;
    }
    else {
        for (ll i = 1; i <= n; i++){
            ll x = sum[i] + t ;
            ve.push_back(x) ;
        }
        sort(ve.begin(), ve.end()) ;
        ve.erase(unique(ve.begin(), ve.end()), ve.end()) ;
        ll len = ve.size() ;
        Updata(getId(sum[n]), 1, 1, 1, len) ;
        for (ll i = n - 1; i >= 0; i--){
            ll x = sum[i] + t ;
            lessSum(getId(x), 1, 1, len) ;
            Updata(getId(sum[i]), 1, 1, 1, len) ;
        }
        cout << ans << endl ;
    }
    return 0;
}

//psum[r] < psum[l-1] + t
//weight segment tree