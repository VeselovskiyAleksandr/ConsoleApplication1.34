// ConsoleApplication1.34.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 33. Задание 1. Работа корзины с покупками.

#include <iostream>
#include <string>
#include <exception>
#include <clocale>
#include <map>
using namespace std;

class ItemException : public exception {
public:
	const char* what() const noexcept override {
		return "Неверный артикул.\n";
	}
};

class ProductException : public exception {
public:
	const char* what() const noexcept override {
		return "нет такого товара.";
	}
};

	map<string, int>warehouseGoods;
	map<string, int>shoppingCart;

	pair<string, int> addProduct(string artNumber, int quantGoods, map<string, int>goods) {
		for (int i = 0; i< artNumber.size(); ++i) {
			if (artNumber[i] < 48 || artNumber[i] > 57) {
				throw ItemException();
			}
		}
		map<string, int>::iterator it;
		it = goods.find(artNumber);
		if (it == goods.end()) {
			throw ProductException();
		}
		if (quantGoods <= 0) {
			throw invalid_argument(" Неверный ввод количества товара.");
		}
		if (quantGoods > goods[artNumber]) {
			throw runtime_error(" Указанного количества товара нет в наличии.");
		}
			pair<string, int>oPair(artNumber, quantGoods);
			return oPair;
	}

	pair<string, int> removeProduct(string artNumber, int quantGoods, map<string, int>shoppCart) {
		for (int i = 0; i < artNumber.size(); ++i) {
			if (artNumber[i] < 48 || artNumber[i] > 57) {
				throw ItemException();
			}
		}
		map<string, int>::iterator it;
		it = shoppCart.find(artNumber);
		if (it == shoppCart.end()) {
			throw ProductException();
		}
		if (quantGoods <= 0) {
			throw invalid_argument(" Неверный ввод количества товара.");
		}
		if (quantGoods > shoppCart[artNumber]) {
			throw runtime_error(" Указанного количества товара нет в корзине.");
		}
		pair<string, int>oPair(artNumber, quantGoods);
		return oPair;
	}


int main()
{
	setlocale(LC_ALL,"rus");
	warehouseGoods = {
	   {"10235", 7}, {"10739", 4}, {"10241", 11}, {"10319", 16}, {"10114", 21}, {"10529", 17}, {"10278", 11}, {"10317", 25}
	};
	cout << "\nВыберите товар.\n";
	for (map<string, int>::iterator it = warehouseGoods.begin(); it != warehouseGoods.end(); ++it) {
		cout << " артикул: " << it->first << " " << "в наличии " << it -> second << "\n";
	}
		string item="";
		int quantityGoods = 0, exitSite=1, det=0;
	bool input = true;
	while (exitSite > 0) {
		while (input) {
			cout << "\n Для пополнения корзины введите 1, для удаления товара введите 2.";
			cin >> det;
			cout << "\n Введите артикул товара.";
			cin >> item;
			cout << "\n Введите количество товара.";
			cin >> quantityGoods;
			try {
				switch (det) {
				case 1:
					addProduct(item, quantityGoods, warehouseGoods);
					input = false;
					break;
				case 2:
					removeProduct(item, quantityGoods, shoppingCart);
					input = false;
					break;
				}
			}
			catch (const ItemException& err) {
				cerr << "\nВыброшено исключение: " << err.what();
			}
			catch (const ProductException& err) {
				cerr << "\nВыброшено исключение: " << err.what();
			}
			catch (invalid_argument err) {
				cerr << "\nВыброшено исключение: " << err.what();
			}
			catch (runtime_error err) {
				cerr << "\nВыброшено исключение: " << err.what();
			}
			catch (...) {
				cerr << "\nВыброшено исключение: " << "нет такого товара.";
			};			
		}
		map<string, int>::iterator iter;
			iter = shoppingCart.find(item);
			if (iter != shoppingCart.end()) {
				int transfer = 0;

				switch (det) {
				case 1:
				transfer = shoppingCart[item];
					shoppingCart.erase(item);
					shoppingCart.insert(addProduct(item, quantityGoods, warehouseGoods));
					warehouseGoods[item] -= shoppingCart[item];
					shoppingCart[item] += transfer;
					break;
				case 2:
					warehouseGoods[item] += quantityGoods;
					shoppingCart[item] -= quantityGoods;
					if (shoppingCart[item] == 0) {
						shoppingCart.erase(item);
					}
					break;
				}
			}
			else {
				shoppingCart.insert(addProduct(item, quantityGoods, warehouseGoods));
				warehouseGoods[item] -= shoppingCart[item];
			}
			cout << "\nВаша корзина: \n";
			if (shoppingCart.empty()) {
				cout << "\nВы ничего не выбрали.";
			}
			else {
				for (map<string, int>::iterator it = shoppingCart.begin(); it != shoppingCart.end(); ++it) {
					cout << " артикул: " << it->first << " " << "количество: " << it->second << "\n";
				}
			}
		input = true;
		cout << "\nДля продолжения выбора товаров введите положительное число, для выхода - отрицательное, для очистки корзины - 0";
		cin >> exitSite;
		if (exitSite == 0) {
			for (map<string, int>::iterator it = shoppingCart.begin(); it != shoppingCart.end(); ++it) {
				warehouseGoods[it->first] += it->second;
			}
			shoppingCart.clear();
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
