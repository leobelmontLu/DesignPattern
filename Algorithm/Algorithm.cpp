// SortAlgorithm.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <vector>
#include <iostream>
#include <string>
using namespace std;

#define Print(x) std::cout << x << std::endl
/*******************************************�����㷨**************************************************************************************/
//��ѯ�������Ƿ����ظ�Ԫ��(����Ԫ��Ϊ[1,n])
bool FindVectorHasSameElement(std::vector<int>& _inData)
{
    int temp = 0;
    for (int i = 0; i < _inData.size();)
    {
        //�жϵ�ǰ��ֵ�Ƿ��������ڵ�λ��
        temp = _inData[i];
        if (temp - 1 != i)
        {
            int _desIndex = temp - 1;
            if (temp != _inData[_desIndex])
            {
                //�������ݵ���Ӧλ��
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
//���ŵķ���
int scoreOfParentheses(std::string s)
{
    int Value = 0; // ��ֵ
    int pre = 0; //��һ�����ŵ�����
    std::vector<int> st;//��������ֵ
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
//����Ԫ��֮�������ֵ
// ���Ž⣬˼·����ά��i-1�������Сֵ��
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
//132 ģʽ:�Ӻ���ǰ������ʹ�õ���ջ �ҵ�����2��Ȼ���ж��Ƿ���1���ɡ�
//i < j < k ���� nums[i] < nums[k] < nums[j]
bool find132pattern(vector<int>& nums)
{
    vector<int> stack;
    int max_TowValue = INT_MIN;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] < max_TowValue)return true;//����1������

        while (!stack.empty() && nums[i] > stack.back())
        {
            //���µ���ջ��Ԫ�أ����Ҹ�������2��ֵ�������ǴӺ���ǰ���� ���Աض�����nums[k] < nums[j]��j < k
            max_TowValue = stack.back();
            stack.pop_back();
        }
        stack.push_back(nums[i]);
    }
    return false;
}
//���������ֵ
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
/*******************************************�����㷨**************************************************************************************/
int main()
{
   
}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
