#include <iostream>
using namespace std;


int main()
{
	setlocale(0, "");

	//1 задание
	float q; //числа последовательности
	int n; // кол-во чисел последовательности
	float m = 1; //произведение
	float max, max_i = 0, z = 0;

	cout << "введите количество чисел последовательности ";
	cin >> n;

	if (n < 0) {
		cout << "количество чисел не может быть меньше нуля";
		return 1;
	}
	if (n == 0) {
		m = 0;
	}
	else {
		cout << "введите числа последовательности ";
	}

	for (int i = 0; i != n; i++) {
		cout << i + 1 << " => ";
		cin >> q;
		if (q != int(q)) {
				m = m * q;
			//проверяем наличие числа в max
			if(max == NULL) { 
				// если в max нет числа, то засовывваем туда первое подходящее число
				max = q;
			}
			//сравниваем сначала относительно первого числа, потом уже по ситуации
			if(q > max){
				max = q;
				max_i = i+1;
			}
		}
	}
	//если не нашли подходящих чисел, то приравниваем нулю
	if(max == NULL){
		max = 0;
	}
	cout << "произведение = " << m << endl;
	cout << " наибольшее из чисел = " << max << endl;
	cout << " его номер в последовательности = " << max_i << endl;
}
