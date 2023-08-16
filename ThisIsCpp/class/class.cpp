// class.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
/*
typedef struct USERDATA
{
	int nAge;
	char szName[12];

	void (*print)(USERDATA*);
} USERDATA;

void PrintUserData(USERDATA* pUser)
{
	printf("%d %s\n", pUser->nAge, pUser->szName); //의존성을 줄임
}
int main()
{
	USERDATA a = { 20, "hong", PrintUserData };

	printf("%d %s\n", a.nAge, a.szName);
	PrintUserData(&a);

	a.print(&a);

	// a.print(); <-- c++ 스타일
}
*/

// 구조체가 클래스로 변경
class USERDATA
{
public:
	int nAge;
	char szName[12];

	void PrintUserData(USERDATA* pUser)
	{
		int nData = 5;
		printf("%d %s\n", pUser->nAge, pUser->szName); //의존성을 줄임
	}

	void PrintUserData()
	{
		int nData = 5;
		printf("%d %s\n", this->nAge, this->szName); //의존성을 줄임
	}

};


int main()
{
	USERDATA a = { 20, "hong" };

	printf("%d %s\n", a.nAge, a.szName);

	a.PrintUserData(&a); 
	a.PrintUserData(); //<-- c++ 스타일
}
