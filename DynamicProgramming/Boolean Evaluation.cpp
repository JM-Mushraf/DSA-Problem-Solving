/*
Problem statement
You are given an expression 'exp' in the form of a string where operands will be : (TRUE or FALSE), and operators will be : (AND, OR or XOR).



Now you have to find the number of ways we can parenthesize the expression such that it will evaluate to TRUE.



As the answer can be very large, return the output modulo 1000000007.



Note :

‘T’ will represent the operand TRUE.
‘F’ will represent the operand FALSE.
‘|’ will represent the operator OR.
‘&’ will represent the operator AND.
‘^’ will represent the operator XOR.
Example :

Input: 'exp’ = "T|T & F".

Output: 1

Explanation:
There are total 2  ways to parenthesize this expression:
    (i) (T | T) & (F) = F
    (ii) (T) | (T & F) = T
Out of 2 ways, one will result in True, so we will return 1.
*/
// Code:-
#include <bits/stdc++.h> 
int mod=1000000007;

// //recurssion
// long long f(int i,int j,int isTrue,string & exp){
//     if(i>j)return 0;

//     if(i==j){
//         if(isTrue){//looking for true
//             return exp[i]=='T';
//         }
//         else{//looking for false
//             return exp[i]=='F';
//         }
//     }

//     long long ways=0;
//     for(int ind=i+1;ind<j;ind+=2){

//         long long LT=f(i,ind-1,1,exp);
//         long long LF=f(i,ind-1,0,exp);
//         long long RT=f(ind+1,j,1,exp);
//         long long RF=f(ind+1,j,0,exp);

//         if(exp[ind]=='&'){
//             if(isTrue){//for true
//                 ways=(ways+(LT*RT)%mod)%mod;
//             }else{//for false
//                 ways=(ways+(LT*RF)%mod+(LF*RT)%mod+(LF*RF)%mod)%mod;
//             }
//         }
//         else if(exp[ind]=='|'){
//             if(isTrue){//for true
//                 ways=(ways+(LT*RT)%mod+(LT*RF)%mod+(LF*RT)%mod)%mod;
//             }else{//for false
//                 ways=(ways+(LF*RF)%mod)%mod;
//             }
//         }
//         else{
//             if(isTrue){//for true
//                 ways=(ways+(LT*RF)%mod+(LF*RT)%mod)%mod;
//             }else{//for false
//                 ways=(ways+(LF*RF)%mod+(LT*RT)%mod)%mod;
//             }
//         }
//     }
//     return ways;
// }

// int evaluateExp(string & exp) {
//     int n=exp.size();
//     return f(0,n-1,1,exp);
// }

//Memoization
long long f(int i,int j,int isTrue,string & exp,vector<vector<vector<long long>>>&dp){
    if(i>j)return 0;

    if(i==j){
        if(isTrue){//looking for true
            return exp[i]=='T';
        }
        else{//looking for false
            return exp[i]=='F';
        }
    }
    if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
    long long ways=0;
    for(int ind=i+1;ind<j;ind+=2){

        long long LT=f(i,ind-1,1,exp,dp);
        long long LF=f(i,ind-1,0,exp,dp);
        long long RT=f(ind+1,j,1,exp,dp);
        long long RF=f(ind+1,j,0,exp,dp);

        if(exp[ind]=='&'){
            if(isTrue){//for true
                ways=(ways+(LT*RT)%mod)%mod;
            }else{//for false
                ways=(ways+(LT*RF)%mod+(LF*RT)%mod+(LF*RF)%mod)%mod;
            }
        }
        else if(exp[ind]=='|'){
            if(isTrue){//for true
                ways=(ways+(LT*RT)%mod+(LT*RF)%mod+(LF*RT)%mod)%mod;
            }else{//for false
                ways=(ways+(LF*RF)%mod)%mod;
            }
        }
        else{
            if(isTrue){//for true
                ways=(ways+(LT*RF)%mod+(LF*RT)%mod)%mod;
            }else{//for false
                ways=(ways+(LF*RF)%mod+(LT*RT)%mod)%mod;
            }
        }
    }
    return dp[i][j][isTrue]=ways;
}

int evaluateExp(string & exp) {
    int n=exp.size();
    vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(n,vector<long long>(2,-1)));
    return f(0,n-1,1,exp,dp);
}

// prob link:-https://www.naukri.com/code360/problems/problem-name-boolean-evaluation_1214650?leftPanelTabValue=PROBLEM