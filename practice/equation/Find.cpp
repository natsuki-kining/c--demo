#include "equation.h"
using namespace std;

void Read(float&, float&, float&);

void main() {
	float a, b, c;
	cout << "����һ����һԪ���η���ax2+bx+c=0�ĸ��ĳ���" << endl;
	for (;;) {
		Read(a, b, c);
		if (a == 0) return;
		FindRoot obj(a, b, c);
		obj.Find();
		obj.Display();
	}
	/*
	��������
	1,-2,1
	1,-3,2
	1,3,5
	*/
}

void Read(float& a, float& b, float& c) {
	cout << "���뷽��ϵ��a:";
	cin >> a;
	if (a == 0)
	{
		getchar();//�����س�Ӱ�졣
		return;
	}
	cout << "���뷽��ϵ��b:";
	cin >> b;
	cout << "���뷽��ϵ��c:";
	cin >> c;
}