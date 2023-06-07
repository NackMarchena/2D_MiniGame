#pragma once

#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

enum TipoPersonaje
{
	Lider,
	Habitante,
	Aliado,
	Agente
};

enum TipoMovimiento
{
	Horizontal,
	Vertical,
	Estatico
};


class PersonajeBase
{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;
	int IDx, IDy;
	TipoPersonaje Tipo;

public:
	PersonajeBase();
	int GetX();
	int GetY();
	int GetDX();
	int GetDY();
	void SetX(int value);
	void SetY(int value);
	void SetDX(int value);
	void SetDY(int value);
	Rectangle Area();

	virtual void Mover(Graphics^ g) {}
	
	virtual void Mostrar(Graphics^ g, Bitmap^ img) {
		
		g->FillRectangle(Brushes::Blue, Area());

	}

};

