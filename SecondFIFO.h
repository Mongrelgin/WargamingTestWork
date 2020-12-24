#pragma once
template<typename T>
class SecondFIFO
{
public:
	SecondFIFO();
	~SecondFIFO();

	void pop_front();//������� ������ ������� ������
	void pop_back();//������� ��������� ������� ������
	void push_front(T data);//������� � ������ ������
	void push_back(T data);//������� � ����� ������
	void insert(T data, int index);//���������� �������� �� ������������� �������
	void removeAt(int index);//�������� �������� �� �������
	void clear();//�������� ������ � ������������ ������
	int GetSize() { return Size; }//���������� ������ ������
	void LastToFirst();//������� ��������� ������� �� ������
	//���������� [] (�������� ���������� � ��������� ������ ������� ��� �������� � ������)
	T& operator[](const int index);

private:

	template<typename T>
	class Node//����� ����������� �������� ������
	{
	public:
		Node* pNext;//��������� �� ��������� ������� ������
		T data;//������ ���������� � ������
		//data �� ��������� �������� ����������� ��������, ��� � ������ �������� ������� ��� ��������� ����������� �� ���������
		//pNext �� �������� �������� ������� ��������
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;//���-�� ��������� � ������
	Node<T>* head;//��������� �� ������ ������� ������
};