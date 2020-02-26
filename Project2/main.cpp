#include <iostream>
template<typename T>
void mySwap(T *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
bool twoSort(const int *arr, int p, int r, int target)
{
	if (arr == NULL) return false;

	int mid = (p + r) / 2;

	if (arr[mid] == target) return true;
	if (p > r) return false;

	else if (arr[mid] > target)
	{
		twoSort(arr, p, --mid, target);
	}
	else if (arr[mid] < target)
	{
		twoSort(arr, ++mid, r, target);
	}

	else
	{
		return false;
	}


}
void test()
{
	int arr[8] = { 4,5,6,7,8,8,9,10 };
	int target = 4;
	bool find = twoSort(arr, 0, 7, target);
	if (find)
	{
		printf("find");
	}
	else
		printf("not find");


}
/*===========================��Ŀһ====================================*/
//��Ŀһ :����һ������arr����һ����num�����С�ڵ���num����������
//�����ߣ�����num��������������ұߡ�
void sort(int *arr, int p, int r, int num)
{
	//if (sizeof(arr) / sizeof(int) < 2) return;
	
	int left = p - 1;
	while (p < r)
	{
		if (arr[p] <= num)
		{
			mySwap(arr, ++left, p++);
			
		}
		else
		{
			p++;
		}

	}
}

void test01()
{
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	printf("%d", sizeof(arr) / sizeof(int));
	sort(arr, 0, 10, 2);
	//��ʾ
	for (int i = 0; i < 10; i++)
	{
		printf(" %d", arr[i]);
	}

}
/*������������������⣩
����һ������arr����һ����num�����С��num�������������
��ߣ�����num��������������м䣬����num�������������
�ұߡ�
Ҫ�����ռ临�Ӷ�O(1)��ʱ�临�Ӷ�O(N)
*/
//template<typename T>
void polandFlag(int *arr,int l,int r,int num)
{
	int left = l - 1;
	int right = r + 1;
	

	while (l< right)//�������֮ǰд��l<r
	{
		if (arr[l]<num)
		{
			mySwap(arr,++left,l++);
		}
		else if(arr[l] > num)
		{
			mySwap(arr, --right,l);
		}
		else
		{
			l++;
		}
	}
}

void test02()
{
	int arr[10] = {10,9,8,7,6,5,4,3,2,1};
	 int len=sizeof(arr) / sizeof(int);

	 polandFlag(arr, 0,len-1,3);
	 //��ʾ
	 for (int i = 0; i < len; i++)
	 {
		 printf(" %d", arr[i]);
	 }
}
/*===========================��Ŀ��====================================*/
int main()
{

	
	test02();
	return 0;
}