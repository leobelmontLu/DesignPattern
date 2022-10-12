// SortAlgorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <vector>
#include <iostream>
#include <string>
using namespace std;

#define Print(x) std::cout << x << std::endl
/**
* 排序算法
*/
//冒泡排序:临近的2个元素进行比较，由于是临近的2个元素比较 所以不用担心指向同一个元素位置
std::vector<int>& BubbleSort(std::vector<int>& _inData)
{
    bool bChange = true;
    while (bChange)
    {
        bChange = false;
        for (int i = 0; i < _inData.size() - 1; i++)
        {
            if (_inData[i] > _inData[i + 1])
            {
                bChange = true;
                swap(_inData[i], _inData[i + 1]);
            }
        }
    }
	return _inData;
}
//快速排序：先指定一个基准值，把小于该基准值的元素放在左边，大于该基准值的放在右边，然后再对左右分别做递归操作
std::vector<int>& QuickSort(std::vector<int>& _inData, int begin, int end)
{
    if (begin == end) return _inData;
    int i, j, ReferenceValue;
    i = begin;
    j = end;
    ReferenceValue = _inData[begin];
    while (i != j)
    {
        while (i < j && _inData[i] <= ReferenceValue)//左指针开始遍历找到第一个大于基准值的元素
        {
            i++;
        }
		while (i < j && _inData[j] >= ReferenceValue)//右指针开始遍历找到第一个大于基准值的元素
		{
			j--;
		}

        if (i < j)
        {
            swap(_inData[i], _inData[j]);
        }
    }
    //此时i指向的是第一个大于基准值的元素的位置，所以i-1是最后一个小于基准值的位置
    _inData[begin] = _inData[i - 1];
    _inData[i -1] = ReferenceValue;
    QuickSort(_inData, begin, i - 1);
    QuickSort(_inData, j, end);

	return _inData;
}
//插入排序:假定第一个数是最小，判断第二个数是否小于第一个数，如果是则把第二个数插入到第一个数前，然后再判断第三个数和前两个数。以此类推直到遍历结束
//只用这种写法是为了配合下面希尔排序的逻辑
vector<int>& InsterSort(std::vector<int>& _inData)
{
    int i, j, min_value;
    for (i = 1; i < _inData.size();i++)
    {
        min_value = _inData[i];
        for (j = i - 1; j >= 0 && _inData[j] > min_value; j--)
        {
            _inData[j + 1] = _inData[j];
        }
        //这时 j = -1
        _inData[j + 1] = min_value;
    }
	return _inData;
}
//希尔排序:其实就是再插入排序的基础上进行分步执行，当步长为1的时候
vector<int>& ShellSort(std::vector<int>& _inData)
{
    for (int k = _inData.size() / 2; k > 0; k /= 2)
    {
		int i, j, min_value;
		for (i = k; i < _inData.size(); i++)
		{
			min_value = _inData[i];
			for (j = i - k; j >= 0 && _inData[j] > min_value; j-=k)
			{
				_inData[j + k] = _inData[j];
			}
			//这时 j = -1
			_inData[j + k] = min_value;
		}
    }
	return _inData;
}
//选择排序:假设第一个数为最小的，然后和后面所有的数比较，更新最小的数所在的下标
vector<int>& SelectSort(std::vector<int>& _inData)
{
    int min_index;
    for (int i = 0; i < _inData.size();i++)
    {
        min_index = i;
        for (int j = i + 1; j < _inData.size(); j++)
        {
            if (_inData[j] < _inData[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(_inData[min_index], _inData[i]);
        }
    }
	return _inData;
}
//归并排序:用递归的方式把待排序数组分割成最小单位，然后排序。再归并为一个数组。
vector<int>& Merge(std::vector<int>& _inData, int L, int M, int R)
{
    int LEFT_SIZE = M - L + 1;
    int RIGHT_SIZE = R - M;
    std::vector<int> _LeftData;
    std::vector<int> _RightData;
    int i,j,k;
    for (i = L; i <= M; i++)
    {
        _LeftData.push_back(_inData[i]);
    }
	for (i = M + 1; i <= R; i++)
	{
        _RightData.push_back(_inData[i]);
	}
    i = 0;
    j = 0;
    k = L;
    while (i < LEFT_SIZE && j < RIGHT_SIZE)
    {
        _inData[k++] = _LeftData[i] < _RightData[j] ? _LeftData[i++] : _RightData[j++];
    }
    while (i < LEFT_SIZE)
    {
        _inData[k++] = _LeftData[i++];
    }
	while (j < RIGHT_SIZE)
	{
        _inData[k++] = _RightData[j++];
	}

	return _inData;
}
vector<int>& MergeSort(std::vector<int>& _inData, int L, int R)//L:起始位置的index,R是结束位置的index
{
    if (L == R) return _inData;

    int M = (L + R) / 2;
    MergeSort(_inData,L,M);
    MergeSort(_inData,M+1,R);
    Merge(_inData, L,M, R);
    return _inData;
}

////冒泡排序:临近的2个元素进行比较，由于是临近的2个元素比较 所以不用担心指向同一个元素位置
//std::vector<int>& BubbleSort(std::vector<int> &_inData)
//{
//    bool continue_flag = true;
//    int i = 0;
//    while (continue_flag)
//    {
//        continue_flag = false;
//        for (int j = 0; j < _inData.size() -1 - i; j++)
//        {
//            if (_inData[j] > _inData[j+1])
//            {
//                swap(_inData[j], _inData[j+1]);
//                continue_flag = true;
//            }
//        }
//        i++;
//    }
//    return _inData;
//}
////快速排序：先指定一个基准值，把小于该基准值的元素放在左边，大于该基准值的放在右边，然后再对左右分别做递归操作
//std::vector<int>& QuickSort(std::vector<int>& _inData,int begin,int end)
//{
//    if (begin == end)//只有一个元素就返回
//    {
//        return _inData;
//    }
//    int left, right, pivot; //左指针，右指针，基准值
//    left = begin;
//    right = end;
//    pivot = _inData[begin];//把第一个值作为基准值
//    while (left != right)//左右指针没重叠
//    {
//        //左指针先动
//		while (left < right && _inData[left] <= pivot)//左指针指向第一个大于基准值的数
//		{
//			left++;
//		}
//		while (left < right && _inData[right] >= pivot)//右指针指向第一个大于基准值的数
//		{
//			right--;
//		}
//        if (left < right)//把大于基准值的数放在右边，小于基准值的数放在左边
//        {
//            swap(_inData[left], _inData[right]);
//        }
//    }
//    //定位基准值的位置，基准值要用先动的指针来判断
//	//_inData[begin] = _inData[left - 1];//这里减1是把最后一个小于基准值的数和基准值对换位置
//	//_inData[left - 1] = pivot;
//    swap(_inData[left - 1], _inData[begin]);
//
//	QuickSort(_inData, begin, left - 1);
//	QuickSort(_inData, right, end);
//    return _inData;
//}
////插入排序:假定第一个数是最小，判断第二个数是否小于第一个数，如果是则把第二个数插入到第一个数前，然后再判断第三个数和前两个数。以此类推直到遍历结束
////只用这种写法是为了配合下面希尔排序的逻辑
//vector<int>& InsterSort(std::vector<int>& _inData)
//{
//    int i,j,temp;
//    for (i = 1; i < _inData.size();++i)
//    {
//        temp = _inData[i];
//        for (j = i - 1; j >= 0 && _inData[j] > temp;j--)
//        {
//            _inData[j + 1] = _inData[j];
//        }
//        _inData[j + 1] = temp;
//    }
//    return _inData;
//}
////希尔排序:其实就是再插入排序的基础上进行分步执行，当步长为1的时候
//vector<int>& ShellSort(std::vector<int>& _inData)
//{
//	int i, j, temp, increment;
//    for (increment = _inData.size()/3; increment > 0; increment/=3)
//    {
//		for (i = increment; i < _inData.size(); ++i)
//		{
//			temp = _inData[i];
//			for (j = i - increment; j >= 0 && _inData[j] > temp; j-= increment)
//			{
//				_inData[j + increment] = _inData[j];
//			}
//			_inData[j + increment] = temp;
//		}
//    }
//	return _inData;
//}
////选择排序:假设第一个数为最小的，然后和后面所有的数比较，更新最小的数所在的下标
//vector<int>& SelectSort(std::vector<int>& _inData)
//{
//    int min_index = 0;
//    for (int i = 0; i < _inData.size(); i++)
//    {
//        min_index = i;//假设i为最小的值
//        for (int j = i+1; j < _inData.size(); j++)
//        {
//            if (_inData[j] < _inData[min_index])
//            {
//                min_index = j;
//            }
//        }
//        if (min_index != i)
//        {
//            swap(_inData[min_index], _inData[i]);
//        }
//    }
//    return _inData;
//}
////归并排序:用递归的方式把待排序数组分割成最小单位，然后排序。再归并为一个数组。
//vector<int>& Merge(std::vector<int>& _inData, int L,int M,int R)
//{
//    //L是归并的左侧数组的第一个元素，M是左侧数组的最后一个元素同时也是右侧数组的第一个元素，R是右侧数组的最后一个元素
//    int LEFT_NUM = M - L + 1;//左侧数组的元素数量
//    int RIGHT_NUM = R - M;//右侧数组的元素数量
//    int i, j, k;
//    std::vector<int> left;
//    std::vector<int> right;
//    for (i = L; i <= M;i++)
//    {
//        left.push_back(_inData[i]);
//    }
//	for (i = M + 1; i <= R; i++)
//	{
//        right.push_back(_inData[i]);
//	}
//
//    i = 0; j = 0; k = L;
//    while (i < LEFT_NUM && j < RIGHT_NUM)
//    {
//        _inData[k++] = left[i] > right[j] ? right[j++] : left[i++];
//    }
//
//    while (i < LEFT_NUM)
//    {
//        _inData[k++] = left[i++];
//    }
//	while (j < RIGHT_NUM)
//	{
//		_inData[k++] = right[j++];
//	}
//    return _inData;
//}
//vector<int>& MergeSort(std::vector<int>& _inData,int L, int R)//L:起始位置的index,R是结束位置的index
//{
//    if (L == R) return _inData;
//    int M = (L+R) / 2;
//    MergeSort(_inData,L,M);
//    MergeSort(_inData,M+1,R);
//    Merge(_inData,L,M,R);
//}
//示例代码
/*********************************************************************************************************************************/
////选择排序：假设第i个为最小值，寻找剩下的值中小于第i个值的index，如果index发生改变，交换2个值
//std::vector<int>& SelectSort(std::vector<int>& _inData)
//{
//    int i, j, minIndex;
//    for (i = 0; i < _inData.size()-1;i++)
//    {
//        minIndex = i;
//        for (int j = i + 1;j < _inData.size();j++)
//        {
//            if (_inData[minIndex] > _inData[j])
//            {
//                minIndex = j;
//            }
//        }
//
//        if (minIndex != i)
//        {
//            swap(_inData[i], _inData[minIndex]);
//        }
//    }
//    return _inData;
//}
//
////插入排序：假设第一个数最小，
//std::vector<int>& InsterSort(std::vector<int>& _inData)
//{
//    int i, j, temp;
//    for (i = 1; i < _inData.size();i++)
//    {
//        temp = _inData[i];
//        for (j = i; j > 0 && _inData[j-1] > temp; j--)
//        {
//            _inData[j] = _inData[j - 1];
//        }
//        _inData[j] = temp;
//    }
//    return _inData;
//}
////希尔排序：其实就是再插入排序的基础上先按照一个系数进行局部的排序
//std::vector<int>& ShellSort(std::vector<int>& _inData)
//{
//    int i, j, temp, increment;
//    for (increment = _inData.size()/2; increment > 0; increment/=2)
//    {
//        for (i = increment; i < _inData.size();i++)
//        {
//            temp = _inData[i];
//            for (j = i - increment; j >=0&&_inData[j] > temp; j -= increment)
//            {
//                _inData[j + increment] = _inData[j];
//            }
//            _inData[j + increment] = temp;
//        }
//    }
//    return _inData;
//}

////快速排序:先指定一个基准值，把小于该基准值的元素放在左边，大于该基准值的放在右边，然后再对左右分别做递归操作
//std::vector<int>& QuickSort(std::vector<int>& _inData,int begin, int end)
//{
//    int i, j, pivot;
//    i = begin;
//    j = end;
//    pivot = _inData[i];
//
//    while (i !=  j)
//    {
//        //从右往左寻找小于基准值的element
//        while (_inData[j] >= pivot && i < j)
//        {
//            j--;
//        }
//        //从左往右寻找大于基准值的element
//        while (_inData[i] <= pivot && i < j)
//        {
//            i++;
//        }
//        //交换2个值
//		if (i < j)
//		{
//			swap(_inData[i], _inData[j]);
//		}
//    }
//	//设置基准值的位置并且开始分别对左右进行递归
//	_inData[begin] = _inData[i];
//	_inData[i] = pivot;
//
//	QuickSort(_inData, begin, i - 1);
//	QuickSort(_inData, i + 1, end);
//
//    return _inData;
//}

int main()
{
	std::vector<int> _inData = { 11,5,1,4,2,3,6,7,9,8,10,12 };
    SelectSort(_inData);
    //QuickSort(_inData,0, _inData.size() - 1);
    //MergeSort(_inData,0, _inData.size() - 1);
	for (int i = 0; i < _inData.size(); i++)
	{
		Print(_inData[i]);
	}
   /* char* p = new char[4];
    new(p) char('a');
    new(p+1) char('b');
    new(p+2) char('c');
    new(p+3) char('d');
    Print(p[0]);
    Print(p[1]);
    Print(p[2]);
    Print(p[3]);*/


	/* std::vector<int> a = {2,3,4,5,6,7,1,3,5,6,1,2};
	 for (int i = 0; i < a.size();)
	 {
		 if (a[i] == 1)
			 a.erase(a.begin() + i);
		 else
		 {
			 std::cout << a[i] << std::endl;
			 ++i;
		 }
	 }*/

	/*std::vector<int>_vecA = { 10,4,6,2,1,5,3,7,8,9 };
	_vecA = ShellSort(_vecA);
	for (auto element : _vecA)
	{
		Print(element);
	}*/
    //FindVectorHasSameElement(_vecA) ? std::cout << "有重复元素" << std::endl : std::cout << "没有重复元素" << std::endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
