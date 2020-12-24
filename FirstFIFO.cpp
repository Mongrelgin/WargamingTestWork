	#include "FirstFIFO.h"
#include <iostream>
using namespace std;

template<typename T>
FirstFIFO<T>::~FirstFIFO()
{
	//Если в списке остались элементы то список очистит всё
	while (size)
	{
		Delete();
	}
}

template<typename T>
void FirstFIFO<T>::Add(T value) {
	//Создание нового элемента 
	FirstFIFO* temp = new FirstFIFO;
	//Указываем, что поле head нового элемента указывает на первый элемент
	next = temp->head;
	//Записываем в поле значения элемента переменную, которую передали аргументом
	temp->value = value;
	//Если наш список не пустой(т.е. в нём есть элементы)
	if (head != nullptr) {
		//Записываем в указатель на следующей элемент у последнего элемента наш новый элемент
		tail->next = temp;
		//Делаем наш новый элемент последним в списке
		tail = temp;
	}
	else {
		//Если наш элемент самый первый то указываем на него и в начале и в конце списка
		head = tail = temp;
	}
	//Делаем наш вектор кольцевым
	tail->next = head;
	size++;
}

template<typename T>
void FirstFIFO<T>::Show()
{
	//Если нету первого элемента, то метод выведет информацию о том, что список пуст и прервет выполнение метода
	if (!head)
	{
		cout << "Empty list" << endl;
		return;
	}
	
	//Создание временного элемента и вывод всех значений по порядку от головы до хвоста
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
	//Создание временного элемента и удаление каждого элемента от головы до хвоста
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
