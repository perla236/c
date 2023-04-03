#include <iostream>
#include <string>
using namespace std;

int main() {
	int x;
	int y;

	char op;
    
	string reZultat = "Rezultat je: ";
    cout <<"Odaberi racunsku operaciju (+,-,*,/)";
    cin >> op;	
	cout << "Unesi prvi broj: ";
    cin >> x; 
    cout << "Unesi drugi broj: ";
    cin >> y;
	switch(op)
    {
	case '+':
	cout << reZultat << x+y ;
	break;

	case '-':
	cout << reZultat << x-y;
	break;
	
	case '*':
	cout << reZultat << x*y;
	break;
	
	case '/':
	cout << reZultat << x/y;
	break;

default:
	cout << "Pogreska";
	break; 
	}
	return 0;
}


