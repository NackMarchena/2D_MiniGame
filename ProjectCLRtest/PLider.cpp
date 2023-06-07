#include "PLider.h"


PLider::PLider(Bitmap^ img)

{
	Tipo = TipoPersonaje::Lider;

	x = 100; y = 100;
	dx = dy = 0;
	ancho = img->Width / 4;
	alto = img->Height / 4;

	xpose = CaminarAbajo;
}

void PLider::Mover(Graphics^ g)
{

	if (x + dx >= 96 && x + ancho + dx < g->VisibleClipBounds.Width-96)
		x += dx;
	if (y + dy >=96 && y + alto + dy < g->VisibleClipBounds.Height-96)
		y += dy;

}

void PLider::Dibujar(Graphics^ g, Bitmap^ img)
{

	Rectangle corte = Rectangle(IDx * ancho, xpose * alto, ancho, alto);
	g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);

	if (dx != 0 || dy != 0)
		IDx = (IDx + 1) % 4;

}


void PLider::SetAccion(PoseLider value)
{
	if (xpose != value)
		IDx = 0;

	xpose = value;
}

void PLider::EnviarOrden()
{

}