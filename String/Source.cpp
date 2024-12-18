#include<windows.h>
#include <iostream>
using namespace std;

void RussianMessage(const char* s)
{
	char* buf = new char[strlen(s) + 1];
	CharToOemA(s, buf);
	cout << buf;
	delete[] buf;
}

int main()
{
	char str1[100], str2[100], ch, * p;

	RussianMessage("Введите строку символов: ");
	cin.getline(str1, 100);
	RussianMessage("Длина введённой строки: ");
	cout << strlen(str1);

	strcpy_s(str2, sizeof(str2), str1);
	RussianMessage("\nСкопированная строка: ");
	cout << str2;

	_strrev(str2);
	RussianMessage("\nРеверс строки: ");
	cout << str2;

	strncpy_s(str2, sizeof(str2), str1, 5);
	RussianMessage("\nИз исходной строки скопировано 5 символов: ");
	cout << str2;

	RussianMessage("\nВведите строку символов: ");
	cin.getline(str1, 100);
	RussianMessage("Введите символ для поиска: ");
	cin >> ch;
	p = strchr(str1, ch);
	if (!p)
		RussianMessage("Символ не найден!\n");
	else
	{
		RussianMessage("Первое вхождение символа в строку: ");
		cout << p << endl;
	}

	if (cin.peek() == '\n')
		cin.get();
	RussianMessage("\nВведите строку символов: ");
	cin.getline(str1, 100);
	RussianMessage("Введите символ для поиска: ");
	cin >> ch;
	p = strrchr(str1, ch);
	if (!p)
		RussianMessage("Символ не найден!\n");
	else
	{
		RussianMessage("Последнее вхождение символа в строку: ");
		cout << p << endl;
	}

	if (cin.peek() == '\n')
		cin.get();
	RussianMessage("\nВведите строку символов: ");
	cin.getline(str1, 100);
	RussianMessage("Введите подстроку для поиска: ");
	cin.getline(str2, 100);
	p = strstr(str1, str2);
	if (!p)
		RussianMessage("Подстрока не найдена!\n");
	else
	{
		RussianMessage("Первое вхождение подстроки в строку: ");
		cout << p << endl;
	}

	RussianMessage("Введите первую строку символов: ");
	cin.getline(str1, 100);
	RussianMessage("Введите вторую строку символов: ");
	cin.getline(str2, 100);
	strcat_s(str1, sizeof(str1), str2);
	RussianMessage("Результат конкатенации двух строк: ");
	cout << str1 << endl;

	RussianMessage("Введите первую строку символов: ");
	cin.getline(str1, 100);
	RussianMessage("Введите вторую строку символов: ");
	cin.getline(str2, 100);
	strncat_s(str1, sizeof(str1), str2, 5);
	RussianMessage("К первой строке присоединены 5 символов второй строки: ");
	cout << str1 << endl;

	RussianMessage("Введите первую строку символов: ");
	cin.getline(str1, 100);
	RussianMessage("Введите вторую строку символов: ");
	cin.getline(str2, 100);
	int result = strcmp(str1, str2);
	if (result > 0)
		cout << str1 << " > " << str2;
	else if (result < 0)
		cout << str1 << " < " << str2;
	else
		cout << str1 << " = " << str2;

	RussianMessage("\nВведите строку символов: ");
	cin.getline(str1, 100);
	RussianMessage("Строка преобразована в число: ");
	cout << atoi(str1);

	RussianMessage("\nВведите строку символов: ");
	cin.getline(str1, 100);
	RussianMessage("Строка преобразована в число: ");
	cout << atof(str1);

	RussianMessage("\nВведите строку символов: ");
	cin.getline(str1, 100);
	_strupr_s(str1, sizeof(str1));
	RussianMessage("Модифицированная строка в верхнем регистре: ");
	cout << str1;

	RussianMessage("\nВведите строку символов: ");
	cin.getline(str1, 100);
	_strlwr_s(str1, sizeof(str1));
	RussianMessage("Модифицированная строка в нижнем регистре: ");
	cout << str1;

	int number;
	RussianMessage("\nВведите число: ");
	cin >> number;
	_itoa_s(number, str1, sizeof(str1), 2);
	RussianMessage("Число преобразовано в строку: ");
	cout << str1 << endl;
	memset(str1, 0, sizeof(str1));
	cout << str1;

	return 0;
}