# Copy of 225. Implement Stack using Queues

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (`push`, `top`, `pop`, and `empty`).

Implement the `MyStack` class:

* `void push(int x)` Pushes element x to the top of the stack.
* `int pop()` Removes the element on the top of the stack and returns it.
* `int top()` Returns the element on the top of the stack.
* `boolean empty()` Returns `true` if the stack is empty, `false` otherwise.

Notes:

* You must use **only** standard operations of a queue, which means that only `push to back`, `peek/pop from front`, `size` and `is empty` operations are valid.
* Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.

**Example 1:**

<pre><code><strong>Input
</strong>["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
<strong>Output
</strong>[null, null, null, 2, 2, false]

<strong>Explanation
</strong>MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
</code></pre>



## Solution.

```cpp
class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int sizee=q.size();
        q.push(x);
        for(int i=0; i<sizee; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int store=q.front();
        q.pop();
        return store;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```



### Push()

```cpp
void push(int x) {
        int sizee=q.size();
        q.push(x);
        for(int i=0; i<sizee; i++){
            q.push(q.front());
            q.pop();
        }
    }
```

We will always push it from the back and pop from front. So it will act like reinserting all elements again after inserting a new one.



### Pop()

```cpp
int pop() {
        int store=q.front();
        q.pop();
        return store;
    }
```

Remember to always store it as pop wil not return something.
