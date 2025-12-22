int minDeletionSize(vector<string>& strs) {
    int rows = strs.size();
    int cols = strs[0].size();
    
    vector<int> dp(cols, 1);

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < j; i++) {
            bool ok = true;
            for (int r = 0; r < rows; r++) {
                if (strs[r][i] > strs[r][j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }

    int maxKeep = *max_element(dp.begin(), dp.end());
    return cols - maxKeep;
}
