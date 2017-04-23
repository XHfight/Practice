#include <iostream>
using namespace std;
//堆排：从小到大，所以要建大堆

void AdjustDown(int *arr, size_t root, size_t len)
{
	size_t parent = root;
	size_t child = root*2+1;
	while(child < len)
	{
		if(child+1 < len && arr[child] < arr[child+1])
			++child;
		if(arr[parent] < arr[child])
		{
			swap(arr[parent], arr[child]);
		}
		else
		{
			break;  //如果父结点大于等于子节点，说明下面的也已经有序，直接跳出。
					//因为我们从最后一个子节点开始调整，已经保证连下层有序。
		}
		parent = child;
		child = child*2+1;
	}
}

void CreateHeap(int *arr, size_t len)
{
	//思路：大堆：所有父结点的键值大于等于孩子结点
	//所以要从最后一个非叶子结点开始调整，直到调整到根节点。
	//每次调整都执行向下调整。
	int lastParent = (len-1-1)/2;
	for(int i = lastParent; i >= 0; --i)
	{
		AdjustDown(arr, i, len);
	}

}

void HeapSort(int *arr, size_t len)
{
	//排序思路：将堆第一个和最后一个元素进行交换，拿到最大/最小值（大堆：最大值）。
	//然后对除了最后一个元素的其他元素向下调整。
	//依次循环，直到堆里只剩一个元素。
	
	for(int last = len-1; last > 0; --last)
	{
		swap(arr[0], arr[last]);
		AdjustDown(arr, 0, last);
	}
}

void PrintArr(int *arr, size_t len)
{
	for(int i =0; i < len; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	size_t len = sizeof(arr)/sizeof(arr[0]);
	//建堆
	CreateHeap(arr, len);
	//排序
	PrintArr(arr, len);
	HeapSort(arr, len);
	PrintArr(arr, len);
	return 0;
}
