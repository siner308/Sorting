#include <stdio.h>

void PrintArray(int*, int);
void InitArray(int*, int*, int);
// nextstep
void SelectionSort(int*, int);
void BubbleSort(int*, int);
void InsertionSort(int*, int);

// nextstep
void MergeSort(int*, int, int);
void Merge(int*, int, int, int);
void QuickSort(int*, int, int);
int Quick(int*, int, int);
// nextnextstep 
// void QuickSort(void);
// void HeapSort(void);

int main(void){
	// declaration
	int nMenu = 1;
	int arrdata[10] = { 6, 7, 2, 9, 8, 5, 3, 10, 4, 1 };
	int arr[10];
	int length = sizeof(arr) / sizeof(int);

	while (nMenu != 0){
		printf("1.Selection 2.Bubble 3.Insertion 4.Merge 5.Quick (0 to quit) : ");
		scanf("%d", &nMenu);

		InitArray(arrdata, arr, length);

		printf("(0)");
		PrintArray(arrdata, length);
		printf("\n");

		switch (nMenu)
		{
		case 1:
			SelectionSort(arr, length);
			break;

		case 2:
			BubbleSort(arr, length);
			break;

		case 3:
			InsertionSort(arr, length);
			break;

		case 4:
			MergeSort(arr, 0, length - 1);

		case 5:
			QuickSort(arr, 0, length - 1);

		default:
			break;
		}
	}

	return 0;
}

void PrintArray(int *arr, int length){
	int i = 0;

	printf("\t");

	for (i = 0; i < length; i++){
		printf("%3d", arr[i]);
	}

	printf("\n");
}

void InitArray(int *arrdata, int *arr, int length){
	int i = 0;

	// copy array
	for (i = 0; i < length; i++){
		arr[i] = arrdata[i];
	}
}

void SelectionSort(int *arr, int length){
	int i = 0, j = 0;
	int target = 0;
	int temp = 0;

	// 0 to 8
	for (i = 0; i < length - 1; i++){
		target = i;

		// 1 to 8
		for (j = target + 1; j < length; j++){

			// if there is new target,
			if (arr[target] > arr[j]){
				target = j;
			}
		}

		// sorting (arr[target] & arr[i])
		temp = arr[i];
		arr[i] = arr[target];
		arr[target] = temp;

		// print arr
		printf("(%d)", i + 1);
		PrintArray(arr, length);
		printf("\n");
	}

} // end of SelectionSort

void BubbleSort(int *arr, int length){
	int i = 0, j = 0;
	int target = 0;
	int temp = 0;

	// 0 to 8
	for (i = 0; i < length - 1; i++){
		
		// 0 to 8, 7, 6....
		for (j = 0; j < length - i - 1; j++){

			// if need sorting
			if (arr[j] > arr[j + 1]){

				// swap nearest array
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}	

		// print arr
		printf("(%d)", i + 1);
		PrintArray(arr, length);
		printf("\n");
	}
} // end of BubbleSort

void InsertionSort(int *arr, int length){
	int i = 0, j = 0;
	int target = 0;
	int temp = 0;

	// 0 to 8
	for (i = 0; i < length - 1; i++){

		// if need sorting
		if (arr[i] > arr[i + 1]){
			target = i + 1;
			temp = arr[target];

			// shift array for insertion
			for (j = i; temp < arr[j]; j--){
				arr[j + 1] = arr[j];
			}

			// insert value
			arr[j + 1] = temp;
		}

		// print array
		printf("(%d)", i + 1);
		PrintArray(arr, length);
		printf("\n");
	}
} // end of InsertionSort

void MergeSort(int *arr, int left, int right){
	int mid = (left + right + 1) / 2;

	// separate
	if (left < right){

		// left (recursion)
		if (left < mid - 1){
			MergeSort(arr, left, mid - 1);
		}
		
		// right (recursion)
		if (mid < right){
			MergeSort(arr, mid, right);
		}

		// merge
		Merge(arr, left, mid, right);

		// print
		PrintArray(arr, 10);
		printf("\n");
	}
} // end of MergeSort

void Merge(int *arr, int left, int mid, int right){
	int i = left, j = mid, k = left;
	int target = 0;
	int temp[100];

	// while copy two arrays completely
	while (k < right + 1){

		// if left is remained,
		if (i < mid){
			target = i;

			// if right is smaller than left, and if right is remained
			if ((arr[target] > arr[j]) && (j < right + 1)){
				target = j;
				j++;
			}

			// if left is smaller than right, or if right is not remained
			else if (i < mid){
				i++;
			}
		}

		// if left is not remained,
		else{
			target = j;
			j++;
		}

		// set temp
		temp[k] = arr[target];
		k++;
	}

	// reset arr from temp
	for (i = left; i <= right; i++){
		arr[i] = temp[i];
	}
} // end of Merge

void QuickSort(int *arr, int left, int right){
	// �� ���ʿ� �ִ� ������ �ϳ��� Ÿ������ ���, ��ĭ�� �������� �̵��ϸ鼭 Ÿ�� �����ͺ��� ū �����ʹ� �迭�� ���� ������ ������.
	// �������� �̵��� ������ i++�� ����Ѵ�.
	// ���� ������ ���� ������ for���� j�� Ȱ���Ѵ�.
	// �����͸� �ϳ��� ó���Ҷ����� cnt_check�� �Ͽ�, ó���� �迭 ������ŭ �����Ͽ����� while���� ����������.
	// �̶� ���� ������ ��� �����͸� ������ �ʰ� �н��ߴٸ�, cnt_pass��� ������ ������ ����Ͽ� ī��Ʈ�Ѵ�.

	// �׸��� Ÿ���� ���������͵�� ū������ ���̿� �ִ´�. ( arr[left + cnt_pass]�� ���� �� ���̴�.)
	// Ÿ���� ���������� i�� Ȱ���Ѵ�.

	// �̶� ���� ���������Ϳ� ū�����͸� �������� ���� �۾��� �ݺ��Ѵ�.
	// �������� : left < right�� �ƴ϶�� �����Ѵ�.

	int cnt_pass = 0;

	// if there is data to sort,
	if (left < right){
		// sort
		cnt_pass = Quick(arr, left, right);

		// recursion
		QuickSort(arr, left, left + cnt_pass - 1);
		QuickSort(arr, left + cnt_pass + 1, right);

		// print
		PrintArray(arr, 10);
		printf("\n");
	}
}

int Quick(int *arr, int left, int right){
	int i = left + 1, j = 0;
	int cnt_check = 0, cnt_pass = 0, temp = 0;

	// while check all,
	while (cnt_check < right - left){

		// insert to right (bigger than target)
		if (arr[left] < arr[i]){
			temp = arr[i];

			// shift array for insert
			for (j = i; j < right; j++){
				arr[j] = arr[j + 1];
			}

			arr[right] = temp;
			cnt_check++;
		}

		// pass (smaller than target)
		else{
			i++;
			cnt_pass++;
			cnt_check++;
		}
	}

	temp = arr[left];
	for (i = left; i < left + cnt_pass; i++){
		arr[i] = arr[i + 1];
	}

	arr[left + cnt_pass] = temp;

	return cnt_pass;
}