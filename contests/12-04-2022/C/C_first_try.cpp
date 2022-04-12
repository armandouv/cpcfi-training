//
// Created by armandouv on 12/04/22.
//

/* Brute force solution (time limit exceeded) */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main();

void solve();

void compute_nums(vector<ll> &, vector<ll> &, vector<ll> &, ll n);

pair<bool, ll> search_combinations(const vector<ll> &, ll, set<pair<set<ll>, ll>> &, ll);

int main() {
    solve();
    return 0;
}

void solve() {
    // For each number n, we must have a sorted array with all powerful
    // numbers up to n, powerful_nums. We'll also need:
    // fact[]: arr where arr[i] = i!
    // pow2[]: arr where arr[i] = 2^i
    // Check max_val for powerful numbers, if n is less than it, then:
    // Calculate all numbers up to n for both fact and pow2 and merge them into powerful_nums.

    // Starting with the immediate next smaller or equal element to n in powerful_nums,
    // generate all combinations of size 1 up to the size of the array.
    // If at any point all k-combinations are greater than n, break, since there's no solution.
    // If we find a combination with sum equal to n, return k, its size.

    int t;
    cin >> t;

    vector<ll> fact;
    fact.push_back(1);
    fact.push_back(1);
    fact.push_back(2);

    vector<ll> pow2;
    pow2.push_back(1);
    pow2.push_back(2);

    vector<ll> powerful_nums;
    powerful_nums.push_back(1);
    powerful_nums.push_back(2);


    for (auto i = 0; i < t; i++) {
        ll n;
        cin >> n;

        if (n > powerful_nums[powerful_nums.size() - 1]) compute_nums(powerful_nums, fact, pow2, n);

        auto greater_than_or_equal = lower_bound(powerful_nums.begin(), powerful_nums.end(), n);

        if (*greater_than_or_equal == n) {
            cout << 1 << endl;
            continue;
        }

        // Last idx points to the first element less than n.
        ll last_idx{static_cast<ll>(greater_than_or_equal - powerful_nums.begin()) - 1};

        set<pair<set<ll>, ll> > memo;
        for (ll k = 0; k <= last_idx; k++) {
            memo.insert({{powerful_nums[k]}, powerful_nums[k]});
        }

        bool found{false};
        ll j{2};

        for (; j <= last_idx + 1; j++) {
            auto res = search_combinations(powerful_nums, last_idx, memo, n);
            found = res.first;
            if (found || res.second > n) break;
        }

        if (found) cout << j << endl;
        else cout << -1 << endl;
    }
}

void compute_nums(vector<ll> &powerful_nums, vector<ll> &fact, vector<ll> &pow2, ll n) {
    ll start_fact = fact.size();
    ll start_pow2 = pow2.size();

    ll fact_idx{start_fact};
    ll pow2_idx{start_pow2};

    ll new_fact{0};
    while (new_fact < n) {
        new_fact = fact[fact_idx - 1] * fact_idx;
        fact.push_back(new_fact);
        fact_idx++;
    }

    ll new_pow2{0};
    while (new_pow2 < n) {
        new_pow2 = pow2[pow2_idx - 1] * 2;
        pow2.push_back(new_pow2);
        pow2_idx++;
    }

    // Merge
    while (start_fact < fact_idx && start_pow2 < pow2_idx) {
        if (fact[start_fact] < pow2[start_pow2]) powerful_nums.push_back(fact[start_fact++]);
        else if (fact[start_fact] > pow2[start_pow2]) powerful_nums.push_back(pow2[start_pow2++]);
        else {
            powerful_nums.push_back(fact[start_fact++]);
            start_pow2++;
        }
    }

    while (start_fact < fact_idx) {
        if (powerful_nums[powerful_nums.size() - 1] != fact[start_fact])
            powerful_nums.push_back(fact[start_fact]);
        start_fact++;
    }

    while (start_pow2 < pow2_idx) {
        if (powerful_nums[powerful_nums.size() - 1] != pow2[start_pow2])
            powerful_nums.push_back(pow2[start_pow2]);
        start_pow2++;
    }
}


pair<bool, ll> search_combinations(const vector<ll> &powerful_nums,
                                   ll last_idx,
                                   set<pair<set<ll>, ll>> &memo,
                                   ll n) {
    set<pair<set<ll>, ll>> new_combs;
    ll min_sum{0};

    for (auto &[comb, sum]: memo) {
        for (ll i = last_idx; i >= 0; i--) {
            auto curr_el = powerful_nums[i];
            if (comb.contains(curr_el)) continue;

            auto new_sum = sum + curr_el;
            if (new_sum == n) return {true, min_sum};

            auto new_comb = comb;
            new_comb.insert(curr_el);

            pair<set<ll>, ll> new_pair{new_comb, new_sum};
            if (new_combs.contains(new_pair)) continue;
            new_combs.insert(new_pair);

            min_sum = min_sum == 0 ? new_sum : min(min_sum, new_sum);
        }
    }


    memo = new_combs;
    return {false, min_sum};
}