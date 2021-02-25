#include <iostream>

#include "MyWeatherPrediction.h"

using namespace std;


// �Ļ� Ŭ�������� ���� ���̽� Ŭ������ �޼��带 �ִ��� Ȱ���ϸ� �����ϰ� ����� ������ �� �ִ�.
// ���� �޼����� �θ� ���� �ڵ带 ȣ���ϴ� ������ ���� ����Ѵ� => ȣ���� �Ŀ� ���ϴ� ����� �߰��ϴ� ���




void MyWeatherPrediction::setCurrentTempCelsius(int temp) // �� �������̽��� ���� �޼��带 ���α⸸ �Ѵ�.
{
	int fahrenheitTemp = convertCelsiusToFahrenheit(temp); // ���� �µ��� ȭ���� �ٲ� ��
	setCurrentTempFahrenheit(fahrenheitTemp); // ���̽� Ŭ���� �޼���� ���� => �θ� Ŭ������ �ڵ带 ��Ȱ���Ѵ�.
}
int MyWeatherPrediction::getTomorrowTempCelsius() const
{
	int fahrenheitTemp = getTomorrowTempFahrenheit(); // ���̽� Ŭ���� �޼����� ���� ���� ���� ��
	return convertFahrenheitToCelsius(fahrenheitTemp); // ȭ���� ������ ����
}



void MyWeatherPrediction::showResult() const // �θ� Ŭ���� �޼���� �̿����� �ʴ�, ������ ���� �������̵� �Ѵ�.
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



// �µ��� ��������� �ٲ��ִ� ���� �޼���
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
	// ȭ�� ��ȣ�� �߰��Ѵ�.
	// ����: \u00B0�� ISO/IEC 10646 ǥ���� �µ� ��ȣ��.
	
	// �θ� Ŭ������ �޼��带 ��Ȱ���ϰ�, �� �ڿ� �߰����� ��ȣ���� ���δ�.
	// :: �����ڸ� �̿��Ͽ�, �θ� Ŭ������ �޼��带 ����Ѵٴ� ���� ��������� ǥ��
	return WeatherPrediction::getTemperature() + "\u00B0F";

	/* C++ �� ���� ������ -> Ŭ���� ������ �� �˻��Ѵ�.
	���� getTemperature() �� ��ٸ�, ���� Ŭ���� �������� �ش��ϴ� MyWeatherPrediction ������ �޼��尡 ȣ����� ��,
	���ȣ���� ������ �ݺ����� ���̴�. */


	// __super == super class �� �޼����~ �׷� ��?
	//return __super::getTemperature() + "\u00B0F"; // MS VC++
}


int main()
{
	MyWeatherPrediction p;
	p.setCurrentTempCelsius(33);
	p.setPositionOfJupiter(80);
	p.showResult(); // MyWeatherPrediction ������ showResult() �޼��尡 ȣ��ȴ�.

	cout << p.getTemperature() << endl;
	return 0;
}