// Thanks to codestorywithMIK
// I take a help for this question for tutorial but I fully understand the intution as well as explanation 


int minDeletionSize(vector<string>& strs) {
      int rows = strs.size(); //Number of rows
      int cols = strs[0].size(); //Number of columns
     
      int deletion = 0;

      vector<bool> alreadySorted(rows-1, false);

      int row = 0;
      int col = 0;

      //to iterate in the strs

      for(col = 0; col < cols; col++){
        bool deleted = false;

        for(row = 0; row < rows - 1; row++){
            if(!alreadySorted[row] && strs[row][col] > strs[row+1][col]){
                deletion++;
                deleted = true;
                break;
            }
        }
        if(deleted){
            continue;
        }

        for(int i = 0; i <  rows-1; i++){
            alreadySorted[i] = alreadySorted[i] | (strs[i][col] < strs[i+1][col]);
        }
      }
      return deletion;
    }

    // T.C - O(cols * (2*rows)) ~= O(cols * rows)
    // S.C - O(rows)