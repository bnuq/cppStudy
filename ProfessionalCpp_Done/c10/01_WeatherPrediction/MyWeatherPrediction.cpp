#include <iostream>

#include "MyWeatherPrediction.h"

using namespace std;


// 파생 클래스에서 기존 베이스 클래스의 메서드를 최대한 활용하면 간편하게 기능을 구현할 수 있다.
// 현재 메서드의 부모 버전 코드를 호출하는 패턴을 많이 사용한다 => 호출한 후에 원하는 기능을 추가하는 방식




void MyWeatherPrediction::setCurrentTempCelsius(int temp) // 새 인터페이스는 기존 메서드를 감싸기만 한다.
{
	int fahrenheitTemp = convertCelsiusToFahrenheit(temp); // 현재 온도를 화씨로 바꾼 뒤
	setCurrentTempFahrenheit(fahrenheitTemp); // 베이스 클래스 메서드로 전달 => 부모 클래스의 코드를 재활용한다.
}
int MyWeatherPrediction::getTomorrowTempCelsius() const
{
	int fahrenheitTemp = getTomorrowTempFahrenheit(); // 베이스 클래스 메서드의 리턴 값을 받은 뒤
	return convertFahrenheitToCelsius(fahrenheitTemp); // 화씨를 섭씨로 변경
}



void MyWeatherPrediction::showResult() const // 부모 클래스 메서드는 이용하지 않는, 완전히 새로 오버라이드 한다.
{
	cout << "Tomorrow's temperature will be " <<
		getTomorrowTempCelsius() << " degrees Celsius (" <<
		getTomorrowTempFahrenheit() << " degrees Fahrenheit)" << endl;

	cout << "The chance of rain is " << (getChanceOfRain() * 100) << " percent"
		<< endl;

	if (getChanceOfRain() > 0.5) {
		cout << "Bring an umbrella!" << endl;
	}
}



// 온도를 양방향으로 바꿔주는 헬퍼 메서드
int MyWeatherPrediction::convertCelsiusToFahrenheit(int celsius)
{
	return static_cast<int>((9.0 / 5.0) * celsius + 32);
}
int MyWeatherPrediction::convertFahrenheitToCelsius(int fahrenheit)
{
	return static_cast<int>((5.0 / 9.0) * (fahrenheit - 32));
}




string MyWeatherPrediction::getTemperature() const
{
	// 화씨 기호를 추가한다.
	// 참고: \u00B0는 ISO/IEC 10646 표준의 온도 기호다.
	
	// 부모 클래스의 메서드를 재활용하고, 그 뒤에 추가적인 기호만을 붙인다.
	// :: 연산자를 이용하여, 부모 클래스의 메서드를 사용한다는 것을 명시적으로 표시
	return WeatherPrediction::getTemperature() + "\u00B0F";

	/* C++ 는 로컬 스코프 -> 클래스 스코프 를 검색한다.
	만약 getTemperature() 만 썼다면, 현재 클래스 스코프에 해당하는 MyWeatherPrediction 버전의 메서드가 호출됐을 것,
	재귀호출이 무한히 반복했을 것이다. */


	// __super == super class 의 메서드다~ 그런 뜻?
	//return __super::getTemperature() + "\u00B0F"; // MS VC++
}


int main()
{
	MyWeatherPrediction p;
	p.setCurrentTempCelsius(33);
	p.setPositionOfJupiter(80);
	p.showResult(); // MyWeatherPrediction 버전의 showResult() 메서드가 호출된다.

	cout << p.getTemperature() << endl;
	return 0;
}