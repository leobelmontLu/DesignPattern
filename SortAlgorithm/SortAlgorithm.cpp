// SortAlgorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <vector>
#include <iostream>



#define Print(x) std::cout << x << std::endl
#define swap(x,y) x=x+y;y=x-y;x=x-y
//查询数组中是否有重复元素(数组元素为[1,n])
bool FindVectorHasSameElement(std::vector<int> &_inData)
{
    int temp = 0;
    for (int i = 0; i < _inData.size();)
    {
        //判断当前的值是否再它该在的位置
        temp = _inData[i];
        if (temp - 1 != i)
        {
            int _desIndex = temp - 1;
            if (temp != _inData[_desIndex])
            {
                //交换数据到对应位置
                swap(_inData[i], _inData[_desIndex]);
            }
            else
            {
                return true;
            }
        }
        else
        {
            i++;
        }
    }
    return false;
}

/**
* 排序算法
*/
//冒泡排序:临近的2个元素进行比较
std::vector<int>& BubbleSort(std::vector<int> &_inData)
{
    for (int i = 0; i < _inData.size();i++)
    {
        for (int j = 0; j < _inData.size()-1-i;j++)
        {
            if (_inData[j] > _inData[j+1])
            {
                swap(_inData[j], _inData[j + 1]);
            }
        }
    }
    return _inData;
}


/************************************************************************/



int main()
{
    std::vector<int>_vecA = {10,4,6,2,1,5,3,7,8,9};
    _vecA = BubbleSort(_vecA);
    for (auto element : _vecA)
    {
        Print(element);
    }
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
