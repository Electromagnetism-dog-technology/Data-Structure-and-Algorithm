#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class myquickSort
{
public:
	void quickSort(vector<int>& L, int left, int right)
	{
		int low, high, m, pivot, temp;
		low = left; high = right;//将枢轴关键字备份到left

		//三数取中法
		m = (low + high) / 2;
		if (L[low] > L[high]) swap(L[low], L[high]);
		if (L[m] > L[high]) swap(L[m], L[high]);
		if (L[m] > L[low]) swap(L[m], L[low]);

		//表的两端交替向中间扫描
		pivot = L[low];
		while (low < high)
		{
			while (low < high && L[high] >= pivot)
				high--;
			while (low < high && L[low] <= pivot)
				low++;
			if (low < high)
				swap(L[low], L[high]);
		}


		if (left < low)
		{
			//用枢轴数值替换回L[low]
			swap(L[left], L[low]);
			quickSort(L, left, low - 1);//对低子表递归排序
			quickSort(L, low + 1, right);//对高子表递归排序
		}
	}
};


int main()
{
	vector<int>arr = { 1,5,7,2,9 };
	int len = arr.size();
	myquickSort newquickSort;
	newquickSort.quickSort(arr, 0, len-1);
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
	return EXIT_SUCCESS;
}