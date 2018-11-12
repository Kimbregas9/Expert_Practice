#include<cstdio>
#define MAX_N 100

using namespace std;

int arr[1000000];
int n;

typedef struct {
	int front;
	int rear;
}Digit;
Digit digit[10];

typedef struct {
	int queue[MAX_N];
}queue_index;
queue_index queue[10];

bool queueIsEmpty(int index){

	return (digit[index].front == digit[index].rear);
}

int queueIsFull(int index){

	if ((digit[index].front + 1) % MAX_N == digit[index].rear)
		return 1;
	else
		return 0;
}

int queueEnqueue(int* queue,int index,int value){

	if (queueIsFull(index)){
		printf("queue is full!");
		return 0;
	}

	queue[digit[index].front] = value;
	digit[index].front++;
	
	if (digit[index].front == MAX_N){
		digit[index].front = 0;
	}
	
	return 1;
}

int queueDequeue(int* queue,int index){
	
	if (queueIsEmpty(index)){
		printf("queue is empty!");
		return 0;
	}
	
	int ans = queue[digit[index].rear];
	
	digit[index].rear++;
	if (digit[index].rear == MAX_N)
		digit[index].rear = 0;

	return ans;
}

void radix_sort() {

	int max_value = 0;
	int factor = 1;

	for (int i = 0; i < n; i++) {
		if (max_value < arr[i]) {
			max_value = arr[i];
		}
	}

	while (max_value / factor > 0) {

		for (int i = 0; i < n; i++) {
			int index = (arr[i] / factor) % 10;
				
			queueEnqueue(queue[index].queue, index, arr[i]);
		}

		int k = 0;
		for (int i = 0; i < 10; i++) {
			while (queueIsEmpty(i) != true) {
				arr[k++] = queueDequeue(queue[i].queue, i);
			}
		}

		factor *= 10;
	}
}

int main() {

	printf("How many numbers do you enter? \n");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	radix_sort();

	printf("-----------------------RESULT---------------------------\n");

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}