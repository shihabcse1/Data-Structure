#include <bits/stdc++.h>
using namespace std;

class Stack{
public:
	queue<int> q1,q2;
	void push(int x){
		if(q1.empty()){
			q2.push(x);
		}
		else{
			q1.push(x);
		}
	}

	int pop(){
	int count,size,item;
	if(q2.empty()){
		size=q1.size();            //size=no of elements;
		count=0;
		while(count<size-1){         //transferring n-1 elements
			q2.push(q1.front());
			q1.pop();
			count++;
		}
		item=q1.front();
		q1.pop();
		return item;                 //popping out the element
	}
	else{
		size=q2.size();
		count=0;
		while(count<size-1){
			q1.push(q2.front());
			q2.pop();
			count++;
		}
		item=q2.front();
		q2.pop();
		return item;
		}
	}
};

int main(){
	cout<<"Enter any integer to push and 0 to stop pushing &  then it will show the popping operation like queue : "<<endl;
	Stack s;
	int x,count=0;
	cin>>x;

	while(x){
		s.push(x);
		cin>>x;
		count++;
	}

	cout<<"Now popping......."<<endl;

	while(count){
		cout<<s.pop()<<endl;
		count--;
	}

	cout<<"Executed successfully!!!"<<endl;

	return 0;
}
