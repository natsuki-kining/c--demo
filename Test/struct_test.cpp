#include <iostream>
using namespace std;

struct Student {
	int age;
	string name;
	double score;


	void PrintInfo() {
		cout << "age="<<age<<",name="<<name<<",socre="<<score<<endl;

	}

};

struct Point {
	private:
		double x, y;
	public:
		void Init(double x, double y) {
			this->x = x;
			this->y = y;
		}

		void Print() {
			cout << "x=" << x << "\ty=" << y << endl;
		}
};

struct Constructor {
	private: string name = "default";
	public:
		Constructor() {
			cout << "调用无参构造函数" << endl;
		}
		Constructor(string name) {
			this->name = name;
			cout << "调用有参构造函数" << endl;
		}
		void Print() {
			cout << "name = " << name << endl;
		}
};

//后面的就是结构体演变成类

void main() {
	Student stu;
	stu.age = 18;
	stu.name = "siri";
	stu.score = 100;
	stu.PrintInfo();


	Point p;
	p.Init(1, 3);
	p.Print();


	Constructor c1;
	c1.Print();

	Constructor c2("c2");
	c2.Print();
}