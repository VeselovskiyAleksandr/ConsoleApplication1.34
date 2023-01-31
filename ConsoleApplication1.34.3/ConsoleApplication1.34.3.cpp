// ConsoleApplication1.34.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 33. Задание 3. Реестр данных на шаблонах.

#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include<clocale>
using namespace std;

class InputException : public exception {
public:
	const char* what() const noexcept override {
		return "неверный ввод.\n";
	}
};

template <typename T1, typename T2>
struct RegistryPair {
	T1 key;
	T2 value;
	void setKey(T1 var) {
		key = var;
	}
	void setValue(T2 var) {
		value = var;
	}
	T1 getKey() {
		return key;
	}
	T2 getValue() {
		return value;
	}
};

template <typename T1, typename T2>
class Registry {

public:	 RegistryPair<T1, T2> r;
	vector< RegistryPair<T1, T2>>regStorage;
	void addData(T1 a, T2 b, vector< RegistryPair<T1, T2>>& regStorage) {

		r.key = a;
		r.value = b;
		regStorage.push_back(r);
	}
	void removeDafa(T1 a, vector< RegistryPair<T1, T2>>& regStorage) {
			for (int i = 0; i < regStorage.size(); ++i) {
				if (regStorage[i].key == a) {
					  regStorage.erase(regStorage.begin()+i);
					  --i;
			}
		}
	}
	void findData(T1 a, vector< RegistryPair<T1, T2>>& regStorage) {
		for (int i = 0; i < regStorage.size(); ++i) {
				if (regStorage[i].key == a) {
					cout<< regStorage[i].key<< " " << regStorage[i].value<<"\n" ;
			}
		}
	}
	void printData(vector< RegistryPair<T1, T2>>& regStorage) {
		for (int i = 0; i < regStorage.size(); ++i) {
			cout << regStorage[i].key << " " << regStorage[i].value;
			cout << "\n";
		}
	}
};

void checkInputContainer(int inputC) {
	if (inputC < 1 || inputC>3) {
		throw  InputException();
	}
}

void checkInputAct(int inputAct) {
	if (inputAct < 1 || inputAct>4) {
		throw  InputException();
	}
}

void checkInputCont(int inputCont) {
	if (inputCont == 0) {
		throw  InputException();
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	Registry<string, double> registry1;
	Registry<int, char> registry2;
	Registry<char, string> registry3;
	int input = 1;
	while (input >= 0) {
		int choosContainer = 0, container = 1, act = 0, k2 = 0;
		double m1 = 0;
		char m2 = '0', k3 = '0';
		string k1 = "", m3 = "";
		try {
			cout << "Выберите контейнер.\n";
			cout << "string, double - введите 1;\n";
			cout << "int, char - введите 2;\n";
			cout << "char, string - введите 3;\n";
			cin >> choosContainer;
			checkInputContainer(choosContainer);
		}
		catch (InputException& err) {
			cerr << "\nВызвано исключение : " << err.what();
			return 2;
		}
		switch (choosContainer) {
		case 1:
			while (container >= 0) {
				try {
					cout << "Выберите действие:\n";
					cout << "добавление элемента - введите 1;\n";
					cout << "нахождение элемента - введите 2;\n";
					cout << "удаление элемента - введите 3;\n";
					cout << "вывод содержимого на экран - введите 4;\n";
					cin >> act;
					checkInputAct(act);
				}
				catch (InputException& err) {
					cerr << "\nВызвано исключение : " << err.what();
					return 1;
				}
				switch (act) {
				case 1:
					cout << "Введите ключ.\n";
					cin >> k1;
					cout << "Введите значение.\n";
					cin >> m1;
					registry1.addData(k1, m1, registry1.regStorage);
					break;
				case 2:
					cout << "Введите ключ.\n";
					cin >> k1;
					registry1.findData(k1, registry1.regStorage);
					break;
				case 3:
					cout << "Введите ключ.\n";
					cin >> k1;
					registry1.removeDafa(k1, registry1.regStorage);
					break;
				case 4:
					registry1.printData(registry1.regStorage);
					break;
				}
				cout << "Для работы с контейнером введите положительное число, для выхода - отрицательное.";
				cin >> container;
			}
		case 2:
			while (container >= 0) {
				try {
					cout << "Выберите действие:\n";
					cout << "добавление элемента - введите 1;\n";
					cout << "нахождение элемента - введите 2;\n";
					cout << "удаление элемента - введите 3;\n";
					cout << "вывод содержимого на экран - введите 4;\n";
					cin >> act;
					checkInputAct(act);
				}
				catch (InputException& err) {
					cerr << "\nВызвано исключение : " << err.what();
					return 1;
				}
				switch (act) {
				case 1:
					cout << "Введите ключ.\n";
					cin >> k2;
					cout << "Введите значение.\n";
					cin >> m2;
					registry2.addData(k2, m2, registry2.regStorage);
					m2 = '0';
					break;
				case 2:
					cout << "Введите ключ.\n";
					cin >> k2;
					registry2.findData(k2, registry2.regStorage);
					break;
				case 3:
					cout << "Введите ключ.\n";
					cin >> k2;
					registry2.removeDafa(k2, registry2.regStorage);
					break;
				case 4:
					registry2.printData(registry2.regStorage);
					break;
				}
				cout << "Для работы с контейнером введите положительное число, для выхода - отрицательное.";
				cin >> container;
			}
		case 3:
			while (container >= 0) {
				try {
					cout << "Выберите действие:\n";
					cout << "добавление элемента - введите 1;\n";
					cout << "нахождение элемента - введите 2;\n";
					cout << "удаление элемента - введите 3;\n";
					cout << "вывод содержимого на экран - введите 4;\n";
					cin >> act;
					checkInputAct(act);
				}
				catch (InputException& err) {
					cerr << "\nВызвано исключение : " << err.what();
					return 1;
				}
				switch (act) {
				case 1:
					cout << "Введите ключ.\n";
					cin >> k3;
					cout << "Введите значение.\n";
					cin >> m3;
					registry3.addData(k3, m3, registry3.regStorage);
					k3 = '0';
					break;
				case 2:
					cout << "Введите ключ.\n";
					cin >> k3;
					registry3.findData(k3, registry3.regStorage);
					k3 = '0';
					break;
				case 3:
					cout << "Введите ключ.\n";
					cin >> k3;
					registry3.removeDafa(k3, registry3.regStorage);
					k3 = '0';
					break;
				case 4:
					registry3.printData(registry3.regStorage);
					break;
				}
				try {
					cout << "Для работы с контейнером введите положительное число, для выхода - отрицательное.";
					cin >> container;
					checkInputCont(container);
				}
				catch (InputException& err) {
					cerr << "\nВызвано исключение : " << err.what();
					return 3;
				}
			}
		}
		try {
			cout << "Для выбора контейнера введите положительное число, для выхода - отрицательное.";
			cin >> input;
			checkInputCont(input);
		}
		catch (InputException& err) {
			cerr << "\nВызвано исключение : " << err.what();
			return 3;
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
