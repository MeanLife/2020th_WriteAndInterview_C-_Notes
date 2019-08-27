#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/*
（ 1）简单查找算法
（ 1） find(beg, end, val) //若找到指向指定元素迭代器,返回指向元素的迭代器，若没找到，则返回end迭代器
（ 2） find_if(beg, end, unaryPred) //返回第一个满足 unaryPred(一元谓词)的元素,否则返回end迭代器
（ 3） count(beg, end, val) //返回val一共有多少个
（ 4） count_if(beg, end, val) //满足条件的一共有多少个
（ 5） search(beg1, end1, beg2, end2) //子序列 2 在序列 1 中所处的位置
（ 6） find_first_of(beg1, end1, beg2, end2) //返回第二个序列任意元素在第一个范围内出现的位置
（ 7） rfind(beg1, end1, beg2, end2) //和 search 相反，返回最后一个出现的子序列的位置


（ 2）其他只读算法
（ 1） for_each(beg, end, unaryOp) //对每个元素使用可调用对象
（ 2） equal(beg1, end1, beg2) //如果输入序列每个元素都和 beg2 开始的序列相等，则返回 true


（ 3）二分搜索算法
（ 1） lower_bound(beg, end, val) //返回指向第一个  大于等于  val 的迭代器
（ 2） upper_bound(beg, end, val) //返回指向第一个  大于  val 的迭代器
（ 3） equal_range(beg, end, val) //返回以上一个 pair 包含以上两个函数返回参数
（ 4） binary_search(起始地址，结束地址，要查找的数值)  返回的是是否存在这么一个数，是一个bool值。

（ 4）写容器算法
（ 1）暂不总结；


（ 5）划分算法
（ 1） is_partitioned(beg, end, unaryPrey) //若满足谓词的在前，不满足在后，则返回 true, 空也是 true
（ 2） partitioned_copy(beg, end, dest1, dest2, unaryPred) //将满足谓词的元素放在 dest1 中，将不满足拷贝在 dest2 中，
														 // 返回一个 pair,first 指向 dest1 的末尾， second 指向 dest2 的末尾


（ 6）排序算法
（ 1） sort(beg, end) //给容器排序
（ 2） stable_sort(beg, end, comp) //稳定排序
（ 3） is_sorted(beg, end) //返回 bool，表示是否有序
（ 4） is_sorted_until(beg, end) //返回最长有序子序列的尾后迭代器
（ 5） remove(beg, end, val) //删除元素 val，返回指向删除最后一个元素的迭代器
（ 6） remove_if(beg, end, unaryPred) //删除满足谓词的元素，返回指向删除最后一个元素的迭代器
（ 7） unique(beg, end, val) //重排元素，对于重复元素重新排在最大不重复子序列的尾后迭代器，一般 sort 之后使用该元素将重复元素放在最大不重复子序列的后面，然后可以使用 erase 删除
（ 8） reverse(beg, end) //翻转序列


（ 7）最大最小值算法
（ 1） min(val1, val2)
（ 2） max(val1, val2)
（ 3） min_element(beg, end) //返回指向最小值的迭代器
（ 4） max_element(beg, end) //返回指向最大值的迭代器
（ 5） minmax_element(beg, end) //返回 pair 指向（ min, max）的两个迭代器
（ 8）数值算法
（ 1） accumulate(beg, end, init) //求容器和， init 设定为初值，返回和
*/
void myAlgorithmTest()
{
	std::cout << "----------------------------this is class Algorithm demo------------------------" << std::endl;
}



int main123222222222222222221231(void)
{
	myAlgorithmTest();

	
	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	system("pause");
	return 0;
}