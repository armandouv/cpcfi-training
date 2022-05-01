//
// Created by armandouv on 12/04/22.
//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'

int main();

void solve();

bool can_finish(ll, int, int, vector<int> &);

ll search_time(int, int, int, int, vector<int> &);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}


void solve() {
    int n, c, t;
    cin >> n >> c >> t;

    vector<int> bags;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        bags.push_back(p);
    }

    cout << search_time(0, INT_MAX, t, c, bags) << endl;
}

bool can_finish(ll time, int max_popcorn_per_sec, int competitors, vector<int> &bags) {
    ll acc{0}, popcorn_in_time{time * max_popcorn_per_sec};
    int n{static_cast<int>(bags.size())}, remaining_competitors{competitors};

    // acc is <= to popcorn_in_time
    for (int i = 0; i < n; ++i) {
        if (remaining_competitors < 1 || bags[i] > popcorn_in_time) return false;

        acc += bags[i];
        if (acc <= popcorn_in_time) continue;

        if (acc == popcorn_in_time) acc = 0;
        else acc = bags[i];
        remaining_competitors--;
    }

    if (acc > 0) remaining_competitors--;
    return remaining_competitors >= 0;
}

ll search_time(int start, int end, int max_popcorn_per_sec, int competitors, vector<int> &bags) {
    ll low{start}, high{end};
    while (low < high) {
        ll middle{(low + high) / 2};
        if (can_finish(middle, max_popcorn_per_sec, competitors, bags)) high = middle;
        else low = middle + 1;
    }

    return low;
}