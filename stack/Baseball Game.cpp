/*
682. Baseball Game
Solved
Easy
Topics
Companies
You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.

The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.



Example 1:

Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.

*/

// code:
class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        vector<int> rec;

        for (auto op : operations)
        {
            if (op == "C")
            {
                rec.pop_back();
            }
            else if (op == "D")
            {
                rec.push_back(rec.back() * 2);
            }
            else if (op == "+")
            {
                int n = rec.size();
                rec.push_back(rec[n - 1] + rec[n - 2]);
            }
            else
            {
                rec.push_back(stoi(op));
            }
        }
        int sum = 0;
        for (int i : rec)
        {
            sum += i;
        }
        return sum;
    }
};

// prob link:https://leetcode.com/problems/baseball-game/?envType=problem-list-v2&envId=stack