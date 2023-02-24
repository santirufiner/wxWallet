#include <iostream>
#include <tuple>
using namespace std;

class Transaccion {

private:
	
	string m_tipo;
	string m_emisor;
	string m_receptor;
	string m_simboloMoneda;
	float m_monto;
	string m_fecha;
	string m_motivo;
	
	string calcularFecha(int dia, int mes, int anio){ return to_string(dia) + '/' + to_string(mes) + '/' + to_string(anio); };
	
public:
	
	Transaccion(int tipo, string emisor, string receptor, string simboloMoneda, float monto, int dia, int mes, int anio, string motivo){
		
		m_fecha = calcularFecha(dia, mes, anio);
		
		if(tipo == 0)
			m_tipo = "Agregar saldo";
		if(tipo == 1)
			m_tipo = "Restar saldo";
		if(tipo == 2)
			m_tipo = "Canjear saldo";
		
		m_emisor = emisor;
		m_receptor = receptor;
		m_simboloMoneda = simboloMoneda;
		m_monto = monto;
		m_motivo = motivo;
	}
	
	string verTipoTransaccion() const { return m_tipo; };
	string verAddressEmisor() const { return m_emisor; };
	string verAddressReceptor() const  { return m_receptor; };
	string verSimboloMoneda() const { return m_simboloMoneda; };
	float verMonto() const { return m_monto; };
	string verFechaTransaccion() const { return m_fecha; };
	string verMotivo() const { return m_motivo; };
	
	
	// Función que retorna todos los datos de la transaccion en conjunto
	tuple<string,string,string,string,string,float> emitirTransaccion() {
		return make_tuple(m_tipo, m_emisor, m_receptor, m_fecha, m_simboloMoneda, m_monto);
	}
	
};


// no son clases, y están dentro de wallet, no de Movimiento (solo son funciones)
//class AgregarSaldo : public Movimiento {
//	/// involucra: desde que wallet 
//};
//
//class RestarSaldo : public Movimiento {
//	/// involucra: emisor - receptor - moneda a enviar - monto 
//};
//
//class CanjearSaldo : public Movimiento {
//	/// involucra: receptor - moneda a canjear - monto moneda a canjear - moneda a recibir - monto moneda a recibir 
//};


/// PRUEBAS ///

int main() {
	
	Transaccion t1(1, "0xjkfd3sj13859123askjd1d39g", "0x3912ljkf39fjo32jfcsas132", "ETH", 0.34510, 10, 12, 2022, "hola mundo xd");
	
	cout << "/-----DETALLES TRANSACCION-----/" << endl;
	cout << endl;
	cout << "De: " << t1.verAddressEmisor() << endl;
	cout << "Para: " << t1.verAddressReceptor() << endl;
	cout << "Monto: " << t1.verMonto() << " " << t1.verSimboloMoneda() << endl;
	cout << "Fecha: " << t1.verFechaTransaccion() << endl;
	cout << "Motivo: " << t1.verMotivo() << endl;
	
	if(t1.verTipoTransaccion() == "Depositar")
		cout << "Detalle: " << t1.verAddressEmisor() << " le depositó " << t1.verMonto() << " " << t1.verSimboloMoneda() << " a " << t1.verAddressReceptor() << endl;
	if(t1.verTipoTransaccion() == "Enviar")
		cout << "Detalle: " << t1.verAddressEmisor() << " le envio " << t1.verMonto() << " " << t1.verSimboloMoneda() << " a " << t1.verAddressReceptor() << endl;
	if(t1.verTipoTransaccion() == "Canjear")
		cout << "Detalle: " << t1.verAddressEmisor() << " canjeó " << t1.verMonto() << " " << t1.verSimboloMoneda() << " a " << t1.verAddressReceptor() << endl;
	
	
	cout << endl;
	string tipoTrans, addressEmi, addressRec, fechaTrans, simbolo;
	double monto_x;
	
	tie(tipoTrans, addressEmi, addressRec, fechaTrans, simbolo, monto_x) = t1.emitirTransaccion();
	cout << tipoTrans << endl 
		<< addressEmi << endl
		<< addressRec << endl
		<< fechaTrans << endl
		<< -monto_x << " " << simbolo << endl;
	
	return 0;
}

