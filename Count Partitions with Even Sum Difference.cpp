/* T.C - O(n)
    S.C - O(1)*/

int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        int sum1 = 0, sum2 = 0, count = 0;
        for(int i = 0; i < n -1; i++){
            sum1 = sum1 + nums[i];
            sum2 = sum - sum1;
            if((sum1-sum2)%2 == 0){
                count++;
            }
        }
        return count;
    }