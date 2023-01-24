// ConsoleApplication1.34.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 33. Задание 2. Игра по ловле рыбы.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <exception>
#include <string>
#include <ctime>
#include <clocale>
using namespace std;

class FieldException : public exception {
public:
	const char* what() const noexcept override {
		return "большой размер пруда.";
	}
};

class MeaningException : public exception {
public:
	const char* what() const noexcept override {
		return "неверное значение поля.";
	}
};

int castingFishingRod() {
	int numField=0;
			cout << "\nЗабросьте удочку (введите число от 1 до 9 включительно).";
		cin >> numField;
			if (numField < 0) {
				throw invalid_argument("отрицательное поле");
			}
			else if (numField > 9) {
				throw FieldException();
			}
			else if ( numField ==0) {
				throw MeaningException();
			}	
		return numField-1;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(nullptr));
	cout << "                                      РЫБАЛКА \n\n";
	cout << " Перед всё приближающемся восходом солнца студёный, розовеющий восток, словно в мутном,запотевшем зеркале,\n";
	cout << "едва отражается сквозь дымку тумана, слоящегося в изгибе сонной реки,  \n";
	cout << " Нет ни малейшего ветерка.Тихо. Где - то вдалеке - далёко, как будто ошалев спросонок,\n";
	cout<<"стараясь драть горло до хрипоты, прогорланили первые петухи, и опять всё затихло..\n";
	cout << "                               Под ракитой, с бородою,\n";
	cout << "                               Дед Макар сидит с удою :\n";
	cout << "                               Из - под уток и гусей\n";
	cout << "                               Извлекает карасей...\n";

	int field[9], numberField=0, fishedOut=0;
	bool cast = true;
	for (int i = 0; i < 9; ++i) {
		field[i] = 0;
	}
	numberField = rand() % 9;
	field[numberField] = 1;
	for (int i = 0; i < 3; i++) {
		do {
		numberField = rand() % 9;
			if (field[numberField] == 0) {
		field[numberField] = -1;
				break;
			}
		} while (field[numberField] != 0);
	}
	while (true) {
		while (cast) {
			try {
				fishedOut = field[castingFishingRod()];
				cast = false;
			}
			catch (const invalid_argument& err) {
				cerr << "\nВызвано исключение : " << err.what();
			}
			catch (const FieldException& err) {
				cerr << "\nВызвано исключение : " << err.what();
			}
			catch (MeaningException& err) {
				cerr << "\nВызвано исключение : " << err.what();
				return 1;
			}
			catch (...) {
				cerr << "\nВызвано исключение ... ";
			};
		}
		if (fishedOut == -1) {
			cout << "\nВаш сапог!";
			break;
		}
		else if (fishedOut == 1) {
			cout << "\nПоздравляем Вы поймали рыбку. Может быть она золотая.";
			break;
		}
		if (fishedOut == 0) {
			cast = true;
			cout << " Кажется клюёт.";
		}
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
