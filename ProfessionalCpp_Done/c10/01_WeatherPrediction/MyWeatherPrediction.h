#pragma once

#include "WeatherPrediction.h"

/*
������Ƽ Ŭ������ WeatherPrediction ���� �� ���� ����� �߰��ϰ�, �� ���� ����� �����ؼ� ���� �ʹ�.
�̶� �ʿ��Ѱ� ��� => ������� �ڵ带 ����
*/

class MyWeatherPrediction : public WeatherPrediction // ���
{
public:
	// ���� �µ��� �����µ��� �̿��ؼ� ����
	virtual void setCurrentTempCelsius(int temp);

	// ���� �µ��� �����µ��� ����
	virtual int getTomorrowTempCelsius() const;

	// ������ ��¹���� �ƴ� ���ϴ� ��¹������ ����
	virtual void showResult() const override; // �Ļ� Ŭ�������� ���̽� Ŭ������ �޼��� ������ ������ ���̱� ������, override Ű���带 �ۼ��ߴ�.

	// ���� �θ� Ŭ������ �޼��带 �ڽ� Ŭ�������� ���ϴ� ������� ����� �����Ų��.
	virtual std::string getTemperature() const override; // �θ� Ŭ���� �޼��带 �������̵� �� ���̱⿡ override Ű���带 �־��ش�.

private:
	// ȭ���µ��� �����µ��� �ٲٰų�, �����µ��� ȭ���µ��� �ٲ��ִ� ���� �޼���
	// Ư�� ��ü�� ������ �ʰ�, ��� ��ü�� �Ȱ��� ����Ǳ� ������ static member function ���� �����Ѵ�.
	static int convertCelsiusToFahrenheit(int celsius);
	static int convertFahrenheitToCelsius(int fahrenheit);
};
