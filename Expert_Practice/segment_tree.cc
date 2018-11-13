#include<cstdio>
#include<iostream>
#define MAX_N 100

using namespace std;

int arr[MAX_N*2]; //Make Tree.
int store[10];


int update(int left,int right,int index,int node,int val) {
	
	if (index < left || right < index) return arr[node]; // return already stored range.

	if (left == right) return arr[node] = val; //store at own location.

	int mid = (left + right) / 2;
	int left_ans = update(left, mid, index, node * 2, val);
	int right_ans = update(mid + 1, right, index, (node * 2) + 1, val);
	
	if (left_ans > right_ans)
		return arr[node] = left_ans;
	else
		return arr[node] = right_ans;
}

int search(int left, int right, int first, int last, int node) {

	if (last < left || right < first) return 0;

	if (first <= left && right <= last) return arr[node];

	int mid = (left + right) / 2;
	int left_result = search(left, mid,first,last, node * 2);
	int right_result = search(mid + 1, right, first,last,(node * 2) + 1);

	if (left_result > right_result)
		return left_result;
	else
		return right_result;
}


int main() {
	
	for (int i = 0; i < 10; i++) {
		scanf("%d", &store[i]);
	}

	for (int i = 0; i < 10; i++) {
		update(1, 10, i+1,1, store[i]);
	}
}