   int countCoveredBuildings(int n, vector<vector<int>>& b) {
    unordered_map<int, set<int>> row, col;
    for (auto &p : b) {
        row[p[1]].insert(p[0]);
        col[p[0]].insert(p[1]);
    }
    int ans = 0;
    for (auto &p : b) {
        int x = p[0], y = p[1];
        auto &xs = row[y];
        auto &ys = col[x];
        if (*xs.begin() < x && *xs.rbegin() > x 
         && *ys.begin() < y && *ys.rbegin() > y) {
            ans++;
        }
    }
    return ans;
    }

    // T.C - O(n)
    // S.C - O(2n)