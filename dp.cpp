#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
//Knapsack problem 0/1
 int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
     int dp[n+1][W+1];
     for(int i=0;i<n+1;i++){
         dp[i][0]=0;
     }
     for(int i=0;i<W+1;i++){
         dp[0][i]=0;
     }
     for(int i=1;i<n+1;i++){
         for(int j=1;j<W+1;j++){
             if(wt[i-1]<=j)
               dp[i][j]= max(val[i-1]+ dp[i-1][j-wt[i-1]], dp[i-1][j]);
             else
               dp[i][j]= dp[i-1][j];
         }
     }
     return dp[n][W];
    }

//https://practice.geeksforgeeks.org/problems/ncr1019/1
//binomial nCr
 int nCr(int n, int r){
         int mod = 1000000007;
        int C[r+1];
        memset(C, 0, sizeof(C));
        
        C[0] = 1; 
    	for (int i = 1; i <= n; i++) { 
    		for (int j = min(i, r); j > 0; j--){ 
    			C[j] = (C[j] + C[j-1])%mod;
    		}
    	} 
    	return C[r]%mod;
 }

 //https://practice.geeksforgeeks.org/problems/coin-change2448/1
 //coin change
 long long int count( int S[], int m, int n )
    {    
  long long int dp[m+1][n+1];
        for(int i=0;i<m+1;i++){
            dp[i][0]=1;
        }
        for(int j=1;j<n+1;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(S[i-1]<=j){
                    dp[i][j]= dp[i][j-S[i-1]] + dp[i-1][j];
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[m][n];
    }

//https://practice.geeksforgeeks.org/problems/edit-distance3702/1
//Edit distance
int editDistance(string s, string t) {
        // Code here
       int n =s.length();
       int m =t.length();
       int dp[n+1][m+1];
      for(int j=0;j<m+1;j++){
           dp[0][j]=j;
       }
       for(int i=0;i<n+1;i++){
           dp[i][0]=i;
       }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                 if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }
        return dp[n][m];
    }
//https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
//subset sum
 bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        bool dp[N+1][sum+1];
        for(int i=0;i<N+1;i++){
            dp[i][0]=true;
        }
        for(int j=1;j<sum+1;j++){
            dp[0][j]=false;
        }
        
        for(int i=1;i<N+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j] =( dp[i-1][j-arr[i-1]] || dp[i-1][j] );
                }
                else
                  dp[i][j] =  dp[i-1][j];
            }
        }
        return dp[N][sum];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum=sum+arr[i];
        }
        int x=sum/2;
        if(sum%2!=0 ){
            return 0;
        }
        return isSubsetSum(N,arr,sum/2);
    }

//https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
//unbounded knapsack
  int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int dp[N+1][W+1];
        for(int i=0;i<N+1;i++){
            dp[i][0]=0;
        }
        for(int j=1;j<W+1;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<N+1;i++){
            for(int j=1;j<W+1;j++){
                if(wt[i-1]<=j){
                    dp[i][j]= max(val[i-1]+dp[i][j-wt[i-1]], dp[i-1][j]);
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[N][W];
    }

//https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
//Partition Equal Subset Sum 
bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        bool dp[N+1][sum+1];
        for(int i=0;i<N+1;i++){
            dp[i][0]=true;
        }
        for(int j=1;j<sum+1;j++){
            dp[0][j]=false;
        }
        
        for(int i=1;i<N+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j] =( dp[i-1][j-arr[i-1]] || dp[i-1][j] );
                }
                else
                  dp[i][j] =  dp[i-1][j];
            }
        }
        return dp[N][sum];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum=sum+arr[i];
        }
        int x=sum/2;
        if(sum%2!=0 ){
            return 0;
        }
        return isSubsetSum(N,arr,sum/2);
    }

//https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
//Longest Common Subsequence
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
}
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        
        int dp[x+1][y+1];
        for(int i=0;i<x+1;i++){
            dp[i][0]=0;
        }
        for(int j=1;j<y+1;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<x+1;i++){
            for(int j=1;j<y+1;j++){
                if(s1[i-1]==s2[j-1])
                  dp[i][j]=1+dp[i-1][j-1];
                else
                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[x][y];
    }

//https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
//Longest Repeating Subsequence 
int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.size();
		    int dp[n+1][n+1];
		    for(int i=0;i<n+1;i++){
		        for(int j=0;j<n+1;j++){
		            if(i==0 || j==0)dp[i][j]=0;
		            else if(str[i-1]==str[j-1] && i!=j)
		              dp[i][j]=dp[i-1][j-1]+1;
		            else
		              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		        }
		    }
		    return dp[n][n];
		    
		}

//https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1#
//Goldmine
 int maxGold(int n, int m, vector<vector<int>> M)
    {
        
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        for(int j = m-1; j>=0; j--){
            for(int i = 0; i<n; i++){
                if(j == m-1)
                    dp[i][j] = M[i][j];
                else if(i == 0)
                    dp[i][j] = M[i][j] + max(dp[i][j+1], dp[i+1][j+1]);
                else if(i == n-1)
                    dp[i][j] = M[i][j] + max(dp[i-1][j+1], dp[i][j+1]);
                else
                    dp[i][j] = M[i][j] + max(dp[i-1][j+1], max(dp[i][j+1], dp[i+1][j+1]));
            }
        }
        int res = INT_MIN;
        for(int i = 0; i<n; i++)
            res = max(res, dp[i][0]);
        return res;
    }

//https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#
//Friends pairing

int countFriendsPairings(int n) 
    { 
        // code here
        long long int dp[n+1];
        for(int i=0;i<=n;i++)
        {
            if(i<=2)
                dp[i]=i;
            else
              dp[i]=(dp[i-1]%1000000007 + (i-1)%1000000007 * dp[i-2]%1000000007 )%1000000007;
        }
        return dp[n];
    }