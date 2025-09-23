/*

The Celebrity Problem
Difficulty: MediumAccuracy: 38.33%Submissions: 312K+Points: 4Average Time: 30m
A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. A square matrix mat[][] (n*n) is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

Note: Follow 0-based indexing.

Examples:

Input: mat[][] = [[1, 1, 0], [0, 1, 0], [0, 1, 1]]
Output: 1
Explanation: 0th and 2nd person both know 1st person. Therefore, 1 is the celebrity person. 
Input: mat[][] = [[1, 1], [1, 1]]
Output: -1
Explanation: Since both the people at the party know each other. Hence none of them is a celebrity person.
Input: mat[][] = [[1]]
Output: 0
Constraints:
1 <= mat.size()<= 1000
0 <= mat[i][j]<= 1
mat[i][i] == 1
*/

// code:
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        
        int top=0;
        int down=n-1;
        
        while(top<down){
            if(mat[top][down]==1){ //top knows down so top cannot be a celevrity
                top++;
            }
            else if(mat[down][top]==1){ //down knows top so down cannot be a celevrity
                down--;
            }
            else{ //know one knows anyone
                top++;
                down--;
            }
        }
        
        if(top>down)return -1;
        
        for(int i=0;i<n;i++){
            if(top==i) continue; //skip the diagonal element
            if(mat[top][i]==0 && mat[i][top]==1){}
            else{
                return -1;
            }
        }
        return top;
    }
};

// prob link:https://www.geeksforgeeks.org/problems/the-celebrity-problem/1