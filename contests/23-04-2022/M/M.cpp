//
// Created by armandouv on 12/04/22.
//
// WA on test 20

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'

int main();

void solve();


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}


void solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> assignments;

    for (int i = 0; i < n; ++i) {
        int t, d;
        cin >> t >> d;

        assignments.emplace_back(d, i + 1, t);
    }

    std::sort(assignments.begin(), assignments.end());

    vector<int> ordered;
    ll current_time{0};
    for (auto &[deadline, assignment_number, time_required]: assignments) {
        if (current_time + time_required > deadline) {
            cout << "*" << endl;
            return;
        }

        current_time += time_required;
        ordered.push_back(assignment_number);
    }

    for (int i = 0; i < n - 1; ++i) {
        cout << ordered[i] << " ";
    }

    cout << ordered[n - 1] << endl;
}
