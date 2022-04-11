//
// Created by armandouv on 11/04/22.
//

#include <bits/stdc++.h>

using namespace std;

int main();

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    // O(1) solution: logx (n) + (x + 2x + 4x + ... + 2^i * x)(logx (n) - 1 times) ??
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int j = 0; j < n; ++j) {
            int e;
            cin >> e;
            arr.push_back(e);
        }


        // Find most frequent element
        unordered_map<int, int> freqs;
        for (auto e: arr) {
            if (!freqs.contains(e)) freqs[e] = 0;
            freqs[e]++;
        }

        int f = 1;
        for (auto[_, v]: freqs) {
            f = max(f, v);
        }


        int total_steps = 0;
        while (f != n) {
            total_steps++;
            auto added = min(f, n - f);
            total_steps += added;
            f += added;
        }

        cout << total_steps << endl;
    }
}