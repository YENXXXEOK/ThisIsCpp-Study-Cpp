// r-value.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int TestFunc(int nParam)
{
    int nResult = nParam * 2;
    return nResult;
}
int main()
{
    int nInput = 0;
    cin >> nInput;

    int &&rdata = nInput + 5;
    cout << rdata << endl;

    int&& result = TestFunc(10);

    result += 10;
    cout << result << endl;

}
