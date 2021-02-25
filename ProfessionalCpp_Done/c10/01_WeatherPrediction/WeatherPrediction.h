#pragma once
#include <string>


/* �ڵ� ������ �������� ����� �̿��ϴ� ��� */


/*  WeatherPrediction Ŭ���� = �ܺο��� �����Ǵ� ������Ƽ Ŭ���� */


// ���� �µ�, �񼺰� ȭ�� ������ �Ÿ��� ������� ������ �����ϴ� ������ ��÷�� ����� �����Ѵ�.
// �̷� ���� �������� �ʾƵ� ������ ������ �� ������ ��Ȯ���� 99%�� �Ұ��ϴ�.
// �Ļ� Ŭ�������� �޼��� �������̵��� �� ���̶� �����ϱ� ������ ��� �޼��带 virtual �� �����ߴ�.
class WeatherPrediction
{
public:
	// Virtual �Ҹ���
	virtual ~WeatherPrediction();

	// ���� �µ��� ȭ�� ������ �����Ѵ�.
	virtual void setCurrentTempFahrenheit(int temp);

	// �񼺰� ȭ�� ������ ���� �Ÿ��� �����Ѵ�.
	virtual void setPositionOfJupiter(int distanceFromMars);
	
	// ���� �µ��� ���� �������� �����´�.
	virtual int getTomorrowTempFahrenheit() const;
	
	// ���� �� �� Ȯ���� �����´�. ���� 1�̸� Ȯ���� �� ����, 
    // 0�̸� �� ���� �ʴ´ٴ� ���� �ǹ��Ѵ�.
	virtual double getChanceOfRain() const;
	
	// ����ڿ��� ������ ���� �������� ����� ����Ѵ�:
	// Result: x.xx chance. Temp. xx
	virtual void showResult() const;
	
	// ���� �µ��� ��Ʈ�������� �����Ѵ�.
	virtual std::string getTemperature() const;

private:
	// ���� �µ��� ȭ���θ� ����
	int mCurrentTempFahrenheit;
	int mDistanceFromMars;
};