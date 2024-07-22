#ifndef FECHA_H
#define FECHA_H

class Fecha {
public:
	Fecha();
	Fecha(int i);
	Fecha(int Dia, int Mes, int Anio);
	void Cambiar_Fecha(int dia,int mes,int anio);
	int &operator[](int i);
	Fecha &operator=(Fecha F2);
	bool operator==(Fecha F2);
	void Cambiar_Fecha_Actual();
	
private:
	int M_Dia, M_Mes, M_Anio;
};
bool operator<=(Fecha F1, Fecha F2);
bool operator>=(Fecha F1, Fecha F2);
int Pasar_A_Dias(Fecha F2);

#endif
