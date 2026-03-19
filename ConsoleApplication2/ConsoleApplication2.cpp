/*Вариант 10.
Написать программу, которая находит M максимальных чисел в массиве
размерности N.Максимальные числа представить в виде отдельного массива.*/


#include <iostream>
using namespace std;
int main() {
	int n, m,o;
	cin>>n;
	if (n < 1 || !cin) {
		cout << "Ошибка: некорректный ввод. Проверьте данные.";
		return 1;
	}
	int* s = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		if (!cin) {
			cout << "Ошибка: некорректный ввод. Проверьте данные.";
			delete[] s;
			return 1;
		}
	}
	cin >> m;
	if (m < 1 || !cin) {
		cout << "Ошибка: некорректный ввод. Проверьте данные.";
		delete[] s;
		return 1;
	}
	if (m < n)
		o = m;
	else
		o = n;
	int* p = new int[o];
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (s[j] < s[j + 1]) {
				int x=s[j];
				s[j] = s[j + 1];
				s[j + 1] = x;
			}
		}
	}
	for (int i = 0; i < o; ++i) {
		p[i] = s[i];
		cout << p[i]<<" ";
	}
	delete[] s;
	delete[] p;
}





/*Вариант 10.
Дан текст в формате HTML. Найти в нем все гиперссылки. Гиперссылки могут
быть такими:
https://www.susu.ru/ru
https://ya.ru/?npr=1&utm_referrer=https%3A%2F%2Fyandex.ru%2F
http://web-archive.com
*/
#include <iostream>
#include <string>
using namespace std;
int main(){
	string s,p;
	getline(cin, s);
	for (int i = 0; i < s.size(); ++i) {
		if (s.compare(i, 7, "http://")==0 || s.compare(i, 8, "https://")==0) {
			p = "";
			while ( i < s.size() && s[i] != '"'){
				p += s[i]; 
				++i; 
			}
			cout << p << endl;
		}
	}
	
}
