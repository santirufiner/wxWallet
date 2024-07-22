#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <iostream>
#include <tuple>
#include "Fecha.h"
using namespace std;

struct Fecha_Registro {
	/*Datos fecha*/
	int dia;
	int mes;
	int anio;
};

struct registro_transaccion {
	/*Datos transacción*/
	int id;
	char tipo[256];
	char emisor[256];
	char receptor[256];
	Fecha_Registro F_Transaccion;
	char simbolomoneda[256];
	float monto;
	char motivo[256];
};

class Transaccion {
	
private:
	// Datos de una transacción
	int m_id;					/// Id Transaccion
	string m_tipo;				/// Tipo de Transaccion
	string m_emisor;			/// Emisor de la Transaccion
	string m_receptor;			/// Receptor de la Transaccion
	Fecha m_fecha;				/// Fecha de la Transaccion
	string m_simboloMoneda;		/// Simbolo de la Transaccion
	string m_motivo;			/// Motivo de la Tranasacion
	float m_monto;				/// Monto de la Tranasaccion
	
	
public:
	/// Constructores
	Transaccion(int id, string emisor, string receptor, string simboloMoneda, Fecha fecha_emision, float monto, string motivo);
	Transaccion(int id, string emisor, string receptor, string simboloMoneda, float monto, string motivo);
	Transaccion();
	
	/// Obtener los datos de la transacción
	int verIdTransaccion() const;
	string verTipoTransaccion() const;
	string verAddressEmisor() const;
	string verAddressReceptor() const;
	Fecha verFechaTransaccion() const;
	string verSimboloMoneda() const;
	float verMonto() const;
	string verMotivo() const;
	
	/// Guardar los datos de una transacción en un archivo binario
	void GuardarTransaccionEnBinario(ofstream &archivo);
	
};

/// Funciones para ordenar transacciones
bool OrdenarPorFecha(const Transaccion &a, const Transaccion &b);
bool OrdenarPorMonto(const Transaccion &a, const Transaccion &b);
bool OrdenarPorMotivo(const Transaccion &a, const Transaccion &b);

#endif
