#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

int main() {
	setlocale(LC_ALL, "Rus");
	int pop_1, pop_2, pop_3;
	double sr_ariv, BON = .557;
	cout << "������� �1" << endl;
	cout << "������� ����� �� 11 �� 99" << endl;
	cin >> pop_1;
	cout << "������� �2" << endl;
	cout << "������� ����� �� 101 �� 199" << endl;
	cin >> pop_2;
	cout << "������� �3" << endl;
	cout << "������� ����� �� 201 �� 299" << endl;
	cin >> pop_3;
	sr_ariv = (pop_1 + pop_2 + pop_3) / 3;
	cout << "������� �������������� �����: " << sr_ariv << endl;
	cout << "����� �� ��������� �����: " << BON * sr_ariv << endl;
	return 0;
}