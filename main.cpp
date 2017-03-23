/**
* main.cpp 
* 
* This file is provided for you to run and test the program
* You may add your own tests here to debug and verify your program
* But this file will NOT be considered by the grader
*/

#include <iostream>
#include "poly.h"

using namespace std;

/* Example test case */
void Test1() {
	Poly p1("3x^2+2x+1");
	Poly p2("1x+2");
	p2.print();
	p1.print();
	Poly *p4 = p1.add(p2);
	Poly *p3 = p1.multiply(p2);


	bool errors = false;
	if (p3->eval(0) != 2) {
		cout << "test1 failed multiplying\n";
		errors = true;
	}
	if (p4->eval(0) != 3) {
		cout << "test1 failed adding\n";
		errors = true;
	}
    
    delete p3; 
    delete p4; 

	if (!errors) {
		cout << "test1 passed\n";
	}
}

void Test2(void) {
	Poly pz("-3.5x^2-2x+2");
	Poly p1("-3.5x^2-2x+2");
	Poly p3("-3.5x^2+2x");
	Poly p7("");
	Poly p2("0");
	Poly p5("-3.5x^2-2x-2");
	Poly pc("0x^3+1x+2");
	Poly pa("2x^3+0x+4");
	Poly pb("2x^3+3x+0");
	Poly *p4 = p1.add(p7);
	Poly *p8 = p7.add(p2);
	Poly *py = p1.add(p3);			//-7x^2+2
	Poly *pzz = p1.add(p1);
	int x = p5.equals(p1);
	x = pz.equals(p1);
	x = p7.equals(p2);				
	x = p7.equals(p1);
	x = p1.equals(p7);
	x = 5;


}

void Test3(void) {
	Poly p1("1x+1");
	Poly p2("1x-1");
	Poly* p3 = (p1.multiply(p2));
	
	Poly pa("");
	Poly pb("2x^2+3x+4");
	Poly* pc = pa.multiply(pb);
	Poly* pd = pa.multiply(pa);

	Poly p4("3.5x^2-2.2x+3");
	Poly p5("1x^2+2x");
	Poly *p6 = p4.multiply(p4);
	Poly *p7 = p4.multiply(p5);

	Poly p9("2x^2+4");
	Poly p10("2x^2-4");
	Poly *p11 = p9.multiply(p10);
	int x = 0;
}

void Test4(void) {
	Poly p1("1x^2+2x+3");
	Poly p2("");
	int x = p1.eval(1);
	x = p1.eval(0);
	x = p1.eval(3);
	x = p2.eval(1);
	x = p2.eval(0);
	x = x;
}

/* You can add more test cases here */

int main() {
	Test4();
	Test2();
	Test3();
	Test1();
	
}
