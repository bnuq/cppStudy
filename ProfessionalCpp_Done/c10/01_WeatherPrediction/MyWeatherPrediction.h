#pragma once

#include "WeatherPrediction.h"

/*
서드파티 클래스인 WeatherPrediction 에서 몇 가지 기능은 추가하고, 몇 가지 기능은 수정해서 쓰고 싶다.
이때 필요한게 상속 => 상속으로 코드를 재사용
*/

class MyWeatherPrediction : public WeatherPrediction // 상속
{
public:
	// 현재 온도를 섭씨온도를 이용해서 설정
	virtual void setCurrentTempCelsius(int temp);

	// 내일 온도를 섭씨온도로 받음
	virtual int getTomorrowTempCelsius() const;

	// 기존의 출력방식이 아닌 원하는 출력방식으로 변경
	virtual void showResult() const override; // 파생 클래스에서 베이스 클래스의 메서드 동작을 변경할 것이기 때문에, override 키워드를 작성했다.

	// 역시 부모 클래스의 메서드를 자식 클래스에서 원하는 방식으로 기능을 변경시킨다.
	virtual std::string getTemperature() const override; // 부모 클래스 메서드를 오버라이드 할 것이기에 override 키워드를 넣어준다.

private:
	// 화씨온도를 섭씨온도로 바꾸거나, 섭씨온도를 화씨온도로 바꿔주는 헬퍼 메서드
	// 특정 객체에 속하지 않고, 모든 객체에 똑같이 적용되기 때문에 static member function 으로 선언한다.
	static int convertCelsiusToFahrenheit(int celsius);
	static int convertFahrenheitToCelsius(int fahrenheit);
};
