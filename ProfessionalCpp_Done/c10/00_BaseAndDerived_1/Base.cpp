#include "Base.h"
#include <iostream>
using namespace std;


void Base::someMethod() // 메서드 구현 시 virtual 키워드는 생략
{
	cout << "이 메서드는 Base 의 someMethod() 메서드다" << endl;
}