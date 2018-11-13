#include<cstdio>

using namespace std;

int arr[1000000];
int tmp[1000000];
int n;

void merge_sort(int first,int last) {

	if (first == last) return;

	int mid = (first + last) / 2;
	merge_sort(first, mid);
	merge_sort(mid + 1, last);

	int i = first;
	int j = mid + 1;
	int k = first;

	while (i <= mid && j <= last) {
		if (arr[i] < arr[j]) {
			tmp[k++] = arr[i++];
		}
		else {
			tmp[k++] = arr[j++];
		}
	}

	while (i <= mid) tmp[k++] = arr[i++];
	while (j <= last) tmp[k++] = arr[j++];

	for (int i = first; i <= last; i++) {
		arr[i] = tmp[i];
	}
}

int main() {

	//printf("How many numbers do you enter?\n");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	merge_sort(0,n-1);
	//printf("---------------RESULT-------------------\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

}