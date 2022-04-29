//
// Created by armandouv on 12/04/22.
//

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main();

void solve();

bool is_on_border(int, int, int, int);

int get_position(int, int, int, int);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}

/*
 * A pair of points will only cause conflict between each other if they are on the border.
 * We discard any pair of points that are not both on the border. Then, we assign them positions as if we put them on
 * a line, in a clockwise manner starting with the left side. Having them in an array of (first, last) pairs, where
 * first comes before last in the positions we assigned, we sort them according to the first point.
 * Then, the problem reduces to find whether these pairs of points (or intervals) overlap between each other. Note that
 * if an interval is contained between another, it does not cause an issue because we can connect both points.
 * To determine whether there exists an interval, we use the following algorithm:
 * 1. Create min heap that will contain end times.
 * 2. For each interval (start, end):
 *      Clear all elements in heap < start. We can think of this as deleting all already passed intervals.
 *      Get the smallest end time (which will be greater than start) using the heap.
 *      If it is less than end, return because there is an overlap with the current interval.
 *      Else, add end to the heap and continue iterating.
*/

void solve() {
    int w, h, n;
    cin >> w >> h >> n;

    vector<pair<int, int>> points;

    for (auto i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (!is_on_border(x1, y1, w, h) || !is_on_border(x2, y2, w, h))
            continue;

        auto p1_position = get_position(x1, y1, w, h),
                p2_position = get_position(x2, y2, w, h);

        auto tmp1 = p1_position, tmp2 = p2_position;
        p1_position = min(tmp1, tmp2);
        p2_position = max(tmp1, tmp2);

        points.emplace_back(p1_position, p2_position);
    }

    std::sort(points.begin(), points.end());

    priority_queue<int, vector<int>, greater<>> ends;

    for (auto &[start, end]: points) {
        while (!ends.empty() && ends.top() < start)
            ends.pop();

        if (!ends.empty() && ends.top() < end) {
            cout << "N" << endl;
            return;
        }
        ends.push(end);
    }

    cout << "Y" << endl;
}

bool is_on_border(int x, int y, int w, int h) {
    return (x == 0 || x == w || y == 0 || y == h);
}

int get_position(int x, int y, int w, int h) {
    if (x == 0) return y;
    else if (x == w) return h + w + (h - y);
    else if (y == h) return h + x;
    else return 2 * h + w + (w - x);
}
