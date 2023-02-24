#include <iostream>
using namespace std;

class Moneda {	

private:
	int m_id;
	string m_nombre;
	string m_simbolo;
	float m_cantidad;
	float m_precio; /// el precio de todas las monedas se toma en USD a la fecha dd/mm/aaaa ///
	
public:
	Moneda(int id, string nombre, string simbolo, float cantidad, float precio){
		m_id = id;
		m_nombre = nombre;
		m_simbolo = simbolo;
		m_cantidad = cantidad;
		m_precio = precio;
	}
	
	int verIdMoneda() const { return m_id; }; 
	string verNombreMoneda() const { return m_nombre; };
	string verSimboloMoneda() const { return m_simbolo; };
	float verCantidadMoneda() const { return m_cantidad; };
	float verPrecioMoneda() const { return m_precio; };
	
	void modificarCantidad(float cantidadNueva, bool emisionOquema) { 
		if (emisionOquema == 0)
			m_cantidad += cantidadNueva; 
		if(emisionOquema == 1)
			m_cantidad -= cantidadNueva;
		else
			cout << "El número ingresado es incorrecto" << endl;
	};
};

/// PRUEBAS ///
/*
int main() {
	
	Moneda m1(1, "Ether", "ETH", 200000, 2300);
	cout << "Id moneda: " << m1.verIdMoneda() << endl;
	cout << "Nombre de la moneda: " << m1.verNombreMoneda() << endl;
	cout << "Simbolo de la moneda: " << m1.verSimboloMoneda() << endl;
	cout << "Supply actual: " << m1.verCantidadMoneda() << endl;
	cout << "Precio moneda (en dolares): " << m1.verPrecioMoneda() << " USD " << endl;
	
	return 0;
}
*/

