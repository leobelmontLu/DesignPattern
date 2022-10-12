// SortAlgorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <vector>
#include <iostream>
#include <string>
using namespace std;

#define Print(x) std::cout << x << std::endl
/*******************************************其他算法**************************************************************************************/
//查询数组中是否有重复元素(数组元素为[1,n])
bool FindVectorHasSameElement(std::vector<int>& _inData)
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
//括号的分数
int scoreOfParentheses(std::string s)
{
    int Value = 0; // 总值
    int pre = 0; //上一个符号的类型
    std::vector<int> st;//用来缓存值
    for (char c : s)
    {
        if (c == '(')
        {
            st.push_back(0);
        }
        else
        {
            int cur = st.back();
            st.pop_back();

            if (pre == '(')
                cur++;
            else
                cur *= 2;

            if (st.empty())
            {
                Value += cur;
            }
            else
            {
                st[st.size() - 1] += cur;
            }
        }
        pre = c;
    }
    return Value;
}
//增量元素之间的最大差值
// 最优解，思路就是维护i-1里面的最小值。
//int maximumDifference(vector<int>& nums) 
//{
//	int n = nums.size();
//	int ans = -1, premin = nums[0];
//	for (int i = 1; i < n; ++i) {
//		if (nums[i] > premin) {
//			ans = max(ans, nums[i] - premin);
//		}
//		else {
//			premin = nums[i];
//		}
//	}
//	return ans;
//}
int maximumDifference(vector<int>& nums)
{
    int _maximumDifference = -1;
    while (nums.size() > 1)
    {
        int _value = nums.back();
        nums.pop_back();
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (_value > nums[i])
            {
                _maximumDifference = max(_value - nums[i], _maximumDifference);
            }
        }
    }
    return _maximumDifference;
}
//132 模式:从后往前遍历，使用单调栈 找到最大的2，然后判断是否有1即可。
//i < j < k 并且 nums[i] < nums[k] < nums[j]
bool find132pattern(vector<int>& nums)
{
    vector<int> stack;
    int max_TowValue = INT_MIN;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] < max_TowValue)return true;//出现1，返回

        while (!stack.empty() && nums[i] > stack.back())
        {
            //更新单调栈的元素，并且更新最大的2的值。由于是从后往前遍历 所以必定满足nums[k] < nums[j]且j < k
            max_TowValue = stack.back();
            stack.pop_back();
        }
        stack.push_back(nums[i]);
    }
    return false;
}
//插入后的最大值
string maxValue(string n, int x)
{
    bool bNegativeNumber = false;
    string max_Value = "";
    if (n[0] == '-')
    {
        bNegativeNumber = true;
        n = n.substr(1);
    }
    int lastIndex = n.length();
    for (int i = 0; i <= lastIndex; i++)
    {
        string _str = n;
        _str.insert(i, to_string(x));
        if (!bNegativeNumber)
        {
            if (max_Value < _str || max_Value == "")
            {
                max_Value = _str;
            }
        }
        else
        {
            if (max_Value > _str || max_Value == "")
            {
                max_Value = _str;
            }
        }
    }
    if (bNegativeNumber)
    {
        max_Value = "-" + max_Value;
    }
    return max_Value;
}
/*******************************************其他算法**************************************************************************************/
int main()
{
   
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
