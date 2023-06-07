#include "PersonajeBase.h"


PersonajeBase::PersonajeBase()
{
	x = y = 0;
	dx = dy = 0;
	ancho = alto = 0;
	IDy = 0;
	IDx = 0;

}

int PersonajeBase:: GetX()
{
	return x;
}

int PersonajeBase:: GetY()
{
	return y;
}

int PersonajeBase:: GetDX()
{
	return dx;
}

int PersonajeBase:: GetDY()
{
	return dy;
}
void PersonajeBase:: SetX(int value)
{
	x = value;
}
void PersonajeBase:: SetY(int value)
{
	y = value;
}

void PersonajeBase:: SetDX(int value)
{
	dx = value;
}
void PersonajeBase:: SetDY(int value)
{
	dy = value;
}

Rectangle PersonajeBase:: Area()
{
	return Rectangle(x, y, ancho, alto);
}


