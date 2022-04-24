//
// Created by armandouv on 12/04/22.
//

#include <bits/stdc++.h>

using namespace std;

/*
 * Since 2^n = 2^1 + ... 2^(n - 1)   +   2, Ana must have the nth field. If this were not true and Bob were assigned it,
 * Bob would have more yields than Ana even if she had all other fields.
 *
 * Using a similar reasoning, Bob must have the (n - 1)th field, because its yield is greater than the sum of all
 * remaining fields. Thus, the best we can do is to assign all reachable fields from this one to Bob, such that they
 * don't pass by the nth one (Ana's). The remaining fields will be assigned to Ana.
 */


int main();

void solve();

void dfs_build_component(int, const vector<vector<int>> &, set<int> &);

int main() {
    solve();
    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj_list(n + 1, vector<int>{});

    for (auto i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    set<int> bobs_fields;
    bobs_fields.insert(n);
    dfs_build_component(n - 1, adj_list, bobs_fields);
    bobs_fields.erase(n);

    string assignment;
    for (int i = 1; i <= n; ++i) {
        if (bobs_fields.contains(i)) assignment.append(1, 'B');
        else assignment.append(1, 'A');
    }

    cout << assignment << endl;
}

void dfs_build_component(int current_node, const vector<vector<int>> &adj_list, set<int> &component) {
    if (component.contains(current_node)) return;
    component.insert(current_node);

    for (auto neighbor: adj_list[current_node]) {
        dfs_build_component(neighbor, adj_list, component);
    }
}
