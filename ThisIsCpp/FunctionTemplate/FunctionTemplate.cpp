// over.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

/*
int Add(int a, int b)
{
	return a + b;
}
double Add(double a, double b)
{
	return a + b;
}
*/

template <typename T>
T Add(T a, T b)
{
	return a + b;
}

void TestFunc(int a, int b = 5)
{

}
void TestFunc(int nParam)
{

}
int main()
{
	int nResult = Add(3, 4);
	std::cout << Add(3, 4) << std::endl;
	std::cout << Add(3.3, 4.5) << std::endl;

}

