  int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        int sum = 0;
        for(int i = 0; i < apple.size(); i++){
            sum += apple[i];
        }
        int sum1 = 0;
        int ans = 0;
        int n = capacity.size();
        int j = 0;
        for(j = 0; j < n; j++){
            sum1 += capacity[j];
            if(sum1 >= sum){
               ans = j;
                break;
            }
        }
        return ans + 1;
    }


    // T.C - O(nlogn)
    // S.C - O(1)