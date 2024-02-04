#include <iostream>

struct node
{
	int data;
	node* next;
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

	void addNodeEnd(int value)
	{
		node* temp = new node; //iskiria vieta atmintyje naujam "node" tipo kintamajam ir sukuria rodykle "temp", rodancia i nauja elementa
		temp->data = value;    //priskiria reiksmes naujam elementui
		temp->next = NULL;
		if (head == NULL)  // jeigu tiesinis sarasas tuscias
		{
			head = temp; // galvute ir uodega rodys i sukurta elementa
			tail = temp;
		}
		else  // pridedam i gala
		{
			tail->next = temp; // uodega rodo i priespaskutini elementa - priespaskutinio elemento rodykle rodyti i nauja elementa
			tail = temp;       // uodega pakeiciam, kad rodytu i nauja-paskutini elementa
		}
	}
	bool isEmpty() {
		if (head == NULL && tail == NULL) {
			return true;
		}
		else
			return false;
	}
	void display()
	{
		if (isEmpty()) {
			std::cout << "Tuscia ";
			return;
		}
		node* temp = head;     			//sukuria pagalbine "temp" rodykle ir ji rodo i pirma elementa
		while (temp != NULL)
		{
			std::cout << temp->data << "\t"; // #tab
			temp = temp->next; 			//rodykle rodo i sekanti elementa
		}
	}

	void addNodeStart(int value)
	{
		// naudoti galvute/head surasti pirma pozicija
		node* temp = new node;
		temp->data = value;
		if (head == NULL) {
			head = temp;
			tail = temp;
			temp->next = nullptr;
		}
		else {
			temp->next = head;
			head = temp;
		}
	}
	void deleteNodeStart() {
		node* temp = head;
		if (isEmpty()) {
			std::cout << "Listas tuscias";
			return;
		}
		else if (head==tail && head!=NULL) {
			head = NULL;
			tail = NULL;
		}
		else {
			head = temp->next;
		}
	}
	void deleteNodeEnd() {
		if (isEmpty()) {
			std::cout << "Listas tuscias";
			return;
		}
		else {
			node* temp=head;
			while (temp->next != tail) {
				temp = temp->next;
			}
			temp->next = NULL;
			temp = tail;
		}
	}
	void reverse() {
		node* curr = head; //dabartine poz
		node* prev = head; //buvusi poz
		node* next = NULL;
		node* temp;

		while (curr != NULL) {
			next = curr->next; //issaugoti kita
			curr->next = prev; //apsukti pointeri
			prev = curr; //pajudint pointerius
			curr = next;
		}
		temp = head;
		head = tail;
		tail = temp;
		tail->next = NULL;
	}
	void addNodePos(int pos, int value)
	{
		// 1. - nubegti iki pozicijos, i kuria reikia iterpti
		if(value<1){
			std::cout << "Klaida";
			return;
		}
		node* pre;
		pre = head;
		for (int i = 1; i < pos - 1; i++) {
			pre = pre->next;
			if (pre == NULL) {
				std::cout << "Klaida" << std::endl;
				return;
			}
		}
		if (pos == 1) {
			addNodeStart(value);
		}
		else if (pre->next == NULL) {
			addNodeEnd(value);
		}
		// 2. - ideti nauja mazga ir sukeisti rodykles
		else {
			node* temp = new node;
			temp->data = value;
			temp->next = pre->next;
			pre->next = temp;
		}
	}
	void deleteNodePos(int pos)
	{
		// 1. - nubegti iki pozicijos, i kuria reikia iterpti
		if (isEmpty()) {
			std::cout << "Klaida";
			return;
		}
		node* pre;
		pre = head;
		for (int i = 1; i < pos-1; i++) {
			pre = pre->next;
			if (pre == NULL) {
				std::cout << "Klaida " << std::endl;
				return;
			}
		}
		if (pos == 1) {
			deleteNodeStart();
		}
		else if (pre->next == NULL) {
			deleteNodeEnd();
		}
		// 2. - ideti nauja mazga ir sukeisti rodykles
		else {
			node* temp = new node;
			node* nex = new node;
			temp = pre->next;
			nex = temp->next;
			pre->next = nex;
			delete temp;
		}
	}
	void clear() {
		while (!isEmpty()) {
			deleteNodeStart();
		}
		head = NULL;
		tail = NULL;
	}
	// nepamirsti kitu funkciju ir destruktoriaus
};

int main()
{
	linkedList listas;
	listas.addNodeStart(5);
	listas.addNodePos(2, 100);
	listas.addNodeEnd(5);
	listas.addNodeEnd(28);
	//listas.clear();
	//listas.deleteNodePos(2);
	listas.deleteNodeStart();
	listas.display();
	system("pause");
	return 0;
}
