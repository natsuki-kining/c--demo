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

template <typename T> //使用typename代替class
T maxXX(T v1, T v2)
{
	return v1 > v2 ? v1 : v2;
}


int main() {

	//使用string类的对象作为函数参数
	string str1 = "str1", str2 = "str2";
	swap1(str1, str2);
	cout << "交换后>> str1:" << str1 << "; str2:" << str2 << endl << endl;

	//使用string类的指针作为函数参数
	str1 = "str1", str2 = "str2";
	swap2(&str1, &str2);
	cout << "交换后>> str1:" << str1 << "; str2:" << str2 << endl << endl;

	//传递数组名实例
	int a[] = {3,8};
	swap3(a);
	cout << "交换后>> a[0]:" << a[0] << "; a[1]:" << a[1] << endl << endl;

	//引用作为函数参数
	str1 = "str1", str2 = "str2";
	swap4(str1, str2);
	cout << "交换后>> str1:" << str1 << "; str2:" << str2 << endl << endl;

	//默认参数
	swap5();
	cout << endl << endl;

	//使用const保护数据
	str1 = "str1";
	swap6(str1);
	cout << "交换后>> str:" << str1 << endl << endl;


	//返回引用的函数 有问题，结果并不是16
	index1(3) = 16;
	cout << "执行后>> " << index1(3) << endl << endl;


	//返回指针函数
	int i;
	int* value;
	value = index2(i);
	cout << "执行后>> value[0]:" << value[0] << "; i:" << i << endl << endl;

	//内联函数
	//如果程序中多次调用这个函数，将会大大降低使用效率，为了提供效率，常将函数main中对函数isnumber的调用替换成方法体。
	//这种替换只要在函数isnumber的定义前面加上关键字inline即可。
	char chars[] = {'0','1','a'};
	for (int i = 0; i < 3; i++) {
		cout << chars[i] << " is number? " << isnumber(chars[i]) << endl;
	}
	cout << endl;

	//函数重载
	cout << "函数重载" << endl;
	cout << "double:\t" << max(1.2, 4.5) << endl
		<< "int:\t" << max(5, 7) << endl
		<< "char:\t" << max('a', '5') << endl
		<< "string:\t" << max("hello","world") << endl << endl;


	//函数模板.规定模板以template关键字和一个形参表开头
	cout << "函数模板" << endl;
	cout << "double:\t" << maxX(1.2, 4.5) << endl
		<< "int:\t" << maxX(5, 7) << endl
		<< "char:\t" << maxX('a', '5') << endl
		<< "string:\t" << maxX("hello", "world") << endl << endl;

	//具有复数complex模板类的函数
	complex<int> comp1(2, 3);
	complex<double> comp2(2.2, 3.3);
	printer(comp1);
	printer(comp2);
	cout << endl << endl;

	//模板complex
	printerX(comp1);
	printerX(comp2);
	cout << endl << endl;


	//使用typename代替class，
	cout << "函数模板" << endl;
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
	//str = str2;//编译无法通过
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