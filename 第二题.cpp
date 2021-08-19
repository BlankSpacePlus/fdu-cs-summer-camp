#include <iostream>
#include <vector>

using namespace std;

int f(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dp(n, vector<int>(n,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = graph[i][j];
        }
    }
    dp[0][0] = graph[0][0];
    for (int i = 1; i < n; i++) {
        dp[0][i] += dp[0][i-1];
        dp[i][0] += dp[i-1][0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n-1][n-1];
}

int main() {
    vector<vector<int>> dp(3, vector<int>(3,0));
    dp = { {1, 5, 1}, {1, 6, 1}, {2, 3, 1} };
    cout << f(dp) << endl;
    return 0;
}