
---

````markdown
# 📚 Queues and Deques in C++ STL

This document provides a complete overview of **Queue** and **Deque (Double Ended Queue)** in **C++ STL**, including theory, syntax, operations, code examples, and real-life applications.

---

## 🟦 QUEUE IN C++

### ✅ What is a Queue?

A **Queue** is a linear data structure that works on the **FIFO (First In First Out)** principle. The element inserted first is the one to be removed first.

### 📌 Characteristics:
- Insertion is done at the **back (rear)**.
- Deletion is done from the **front**.
- Maintains the order of processing.

### 🔧 Header File:
```cpp
#include <queue>
````

### 🛠️ Syntax:

```cpp
std::queue<int> q;
```

### 🚀 Queue Operations:

| Function  | Description                             | Syntax        |
| --------- | --------------------------------------- | ------------- |
| `push(x)` | Adds element `x` to the back            | `q.push(10);` |
| `pop()`   | Removes the front element               | `q.pop();`    |
| `front()` | Returns the front element               | `q.front();`  |
| `back()`  | Returns the last element                | `q.back();`   |
| `empty()` | Returns `true` if queue is empty        | `q.empty();`  |
| `size()`  | Returns the number of elements in queue | `q.size();`   |

---

### 🧪 Queue Code Example:

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl;  // 10
    cout << "Back: " << q.back() << endl;    // 30

    q.pop();  // Removes 10

    cout << "Front after pop: " << q.front() << endl;  // 20

    cout << "Size: " << q.size() << endl;
    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
```

---

## 🟨 DEQUE (DOUBLE ENDED QUEUE) IN C++

### ✅ What is a Deque?

A **Deque** is a linear data structure that allows **insertion and deletion at both ends** — front and back. It combines the functionality of both stacks and queues.

### 📌 Characteristics:

* Supports insertion and deletion at **both ends**.
* Can be used as **stack**, **queue**, or **both**.
* Useful for implementing advanced algorithms like **sliding window** problems.

### 🔧 Header File:

```cpp
#include <deque>
```

### 🛠️ Syntax:

```cpp
std::deque<int> dq;
```

### 🚀 Deque Operations:

| Function        | Description                         | Syntax              |
| --------------- | ----------------------------------- | ------------------- |
| `push_back(x)`  | Adds `x` to the back                | `dq.push_back(10);` |
| `push_front(x)` | Adds `x` to the front               | `dq.push_front(5);` |
| `pop_back()`    | Removes element from the back       | `dq.pop_back();`    |
| `pop_front()`   | Removes element from the front      | `dq.pop_front();`   |
| `front()`       | Returns the front element           | `dq.front();`       |
| `back()`        | Returns the back element            | `dq.back();`        |
| `empty()`       | Checks if deque is empty            | `dq.empty();`       |
| `size()`        | Returns number of elements in deque | `dq.size();`        |

---

### 🧪 Deque Code Example:

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);

    cout << "Front: " << dq.front() << endl;  // 20
    cout << "Back: " << dq.back() << endl;    // 30

    dq.pop_front();  // Removes 20
    dq.pop_back();   // Removes 30

    cout << "Front after pops: " << dq.front() << endl;  // 10

    cout << "Size: " << dq.size() << endl;
    cout << "Is empty? " << (dq.empty() ? "Yes" : "No") << endl;

    return 0;
}
```

---

## 📊 Queue vs Deque Comparison

| Feature           | `queue`       | `deque`                             |
| ----------------- | ------------- | ----------------------------------- |
| Insert at front   | ❌ Not allowed | ✅ Allowed                           |
| Insert at back    | ✅ Allowed     | ✅ Allowed                           |
| Delete from front | ✅ Allowed     | ✅ Allowed                           |
| Delete from back  | ❌ Not allowed | ✅ Allowed                           |
| Access front/back | ✅ Yes         | ✅ Yes                               |
| Header file       | `<queue>`     | `<deque>`                           |
| Use case          | FIFO tasks    | Advanced structures, sliding window |

---

## 💡 Use Cases

### ✅ Queue:

* Task Scheduling
* CPU/Printer Job Scheduling
* BFS in Graphs

### ✅ Deque:

* Sliding Window Maximum/Minimum
* Palindrome Check
* Implementing Stack and Queue
* Real-time applications needing access from both ends

---

## 🧠 Summary

* Use `queue` when you need **FIFO** behavior with insertion at rear and deletion from front only.
* Use `deque` when you need **flexibility** of accessing both front and back ends.

---

> 🔁 STL containers like `queue` and `deque` help implement data structures efficiently without writing low-level code.

---

```

Let me know if you'd like this saved into a `.md` file or need additional diagrams or visuals!
```
