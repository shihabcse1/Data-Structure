#include <bits/stdc++.h>
using namespace std;

class Queue{
public:
	stack<int> s1, s2; // Using STL
	void enQueue(int x){
		s1.push(x);
	}

	int deQueue(){
		// if both stacks are empty then Queue is empty
		if (s1.empty() && s2.empty()){
			cout << "Queue is empty";
			exit(0);
		}
		// if s2 is empty, move elements from s1 to s2
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		// return the top item from s2
		int x = s2.top();
		s2.pop();
		return x;
	}
};

int main(){

	Queue q;
	int x,count=0;
	cout<<"press 0 to stop push operation, else enqueue integers"<<endl;
	cin>>x;
	while(x){
		q.enQueue(x);
		count++;
		cin>>x;
	}
	cout<<"dequeuing...."<<endl;
	while(count){
		cout<<q.deQueue()<<endl;
		count--;
	}
	cout<<"Execution completed"<<endl;
	return 0;
}
