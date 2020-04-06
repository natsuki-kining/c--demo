#include "equation.h"
using namespace std;

void Read(float&, float&, float&);

void main() {
	float a, b, c;
	cout << "这是一个求一元二次方程ax2+bx+c=0的根的程序。" << endl;
	for (;;) {
		Read(a, b, c);
		if (a == 0) return;
		FindRoot obj(a, b, c);
		obj.Find();
		obj.Display();
	}
	/*
	测试数据
	1,-2,1
	1,-3,2
	1,3,5
	*/
}

void Read(float& a, float& b, float& c) {
	cout << "输入方程系数a:";
	cin >> a;
	if (a == 0)
	{
		getchar();//消除回车影响。
		return;
	}
	cout << "输入方程系数b:";
	cin >> b;
	cout << "输入方程系数c:";
	cin >> c;
}