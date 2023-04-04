
USING TWO QUEUES

class MyStack {
    
    queue <int> q1, q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        
       queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    
    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};




USING 1  QUEUE


class MyStack {
    
    queue <int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int sz = q.size();
        sz--;
        while(sz) {
            q.push(q.front());
            q.pop();
            sz--;
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};




