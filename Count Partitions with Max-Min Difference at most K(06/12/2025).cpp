int countPartitions(vector<int>& nums, int k) {
         const int MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> dp(n + 1, 0);
        vector<long long> pref(n + 2, 0); 
        pref[0] = 1;
        deque<int> dqMax, dqMin;
        int l = 0;
        pref[0] = 1;

        for(int r = 0; r < n; r++){

            // Maintain max deque
            while(!dqMax.empty() && nums[dqMax.back()] <= nums[r])
            dqMax.pop_back();
            dqMax.push_back(r);
            
            // Maintain min deque
            while(!dqMin.empty() && nums[dqMin.back()] >= nums[r])
            dqMin.pop_back();
            dqMin.push_back(r);
            
            // Shrink window until valid
            while(!dqMax.empty() && !dqMin.empty() && nums[dqMax.front()] - nums[dqMin.front()] > k){
                if(dqMax.front() == l)
                dqMax.pop_front();
                if(dqMin.front() == l)
                dqMin.pop_front();
                l++;
            }

            // Window [l..r] is valid
          long long ways = (pref[r] - (l == 0 ? 0 : pref[l-1]) + MOD) % MOD;
             dp[r+1] = ways;

            pref[r+1] = (pref[r] + dp[r+1]) % MOD;
        }
        return dp[n];
    }