#include "Fecha.h"
#include <ctime>
#include "Herramientas.h"
using namespace std;

int Pasar_A_Dias(Fecha F){
	vector<int>Cant_Dias_Meses{31,28,31,30,31,30,31,31,30,31,30,31};
	vector<int>Cant_Dias_Bisiesto{31,29,31,30,31,30,31,31,30,31,30,31};
	int Dias=0;
	if(F[2]%4==0){
		for(int i=0;i<(F[1]-1);i++){
			Dias+=Cant_Dias_Bisiesto[i];
		}
		Dias+=F[0]+(F[2]*365);
	}else{
		for(int i=0;i<(F[1]-1);i++) { 
			Dias+=Cant_Dias_Meses[i];
		}
		Dias+=F[0]+(F[2]*365);
	}
	return Dias;
}
	/// Constructor de Fecha (si esta vacio se le asigna cero a sus atributos)
	Fecha::Fecha(){
		M_Dia=0;
		M_Mes=0;
		M_Anio=0;
	}
	
	/// Constructor de Fecha (pasandole una Fecha)
	Fecha::Fecha(int Dia, int Mes, int Anio):M_Dia(Dia),M_Mes(Mes),M_Anio(Anio){}
	
	/// Constructor de Fecha (pasando un int y creando la fecha actual)
	Fecha::Fecha(int i){
		time_t now=time(0);
		tm *time=localtime(&now);
		M_Dia=(time->tm_mday);
		M_Mes=(time->tm_mon+1);
		M_Anio=(1900+time->tm_year);
	}
	
	/// Metodo de Cambiar Atributos
	void Fecha::Cambiar_Fecha(int dia,int mes,int anio){
		M_Dia=dia;
		M_Mes=mes;
		M_Anio=anio;
	}
	
	/// Operator [] de Fecha
	int& Fecha::operator[](int i){
		switch(i){
		case 0:
			return M_Dia;
			break;
		case 1:
			return M_Mes;
			break;
		case 2:
			return M_Anio;
			break;
		default:return M_Anio;
		}
	}
	
	/// Operator de asignacion de Fecha
	Fecha& Fecha::operator=(Fecha F2){
		this->M_Dia=F2[0];
		this->M_Mes=F2[1];
		this->M_Anio=F2[2];
		return *this;
	}
	
	/// Operadores de Comparacion de Fechas
	bool Fecha::operator==(Fecha F2){
		if(M_Dia==F2[0] and M_Mes==F2[1] and M_Mes==F2[2]){
			return true;
		}
		return false;
	}
	
	bool operator<=(Fecha F1, Fecha F2){
		int Dias_Fecha_F1=Pasar_A_Dias(F1);
		int Dias_Fecha_F2=Pasar_A_Dias(F2);
		if(Dias_Fecha_F1<=Dias_Fecha_F2){
			return true;
		}else{
			return false;
		}
	}
	
	bool operator>=(Fecha F1, Fecha F2){
		int Dias_Fecha_F1=Pasar_A_Dias(F1);
		int Dias_Fecha_F2=Pasar_A_Dias(F2);
		if(Dias_Fecha_F1>=Dias_Fecha_F2){
			return true;
		}else{
			return false;
		}
	}
	
	/// Actualiza la Fecha Actual
	void Fecha::Cambiar_Fecha_Actual(){
		time_t now=time(0);
		tm *time=localtime(&now);
		int dia=(time->tm_mday);
		int mes=(time->tm_mon+1);
		int anio=(1900+time->tm_year);
		M_Dia=dia;
		M_Mes=mes;
		M_Anio=anio;
	}
