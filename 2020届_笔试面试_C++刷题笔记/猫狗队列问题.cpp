#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

/*
实现一种猫狗队列的结构，要求如下：
用户可以调用add方法将cat类或dog类的实例放入队列中；
用户可以调用pollAll方法，将队列中所有的实例按照队列先进先出的顺序依次弹出；
用户可以调用pollDog方法，将队列中dog的实例按照队列先进先出的顺序依次弹出；
用户可以调用pollCat方法，将队列中cat的实例按照队列先进先出的顺序依次弹出；
用户可以调用isEmpty()方法，检查队列中所有的实例是否为空；
用户可以调用isDogEmpty()方法，检查队列中dog的实例是否为空；
用户可以调用isCatEmpty()方法，检查队列中cat的实例是否为空；

思想：基本方法是写一个带有时间戳的类型PetCount，使其含有一个用于记录先后顺序的计数器count，
每次入队的时候根据类型进入对应的队列，并赋予独一无二的时间戳。出队的时候根据要求比较先后时间即可。
*/

class Pet {
	string type;
public:
	Pet(string type) {
		this->type = type;
	}
	string getPetType() {
		return this->type;
	}
};

class Dog :public Pet {
public:
	Dog() :Pet("Dog") {}
	Dog(string type) : Pet(type) {}
};

class Cat :public Pet {
public:
	Cat() : Pet("Cat") {}
	Cat(string type) : Pet(type) {}
};

/*
这里Pet* pet;使用指针的原因是，C++中父类即使用来保存子类，也不能再次转换成子类，因为数据会被截断。
只有使用指针才能实现类的转换。另一种更方便的方式是定义两种Count类，分别存储猫狗两种类。
*/
class PetCount {
	Pet* pet;
	int count; // 每个宠物各自的时间戳
public:
	PetCount(Pet* pet, int cnt) {
		this->pet = pet;
		this->count = cnt;
	}
	Pet* getPet() {
		return pet;
	}
	int getCount() {
		return this->count;
	}
	string getPetType() {
		return pet->getPetType();
	}
};

class DogCatQueue {
	queue<PetCount>catq;
	queue<PetCount>dogq;
	int count; // 所有宠物总的时间戳
public:
	DogCatQueue() :count(0) {}
	void add(Pet *pet) {
		if (pet->getPetType().find("dog") )
		{
			dogq.push(PetCount(pet, ++count)); // pet是在主函数中new出来的，所以它不是临时对象
		}
		else
		{
			catq.push(PetCount(pet, ++count));
		}
	}
	//void add(Dog *d) {
	//	dogq.push(PetCount(d, ++count));
	//}
	//void add(Cat *c) {
	//	catq.push(PetCount(c, ++count));
	//}
	bool empty() {
		return dogq.empty() && catq.empty();
	}
	bool DogEmpty() { return dogq.empty(); }
	bool CatEmpty() { return catq.empty(); }

	Cat *pollCat() {
		Cat* r = static_cast<Cat*>(catq.front().getPet());
		catq.pop();
		return r;
	}
	Dog *pollDog() {
		Dog*r = static_cast<Dog*>(dogq.front().getPet());
		dogq.pop();
		return r;
	}
	Pet* pollAll() {
		if (empty())return nullptr;
		else if (DogEmpty())return pollCat();
		else if (CatEmpty())return pollDog();
		cout << dogq.front().getPetType() << " Count = " << dogq.front().getCount() << endl;
		cout << catq.front().getPetType() << " Count = " << catq.front().getCount() << endl;
		return (dogq.front().getCount() < catq.front().getCount()) ? (Pet*)pollDog() : (Pet*)pollCat();
	}
};

int main10011011112120020200(void)
{
	DogCatQueue myqueue;
	Dog *dog1 = new Dog("dog1");
	Cat *cat1 = new Cat("cat1");
	Dog *dog2 = new Dog("dog2");
	Cat *cat2 = new Cat("cat2");
	Dog *dog3 = new Dog("dog3");
	Cat *cat3 = new Cat("cat3");

	myqueue.add(dog1);
	myqueue.add(cat1);
	myqueue.add(dog2);
	myqueue.add(cat2);
	myqueue.add(dog3);
	myqueue.add(cat3);

	for (int i = 0; (!myqueue.CatEmpty() || !myqueue.DogEmpty()); ++i)
	{
		cout << myqueue.pollAll()->getPetType() << endl;
	}

	cout << "Write By JZQ!" << endl;
	//自动排版：ctrl+k+F
	return 0;
}