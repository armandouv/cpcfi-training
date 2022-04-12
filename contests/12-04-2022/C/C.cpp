//
// Created by armandouv on 12/04/22.
//

/* Second attempt (didn't work) */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main();

void solve();

ll count_ones(ll);

ll get_sum(ll, vector<ll> &);

int main() {
    solve();
    return 0;
}

void solve() {
    int t;
    cin >> t;

    vector<ll> fact(15);
    fact[0] = 1;
    for (int i = 1; i < 15; i++) {
        fact[i] = i * fact[i - 1];
    }

    vector<ll> sums(0b11111111111111 + 1);

    for (auto i = 0; i < t; i++) {
        ll n;
        cin >> n;

        ll result{count_ones(n)};

        for (int mask = 0; mask <= 0b11111111111111; mask++) {
            ll used_factorials = count_ones(mask);
            if (sums[mask] == 0) sums[mask] = get_sum(mask, fact);
            if (sums[mask] > n) continue;

            ll used_powers = count_ones(n - sums[mask]);
            result = min(result, used_factorials + used_powers);
        }

        cout << result << endl;
    }
}


ll count_ones(ll mask) {
    ll res = 0;
    for (int i = 0; i < 64; i++) {
        if (mask & (1 << i)) res++;
    }
    return res;
}

ll get_sum(ll mask, vector<ll> &nums) {
    ll res = 0;
    for (int i = 0; i < 64; i++) {
        if (mask & (1 << i)) res += nums[i];
    }
    return res;
}