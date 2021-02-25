#include <iostream>
#include <sstream> // stringstream 객체 사용

#include "WeatherPrediction.h"

using namespace std;

WeatherPrediction::~WeatherPrediction() = default; // 소멸자는 디폴트 소멸자를 사용


// 데이터 멤버값을 지정하고 불러오는 세터와 게터 메서드
void WeatherPrediction::setCurrentTempFahrenheit(int temp)
{
	mCurrentTempFahrenheit = temp;
}

void WeatherPrediction::setPositionOfJupiter(int distanceFromMars)
{
	mDistanceFromMars = distanceFromMars;
}




int WeatherPrediction::getTomorrowTempFahrenheit() const
{
	// 당연히 잘못된 문장이다.
	return (mDistanceFromMars / 1000) + mCurrentTempFahrenheit;
}

double WeatherPrediction::getChanceOfRain() const
{
	// 당연히 잘못된 문장이다.
	return 0.5;
}

void WeatherPrediction::showResult() const
{
	cout << "Result: " << (getChanceOfRain() * 100) << " chance."
		<< " Temp. " << getTomorrowTempFahrenheit() << endl;
}




// 현재 온도를 스트링값으로 리턴한다.
std::string WeatherPrediction::getTemperature() const
{
	stringstream ss;
	ss << mCurrentTempFahrenheit; // 화씨 온도 데이터를 stringstream 객체에 문자열 형태로 입력
	return ss.str(); // stringstram 객체의 str() 메서드를 이용, 내부에 저장한 문자열을 리턴한다.
}

/*
int main()
{
	WeatherPrediction p;
	p.setCurrentTempFahrenheit(24);
	p.setPositionOfJupiter(80);
	p.showResult();

	cout << p.getTemperature() << endl;
	
	return 0;
}
*/