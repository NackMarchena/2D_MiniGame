#include "PAgente.h"



PAgente::PAgente(Bitmap^ img,int _alto,int _ancho) {

	Tipo = TipoPersonaje::Agente;


	dx = dy = rand() % 8 + 2;

	ancho = img->Width / 4;

	alto = img->Height / 4;


	x = (rand() % (_ancho - ancho - 192)) + 96;
	y = (rand() % (_alto - alto - 192)) + 96;

	direccionAgente = rand() % 2;
	if (direccionAgente == 0)
		poseagente = AGCaminarAbajo;
	else
		poseagente = AGCaminarDerecha;
	
}

void PAgente::Mover(Graphics^ g,Rectangle r, PAliados* aliado, GenPAliados* aliados) {

	if (aliados->Size() > 0)
	{
		if (x == aliado->GetX()) {
			x += 0;
		}
		else if (x > aliado->GetX()) {
			x -= dx;
			poseagente = AGCaminarIzquierda;
		}
		else if (x < aliado->GetX()) {
			x += dx;
			poseagente = AGCaminarDerecha;
		}

		if (y == aliado->GetY()) {
			y += 0;
		}
		else if (y > aliado->GetY()) {
			y -= dy;
			poseagente = AGCaminarArriba;
		}
		else if (y < aliado->GetY()) {
			y += dy;
			poseagente = AGCaminarAbajo;
		}	
	}
		
	if (direccionAgente == 0)
	{
		if (!(y + dy >= 96 && y + alto + dy < g->VisibleClipBounds.Height - 96) || this->Area().IntersectsWith(r))
		{
			dy *= -1;
			IDx = 0;

			if (poseagente == AGCaminarAbajo)
				poseagente = AGCaminarArriba;
			else
				poseagente = AGCaminarAbajo;
		}
		y += dy;

	}

	else
	{


		if (!(x + dx >= 96 && x + ancho + dx < g->VisibleClipBounds.Width - 96) || this->Area().IntersectsWith(r))
		{
			dx *= -1;
			IDx = 0;

			if (poseagente == AGCaminarIzquierda)
				poseagente = AGCaminarDerecha;
			else
				poseagente = AGCaminarIzquierda;

		}

		x += dx;

	}
}


	


void PAgente::Dibujar(Graphics^ g, Bitmap^ img) {

	Rectangle corte = Rectangle(IDx * ancho, poseagente * alto, ancho, alto);
	g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
	if (dx != 0 || dy != 0)
				IDx = (IDx + 1) % 4;
}

void PAgente::EliminarAliado() {

}


void GenPAgentes::RebotaAgente(Rectangle lider)
{
	for (int z = 0; z < agentes.size();z++)
	{

		if (agentes[z]->Area().IntersectsWith(lider))
		{
			//aliados.erase(aliados.begin() + z--);

			

		}

	}

}


GenPAgentes::~GenPAgentes()
{
	for each (PAgente * S in agentes)
		delete S;
}

int GenPAgentes::Size()
{
	return agentes.size();
}

PAgente* GenPAgentes::Get(int pos)
{
	return agentes[pos];
}

void GenPAgentes::Agregar(PAgente* aliado)
{
	agentes.push_back(aliado);
}
void GenPAgentes::Vaciar()
{
	for each (PAgente * S in agentes)
		delete S;
	agentes.clear();
}



void GenPAgentes::Mover(Graphics^ g,Rectangle r, PAliados* aliado, GenPAliados* aliados)
{
	for each (PAgente * S in agentes) {
           S->Mover(g, r,aliado,aliados);
	}
}
void GenPAgentes::Dibujar(Graphics^ g, Bitmap^ img)
{
	for each (PAgente * S in agentes)
		S->Dibujar(g, img);
}
