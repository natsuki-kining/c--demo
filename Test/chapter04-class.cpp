#include <iostream>

using namespace std;

class Point {
	private:
		int x, y;
	public:
		//�޲ι��캯��
		Point():x(0),y(0)
		{
			cout << "����Ĭ�Ϲ��캯��" << endl;
		}
		//�вι��캯��
		Point(int a,int b) :x(a), y(b)
		{
			cout << "�����вι��캯����x:" << x << ",y:" << y << endl;
		}
		//���ƹ��캯��
		Point(Point& c)
		{
			x = c.x;
			y = c.y;
			cout << "���ø��ƹ��캯����x:" << x << ",y:" << y << endl;
		}
		//��������
		~Point() {
			cout << "������������" << endl;
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
	//thisָ��
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

//���ࡢ���ϸ��޲ι��캯������������

void main() {
	cout << "��ȥmain����" << endl;
	//ʹ�������

	Point A, B;//����Point���͵Ķ���
	Point* p = &A; //����ָ�����A��Point���͵�ָ��
	Point& R = B; //����RΪpoint���Ͷ���B������
	//��������ö�����ʹ���������.�����ʶ���ĳ�Ա��ָ����ʹ�á�->���������
	A.Display();
	A.Setxy(10, 20);
	A.Display();
	A.Move(2,3);
	print(A);
	B = A;
	print(B);

	printX(R);
	printX(p);

	//���캯��
	Point C(3, 5);
	Point array[2];


	//���ƹ��캯��
	Point D(A);

	//���������������delete
	Point* ptr = new Point[2];
	delete []ptr; //Ҫ����[]���������ڱ�������ǰ��

	cout << "�˳�main����" << endl;
}

