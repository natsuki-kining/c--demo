#include <iostream>

using namespace std;

class Point {
	private:
		int x, y;
	public:
		//无参构造函数
		Point():x(0),y(0)
		{
			cout << "调用默认构造函数" << endl;
		}
		//有参构造函数
		Point(int a,int b) :x(a), y(b)
		{
			cout << "调用有参构造函数，x:" << x << ",y:" << y << endl;
		}
		//复制构造函数
		Point(Point& c)
		{
			x = c.x;
			y = c.y;
			cout << "调用复制构造函数，x:" << x << ",y:" << y << endl;
		}
		//析构函数
		~Point() {
			cout << "调用析构函数" << endl;
		}
		void Setxy(int a,int b);
		void Move(int a,int b);
		void Display() {
			cout << "x:" << x << ",y:" << y << endl;
		}
		int Getx() {
			return x;
		}
		int Gety() {
			return y;
		}
};


void Point::Setxy(int a, int b) {
	//this指针
	this->x = a;
	this->y = b;
}
void Point::Move(int a, int b) {
	x += a;
	y += b;
}

void print(Point a) {
	a.Display();
}

void printX(Point & a) {
	a.Display();
}

void printX(Point * a) {
	a->Display();
}

//空类、加上个无参构造函数能消除警告

void main() {
	cout << "进去main函数" << endl;
	//使用类对象

	Point A, B;//定义Point类型的对象
	Point* p = &A; //定义指向对象A的Point类型的指针
	Point& R = B; //定义R为point类型对象B的引用
	//对象和引用都可以使用运算符“.”访问对象的成员。指针则使用“->”运算符。
	A.Display();
	A.Setxy(10, 20);
	A.Display();
	A.Move(2,3);
	print(A);
	B = A;
	print(B);

	printX(R);
	printX(p);

	//构造函数
	Point C(3, 5);
	Point array[2];


	//复制构造函数
	Point D(A);

	//析构函数和运算符delete
	Point* ptr = new Point[2];
	delete []ptr; //要加上[]，并且是在变量名的前面

	cout << "退出main函数" << endl;
}

