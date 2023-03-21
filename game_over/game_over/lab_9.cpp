#include <iostream>
#include <math.h>
#include <locale.h>
using namespace std;

typedef int telem; //���������� ���� �������� �������
typedef telem* tmas; //���������� ���� "��������� �� telem"
int nomer(tmas a, telem& max, int n);
void inputmas(tmas a, int n);
//main_beg_

int main()
{
    int n;                  //������ �������
    setlocale(LC_ALL, "Russian");
    cout << "\n ����� ����� �������� �������, ��� �������� �����" << endl;
    cout << " ��������� �� ���������� �������� ��������� �����������";
                            //���� �������� ������
    cout << "\n ������� ���������� ��������� �������: ";
    cin >> n;
    tmas a = new telem[n]; /*�������� ����������-��������� �� telem, ��������� ������������ ������ ��� ������ ����� ������ ������� ��������� � a*/
    int nom;                //����� �������� ��������
    telem max;              //�������� ������������ ��������
    inputmas(a, n);
    //����� ������ ��������
    nom = nomer(a, max, n);
    cout << " ������� ����� �������� �������: " << nom << endl;
    cout << " �������� ��������: " << *(a + nom) << endl;
    cout << " ����� ��������� = " << max;
    delete[] a;             //������������ ������������ ������
    return 0;
}

//main_end_
//nomer_beg_

int nomer(tmas a, telem& max, int n) {
    telem pr;   //������� �������� ��������
    int imax = 0;  //�� �������� ��������� ������ �� ����� �������
    max = fabs(*(a + n - 1) - *a) + fabs(*(a + 1) - *a);
    for (int i = 1; i < n - 1; i++)
        if (max < (pr = fabs(*(a + i - 1) - *(a + i)) + fabs(*(a + i + 1) - *(a + i))))
        {
            imax = i;
            max = pr;
        }
    if (max < (pr = fabs(*a - *(a + n - 1)) + fabs(*(a + n - 2) - *(a + n - 1)))) {
        imax = n - 1;
        max = pr;
    }
    return imax;
}

//nomer_end_____________________________________________________________
//inputmas_beg__________________________________________________________

void inputmas(tmas a, int n) {
    cout << " ������� ����� ������� �������� ������� �� ";
    cout << n << " ����� � ������� <Enter>" << endl << " ";
    for (int i = 0; i < n; i++)
        cin >> *(a + i);
}

//inputmas_end_