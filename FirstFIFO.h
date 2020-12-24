#pragma once
template<typename T>
class FirstFIFO
{
public:
	FirstFIFO():head(nullptr), tail(nullptr), next(nullptr), size(0) {};
	~FirstFIFO();
	void Add(T value);
	void Show();
	void Delete();
private:
	T value;
	int size;
	FirstFIFO* head, * tail, * next;
};