/*
621. Task Scheduler
Solved
Medium
Topics
Companies
Hint
You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.



Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

Example 2:

Input: tasks = ["A","C","A","B","D","B"], n = 1

Output: 6

Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

With a cooling interval of 1, you can repeat a task after just one other task.
*/

// code:
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {

        // step1:calculate frequency
        unordered_map<char, int> f;
        for (auto i : tasks)
        {
            f[i]++;
        }

        // step2:store frquencies in max heap
        priority_queue<int> max_heap;
        for (auto &i : f)
        {
            max_heap.push(i.second);
        }

        // step3:calculate time interval
        int time = 0;
        while (!max_heap.empty())
        {
            vector<int> temp; // to stored the executed taks and there are still remaining those type of tasks
            int cycle_time = n + 1;

            for (int i = 0; i < cycle_time; i++)
            {
                if (!max_heap.empty())
                {
                    int task = max_heap.top();
                    max_heap.pop();

                    if (task - 1 > 0)
                    {
                        temp.push_back(task - 1);
                    }
                    time++;
                }
                else
                {
                    if (!temp.empty())
                        time++; // Add idle time only if needed
                }
            }
            // Re-add tasks that still have remaining occurrences
            for (int remaining_task : temp)
            {
                max_heap.push(remaining_task);
            }
        }
        return time;
    }
};

// prob link:https://leetcode.com/problems/task-scheduler/?envType=problem-list-v2&envId=heap-priority-queue