#include "希尔排序算法.h"

/*
在直接插入排序算法中，每次插入一个数，使有序序列只增加1个节点，
并且对插入下一个数没有提供任何帮助。如果比较相隔较远距离（称为
增量）的数，使得数移动时能跨过多个元素，则进行一次比较就可能消除
多个元素交换。
算法先将要排序的一组数按某个增量d分成若干组，每组中记录的下标相差d.
对每组中全部元素进行排序，然后再用一个较小的增量对它进行，在每组中
再进行排序。当增量减到1时，整个要排序的数被分成一组，排序完成。
*/

template<class T>
void ShellSort(T *array, int len)
{
	T temp;
	int gap = len;////初始化划分增量
	do 
	{
		//业界统一实验的 平均最好情况 经过若干次后，收敛为1(跳出循环)
		gap = gap / 3 + 1;
		for (int i = gap; i < len; i += gap) //对每个划分进行   直接插入法排序
		{
			temp = array[i];//找到当前这个元素
			int j = 0;
			for (j = i - gap; j >= 0; j -= gap)//这个元素的和前面有序序列比较，直到下标0
			{
				if (array[j] > temp)//将大于temp的数向后移动
				{
					array[j + gap] = array[j];
				}
				else
				{
					break;//不再比temp大了，就不移动了
				}
			}
			//移动完，就插入元素
			array[j + gap] = temp;//这里，因为j-gap，跳出循环时，j多减了一次gap
		}
	} while (gap > 1);
}

