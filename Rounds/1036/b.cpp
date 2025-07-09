#include <vector>
#include <cstdint>
#include <cstddef>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <iterator>
#include <climits>

using ull = unsigned long long;
using ll = long long;

static constexpr ll INF = 1LL << 60;

using namespace std;

struct STree {
    int N;
    vector<ll> t;
    STree(int N_in){
        N = 1;
        while(N < N_in) N <<= 1;
        t.assign(2*N, INF);
    }

    void update(int pos, ll val){
        pos += N;
        t[pos] = min(t[pos], val);
        for (pos >>= 1; pos; pos >>= 1)
            t[pos] = min(t[2 * pos], t[2 * pos + 1]);
    }

    ll query(int l, int r){
        ll res = INF;
        for(l += N, r += N; l < r; l >>= 1, r >>= 1){
            if(l & 1) res = min(res, t[l++]);
            if(r & 1) res = min(res, t[--r]);
        }
        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<ll> pre(n+1);
        pre[1] = a[1];
        ll s = pre[1];
        for (int i = 2; i <= n; i++) {
            pre[i] = min(pre[i-1], a[i]);
            s += pre[i];
        }

        vector<ll> suffix(n+2, 0);
        for (int i = n; i >= 1; i--) {
            suffix[i] = pre[i] + suffix[i+1];
        }

        int first_unused = 2;
        for (; first_unused < n; first_unused++)
            if (a[first_unused] >= pre[first_unused-1]) break;

        // find where min is set for prefix
        vector<int> p; // index
        vector<ll> m; // val
        {
            ll c = LLONG_MAX;
            for (int i = 1; i <= n; i++) {
                if (a[i] < c){
                    p.push_back(i);
                    m.push_back(c);
                    c = a[i];
                }
            }
        }
        int K = p.size();
    
        vector<ll> delta(K), L(K);
        delta[0] = n + 1;
        for(int i = 1; i < K; i++){
            delta[i] = m[i-1] - m[i];
        }
        for(int i = 0; i+1 < K; i++){
            L[i] = p[i+1] - p[i];
        }

        vector<ll> comp;
        for(int i = 0; i+1 < K; i++) { // compress
            comp.push_back(delta[i]);
        }
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        // segL: min L[i] from d index
        // segG: min (L[i]*delta[i]) at d index
        STree segL(comp.size()), segG(comp.size());

        vector<vector<int>> events(n+2);
        for(int i = 0; i+1 < K; i++){
            int when = p[i+1] + 1;
            if(when <= n) 
                events[when].push_back(i);
        }

        ll best_gain = 0;
        int pm_ptr = 0;  // index in p so that p[pm_ptr] < j
        for(int j = 2; j <= n; j++){
            for(int i : events[j]){
                int idx = int(lower_bound(comp.begin(), comp.end(), delta[i]) - comp.begin());
                segL.update(idx, L[i]);
                segG.update(idx, L[i]*delta[i]);
            }

            while(pm_ptr+1 < K && p[pm_ptr+1] < j)
                pm_ptr++;

            ll cost_pref = INF;
            {
                ll len = j - p[pm_ptr];
                ll d  = min(delta[pm_ptr], a[j]);
                cost_pref = min(cost_pref, len * d);
            }
            if(pm_ptr > 0){
                int k = int(lower_bound(comp.begin(), comp.end(), a[j]) - comp.begin());
                if(k < (int)comp.size()){
                    ll minL = segL.query(k, comp.size());
                    if(minL < INF) 
                        cost_pref = min(cost_pref, minL * a[j]);
                }
                if(k > 0){
                    ll minG = segG.query(0, k);
                    cost_pref = min(cost_pref, minG);
                }
            }

            static bool seen_non_table[200000+5];
            if(j==2){
                vector<bool> non_table(n+1,false);
                ll cur = a[1];
                for(int x = 2; x <= n; x++){
                    if(a[x] >= cur)
                        non_table[x] = true;
                    cur = min(cur, a[x]);
                }
                seen_non_table[1] = false;
                for(int x = 2; x <= n; x++){
                    seen_non_table[x] = seen_non_table[x-1] || non_table[x];
                }
            }

            ll cost_j = seen_non_table[j-1] ? 0LL : cost_pref;
            ll gain = suffix[j] - cost_j;
            best_gain = max(best_gain, gain);
        }
        cout << (s - best_gain) << "\n";
    }
    return 0;
}