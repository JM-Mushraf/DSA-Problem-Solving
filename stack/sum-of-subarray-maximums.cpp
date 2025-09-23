vector<int> prev_max(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prev(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            st.pop();
        }
        prev[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return prev;
}

vector<int> next_max(vector<int> &arr)
{
    int n = arr.size();
    vector<int> next(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }
        next[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return next;
}

long long sumSubarrayMaxs(vector<int> &arr)
{
    long long res = 0;
    int n = arr.size();
    vector<int> prevmax = prev_max(arr);
    vector<int> nextmax = next_max(arr);

    for (int i = 0; i < n; i++)
    {
        long long left = i - prevmax[i];
        long long right = nextmax[i] - i;
        res += left * right * (long long)arr[i];
    }
    return res;
}