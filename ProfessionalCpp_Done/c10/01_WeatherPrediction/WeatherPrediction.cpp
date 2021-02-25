#include <iostream>
#include <sstream> // stringstream ��ü ���

#include "WeatherPrediction.h"

using namespace std;

WeatherPrediction::~WeatherPrediction() = default; // �Ҹ��ڴ� ����Ʈ �Ҹ��ڸ� ���


// ������ ������� �����ϰ� �ҷ����� ���Ϳ� ���� �޼���
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
	// �翬�� �߸��� �����̴�.
	return (mDistanceFromMars / 1000) + mCurrentTempFahrenheit;
}

double WeatherPrediction::getChanceOfRain() const
{
	// �翬�� �߸��� �����̴�.
	return 0.5;
}

void WeatherPrediction::showResult() const
{
	cout << "Result: " << (getChanceOfRain() * 100) << " chance."
		<< " Temp. " << getTomorrowTempFahrenheit() << endl;
}




// ���� �µ��� ��Ʈ�������� �����Ѵ�.
std::string WeatherPrediction::getTemperature() const
{
	stringstream ss;
	ss << mCurrentTempFahrenheit; // ȭ�� �µ� �����͸� stringstream ��ü�� ���ڿ� ���·� �Է�
	return ss.str(); // stringstram ��ü�� str() �޼��带 �̿�, ���ο� ������ ���ڿ��� �����Ѵ�.
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