#include "PAliados.h"


PAliados::PAliados(Bitmap^ img,int _alto,int _ancho) {

	Tipo = TipoPersonaje::Aliado;


	dx = dy = rand() % 8 + 2;

	ancho = img->Width / 4;

	alto = img->Height / 4;

	x = (rand() % (_ancho - ancho - 192)) + 96;
	y = (rand() % (_alto - alto - 192)) + 96;

	
	direccionAliado = rand() % 2;

	if (direccionAliado==0)
		posealiado = lCaminarAbajo;
	else
		posealiado = lCaminarDerecha;

}

void PAliados::Mover(Graphics^ g) {

	if (direccionAliado == 0)
	{
		if (!(y + dy >= 96 && y + alto + dy < g->VisibleClipBounds.Height-96))
		{
			dy *= -1;
			IDx = 0;

			if( posealiado== lCaminarAbajo)
				posealiado = lCaminarArriba;
			else
				posealiado = lCaminarAbajo;
		}
		y += dy;

	}

	else
	{


		if (!(x + dx >= 96 && x + ancho + dx < g->VisibleClipBounds.Width-96))
		{
			dx *= -1;
			IDx = 0;

			if (posealiado == lCaminarIzquierda)
				posealiado = lCaminarDerecha;
			else
				posealiado = lCaminarIzquierda;

		}

		x += dx;

	}



}

void PAliados::Dibujar(Graphics^ g, Bitmap^ img) {
	Rectangle corte = Rectangle(IDx * ancho, posealiado * alto, ancho, alto);
	g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);

	if (dx != 0 || dy != 0)
		IDx = (IDx + 1) % 4;

}

void PAliados::AsistirHabitante() {}
void PAliados::EvadirAgente(){}
void PAliados::Destruir(){}




int GenPAliados::EliminaAliado(Rectangle agente)
{
	int puntosaRestar = 0;

	for ( int z=0; z< aliados.size();z++)
	{
		
		if (aliados[z]->Area().IntersectsWith(agente))
		{
			aliados.erase(aliados.begin() + z--);

			puntosaRestar += 5;

		}

	}

	return puntosaRestar;
}

GenPAliados::~GenPAliados()
{
	for each (PAliados * S in aliados)
		delete S;
}

int GenPAliados::Size()
{
	return aliados.size();
}

PAliados* GenPAliados::Get(int pos)
{
	return aliados[pos];
}

void GenPAliados::Agregar(PAliados* aliado)
{
	aliados.push_back(aliado);
}
void GenPAliados::Vaciar()
{
	for each (PAliados * S in aliados)
		delete S;
	aliados.clear();
}

void GenPAliados::Mover(Graphics^ g)
{
	for each (PAliados * S in aliados) S->Mover(g);  
		
	
}

void GenPAliados::Dibujar(Graphics^ g, Bitmap^ img)
{
	for each (PAliados * S in aliados)
		S->Dibujar(g, img);
}

PAliados* GenPAliados::getAliado() {
	for each (PAliados * S in aliados)
		return S;
}
