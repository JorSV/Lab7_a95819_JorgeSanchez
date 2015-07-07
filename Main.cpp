#include "stdafx.h"
#include "ElementoPersona.h"
#include "Lista.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	Lista<int> listaInt;
	listaInt.agregarAlFinal(4);
	listaInt.agregarAlFinal(272);
	listaInt.agregarAlFinal(27);
	listaInt.agregarAlFinal(2);
	cout << listaInt << endl << endl;

	Lista<string> listaString;
	listaString.agregarAlFinal("uno");
	listaString.agregarAlFinal("dos");
	listaString.agregarAlFinal("tres");
	listaString.agregarAlFinal("cuatro");
	listaString.agregarAlFinal("cinco");
	cout << listaString << endl << endl;



	system("pause");
	return 0;
}