/*
Longest Substring with At Most Two Distinct Characters
Moderate
80/80
Contributed by
8 upvotes
Asked in companies
Problem statement
You are given a string ‘S’, you need to find the length of the longest substring that contains at most two distinct characters.

Note:

A string ‘B’ is a substring of a string ‘A’ if ‘B’ that can be obtained by deletion of, several characters(possibly none) from the start of ‘A’ and several characters(possibly none) from the end of ‘A’.
Follow up :
Can you try to solve this problem in O(N) time and O(1) space.
Example :
If ‘S’ = “ninninja”

Then, “ninnin” is the longest substring that contains at most two distinct characters. We will print the length of this substring which is equal to 6.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 ≤ T ≤ 10
1 ≤ |S| ≤ 1000
Where 'S' contains lowercase English alphabets

Time limit: 1 sec
Sample Input 1 :
2
ninninja
aaa
Sample Output 1 :
6
3
Explanation For Sample Input 1 :
For test case 1 :
We will print 6 because:
“ninnin” is the longest substring containing at most two distinct characters.

For test case 2 :
We will print 3 because:
The given string “aaa” itself contains a single character, therefore the longest substring will itself be “aaa”.
Sample Input 2 :
2
ninjacoder
abbadca
Sample Output 2 :
3
4
*/

// code:
int lengthOfLongestSubstring(string s)
{ // Tc:O(2n) not good
    // Write your code here.
    int l = 0, r = 0, maxlen = 0;
    unordered_map<char, int> mp;
    while (r < s.size())
    {
        mp[s[r]]++;
        while (mp.size() > 2)
        {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
                mp.erase(s[l]);
            ;
            l = l + 1;
        }
        if (mp.size() <= 2)
        {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}

int lengthOfLongestSubstring(string s)
{
    int k = 2;
    int n = s.size();
    int l = 0, r = 0, maxlen = 0, len;
    unordered_map<char, int> mp;

    while (r < n)
    {
        mp[s[r]]++;

        if (mp.size() > k)
        {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
                mp.erase(s[l]);
            l++;
        }
        if (mp.size() <= k)
        {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}
