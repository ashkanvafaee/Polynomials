/**
* assignment-7.cpp
* Implementation of Poly member functions
*
* Authors:
* Ashkan Vafaee [av28837]
* Genki Oji [gto99]
*/

#include <iostream>
#include <string> 
#include <cstdlib> 
#include "poly.h"
#include <math.h>

using namespace std;

Poly::Poly(char* str) {
	head = NULL;
	nodeCt = 0;
	int n = strlen(str);
	Node* temp = '\0';
	while (n > 0) {

		if (stof(str) == 0.0) {							//Skips 0 coefficient terms

			if (*(str + 1) == 'x' && *(str + 2) == '^') {			// CASE: #x^#
				n--; str++;
				n--; str++;
				n--; str++;
				n--; str++;
			}

			else if (*(str + 1) == 'x' && *(str + 2) != '^') {		// CASE: #x^1				
				n--; str++;		//skips over coeff
				n--; str++;		//skips over 'x'
			}

			else if (*(str + 1) != 'x') {					// CASE: #x^0
				n--; str++;
			}



			continue;
		}										

		Node* x = new Node;
		x->next = NULL;
		if (this->head == NULL) {						
			this->head = x;
		}
		x->coeff = stof(str);
		while (*str != 'x' && n > 0) {
			str++;
			n--;
		}
		if (*str == 'x') {
			if (*(str + 1) == '^') {
				x->degree = stoi(str + 2);
				str += 3;
				n -= 3;
			}
			else {
				x->degree = 1;
				str++;
				n--;
			}
		}
		else {
			x->degree = 0;
			str++;
			n--;
		}
		if (temp != '\0')
			temp->next = x;					//occures rest of the time
		else
			x->next = NULL;					//only occures first time
		temp = x;
		nodeCt++;
	}

}

Poly::~Poly() {
	int n = nodeCt;
	for (int j = 0; j < nodeCt; j++) {
		Node* n1 = head;
		for (int i = 0; i < (n - 1); i++) {
			n1 = n1->next;
		}
		delete n1;
		n--;
	}
	
}

Poly* Poly::add(Poly& otherPoly) {
	if (this->nodeCt == 0 && otherPoly.nodeCt != 0) {			
		Poly* p1;
		Poly* p3 = new Poly;
		p3->head = NULL;
		p1 = &otherPoly;
		Node *n1 = p1->head;
		Node *temp = NULL;

		for (int i = 0; i < otherPoly.nodeCt; i++) {
			Node *n3 = new Node;
			n3->coeff = n1->coeff;
			n3->degree = n1->degree;
			n3->next = NULL;
			if (temp != NULL) {
				temp->next = n3;
			}
			else {
				p3->head = n3;
			}
			temp = n3;
			n1 = n1->next;

		}
		p3->nodeCt = otherPoly.nodeCt;
		return(p3);

	}

	if (this->nodeCt != 0 && otherPoly.nodeCt == 0) {			// Accounting for empty polynomials			
		Poly* p1;
		Poly* p3 = new Poly;
		p3->head = NULL;
		p1 = this;
		Node *n1 = p1->head;
		Node *temp = NULL;

		for (int i = 0; i < this->nodeCt; i++) {
			Node *n3 = new Node;
			n3->coeff = n1->coeff;
			n3->degree = n1->degree;
			n3->next = NULL;
			if (temp != NULL) {
				temp->next = n3;
			}
			else {
				p3->head = n3;
			}
			temp = n3;
			n1 = n1->next;

		}
		p3->nodeCt = this->nodeCt;
		return(p3);
	}

	if (this->nodeCt == 0 && otherPoly.nodeCt == 0) {
		Poly *temp = new Poly;
		temp->head = NULL;
		return(temp);
	}														  



	Poly* p1;
	Poly* p2;
	Poly* p3 = new Poly;
	p3->head = NULL;
	p3->nodeCt = 0;
	if (this->head->degree > otherPoly.head->degree) {
		p1 = this;
		p2 = &otherPoly;
	}
	else {
		p1 = &otherPoly;
		p2 = this;
	}
	Node *n1 = p1->head;
	Node *n2 = p2->head;
	Node *temp = NULL;
	int n = p1->head->degree;
	while (n >= 0) {
		if (n1 != NULL && n2 != NULL) {
			if (n1->degree == n2->degree) {

				if (n1->coeff == n2->coeff*-1) {	// Accounts for complete cancellation of coefficients of same degree (Shouldn't store 0 coefficients)		
					n1 = n1->next;			
					n2 = n2->next;			
					n--;
					continue;
				}												


				Node *n3 = new Node;
				n3->coeff = n1->coeff + n2->coeff;
				n3->degree = n1->degree;
				n3->next = NULL;
				if (temp != NULL) {
					temp->next = n3;
				}
				else {
					p3->head = n3;
				}
				temp = n3;
				n1 = n1->next;
				n2 = n2->next;
				p3->nodeCt++;
			}
			else if (n1->degree > n2->degree) {
				Node *n3 = new Node;
				n3->coeff = n1->coeff;
				n3->degree = n1->degree;
				n3->next = NULL;
				if (temp != NULL) {
					temp->next = n3;
				}
				else {
					p3->head = n3;
				}
				temp = n3;
				n1 = n1->next;
				p3->nodeCt++;
			}
			else if (n2->degree > n1->degree) {
				Node *n3 = new Node;
				n3->coeff = n2->coeff;
				n3->degree = n2->degree;
				n3->next = NULL;
				if (temp != NULL) {
					temp->next = n3;
				}
				else {
					p3->head = n3;
				}
				temp = n3;
				n2 = n2->next;
				p3->nodeCt++;
			}
			n--;
		}
		else if (n1 == NULL && n2 != NULL) {
			Node *n3 = new Node;
			n3->coeff = n2->coeff;
			n3->degree = n2->degree;
			n3->next = NULL;
			if (temp != NULL) {
				temp->next = n3;
			}
			else {
				p3->head = n3;
			}
			temp = n3;
			n2 = n2->next;
			n--;
			p3->nodeCt++;
		}
		else if (n2 == NULL && n1 != NULL) {
			Node *n3 = new Node;
			n3->coeff = n1->coeff;
			n3->degree = n1->degree;
			n3->next = NULL;
			if (temp != NULL) {
				temp->next = n3;
			}
			else {
				p3->head = n3;
			}
			temp = n3;
			n1 = n1->next;
			n--;
			p3->nodeCt++;
		}
	}
	/*if (p3->head == NULL) {
		Node *n3 = new Node;
		n3->coeff = 0;
		n3->degree = 0;
		n3->next = NULL;
		p3->head = n3;
		p3->nodeCt++;
	}*/
	return p3;
}

