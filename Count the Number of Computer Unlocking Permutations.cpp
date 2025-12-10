long long fact(long long n, long long M){
     if(n <= 1)return 1;
     return (n % M) * fact(n-1, M) % M;
}
    int countPermutations(vector<int>& complexity) {
        long long M = 1e9+7;
        long long n = complexity.size();
        for(int i = 1; i < n; i++){
           if(complexity[i] <= complexity[0]){
            return 0;
           }
        }
       return fact(n-1, M);
    }

    // T.C - O(n)
    // S.C - O(1)