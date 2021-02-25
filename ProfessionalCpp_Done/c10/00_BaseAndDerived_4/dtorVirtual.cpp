#include "dtorVirtual.h"

void Base::someMethod() // final 로 지정된 메서드를 정의할 때, final 키워드를 또 쓸 필요는 없다.
{
	cout << "final 로 지정된 메서드는 파생 클래스에서 오버라이드 할 수 없다" << endl;
}