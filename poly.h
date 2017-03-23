/** 
* poly.h 
* 
* This file defines the prototypes of strct Node and class Poly
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
	Poly(char* str);			//Constructor that takes in a String representation of a polynomial
	~Poly();				/Destructor
	Poly* add(Poly& otherPoly);		//Adds 2 polynomials
	Poly* multiply(Poly& otherPoly);	//Multiplies 2 polynomials
	double eval(int x);			//Evaluates polynomial using a given integer value of x
	void print();				//Prints the polynomial
	bool equals(Poly& otherPoly);		//Determines if 2 polynomials are equal
	Node* getPoly(void);			
	// Add public members if needed
	Poly operator+(Poly otherPoly);		//Overloads + operation
	Poly operator*(Poly otherPoly);		//Overload * operation
	bool operator==(Poly otherPoly);	//Overloads == operation
	double operator()(int x);		//Evaluates polynomial using a given integer value of x
};
