#include<iostream>
#include<vector>
using namespace std;

void printLCS(string s1,string s2){
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int j=0;j<=m;j++)dp[0][j]=0;
    for(int i=0;i<=m;i++)dp[i][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int lcslen=dp[n][m];

    string str1="";
    for(int i=0;i<lcslen;i++){
        str1+="$";
    }
    int i=n,j=m;
    int ind=lcslen-1;
    while(i>0 && j>0){
        //match
        if(s1[i-1]==s2[j-1]){
            str1[ind]=s1[i-1];
            ind--;
            i--,j--;
        }
        //no match
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    printf("Longest common substring is:");
    for(int k=0;k<lcslen;k++){
        cout<<str1[k];
    }
}
int main()
{
    string s1="abcde",s2="bdgek";
    printLCS(s1,s2);
    return 0;
}