/*
146. LRU Cache
Solved
Medium
Topics
Companies
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

*/

// code:
class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v) {
        key = k;
        val = v;
        next = nullptr;
        prev = nullptr;
    }

    static void insertDel(Node*head,Node*node){
        Node*temp=node->prev;
        Node*temp2=node->next;

        temp->next=temp2;
        temp2->prev=temp;

        Node*temp3=head->next;
        node->next=temp3;
        temp3->prev=node;

        node->prev=head;
        head->next=node;
    }
};
class LRUCache {
public:
    int capacity;
    unordered_map<int,Node*>m;
    Node*head;
    Node*tail;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(!m.count(key))return -1;

        Node*node=m[key];
        Node::insertDel(head,node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            Node*node=m[key];
            node->val=value;
            Node::insertDel(head,node);
        }
        else{
            if(m.size()==capacity){
                Node* lru = tail->prev;
                m.erase(lru->key);
                lru->key=key;
                lru->val=value;
                m[key]=lru;
                Node::insertDel(head, lru);
            }
            else{
                Node*node=new Node(key,value);
                m[key] = node;

                // Insert new node right after head
                Node* temp = head->next;
                node->next = temp;
                temp->prev = node;
                node->prev = head;
                head->next = node;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


//  prob link:https://leetcode.com/problems/lru-cache/