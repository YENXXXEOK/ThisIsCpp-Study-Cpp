// OperatorOverloading.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;
class CMyData
{
public:
	CMyData()
	{
		cout << "CMyData()" << endl;
	}
	~CMyData()
	{
		cout << "~CMyData()" << endl;
	}

	explicit CMyData(int nParam)
		: m_nData(nParam)
	{
		cout << "CMyData(int)" << endl;
	}

	CMyData(const CMyData& rhs)
	{
		cout << "CMyData(const CMyData& )" << endl;
		m_nData = rhs.m_nData;
	}

	CMyData(const CMyData&& rhs)
	{
		cout << "CMyData(const CMyData&& )" << endl;
		m_nData = rhs.m_nData;
	}

	int GetData() const
	{
		cout << m_nData << endl;
		return m_nData;
	}

	void SetData(int nParam)
	{
		m_nData = nParam;
	}

	/*
	// 허용되는 변환
	operator int(void)
	{
		return m_nData;
	}
	*/

	CMyData operator+(const CMyData &rhs) const
	{
		//return CMyData(this->m_nData + rhs.m_nData);
		CMyData result;
		result = m_nData + rhs.m_nData;
		return result;
	}

	int operator=(int nParam)
	{
		SetData(nParam);
		return m_nData;
	}
	

	//int operator=(CMyData rhs)
	//{
	//	SetData(rhs.GetData());
	//	return m_nData;
	//}

	// 공식
	CMyData& operator=(const CMyData& rhs)
	{
		SetData(rhs.GetData());
		return *this;
	}
private:
	int m_nData = 0;
};

CMyData TestFunc(const CMyData &l, const CMyData &r)
{
	return l + r;
}

CMyData TestFunc(const CMyData& l)
{
	return l;
}
int main()
{
	CMyData a;
	CMyData b;
	CMyData c;

	
	CMyData result = TestFunc(a, b);
	c = result;
	
	cout << "end of main" << endl;
	//cout << a + b << endl;

	return 0;
}
