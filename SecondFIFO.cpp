#include "SecondFIFO.h"
#include <iostream>
using namespace std;

//Т.к. класс List теперь шаблонный, то и его конструктор и методы теперь шаблонные (<T>) 
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
	Node<T>* temp = head;//Запись в temp первого элемента
	head = head->pNext;//Сдвиг вправо (теперь второй элемент стал первым, а первый остался в temp)
	LastToFirst();
	delete temp;//Удаляет данные которые были в temp (т.е. первый элемент head)
	Size--;
}

template<typename T>
void SecondFIFO<T>::pop_back()
{
	//Удаляем элемент который находится по индексу кол-во элементов минус 1 (т.е. последний)
	removeAt(Size - 1);

	LastToFirst();
}

template<typename T>
void SecondFIFO<T>::push_front(T data)
{
	//Добавляем в head новый элемент и в поле указателя добавляем старый элемент который был в head
	//тем самым сдвигая список вперед( если head пуст то создастся новый объект а в поле указателя добавится nullptr)
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
		Node<T>* current = this->head;//Current содержит указатель на значение в заголовке
		while (current->pNext != head) //Пока поле pNext не указывает на нулевое значение
		{
			current = current->pNext;//current равен указателю на следующий элемент
		}

		current->pNext = new Node<T>(data);//Запись в поле pNext указателя на следующий элемент и добавление в список нового элемента
		current = current->pNext;//Переключяемся на новый добавленый элемент
		current->pNext = head;//В поле pNext указываем на первый элемент, тем самым делая циклический список
	}

	Size++;
}

template<typename T>
void SecondFIFO<T>::insert(T data, int index)
{
	if (index == 0)
	{
		//Если индекс искомого элемента равен нулю то просто вызываем функцию добавляющую элемент в начало
		push_front(data);
	}
	else
	{
		//previous - указательна первый элемент списка
		Node<T>* previous = this->head;
		//ищем элемент списка индекс которого был передан аргументом (-1 - т.к. отсчёт идёт с нуля)
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		//Созжание нового элемента списка и добавление полю pNext указатель на следующий элемент списка
		Node<T>* newNode = new Node<T>(data, previous->pNext);
		//а в элемент который идёт до новой записи в поле pNext Добавляем указатель на наш новый элемент
		previous->pNext = newNode;
		//Можно сократить до previous->pNext = new Node<T>(data, previous->pNext);
		Size++;
	}
}

template<typename T>
void SecondFIFO<T>::removeAt(int index)
{
	if (index == 0)
	{
		//Вызыв метода удаляющий первый элемент списка
		pop_front();
	}
	else
	{
		//previous - указательна первый элемент списка
		Node<T>* previous = this->head;
		//ищем предыдущий элемент списка индекс которого был передан аргументом (-1 - т.к. отсчёт идёт с нуля)
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		//Создание объекта которому передается указатель на элемент который нужно удалисть
		Node<T>* toDelete = previous->pNext;
		//Предыдущему элементу в поле pNext передаем указатель на элемент который идёт поосле удаляемого
		previous->pNext = toDelete->pNext;
		//Удаляем ненужный элемент
		delete toDelete;
		Size--;
	}
}

template<typename T>
void SecondFIFO<T>::clear()
{
	while (Size)//Пока Size не равна 0
	{
		pop_front();//Вызов метода удаления
	}
}

template<typename T>
void SecondFIFO<T>::LastToFirst()
{
	Node<T>* current = this->head;//Current содержит указатель на значение в заголовке
	while (current->pNext != head || current->pNext != nullptr) //Пока поле pNext не указывает на нулевое значение
	{
		current = current->pNext;//current равен указателю на следующий элемент
	}
	current->pNext = head;//В поле pNext указываем на первый элемент, тем самым делая циклический список
}

template<typename T>
T& SecondFIFO<T>::operator[](const int index)
{
	int counter = 0;//Счетчик
	Node<T>* current = this->head;//Current содержит указатель на значение в заголовке
	while (current != nullptr)
	{
		if (counter == index)//Если индекс совпадает
		{
			return current->data;//Возвращаем данные из поля data Объекта current
		}
		current = current->pNext;//ЗАписываем в current индекс следующего элемента
		counter++;
	}
}
