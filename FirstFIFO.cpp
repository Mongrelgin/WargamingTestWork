	#include "FirstFIFO.h"
#include <iostream>
using namespace std;

template<typename T>
FirstFIFO<T>::~FirstFIFO()
{
	//���� � ������ �������� �������� �� ������ ������� ��
	while (size)
	{
		Delete();
	}
}

template<typename T>
void FirstFIFO<T>::Add(T value) {
	//�������� ������ �������� 
	FirstFIFO* temp = new FirstFIFO;
	//���������, ��� ���� head ������ �������� ��������� �� ������ �������
	next = temp->head;
	//���������� � ���� �������� �������� ����������, ������� �������� ����������
	temp->value = value;
	//���� ��� ������ �� ������(�.�. � �� ���� ��������)
	if (head != nullptr) {
		//���������� � ��������� �� ��������� ������� � ���������� �������� ��� ����� �������
		tail->next = temp;
		//������ ��� ����� ������� ��������� � ������
		tail = temp;
	}
	else {
		//���� ��� ������� ����� ������ �� ��������� �� ���� � � ������ � � ����� ������
		head = tail = temp;
	}
	//������ ��� ������ ���������
	tail->next = head;
	size++;
}

template<typename T>
void FirstFIFO<T>::Show()
{
	//���� ���� ������� ��������, �� ����� ������� ���������� � ���, ��� ������ ���� � ������� ���������� ������
	if (!head)
	{
		cout << "Empty list" << endl;
		return;
	}
	
	//�������� ���������� �������� � ����� ���� �������� �� ������� �� ������ �� ������
	FirstFIFO* temp = head;
	for (size_t i = 0; i < size; i++)
	{
		cout << temp->value << endl;
		temp = temp->next;
	}
}

template<typename T>
void FirstFIFO<T>::Delete()
{
	//�������� ���������� �������� � �������� ������� �������� �� ������ �� ������
	FirstFIFO* temp = head;
	while (temp != tail)
	{
		temp = head;
		head = head->next;
		cout << temp->value << " is deleted" << endl;
		delete temp;
		size--;
	}
}
