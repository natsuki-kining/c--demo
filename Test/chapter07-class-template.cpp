#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

template<class T>
class Max4 {
	T a, b, c, d;
	T Max(T a, T b) {
		return (a > b) ? a : b;
	}
	public:
		Max4(T, T, T, T);
		T Max(void);
};

template<class T> //�����Ա���������ٴ�����ģ��
Max4<T>::Max4(T x1,T x2,T x3,T x4):a(x1),b(x2),c(x3),d(x4){}

template<class T>
T Max4<T>::Max(void)
{
	return Max(Max(a, b), Max(c, d));
}


template <typename T>
class Point {
	T x, y;
public:
	Point(T a, T b) 
	{
		x = a;
		y = b;
	}
	void display()
	{
		cout << "x=" <<x << ",y=" << y << endl;
	}
};
template<typename T>
class Line :public Point<T> {
	T x2, y2;
public:
	Line(T a, T b, T c, T d) :Point<T>(a, b)
	{
		x2 = c;
		y2 = d;
	}
	void display()
	{
		Point<T>::display();
		cout << "x2=" << x2 << ",y2=" << y2 << endl;
	}
};

void main()
{
	cout << "��ģ�壺" << endl;
	Max4<char> C('W', 'w', 'a', 'A');
	Max4<int> I(1,2,3,4);
	Max4<double> D(1.2,3.4,5.6,7.8);
	Max4<string> S("abc","def","ghi","jkl");

	cout << C.Max() << "," << I.Max() << "," << D.Max() << "," << S.Max() << endl << endl;


	cout << "��ģ��ļ̳к�������" << endl;
	Point<double> a(1.2, 4.6);
	a.display();
	Line<int> ab(1, 2, 3, 4);
	ab.display();

	cout << endl << endl;


	cout << "�����뷺��ָ�룺" << endl;
	double d_array[] = {1.1,2.2,3.3,4.4};
	vector<double> va(d_array, d_array + 4), vb(4);//���岢��ʼ������va
	typedef vector<double>::iterator iterator;	//�Զ���һ��������ָ���ʶ��iterator
	iterator first = va.begin();	//����ָ��firstָ��va����Ԫ��
	for (first; first < va.end(); first++) {
		cout << *first << " ";  //�������
	}
	cout << endl;
	for (-- first; first > va.begin(); first --) { 
		cout << *first << " ";  //�������
	}
	cout << endl;

	copy (va.begin(), va.end(), ostream_iterator<double>(cout," "));


	
}


