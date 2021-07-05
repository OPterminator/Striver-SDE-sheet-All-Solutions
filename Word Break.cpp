https://www.interviewbit.com/problems/word-break/

int Solution::wordBreak(string A, vector<string> &B) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int N = A.length();
    int n = B.size();
    
    vector<bool> dp(N + 1);
    dp[0] = 1;
    
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            int idx1 = i;
            int idx2 = B[j].length() - 1;
           
            while(idx1 >= 0 && idx2 >= 0 && A[idx1] == B[j][idx2]) idx1--, idx2--;
           
            if(idx2 == -1) dp[i + 1] = dp[idx1 + 1];
            if(dp[i + 1]) break;
        }
    }
    
    return dp[N];
}
