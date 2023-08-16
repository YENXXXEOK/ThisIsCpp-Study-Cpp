// namespace.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int Add(int a, int b)
{
	return a + b;
}

namespace TEST 
{
	int TestFunc()
	{
		return Add(4, 3);
	}

	int Add(int a, int b)
	{
		return a - b;
	}
}
int main()
{
	printf("%d", TEST::TestFunc()); // 전역 Add를 불러옴 
}
