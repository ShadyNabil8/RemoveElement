#include<stdio.h>
#define SIZE 1000 /*Size of array*/
void swap(int* nums, int* ptr, int val, int index);
int removeElement(int* nums, int numsSize, int val);
int main() {
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++)
		arr[i] = rand() % 5 + 1;/*rand()=> to genarete random numbers*/
	int k= removeElement(arr, SIZE, 2);
	printf("Array elements after removing : %d\n", k);
	printf("|=====Array elemants=====|\n");
	for (int i = 0; i < SIZE; i++)
		printf("%d ",arr[i]);
}
int removeElement(int* nums, int numsSize, int val) {
	int index = numsSize - 1;/*the index in order to swap with the val*/
	for (int* ptr = nums; ptr < nums + numsSize; ptr++) {
		if (*ptr == val) {
			if (index < ptr - nums)
				break;
			while (*(nums + index) == val && (index > ptr - nums))
				index--;
			if (index == ptr - nums) {
				index--;
				break;
			}	
			swap(nums,ptr,val,index);
			index--;
		}
	}
	return index + 1;
}
void swap(int* nums,int* ptr, int val,int index) {
	*ptr = *(nums + index);
	*(nums + index) = val;
}

