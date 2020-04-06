#include <iostream>
using namespace std;

class object {
	private:
		int val;
	public :
		object() :val(0) {
			cout << "调用object无参构造函数" << endl;
		}
		object(int i) :val(i) {
			cout << "调用object有参构造函数，val:" << val << endl;
		}
		~object() {
			cout << "delete object " << val << endl;
		}
};

class container {
	private :
		object one; //初始化顺序与对象成员产生的顺序有关
		object two; //排在前面的先初始化
		int data;
	public:
		container():data(0)
		{
			cout << "调用container无参构造函数" << endl;
		}
		container(int i,int j,int k);
		~container() {
			cout << "delete container " << data << endl;
		}
};

container::container(int i, int j, int k) :two(i), one(j)
{
	data = k;
	cout << "调用container有参构造函数，i:" << i << ",j:" << j << ",k:" << k << endl;
}


class StaticField {
	
	private:
		int n;
	public:
		static int x;
		static int getx() { return x; }
		static void setx() { ++x; }
		StaticField(int i) {
			n = i;
			cout << "调用 StaticField 有参构造函数，i:" << i << endl;
		}
		~StaticField() {
			cout << "delete StaticField " << n << endl;
		}
		int getn()
		{
			return n;
		}
		void inc()
		{
			++n;
		}
		friend int friendMethod(StaticField &);
};

int friendMethod(StaticField&f)
{
	cout << "调用友元函数，访问私有属性：" << f.x << "," << f.n << endl;
	return f.x + f.n;
}
int StaticField::x = 10; //初始化静态成员，main方法写不了

class A {
private:
	int val;
public:
	A(int i)
	{
		val = i;
	}
	int value(int i) 
	{
		return val + i;
	}
};

void main()
{
	cout << "进入main函数" << endl << endl << "对象成员初始化：" << endl;
	/**
	对象成员初始化：
		con1:
			先初始化object，调用object的无参构造函数 * 2，然后再初始化container
			先初始化one，再初始化two
		con2：
			调用container的有参构造函数，在初始化的时候调用object的有参构造函数，先初始化object，再初始化container
			先初始化two，再初始化one

		console:
			调用object无参构造函数
			调用object无参构造函数
			调用container无参构造函数
			调用object有参构造函数，val:2
			调用object有参构造函数，val:1
			调用container有参构造函数，i:1,j:2,k:3
			delete container 3
			delete object 1
			delete object 2
			delete container 0
			delete object 0
			delete object 0
	*/
	container con1, con2(1, 2, 3);

	cout << endl << endl << "静态成员：" << endl;
	//静态成员
	cout << "x:" << StaticField::x << endl;
	cout << "StaticField::getx():" << StaticField::getx() << endl;
	StaticField::setx();
	cout << "x:" << StaticField::x << endl;
	cout << "StaticField::getx():" << StaticField::getx() << endl;
	StaticField s(1);
	cout << "s.x:" << s.x << endl;

	//静态对象，只初始化一次
	cout << endl << endl << "静态对象：" << endl;
	for (int i = 0;i<3;i++)
	{
		static StaticField field1(1);
		StaticField field2(2);
	}

	//友元函数，能够调用私有属性，但是必须在类里面声明，使用friend修饰。
	cout << endl << endl << "友元函数：" << endl;
	StaticField field3(3);
	int result = friendMethod(field3);
	cout << "结果：" << result << endl;

	//类友元：整个类的成员函数均具有友元函数的性能。

	//const


	//指向类成员的函数指针
	cout << endl << endl << "类函数指针：" << endl;
	int(A :: * pfun)(int); //声明指向类A的成员函数的指针
	pfun = &(A :: value); //指针指向具体成员函数,不加&，vs上会报错。但是书上没有加。
	A objA(10); //创建A对象
	cout << (objA.*pfun)(15) << endl; //对象使用类的函数指针，必须用括号包起来。如果是指针对象调用使用“->”
	A* pc = &objA;
	cout << (pc->*pfun)(15) << endl; //指针对象使用类的函数指针


	cout << endl << endl << "退出main函数" << endl;
}