#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

/**
* 2020-04-10
* Veronica
*/
class MinStack {
private:
	stack<int> stk;
	stack<int> minStk;
public:
	/** initialize your data structure here. */
	void push(int x) {
		stk.push(x);
		if (minStk.empty() || x <= getMin())
			minStk.push(x);
	}

	void pop() {
		if (stk.empty())
			return;
		if (top() == getMin())
			minStk.pop();
		stk.pop();
	}

	int top() {
		return stk.top();
	}

	int getMin() {
		return minStk.top();
	}
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/

int main() {
	MinStack* minStack = new MinStack();
	minStack->push(-2);
	minStack->push(0);
	minStack->push(-3);
	cout << minStack->getMin() << endl;
	minStack->pop();
	cout << minStack->top() << endl;
	cout << minStack->getMin() << endl;
		
	return 0;
}