#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
实现 string 常见的操作：
（ 1）构造、赋值:
（ 2）基本操作： size(), empty(), push_back(), pop_back(), insert(), erase(), clear();
（ 3） string 特有操作： substr(), append(), replace(), find()系列函数, compare(), strstr()
*/
void myStringTest()
{
	cout << "---------this is class string demo--------------------------" << endl;
	string str1 = "hello world";
	cout << "the length of str1： " << str1.size() << endl; // 11.


	str1.push_back('!'); //在尾部添加字符
	cout << "after pushing, str1 is: " << str1 << endl;


	auto ret = str1.insert(str1.begin() + 5, '@');// 参数为迭代器，插入的是字符，返回的是指向插入元素的迭代器
	cout << "after inserting, str1 is : " << str1 << endl;
	cout << "插入返回的迭代器所指向的值为： " << *ret << endl;


	auto ret1 = str1.insert(6, "#"); //参数为下标的，插入的是字符串，返回的是插入之后 str1 的引用,记住字符串下标是从 0 开始的
	cout << "after inserting, str1 is : " << str1 << endl;
	cout << "插入返回的值为： " << ret1 << endl;


	auto ret2 = str1.erase(str1.begin() + 5); //接受迭代器版本的，返回删除元素的下一个元素的迭代器
	cout << "after earsing , str1 is: " << str1 << endl;
	cout << "返回的迭代器指向元素为： " << *ret2 << endl;


	auto ret3 = str1.erase(5, 1); //接受下标参数的，接受删除长度，返回删除后的字符串
	cout << "after earsing , str1 is: " << str1 << endl;
	cout << "返回删除后的字符串为： " << ret3 << endl;


	//string s.substr(pos, n) //n 若缺失，到结尾，即n不写，默认到字符串末尾
	string str2 = str1.substr(0, 5); //从 0 开始，长度为 5 的子串
	cout << "after substr, str2 is :" << str2 << endl;


	str1.append("!!!"); //在尾部添加子串
	cout << "after appending, str1 is :" << str1 << endl;


	//string &s.replace(range, args) //将 range 范围内的元素，替换为 args，可以不一样长
	//举例几种常见的：
	str1.replace(5, 1, "###"); //(pos, len, str)形式
	cout << "after replace, str1 is : " << str1 << endl;


	str1.replace(str1.begin() + 5, str1.begin() + 7, "%%%"); //(iterator1, iterator2, string)形式
	cout << "after replace, str1 is : " << str1 << endl;


	//s.compare() ，目前就记住这一个就行，多了也记不住
	auto ret4 = str1.compare(str2); // compare用于比较两个字符串是否相等。如果相等则输出为0，str1 > str2 输出1，str1 < str2输出-1。
	if (ret4 == 1)
	{
		cout << "str1 > str2" << endl;
	}
	else if (ret4 == -1)
	{
		cout << "str1 < str2" << endl;
	}
	else
	{
		cout << "str1 = str2" << endl;
	}	


	/*
	find 系列函数：
	(1) s.find(args) //查找 s 中第一次出现的位置,并返回子串在主串中第一个字符的下标
	(2) s.rfind(args) //查找最后一个...
	(3) s.find_first_of(args) //在 s 中查找 args 中任何一个字符的第一次出现的位置，
	(4) s.find_last_of(args) //在 s 中查找 args 中任何一个字符最后一次出现的位置。
	(5) s.find_first_not_of(args) //在 s 中查找第一个不在 args 中的字符
	(6) s.find_last_not_of(args) //查找最后一个不在 args 中的字符
	*/
	auto pos = str1.find(str2); // strstr(char *, char *)
	cout << "str2 is at the pos : " << pos << " of str1" << endl;

	string numbers("01234556789");
	string name("r2d2");
	auto pos1 = name.find_first_of(numbers);
	cout << "number first at the pos : " << pos1 << " of name" << endl;


	// 元素计数
	auto cnt = count(numbers.begin(), numbers.end(), '5');
	cout << "cnt : " << cnt << endl;


	// 字符串拷贝
	string str3;
	str3 = str2;
	cout << "str3 : " << str3 << endl;
}

// 分割字符串
static void SplitString(const string& s, vector<string>& v, const string& c)
{
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));
		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
	{
		v.push_back(s.substr(pos1));
	}
}

// 字符串数组转为int数组
static void StringToInt(vector<string>& s, vector<int> &v)
{
	for (auto i = 0; !s.empty(); i++)
	{
		v.push_back(std::stoi(s.front()));
		s.erase(s.begin());
	}
}


int main16165168(void)
{
	myStringTest();

	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	system("pause");
	return 0;
}