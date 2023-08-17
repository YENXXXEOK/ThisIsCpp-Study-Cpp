// Inheritance.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

class CTest
{
public:
	CTest()
	{
		cout << "CTest()" << endl;
		m_nData = 10;
	}

	void TestFunc()
	{
		cout << "CTest::TestFunc()" << endl;
	}

	int GetData() { return m_nData; }

private:
	int m_nData;
};

class CTestEx : public CTest
{
public:
	CTestEx()
	{
		cout << "CTestEx()" << endl;
	}

	// 재정의
	void TestFunc()
	{
		cout << "CTestEx::TestFunc()" << endl;
	}

};
int main()
{
	/*
	CTest a;
	a.TestFunc();

	CTestEx b;
	b.TestFunc();
	*/

	/*
	CTestEx a;
	CTest& b = a;
	b.TestFunc();
	*/

	CTestEx a;
	cout << a.GetData() << endl;

	return 0;
}
