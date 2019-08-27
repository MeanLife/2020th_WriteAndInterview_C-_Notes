#include "iostream"
using namespace std;
/*
Vector型的一维二维数组，看STL容器操作。
*/

int **get_2D_array(int &N, int &M) //注意一点，局部函数分配的内存传递不出来,方法一
{
	static int **array_2D_temp = new int *[N];//二级指针指向N个一级指针，
	for (int i = 0;i < N; i++)
	{
		array_2D_temp[i] = new int[M];
	}
	return array_2D_temp; //他是局部变量的地址，定义为static才能向外返回。
}

void get_2D_array(int **array_2D, int &N, int &M)//方法二：主调函数分配二维数组的内存，被调函数分配一维数组的内存
{
	if (array_2D == nullptr || N < 0 || M < 0)
	{
		return;
	}
	for (int i = 0; i < N; i++)
	{
		array_2D[i] = new int[M];
	}
}

void deldete_2D_array(int **array_2D, int &N, int &M)
{
	if (array_2D == nullptr || N < 0 || M < 0)
	{
		return;
	}
	for (int i = 0; i < N; i++)
	{
		delete []array_2D[i];
		array_2D[i] = nullptr;
	}
	delete array_2D;
	array_2D = nullptr;
	//事实上二维数组空间的释放还可以更简单地用：delete [] array2D;
}

void printf_2D_array(int **array_2D, int &N, int &M)
{
	if (array_2D == nullptr || N < 0 || M < 0)
	{
		return;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0;j <M;j++)
		{
			cout << array_2D[i][j] << '\t';
		}
		cout << endl;
	}
}

void write_value_2D_array(int **array_2D, int &N, int &M)
{
	if (array_2D == nullptr || N < 0 || M < 0)
	{
		return;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> array_2D[i][j];
		}
	}
}



int main_0233333(void)
{
	int N = 0, M = 0;  //N行M列
	cin >> N >> M;
	////////////////////////////////////方法二,,这个方法更常用，
	int **array_2D = new int *[N];  //二级指针指向N个一级指针
	get_2D_array(array_2D, N, M);
	////////////////////////////////////

	/////////////////////////////////方法一
	//int **array_2D = nullptr;
	//array_2D = get_2D_array(N, M); //注意一点，局部函数分配的内存的地址传递不出来,
	/////////////////////////////////
	
	write_value_2D_array(array_2D, N, M);

	printf_2D_array(array_2D, N, M);

	deldete_2D_array(array_2D, N, M);


	cout << "JZQ!" << endl;
	system("pause");
	return 0;
	//自动排版：ctrl+K,ctrl+F
}