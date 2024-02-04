#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* prev;
};

class linkedList
{
private:
	node* head;
	node* tail;
public:
	linkedList()  //konstruktorius 
	{
		head = NULL;
		tail = NULL;
	}

	bool isEmpty()
	{
		return (head == NULL && tail == NULL);
	}
	void display()
	{
		node* temp = new node;
		temp = head;
		if (isEmpty())
			cout << "Tuscias! Neimano atvaizduoti" << endl;
		else
		{
			while (temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	void addNodeEnd(int value)
	{
		node* temp = new node;
		temp->data = value;
		temp->next = NULL;
		temp->prev = tail;
		if (isEmpty())
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}
	void addNodeStar(int value)
	{
		node* temp = new node;
		temp->data = value;
		temp->prev = NULL;
		temp->next = head;
		if (isEmpty())
		{
			head = temp;
			tail = temp;
		}
		else
		{
			head->prev = temp;
			head = temp;
		}
	}
	void addNodePos(int pos, int value)
	{
		if (pos <= 0)
			cout << "Error: netinkama pozicija" << endl;
		else if (pos == 1)
			addNodeStar(value);
		else if (isEmpty())
			cout << "Sarasas tuscias, taciau pos > 1. Elementas neidetas i pozicija" << endl;
		else
		{
			node* pre = new node;
			
			pre = head;
			for (int i = 1; i < pos - 1; i++)
			{
				pre = pre->next;
				if (pre == NULL)
				{
					cout << "ERROR: Pozicija per didele. Elementas neidetas i pozicija! \n";
					return;
				}
			}
			if (pre == tail)addNodeEnd(value);
			else
			{
				node* temp = new node;
				temp->data = value;
				temp->prev = pre;
				temp->next = pre->next;
				pre->next->prev = temp;
				pre->next = temp;

			}
		}
	}

	void delNodeEnd()
	{
		if (isEmpty())
		{
			cout << "ERROR: Sarasas tuscias, neimanoma trinti isgalo!" << endl;
		}
		else if (head == tail)
		{
			head = NULL;
			tail = NULL;
		}
		else
		{
			tail = tail->prev;
			tail->next = NULL;
		}
	}
	void delNodeStart()
	{
		if (isEmpty())
		{
			cout << "ERROR: Sarasas tuscias, neimanoma trinti is priekio!" << endl;
		}
		else if (head == tail)
		{
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = head->next;
			head->prev = NULL;
		}
	}

	void delNodePos(int pos)
	{
		if (pos <= 0)cout << "ERROR: netinkama pozicija" << endl;
		else if (pos == 1)delNodeStart();
		else if (isEmpty())cout << "ERROR: Sarasas tuscias taciau pos>1! Neimanoma trinti" << endl;
		else
		{
			node* pre = new node;
			pre = head;
			for (int i = 1; i < pos - 1; i++)
			{
				pre = pre->next;
				if (pre->next == NULL)
				{
					cout << "ERROR: pozicija per didele! Neimanoma istrinti." << endl;
					return;
				}
			}
			if (pre->next == tail)delNodeEnd();
			else
			{
				pre->next = pre->next->next;
				pre->next->prev = pre;
			}
		}
	}

	void reverse()
	{
		if (isEmpty())cout << "ERROR: Listas tuscias! Neimanoma apsukt" << endl;
		else if (head == tail) {}
		else
		{
			node* pre = new node;
			node* cur = new node;
			node* nxt = new node;
			pre = NULL;
			tail = head;
			cur = head;

			while (cur != NULL)
			{
				nxt = cur->next;
				cur->next = pre;
				cur->prev = nxt;
				pre = cur;
				cur = nxt;
			}
			head = pre;
		}
	}
};

int main()
{
	linkedList listas;
	listas.addNodeEnd(13);
	listas.addNodeEnd(5);
	listas.addNodeStar(3);
	listas.addNodeStar(2);
	listas.addNodePos(3, 88);
	listas.display();
	cout << "--------------------------------\n";
	//listas.delNodeStart();
	//listas.delNodeEnd();
	//listas.delNodePos(2);
	listas.reverse();
	listas.display();


	return 0;
}