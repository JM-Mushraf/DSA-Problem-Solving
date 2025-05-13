/*
290. Word Pattern
Solved
Easy
Topics
Companies
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.


Example 1:

Input: pattern = "abba", s = "dog cat cat dog"

Output: true

Explanation:

The bijection can be established as:

'a' maps to "dog".
'b' maps to "cat".
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"

Output: false

Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"

Output: false
*/

// code:
class Solution
{
public:
    bool wordPattern(string pattren, string s)
    {
        vector<string> words;
        stringstream ss(s); // break string into words
        string word;

        while (ss >> word)
        {
            words.push_back(word);
        }

        if (words.size() != pattren.size())
            return false;

        unordered_map<char, string> m1; // char->str
        unordered_map<string, char> m2; // str->char

        for (int i = 0; i < pattren.size(); i++)
        {
            char c1 = pattren[i];
            string s1 = words[i];

            if (m1.count(c1))
            {
                if (m1[c1] != s1)
                    return false;
            }
            else
            {
                m1[c1] = s1;
            }

            if (m2.count(s1))
            {
                if (m2[s1] != c1)
                    return false;
            }
            else
            {
                m2[s1] = c1;
            }
        }
        return true;
    }
};

// prob link:https://leetcode.com/problems/word-pattern/?envType=problem-list-v2&envId=hash-table