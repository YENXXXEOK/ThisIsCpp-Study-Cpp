// CopyConstructor.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;
class CTest
{
public:
	CTest()	{	
		cout << "CTest()" << endl;	
		m_pData = new int(5);
	}
	~CTest() 
	{ 
		cout << "~CTest()" << endl;
		delete m_pData;
	}
	CTest(const CTest &rhs)  //복사 생성자
	{ 
		cout << "copy CTest()" << endl; 
		this->m_nData = rhs.m_nData;
		//this->m_pData = rhs.m_pData; 잘못된 복사
		this->m_pData = new int(*rhs.m_pData); //깊은 복사
	}
	
	CTest& operator=(const CTest& rhs)	//연산자 오버로딩
	{
		*m_pData = *rhs.m_pData; //Deep copy
		//m_pData = rhs.m_pData; //Shalow copy
		return *this;
	}

	explicit CTest(int nParam) //변환 생성자(매개변수가 하나인 것) , 변환생성자에는 explicit를 써주자 앞에.!
	{
		cout << "CTest(int)" << endl;
		m_pData = new int(nParam);
	}
	int m_nData = 0; 

	void SetData(int nParam)
	{
		*m_pData = nParam;
	}

	int GetData() const
	{
		return *m_pData;

	}
private:
	int* m_pData = NULL;
};


void TestFunc(const CTest &param)
{
	cout << param.GetData() << endl;
}

int main()
{
	//TestFunc(5);	//변환 생성자에 explicit를 쓰지 않으면 동작이 된다.

	CTest a;	// default 생성자 호출

	a.SetData(300);
	CTest b;
	//CTest b(a);	//복사 생성자 호출

	//b = a; // CTest& operator= 연산자 오버로딩을 꼭 해줘야함. b.operator=(a); 

	// CTest a(10); // 변환 생성자 호출
	cout << a.GetData() << endl;
	cout << b.GetData() << endl;

	return 0;
}
