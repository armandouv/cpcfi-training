//
// Created by armandouv on 11/04/22.
//

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main();

void solve();

int main() {
    solve();
    return 0;
}

void solve() {
    int t;
    cin >> t;

    for (auto i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector<int> arr;
        for (auto j = 0; j < n; ++j) {
            int el;
            cin >> el;
            arr.push_back(el);
        }

        sort(arr.begin(), arr.end());

        ull red_sum = arr[n - 1], blue_sum = arr[0] + arr[1];
        int left_idx = 2, right_idx = n - 2;

        // While sums don't overlap, and we haven't found a solution yet.
        while (left_idx < right_idx && red_sum <= blue_sum) {
            red_sum += arr[right_idx];
            blue_sum += arr[left_idx];

            left_idx++;
            right_idx--;
        }

        if (red_sum > blue_sum) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}