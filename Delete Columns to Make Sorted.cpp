   int minDeletionSize(vector<string>& strs) {
      int n = strs.size();
      int m = strs[0].size();
      int i = 0;
      int count = 0;
      while(i < m){
        for(int j = 0; j < n -1 ; j++){
        if(strs[j][i] - '0' > strs[j+1][i] - '0'){
            count++;
            break;
        }
      } 
      i++;
      } 
      return count;
    }

    // T.C = O(m*n)
    // S.C = O(1)