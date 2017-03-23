/** 
* poly.h 
* 
* This file defines the prototypes of strct Node and class Poly
* Implementation should be done in assignment-7.cpp
*/

struct Node {
	double coeff;
	int degree;
	Node* next;
};

class Poly {
private:
	// Add private members as needed
	Node* head;
	int nodeCt;
public:
    Poly() {} 
	Poly(char* str);
	~Poly();
	Poly* add(Poly& otherPoly);
	Poly* multiply(Poly& otherPoly);
	double eval(int x);
	void print();
	bool equals(Poly& otherPoly);
	Node* getPoly(void);
	// Add public members if needed
	Poly operator+(Poly otherPoly);
	Poly operator*(Poly otherPoly);
	bool operator==(Poly otherPoly);
	double operator()(int x);
};