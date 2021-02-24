#include <initializer_list> // std::initializer_list<T> 템플릿을 사용
#include <stdexcept> // 예외를 던지기 위해 필요
#include <vector>
#include <iostream>

using namespace std;


/*
짝수 개의 원소를 가진 initializer_list<T> 를 매개변수로 받는 클래스
짝수 개가 아니면 예외를 던진다
*/
class EvenSequence
{
public:
	/*
	이니셜라이저 리스트 생성자
	첫 번째 매개변수로 initializer_list<T> 를 받고
	다른 매개변수가 없거나 디폴트 값을 가짐
	*/
	EvenSequence(initializer_list<double> args)
	{
		// size( ) 메서드, initializer_list<T> 의 원소의 갯수를 알아낼 수 있다.
		if (args.size() % 2 != 0)
			throw invalid_argument("원소의 갯수가 짝수개가 아니다");
		/*
		* 
		// vector 의 reserve( ) 메서드, 저장할 공간을 미리 예약한다.
		mSequence.reserve(args.size());
		// 범위 기반 for 문으로 initializer_list<T> 내 각 원소에 접근할 수 있다
		for (const auto& value : args)
			mSequence.push_back(value);

		*/


		/*
		위의 공간을 예약하고, 각 원소에 접근하여 복사하는 과정을 
		vector 의 assign( ) 메서드로 한번에 끝낼 수 있다.
		*/
		mSequence.assign(args); // initializer_lsit<T> 를 인수로 바로 넣는다.	
		

	}

	void dump() const
	{
		// vector 내 각 원소들도 범위 기반 for 문으로 접근 가능하다
		for (const auto& value : mSequence)
			cout << value << ", ";
		cout << endl;
	}

private:
	vector<double> mSequence; // 인수로 받은 값들을 저장
};


int main()
{
	// 중괄호로 싸져 있는 집합? 배열? 이 initializer_list<T> 다.
	EvenSequence seq1 = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
	seq1.dump();
	

	// 어쨌든 생성자니까, 등호 기호 없이 객체 선언에 바로 인수로 줄 수도 있다.
	EvenSequence seq2{ 11.0, 12.0, 13.0, 14.0, 15.0, 16.0 };
	// EvenSequence seq2({ 11.0, 12.0, 13.0, 14.0, 15.0, 16.0 });
	seq2.dump();


	try {
		EvenSequence seq3 = { 7.0, 8.0, 9.0 };
		seq3.dump();
	}
	// invalid_argument 예외가 발생한다면 const 레퍼런스로 받아
	catch (const invalid_argument& e) {
		cout << e.what() << endl; // what( ) 메서드, 예외의 문자열을 리턴한다.
	}



	/* 표준 라이브러리에 나온 클래스는 모두 '이니셜라이저 리스트 생성자' 를 지원한다 */
	vector<string> myVec{ "apple", "samsung" };
}