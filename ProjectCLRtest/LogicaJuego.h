#pragma once

#include "PLider.h"
#include "PAliados.h"
#include "PAgente.h"
#include "PHabitante.h"



#include "RecursosMedia.h"


ref class LogicaJuego
{

private:

	PLider* lider;
	Bitmap^ imglider;


	GenPAliados* aliados;
	Bitmap^ imgaliados;

	GenPAgentes* agentes;
	Bitmap^ imgagentes;

	GenHabitante* habitantes;
	Bitmap^ imghabitantes;

	Bitmap^ imgfondo_salud;
	Bitmap^ imgfondo_seguridad;


	int puntos, tiempo;

	int cant_aliados, cant_agentes, cant_habitantes;

	int agregar,controlTiempo;

	int alto_form, ancho_form;

	String^ nombrefondo;

	void MostrarComponentesJuego(Graphics^ g);
	void Restaurar();


public:
	LogicaJuego(int _alto, int _ancho,String^ nombreFondo);
	~LogicaJuego();


	void MoverTodosObjetos(Graphics^ led);
	void MostrarTodosObjetos(Graphics^ led);
	void LeerTeclas(bool estado, Keys tecla);
	int ComprobarEstado();

};

