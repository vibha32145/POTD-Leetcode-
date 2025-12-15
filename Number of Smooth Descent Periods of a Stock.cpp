long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long count = n;
        long long length = 0;
        int i = 0, j = 0;
        while(i < n && j < n - 1){
           if(prices[j]-prices[j+1] == 1){
               j++;
           }else{
            length = j -  i;
            j = j+1;
            i = j;
            long long newCount = (length * (length + 1)) / 2;
            count = count + newCount;
           } 
        }
        length = j -  i;
        long long newCount = (1LL * length * (length + 1)) / 2;
        count = count + newCount;
        return count;
    }

    // T.C - O(n)
    // S.C - O(1)