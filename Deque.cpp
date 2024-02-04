#include <iostream>

#define MAXSIZE 10

class DequeArray
{
private:
	int first, last;
	int deque[MAXSIZE] = { 0 };

public:
	DequeArray()  //konstruktorius 
	{
		first = -1;
		last = -1;
	}

	void pushBack(int value)   //prideti elementa i deko pabaiga
	{
		if (isFull())
		{
			std::cout << "Dekas yra pilnas, negalima prideti naujo elemento. \n";
			return;
		}
		else if (isEmpty())
		{
			first = 0;
			last = 0;
			deque[last] = value;
		}
		else
		{
			last++;
			if (last == MAXSIZE) {
				last = 0;
			}
			deque[last] = value;

		}
	}
	int peekFirst() {
		return deque[first];
	}
	void pushFront(int value)
	{
		if (isFull())
		{
			std::cout << "Dekas yra pilnas, negalima prideti naujo elemento. \n";
			return;
		}
		else if (isEmpty())
		{
			first = 0;
			last = 0;
			deque[first] = value;
		}
		else
		{
			
			first--;
			if (first == -1) {
				first = MAXSIZE - 1;
			}
			deque[first] = value;
		}


	}

	bool isFull()
	{
		if (first == 0 && last == MAXSIZE - 1 || first == last + 1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isEmpty()
	{
		if (first == -1 && last == -1) {
			return true;
		}
		else {
			return false;
		}
	}

	void popBack() {
		deque[last] = -1;
		last--;
		if (last < 0) {
			last = MAXSIZE - 1;
		}
	}
	void popFront() {
		deque[first] = -1;
		first++;
		if (first > MAXSIZE - 1) {
			first = 0;
		}
	}
	char front() {
		std::cout << deque[first]<<" ";
		return deque[first];
	}
	char back() {
		std::cout << deque[last] << " ";
		return deque[last];
	}
	//display() - tik naudojant eiles operacijas, o ne masyvo funkcionalumus.
	void clear() {
		if (isEmpty()) {
			std::cout << "Dekas jau tuscias" << std::endl;
		}
		else {
			first = -1;
			last = -1;
		}
	}
	int getFirst() {
		return first;
	}
	int getLast() {
		return last;
	}
	void deleteFirst() {
		if (isFull())
		{
			std::cout << "Dekas yra pilnas, negalima prideti naujo elemento. \n";
			return;
		}
		else if (isEmpty())
		{
			std::cout << "Dekas yra tuscias \n";
		}
		else
		{

			first++;
			if (first == MAXSIZE) {
				first = 0;
			}

		}

	}
	~DequeArray() {};
};

int main()
{
	DequeArray dekas;
	dekas.pushBack(8);
	dekas.pushBack(1);
	dekas.pushFront(28);
	//dekas.deleteFirst();
	//dekas.clear();
	//dekas.display();

	int ffirst = dekas.getFirst();
	int llast = dekas.getLast();
	if (dekas.isEmpty()) {
		std::cout << "Eile yra tuscia, negalima isimti elemento. \n";
	}
	else if (llast > ffirst) {
		int a = llast - ffirst;
		for (int i = 0; i < a; i++) {
			std::cout << dekas.peekFirst() << " ";
			dekas.popFront();
			dekas.pushBack(dekas.peekFirst());
		}
	}
	else {
		int b = (MAXSIZE - 1) - ffirst + llast;
		for (int i = 0; i < b; i++) {
			std::cout << dekas.peekFirst() << " ";
			dekas.popFront();
			dekas.pushBack(dekas.peekFirst());
		}
	}
	std::cout <<dekas.peekFirst() << std::endl;
	system("pause");
	return 0;
}
