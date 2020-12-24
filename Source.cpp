#include <iostream>
#include <vector>
#include <ctime>
#include "FirstFIFO.cpp"
#include "SecondFIFO.cpp"
using namespace std;

bool isEven(int value);
void InsertionSort(vector<int>& values);

int main() {
	srand(time(NULL));

	//1 �������
	int value = 16;
	if (isEven(value))
	{
		cout << value << " is even" << endl;		
	}
	else {		
		cout << value << " is odd" << endl;
	}

	//2 �������
	FirstFIFO<int> fifo1;
	fifo1.Add(100);
	fifo1.Add(300);
	fifo1.Add(700);
	fifo1.Show();
	fifo1.Delete();
	fifo1.Show();
	
	SecondFIFO<int> fifo2;
	fifo2.push_front(4);
	fifo2.push_front(3);
	fifo2.push_front(1);

	fifo2.insert(202, 2);
	fifo2.insert(2012, 4);
	fifo2.pop_back();
		
	for (int i = 0; i < fifo2.GetSize(); i++)
	{
		cout << fifo2[i] << endl;
	}
	cout << endl;

	//3 �������
	vector<int> values;
	for (size_t i = 0; i < 10; i++)
	{
		values.push_back(rand());
		cout << values[i] << endl;
	}
	cout << endl;

	InsertionSort(values);

	for (size_t i = 0; i < 10; i++)
	{		
		cout << values[i] << endl;
	}
	
	return 0;
}

//������ true ���� ����� ������ (���� ������ ��� ����� ����� 1, �� �������� true, �.�. ���� ����� ��������.
//����� ���� ����������� �������� � ������� !.
bool isEven(int value) { return !(value & 1); }

void InsertionSort(vector<int>& values) {
	//���������� ���������� �� ������� ��������
	for (size_t i = 1; i < values.size(); ++i) {
		//��������� �������� ��������
		int x = values[i];
		//�������� ������ ��� �������� ���� �� ����� ����� ��� ������ ������������ ��������
		size_t j = i;
		while (j > 0 && values[j - 1] > x) {
			values[j] = values[j - 1];
			--j;
		}
		//���������� ����������� �������
		values[j] = x;
	}
}
