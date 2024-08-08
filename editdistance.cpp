#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 

using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    // Initialize the DP table with size (m+1) x (n+1)
    vector<vector<int>> cache(m + 1, vector<int>(n + 1, INT_MAX));

    // Initialize the base cases
    for (int j = 0; j <= n; ++j) {
        cache[m][j] = n - j;
    }

    for (int i = 0; i <= m; ++i) {
        cache[i][n] = m - i;
    }

    // Fill the DP table in a bottom-up manner
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (word1[i] == word2[j]) {
                cache[i][j] = cache[i + 1][j + 1];
            } else {
                cache[i][j] = 1 + min({cache[i + 1][j],      // Deletion
                                       cache[i][j + 1],      // Insertion
                                       cache[i + 1][j + 1]}); // Substitution
            }
        }
    }

    return cache[0][0];
}

int main() {
    string word1 = "kitten";
    string word2 = "sitting";

    cout << "The edit distance between \"" << word1 << "\" and \"" << word2 << "\" is " << minDistance(word1, word2) << endl;

    return 0;
}
