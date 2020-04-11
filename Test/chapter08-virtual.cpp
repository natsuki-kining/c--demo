#include <iostream>
using namespace std;

const double PI = 3.14159;

class Point {
private:
	double x, y;
public:
	Point(double i,double j):x(i),y(j){}
	virtual double area() { return 0; }
};

class Circle:public Point{
	private:
		double radius;
	public:
		Circle(double a, double b, double c) : Point(a, b),radius(c){}

		double area()
		{
			return radius * radius * PI;
		}
};

void print(Point* p)
{
	cout << p->area() << endl;
}

void print(Point& p)
{
	cout << p.area() << endl;
}


class A {
public:
	A() {}
	virtual void func() {
		cout << "constructed class A" << endl;
	}
	~A(){}
	virtual void fund() {
		cout << "delete class A" << endl;
	}
};


class B: public A {
public:
	B() { func(); }
	virtual void fun() {
		cout << "invoke class B method fun...";
		func();
	}
	~B() { fund(); }
};


class C : public B {
public:
	C() { func(); }
	void func() {
		cout << "class C" << endl;
	}
	~C() { fund(); }
	void fund() {
		cout << "delete class C" << endl;
	}
};

void print(A *a,void(A::* af)()) {
	(a->*af)();
}

void main() 
{
	Point po(2.1, 3.2);
	Circle ci(5.6, 7.8, 2.5);

	Point* pc = &ci;
	Point& rc = ci;

	print(po);
	print(pc);
	print(rc);

	cout << endl << endl << "构造函数和析构函数调用虚函数：" << endl;
	C c;
	c.fun();


	cout << endl << endl << "类成员函数的指针与多态性：" << endl;
	A* a = &c;
	void(A::*af)();
	af = &(A::fund);
	print(a,af);

	cout << endl << "退出main函数" << endl << endl;
}
