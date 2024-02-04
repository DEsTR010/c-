#include <iostream>
#include <stack>
#define MAXSIZE 10

class QueueArray
{
private:
	int first, last;
	char queue[MAXSIZE] = { 0 };

public:
	QueueArray()  //konstruktorius 
	{
		first = -1;
		last = -1;
	}

	void enqueue(char value)   //prideti elementa i eiles pabaiga
	{
		if (isFull())
		{
			std::cout << "Eile yra uzpildyta, negalima prideti naujo elemento. \n";
			return;
		}
		else if (isEmpty())
		{
			first = 0;
			last = 0;
			queue[last] = value;
		}
		else
		{
			last++;
			if (last == MAXSIZE) {
				last = 0;
			}
			queue[last] = value;

		}

	}

	void dequeue() {
		if (isEmpty()) {
			std::cout << "Eile yra tuscia, negalima isimti elemento. \n";
		}
		else if (first == last) {
			queue[first] = -1;
			first = -1;
			last = -1;
		}
		else {
			queue[first] = -1;
			first++;
		}
	}

	char peekFirst() {
		if (isEmpty()) {
			std::cout << "Eile yra tuscia, negalima isimti elemento. \n";
		}
		else {
			//std::cout << queue[first];
			return queue[first];
		}
	}
	char peekLast() {
		if (isEmpty()) {
			std::cout << "Eile yra tuscia, negalima isimti elemento. \n";
		}
		else {
			//std::cout << queue[last];
			return queue[last];
		}
	}

	bool isFull() {
		if (first == 0 && last == MAXSIZE - 1 || first == last + 1) {
			return true;
		}
		else {
			return false;
		}

	}

	bool isEmpty() {
		if (first == -1 && last == -1) {
			return true;
		}
		else {
			return false;
		}

	}
	void reverse() {
		std::stack<char> stack;
		if (isEmpty()) {
			std::cout << "Eile yra tuscia, negalima isimti elemento. \n";
		}
		else if (last > first) {
			int a = last - first;
			for (int i = 0; i <= a; i++) {
				stack.push(peekFirst());
				dequeue();
			}
			while (!stack.empty()) {
				enqueue(stack.top());
				stack.pop();
			}
			return;
		}
		else {
			int b = (MAXSIZE - 1) - first + last;
			for (int i = 0; i < b; i++) {
				stack.push(peekFirst());
				dequeue();
			}
			while (!stack.empty()) {
				enqueue(stack.top());
				stack.pop();
			}
			return;
		}
	}
	int getFirst() {
		return first;
	}
	int getLast() {
		return last;
	}
};

int main()
{
	QueueArray q;
	q.enqueue('a');
	q.enqueue('b');
	q.enqueue('c');
	q.reverse();
	//DISPLAYUS
	int ffirst = q.getFirst();
	int llast = q.getLast();
	if (q.isEmpty()) {
		std::cout << "Eile yra tuscia, negalima isimti elemento. \n";
	}
	else if (llast > ffirst) {
		int a = llast - ffirst;
		for (int i = 0; i <= a; i++) {
			std::cout << q.peekFirst() << " ";
			q.dequeue();
			q.enqueue(q.peekFirst());
		}
	}
	else {
		int b = (MAXSIZE - 1) - ffirst + llast;
		for (int i = 0; i < b; i++) {
			std::cout << q.peekFirst() << " ";
			q.dequeue();
			q.enqueue(q.peekFirst());
		}
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}
