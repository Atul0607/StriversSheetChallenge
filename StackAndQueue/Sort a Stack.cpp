#include <bits/stdc++.h> 

void insert(stack<int> &st,int num){
	if(st.empty() || st.top()<num){
		st.push(num);
		return;
	}
	int temp = st.top();
	st.pop();
	insert(st,num);
	st.push(temp);
}
void sortStack(stack<int> &st)
{
	// Write your code here
	if(st.empty()) return;
	int num = st.top();
	st.pop();
	sortStack(st);
	insert(st,num);
	
}