Poly* Poly::multiply(Poly& otherPoly) {

	Node* temp1 = this->getPoly();
	Node* temp2 = otherPoly.getPoly();
	Node* head = new Node;
	Node* last = new Node;
	head->next = NULL;
	last = head;
	double coefficient;
	int degree;
	int flag = 0;
	int flagfirst = 1;
	Poly *p3 = new Poly;
	int counter = 0;


	for (int i = 0; i<this->nodeCt; i++, temp1 = temp1->next) {
		int j = 0;

		for (temp2 = otherPoly.getPoly(); j<otherPoly.nodeCt; j++, temp2 = temp2->next) {
			degree = temp1->degree + temp2->degree;
			for (Node* scan = head; scan != NULL; scan = scan->next) {
				if (scan->degree == degree) {
					scan->coeff = (temp1->coeff * temp2->coeff) + scan->coeff;
					flag = 1;								//found match
				}
			}
			if (flag != 1) {									//No match, make new node


				if (flagfirst == 1) {
					head->coeff = (temp1->coeff * temp2->coeff);
					head->degree = temp1->degree + temp2->degree;
					flagfirst = 0;
					counter++;
				}
				else {
					Node* combine = new Node;
					combine->next = NULL;
					last->next = combine;
					last = combine;
					combine->coeff = (temp1->coeff * temp2->coeff);
					combine->degree = temp1->degree + temp2->degree;
					counter++;

				}


			}
			flag = 0;


		}


	}


	p3->nodeCt = counter;
	p3->head = head;

	//return (p3);


	Poly* p4 = new Poly;										
	p4->head = NULL;
	Poly *p1 = p3;							//p3 is the previous result
	Node* n1 = p1->head;
	Node *temp = NULL;
	int count = 0;

	for (int i = 0; i < p3->nodeCt; i++) {
		if (n1->coeff == 0) {					//skips 0 coefficients
			n1 = n1->next;
			continue;
		}

		Node *n3 = new Node;			
		n3->coeff = n1->coeff;					
		n3->degree = n1->degree;		//Removes all of the 0 coefficent terms in the resulting polynomial
		n3->next = NULL;
		if (temp != NULL) {
			temp->next = n3;
		}
		else {
			p4->head = n3;
		}
		temp = n3;
		n1 = n1->next;
		count++;
	}
	p4->nodeCt = count;
	return(p4);										


}

double Poly::eval(int x) {
	if (this->nodeCt == 0) {			
		return(0.0);					// Accounts for empty polynomial
	}									

	Node *temp = this->head;
	double d = 0;
	while (temp != NULL) {
		d += temp->coeff * pow(x, temp->degree);
		temp = temp->next;
	}
	return d;
}

void Poly::print() {
	Node* n1 = this->head;
	for (int i = 0; i < nodeCt; i++) {
		if (n1->degree > 1) {
			cout << n1->coeff << "x^" << n1->degree;
			if (n1->next != NULL) {
				if (n1->next->coeff > 0) {
					cout << "+";
				}
			}
		}
		else if (n1->degree == 1) {
			cout << n1->coeff << "x";
			if (n1->next != NULL) {
				if (n1->next->coeff > 0) {
					cout << "+";
				}
			}
		}
		else if (n1->degree == 0) {
			cout << n1->coeff;
		}
		n1 = n1->next;
	}
	cout << endl;
}

bool Poly::equals(Poly& otherPoly) {
	if (this->nodeCt == 0 && otherPoly.nodeCt == 0) {						
		return(true);						// Accounts for both polynomials being empty
	}																		//////////////////////////////////////////


	Node* n1 = this->head;
	Node* n2 = otherPoly.head;
	bool flag = true;	// 0 is false. 1 is true.
	if (this->nodeCt != otherPoly.nodeCt) {
		return false;
	}
	else {
		for (int i = 0; i < nodeCt; i++) {
			if ((n1->coeff != n2->coeff) || (n1->degree != n2->degree)) {
				flag = false;
			}
			n1 = n1->next;																///////////////////////// You forgot these 2 lines;
			n2 = n2->next;
		}
		return flag;
	}
	//return false;
}

Node* Poly::getPoly(void) {
	return head;
}

Poly Poly::operator+(Poly other) {
	return *(this->add(other));
}

Poly Poly::operator*(Poly other) {
	return *(this->multiply(other));
}

bool Poly::operator==(Poly other) {
	return this->equals(other);
}

double Poly::operator()(int x) {
	return this->eval(x);
}
