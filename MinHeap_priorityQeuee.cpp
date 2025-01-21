#include<iostream>
using namespace std;


template <typename k,typename v>
class MinHeap
{
public:
	class HeapItem
	{
	public:
		HeapItem(k KEY, v VALUE) {
			Key = KEY;
			value = VALUE;
		}
		HeapItem(){}
		HeapItem& operator ==(HeapItem& Obj) {
			Key = Obj.Key;
			value = Obj.value;
		}
	
		k Key;
		v value;
	};

	 MinHeap(int capacity) {
		if (capacity > 0) {
			size = capacity;
			arr = new HeapItem[capacity];
		}
	}
	void insert(k KEY,v Value ) {
			HeapItem item(KEY, Value);
		if (currentCount >= size) {
			int Newsize = size * 2;
			HeapItem* NewArr = new HeapItem[Newsize];
			int i = 1;
			while (i < size) {
				NewArr[i] = arr[i];
				i++;
			}
			currentCount = i;
			size = Newsize;
			delete[] arr;
		}
		arr[++currentCount] = item;
		for (int i =currentCount; i / 2 > 0 && arr[i / 2].Key > arr[i].Key; i = i / 2)
		{
			swap(arr[i / 2], arr[i]);
		}

	}
	void getMin(v& Retval) {
		if (arr) {
		Retval = arr[1].value;

		}

	}
	void DeleteMin() {
		swap(arr[1], arr[size--]);
		Heapify(1);
	}
	void DecreaseKey(int ind, v NEW_KEY_VALUE)
	{
		
		arr[ind].key==NEW_KEY_VALUE;
		for (int i = ind; i / 2 > 0 && arr[i / 2] > arr[i]; i = i / 2)
		{
			swap(arr[i / 2], arr[i]);
		}

	}
	bool is_Empty() {
		if (arr)
			return 1;
		return 0;
	}
	void Heapify(int i) {
		int l = 2 * i;
		int r = 2 * i + 1;
		int min = i;
		if (l <= size && arr[l] < min)
			min = l;
		if (r <= size && arr[r] < min)
			min = r;
		swap(arr[min], i);
			Heapify(min);

	}
	MinHeap() {
		arr = 0;
		size = 0;
		currentCount = 0;
	}
	~MinHeap() {
		if (arr)
			delete[] arr;
	}


private:
	HeapItem* arr;
	int size;
	int currentCount;
};

void main() {

	MinHeap<int, char> myHeap(6);
	myHeap.insert(51, 'h');
	myHeap.insert(2, 'e');
	myHeap.insert(75, 'i');
	myHeap.insert(69, 'm');
	//myHeap.insert(15, 'a');
	myHeap.DeleteMin();
	char min;
	myHeap.getMin(min);
	cout << min;
}
