#pragma once
template<typename T>
class SecondFIFO
{
public:
	SecondFIFO();
	~SecondFIFO();

	void pop_front();//Удаляет первый элемент списка
	void pop_back();//Удаляет последний элемент списка
	void push_front(T data);//Вставка в начало списка
	void push_back(T data);//Вставка в конец списка
	void insert(T data, int index);//Добавление элемента по определенному индексу
	void removeAt(int index);//Удаление элемента по индексу
	void clear();//Очищение списка и освобождение памяти
	int GetSize() { return Size; }//Возвращает размер списка
	void LastToFirst();//Ссылаем последний элемент на первый
	//Перугрузка [] (Является указателем и принимает индекс нужного нам элемента в списке)
	T& operator[](const int index);

private:

	template<typename T>
	class Node//Класс реализующий элементы списка
	{
	public:
		Node* pNext;//Указатель на следующий элемент списка
		T data;//Данные хранящиеся в списке
		//data по умолчанию содержит примитивнон значение, или в случае передачи объекта как аргумента конструктор по умолчанию
		//pNext по умолчани содержит нулевое значение
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;//Кол-во элементов в списке
	Node<T>* head;//Указатель на первый элемент списка
};