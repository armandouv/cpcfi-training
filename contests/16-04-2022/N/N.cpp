//
// Created by armandouv on 12/04/22.
//

#include <bits/stdc++.h>

using namespace std;

int main();

void solve();

pair<int, int> count_vowels_and_ys(int);

// For each line, the amount of vowels must be less than or equal to the required syllables (5 or 7),
// and the amount of vowels plus the amount of y's must be greater than or equal to the required syllables again.

set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

int main() {
    solve();
    return 0;
}

void solve() {
    int t;
    cin >> t;

    for (auto i = 0; i < t; i++) {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;

        vector<int> line_syllables{5, 7, 5};
        vector<int> words_per_line{n1, n2, n3};

        bool valid{true};
        for (int j = 0; j < 3; j++) {
            auto [vowels_per_line, ys_per_line] = count_vowels_and_ys(words_per_line[j]);

            if (vowels_per_line > line_syllables[j] || vowels_per_line + ys_per_line < line_syllables[j]) {
                valid = false;

                // Consume remaining case lines.
                string _;
                getline(cin, _);
                for (int k = j + 1; k < 3; k++)
                    getline(cin, _);
                break;
            }
        }

        cout << (valid ? "YES" : "NO") << endl;
    }
}


pair<int, int> count_vowels_and_ys(int words_per_line) {
    int vowels_per_line{0}, ys_per_line{0};
    for (int i = 0; i < words_per_line; ++i) {
        string word;
        cin >> word;

        for (auto c: word) {
            if (vowels.contains(c)) vowels_per_line++;
            else if (c == 'y' || c == 'Y') ys_per_line++;
        }
    }
    return {vowels_per_line, ys_per_line};
}