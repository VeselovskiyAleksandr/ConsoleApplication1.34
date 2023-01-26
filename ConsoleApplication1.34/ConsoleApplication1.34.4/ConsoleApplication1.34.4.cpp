// ConsoleApplication1.34.4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 33. Задание 4. Среднее арифметическое число в массиве.

#include <iostream>
#include <exception>
#include <vector>
#include<clocale>
using namespace std;

template <typename T>
T arithmeticMean(const vector<T>& v) {
	T sum = 0;
	for (int i = 0; i < v.size(); ++i) {
		sum += v[i];
	}
	return sum / v.size();
}

void checkInput(int numEl) {
	if (numEl ==0) {
		throw invalid_argument("нулевой размер вектора.");
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int numberElements = 0;
	bool input = true;
		try {
			vector<double>vectd;
			cout << "\nУкажите количество элементов double-массива: ";
			cin >> numberElements;
			checkInput(numberElements);
			vectd.resize(numberElements);
			cout << "\nЗаполните double-массив: ";
			for (int i = 0; i < numberElements; ++i) {
				cin >> vectd[i];
			}
			cout << "\nСреднее арифметическое double-массива: " << arithmeticMean(vectd);
			numberElements = 0;
			input = false;
		}
		catch (const invalid_argument& err) {
			cerr << "\nВызвано исключение : " << err.what();
			return 1;
		}
		vector<int>vecti;
			try {
				cout << "\nУкажите количество элементов int-массива: ";
				cin >> numberElements;
				checkInput(numberElements);
				vecti.resize(numberElements);
				cout << "\nЗаполните int-массив: ";
				for (int i = 0; i < numberElements; ++i) {
					cin >> vecti[i];
				}
				cout << "\nСреднее арифметическое int-массива: " << arithmeticMean(vecti);
				numberElements = 0;
				input = false;
			}
			catch (const invalid_argument& err) {
				cerr << "\nВызвано исключение : " << err.what();
				return 1;
			}
		vector<char>vectch;
			try {
				cout << "\nУкажите количество элементов char-массива: ";
				cin >> numberElements;
				checkInput(numberElements);
				vectch.resize(numberElements);
				cout << "\nЗаполните char-массив: ";
				for (int i = 0; i < numberElements; ++i) {
					cin >> vectch[i];
				}
				cout << "\nСреднее арифметическое char-массива: " << arithmeticMean(vectch);
				numberElements = 0;
				input = false;
			}
			catch (const invalid_argument& err) {
				cerr << "\nВызвано исключение : " << err.what();
				return 1;
			}
	return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
