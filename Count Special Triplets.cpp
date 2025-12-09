// 2 Pass Solution
  int specialTriplets(vector<int>& nums) {
        const int M = 1e9+7;
        int count = 0;
        int n = nums.size();
        unordered_map<int, int>mp_left;
        unordered_map<int, int>mp_right;
        for(int &num: nums){
            mp_right[num]++;
        }
       for(int &num : nums){
          mp_right[num]--;

          int left = mp_left[num * 2];
          int right = mp_right[num * 2];

          count = (count + (1LL * left * right) % M) % M;
          mp_left[num]++;
       }
        return count;
    }

    // T.C - O(n)
    // S.C - O(2n)