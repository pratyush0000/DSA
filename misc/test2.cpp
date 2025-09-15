#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'retrieveData' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING firstInfo
 *  2. STRING secondInfo
 */

string retrieveData(string firstInfo, string secondInfo) {
    // Sort firstInfo to get the lexicographically smallest permutation
    sort(firstInfo.begin(), firstInfo.end());

    // If smallest permutation is already greater than secondInfo → return it
    if (firstInfo > secondInfo) return firstInfo;

    // Otherwise, keep finding next permutation until we either find valid one or exhaust all
    while (next_permutation(firstInfo.begin(), firstInfo.end())) {
        if (firstInfo > secondInfo) return firstInfo;
    }

    // If no valid permutation exists
    return "-1";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string firstInfo, secondInfo;
    cin >> firstInfo >> secondInfo;

    cout << retrieveData(firstInfo, secondInfo) << "\n";

    return 0;
}
