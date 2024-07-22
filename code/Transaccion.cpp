#include "Transaccion.h"
#include "Fecha.h"
#include <iostream>
#include <tuple>
#include <cstring>
#include <fstream>
#include <ctime>
using namespace std;

/// Constructores
Transaccion::Transaccion(int id, string emisor, string receptor, string simboloMoneda, Fecha fecha_emision, float monto, string motivo){
	if(emisor == receptor){
		m_tipo = "Ingreso";
	}else{
		m_tipo = "Egreso";
	}
	m_id = id;
	m_emisor = emisor;
	m_receptor = receptor;
	m_fecha = fecha_emision;
	m_simboloMoneda = simboloMoneda;
	m_monto = monto;
	m_motivo = motivo;
}

Transaccion::Transaccion(int id, string emisor, string receptor, string simboloMoneda, float monto, string motivo){
	if(emisor == receptor){
		m_tipo = "Ingreso";
	}else{
		m_tipo = "Egreso";
	}
	m_id = id;
	m_emisor = emisor;
	m_receptor = receptor;
	m_fecha.Cambiar_Fecha_Actual();
	m_simboloMoneda = simboloMoneda;
	m_monto = monto;
	m_motivo = motivo;
}

Transaccion::Transaccion(){}

/// Obtener los datos de la transacción
int Transaccion::verIdTransaccion() const { return m_id; };
string Transaccion::verTipoTransaccion() const { return m_tipo; };
string Transaccion::verAddressEmisor() const { return m_emisor; };
string Transaccion::verAddressReceptor() const { return m_receptor; };
Fecha Transaccion::verFechaTransaccion() const { return m_fecha; };
string Transaccion::verSimboloMoneda() const { return m_simboloMoneda; };
float Transaccion::verMonto() const { return m_monto; };
string Transaccion::verMotivo() const { return m_motivo; };


/// Guardar los datos de una transacción en un archivo binario
void Transaccion::GuardarTransaccionEnBinario(ofstream &archivo) {
	registro_transaccion reg;
	reg.id=m_id;
	strcpy(reg.tipo, m_tipo.c_str());
	strcpy(reg.emisor, m_emisor.c_str());
	strcpy(reg.receptor, m_receptor.c_str());
	reg.F_Transaccion.dia=m_fecha[0];
	reg.F_Transaccion.mes=m_fecha[1];
	reg.F_Transaccion.anio=m_fecha[2];
	strcpy(reg.simbolomoneda, m_simboloMoneda.c_str());
	reg.monto = m_monto;
	strcpy(reg.motivo, m_motivo.c_str());
	archivo.write((char*)&reg,sizeof(reg));
}

/// Funciones para ordenar transacciones
bool OrdenarPorFecha(const Transaccion &a, const Transaccion &b) {
	return a.verFechaTransaccion() <= b.verFechaTransaccion();
}

bool OrdenarPorMonto(const Transaccion &a, const Transaccion &b) {
	return a.verMonto() < b.verMonto();
}

bool OrdenarPorMotivo(const Transaccion &a, const Transaccion &b) {
	return a.verMotivo() < b.verMotivo();
}
