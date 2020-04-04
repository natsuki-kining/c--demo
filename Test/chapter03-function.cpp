#include <iostream>
#include <string>
#include <complex>

using namespace std;

void swap1(string, string);
void swap2(string *, string *);
void swap3(int[]);
void swap4(string&, string&);
void swap5(string str1="str1",string str2="str2");
void swap6(const string&);
int& index1(int i);
int* index2(int&);
inline int isnumber(char);
double max(double, double);
int max(int,int);
char max(char,char);
string max(string, string);

template <class T>
T maxX(T v1, T v2)
{
	return v1 > v2 ? v1 : v2;
}

void printer(complex<int>);
void printer(complex<double>);

template <class T>
void printerX(complex<T> v) {
	cout << "real is " << v.real() << ", image is " << v.imag() << endl;
}

template <typename T> //ʹ��typename����class
T maxXX(T v1, T v2)
{
	return v1 > v2 ? v1 : v2;
}


int main() {

	//ʹ��string��Ķ�����Ϊ��������
	string str1 = "str1", str2 = "str2";
	swap1(str1, str2);
	cout << "������>> str1:" << str1 << "; str2:" << str2 << endl << endl;

	//ʹ��string���ָ����Ϊ��������
	str1 = "str1", str2 = "str2";
	swap2(&str1, &str2);
	cout << "������>> str1:" << str1 << "; str2:" << str2 << endl << endl;

	//����������ʵ��
	int a[] = {3,8};
	swap3(a);
	cout << "������>> a[0]:" << a[0] << "; a[1]:" << a[1] << endl << endl;

	//������Ϊ��������
	str1 = "str1", str2 = "str2";
	swap4(str1, str2);
	cout << "������>> str1:" << str1 << "; str2:" << str2 << endl << endl;

	//Ĭ�ϲ���
	swap5();
	cout << endl << endl;

	//ʹ��const��������
	str1 = "str1";
	swap6(str1);
	cout << "������>> str:" << str1 << endl << endl;


	//�������õĺ��� �����⣬���������16
	index1(3) = 16;
	cout << "ִ�к�>> " << index1(3) << endl << endl;


	//����ָ�뺯��
	int i;
	int* value;
	value = index2(i);
	cout << "ִ�к�>> value[0]:" << value[0] << "; i:" << i << endl << endl;

	//��������
	//��������ж�ε�����������������󽵵�ʹ��Ч�ʣ�Ϊ���ṩЧ�ʣ���������main�жԺ���isnumber�ĵ����滻�ɷ����塣
	//�����滻ֻҪ�ں���isnumber�Ķ���ǰ����Ϲؼ���inline���ɡ�
	char chars[] = {'0','1','a'};
	for (int i = 0; i < 3; i++) {
		cout << chars[i] << " is number? " << isnumber(chars[i]) << endl;
	}
	cout << endl;

	//��������
	cout << "��������" << endl;
	cout << "double:\t" << max(1.2, 4.5) << endl
		<< "int:\t" << max(5, 7) << endl
		<< "char:\t" << max('a', '5') << endl
		<< "string:\t" << max("hello","world") << endl << endl;


	//����ģ��.�涨ģ����template�ؼ��ֺ�һ���βα�ͷ
	cout << "����ģ��" << endl;
	cout << "double:\t" << maxX(1.2, 4.5) << endl
		<< "int:\t" << maxX(5, 7) << endl
		<< "char:\t" << maxX('a', '5') << endl
		<< "string:\t" << maxX("hello", "world") << endl << endl;

	//���и���complexģ����ĺ���
	complex<int> comp1(2, 3);
	complex<double> comp2(2.2, 3.3);
	printer(comp1);
	printer(comp2);
	cout << endl << endl;

	//ģ��complex
	printerX(comp1);
	printerX(comp2);
	cout << endl << endl;


	//ʹ��typename����class��
	cout << "����ģ��" << endl;
	cout << "double:\t" << maxXX(1.2, 4.5) << endl
		<< "int:\t" << maxXX(5, 7) << endl
		<< "char:\t" << maxXX('a', '5') << endl
		<< "string:\t" << maxXX("hello", "world") << endl
		<< "int double:\t" << maxXX<double>(1, 4.5) << endl << endl;

	return 0;
}

void swap1(string str1, string str2) {
	string temp = str1;
	str1 = str2;
	str2 = temp;
	cout << "swap1>>  str1:" << str1 << "; str2:" << str2 << endl;
}


void swap2(string * str1, string * str2) {
	string * temp = str1;
	str1 = str2;
	str2 = temp;
	cout << "swap2>>  str1:" << *str1 << "; str2:" << *str2 << endl;
}

void swap3(int a[]) {
	int temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	cout << "swap3>>  a[0]:" << a[0] << "; a[1]:" << a[1] << endl;
}

void swap4(string & str1, string & str2) {
	string temp = str1;
	str1 = str2;
	str2 = temp;
	cout << "swap4>>  str1:" << str1 << "; str2:" << str2 << endl;
}

void swap5(string str1, string str2) {
	cout << "swap5>>  str1:" << str1 << "; str2:" << str2 << endl;
}

void swap6(const string& str) {
	string str2 = "str2";
	//str = str2;//�����޷�ͨ��
	cout << "swap6>>  str:" << str2 << endl;
}


int& index1(int i) {
	cout << "index1>>  i:" << i << endl;
	return i;
}

int* index2(int& i) {
	i = 1;
	int* value = new int[i];

	value[0] = 2;
	return value;
}


inline int isnumber(char c) {
	return (c >= '0' && c <= '9') ? 1 : 0;
}

double max(double v1, double v2) {
	return v1 > v2 ? v1 : v2;
}
int max(int v1, int v2) {
	return v1 > v2 ? v1 : v2;
}
char max(char v1, char v2) {
	return v1 > v2 ? v1 : v2;
}
string max(string v1, string v2) {
	return v1 > v2 ? v1 : v2;
}

void printer(complex<int> v) {
	cout << "real is " << v.real() << ", image is " << v.imag() << endl;
}
void printer(complex<double> v) {
	cout << "real is " << v.real() << ", image is " << v.imag() << endl;
}