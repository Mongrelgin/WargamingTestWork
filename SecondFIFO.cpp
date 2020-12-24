#include "SecondFIFO.h"
#include <iostream>
using namespace std;

//�.�. ����� List ������ ���������, �� � ��� ����������� � ������ ������ ��������� (<T>) 
template<typename T>
SecondFIFO<T>::SecondFIFO()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
SecondFIFO<T>::~SecondFIFO()
{
	clear();
}

template<typename T>
void SecondFIFO<T>::pop_front()
{
	Node<T>* temp = head;//������ � temp ������� ��������
	head = head->pNext;//����� ������ (������ ������ ������� ���� ������, � ������ ������� � temp)
	LastToFirst();
	delete temp;//������� ������ ������� ���� � temp (�.�. ������ ������� head)
	Size--;
}

template<typename T>
void SecondFIFO<T>::pop_back()
{
	//������� ������� ������� ��������� �� ������� ���-�� ��������� ����� 1 (�.�. ���������)
	removeAt(Size - 1);

	LastToFirst();
}

template<typename T>
void SecondFIFO<T>::push_front(T data)
{
	//��������� � head ����� ������� � � ���� ��������� ��������� ������ ������� ������� ��� � head
	//��� ����� ������� ������ ������( ���� head ���� �� ��������� ����� ������ � � ���� ��������� ��������� nullptr)
	head = new Node<T>(data, head);

	LastToFirst();

	Size++;
}

template<typename T>
void SecondFIFO<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
		head->pNext = head;
	}
	else
	{
		Node<T>* current = this->head;//Current �������� ��������� �� �������� � ���������
		while (current->pNext != head) //���� ���� pNext �� ��������� �� ������� ��������
		{
			current = current->pNext;//current ����� ��������� �� ��������� �������
		}

		current->pNext = new Node<T>(data);//������ � ���� pNext ��������� �� ��������� ������� � ���������� � ������ ������ ��������
		current = current->pNext;//������������� �� ����� ���������� �������
		current->pNext = head;//� ���� pNext ��������� �� ������ �������, ��� ����� ����� ����������� ������
	}

	Size++;
}

template<typename T>
void SecondFIFO<T>::insert(T data, int index)
{
	if (index == 0)
	{
		//���� ������ �������� �������� ����� ���� �� ������ �������� ������� ����������� ������� � ������
		push_front(data);
	}
	else
	{
		//previous - ����������� ������ ������� ������
		Node<T>* previous = this->head;
		//���� ������� ������ ������ �������� ��� ������� ���������� (-1 - �.�. ������ ��� � ����)
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		//�������� ������ �������� ������ � ���������� ���� pNext ��������� �� ��������� ������� ������
		Node<T>* newNode = new Node<T>(data, previous->pNext);
		//� � ������� ������� ��� �� ����� ������ � ���� pNext ��������� ��������� �� ��� ����� �������
		previous->pNext = newNode;
		//����� ��������� �� previous->pNext = new Node<T>(data, previous->pNext);
		Size++;
	}
}

template<typename T>
void SecondFIFO<T>::removeAt(int index)
{
	if (index == 0)
	{
		//����� ������ ��������� ������ ������� ������
		pop_front();
	}
	else
	{
		//previous - ����������� ������ ������� ������
		Node<T>* previous = this->head;
		//���� ���������� ������� ������ ������ �������� ��� ������� ���������� (-1 - �.�. ������ ��� � ����)
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		//�������� ������� �������� ���������� ��������� �� ������� ������� ����� ��������
		Node<T>* toDelete = previous->pNext;
		//����������� �������� � ���� pNext �������� ��������� �� ������� ������� ��� ������ ����������
		previous->pNext = toDelete->pNext;
		//������� �������� �������
		delete toDelete;
		Size--;
	}
}

template<typename T>
void SecondFIFO<T>::clear()
{
	while (Size)//���� Size �� ����� 0
	{
		pop_front();//����� ������ ��������
	}
}

template<typename T>
void SecondFIFO<T>::LastToFirst()
{
	Node<T>* current = this->head;//Current �������� ��������� �� �������� � ���������
	while (current->pNext != head || current->pNext != nullptr) //���� ���� pNext �� ��������� �� ������� ��������
	{
		current = current->pNext;//current ����� ��������� �� ��������� �������
	}
	current->pNext = head;//� ���� pNext ��������� �� ������ �������, ��� ����� ����� ����������� ������
}

template<typename T>
T& SecondFIFO<T>::operator[](const int index)
{
	int counter = 0;//�������
	Node<T>* current = this->head;//Current �������� ��������� �� �������� � ���������
	while (current != nullptr)
	{
		if (counter == index)//���� ������ ���������
		{
			return current->data;//���������� ������ �� ���� data ������� current
		}
		current = current->pNext;//���������� � current ������ ���������� ��������
		counter++;
	}
}
