USING TWO STACKS


class MyQueue {
public:
    stack<int> st1,st2;
    MyQueue() {

    }
    
    void push(int x) {
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        
        st1.push(x);
        
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int x = st1.top();
        st1.pop();
        return x;
    }
    
    int peek() {
        int x = st1.top();
        return x;
    }
    
    bool empty() {
        return st1.empty();
    }
};




USING 2 STACKS BUT LESSER TIME COMPLEXITY

class MyQueue {
public:
    stack<int> input, output;
    MyQueue() {

    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()) {
            int x = output.top();
            output.pop();
            return x;
        } else {
            // push input to output
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            int x = output.top();
            output.pop();
            return x;
        }
    }
    
    int peek() {
        if(!output.empty()) {
            int x = output.top();
            return x;
        } else {
            // push input to output
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            int x = output.top();
            return x;
        }
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};




