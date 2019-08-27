#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/***************************************
4.strstr：寻找母串中是否存在某个子串（稍难）
实现想法：依次比对
***************************************/
// 指针法
static char * my_strstr(const char * source, const char * sub)
{
	if (source == nullptr || sub == nullptr)
	{
		return nullptr;
	}

	char *cur = const_cast<char *>(source);
	while (*cur)
	{
		char *p2 = const_cast<char *>(sub);
		bool flag = true;
		if (*cur == *p2)
		{
			char *p1 = cur; // 记录第一个相同的位置。
			while (*p2)
			{
				if (*p1 != *p2)
				{
					flag = false;
					break;
				}
				p1++;
				p2++;
			}
			if (flag == true)
			{
				return cur;
			}
		}
		cur++;
	}
	if (*cur == '\0')
	{
		cout << "未找到" << endl;
		return const_cast<char *>(sub);
	}
}


int main_my_strstr(void)
{
	const char * str = "fengcong is fucking too handsome";
	char *p = my_strstr(str, "is");
	cout << p << endl;

	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}