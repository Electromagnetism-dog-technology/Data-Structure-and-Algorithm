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
		low = left; high = right;//������ؼ��ֱ��ݵ�left

		//����ȡ�з�
		m = (low + high) / 2;
		if (L[low] > L[high]) swap(L[low], L[high]);
		if (L[m] > L[high]) swap(L[m], L[high]);
		if (L[m] > L[low]) swap(L[m], L[low]);

		//������˽������м�ɨ��
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
			//��������ֵ�滻��L[low]
			swap(L[left], L[low]);
			quickSort(L, left, low - 1);//�Ե��ӱ�ݹ�����
			quickSort(L, low + 1, right);//�Ը��ӱ�ݹ�����
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