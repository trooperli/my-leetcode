/**
 * We use two stacks, one stack is the one that has push, pop, and top
 * method; while the other one is to store the minimum value when an
 * element is pushed into the first stack. The current minimum value
 * is the minimum between the current pushed value and the last
 * minimum value. When the top of both stacks are the same, and a pop
 * method is called, the top elements of both stacks need to be
 * popped. The online solution method 2 explains this problem well.
 */



class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        stk.push(x);
        if (min_stk.empty()) {min_stk.push(x);}
        else if (x <= min_stk.top()) {min_stk.push(x);}

    }

    void pop() {
        if (stk.top() == min_stk.top()) {min_stk.pop();}
        stk.pop();

    }

    int top() {
        return stk.top();

    }

    int getMin() {
        return min_stk.top();

    }
private:
    stack<int> stk;
    stack<int> min_stk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
