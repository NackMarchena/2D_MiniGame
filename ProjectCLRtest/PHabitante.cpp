#include "PHabitante.h"

PHabitante::PHabitante(Bitmap^ img,int _alto,int _ancho) {

	Tipo = TipoPersonaje::Habitante;



	dx = dy = rand() % 9;

	ancho = img->Width / 4;

	alto = img->Height / 4;

	x = (rand() % (_ancho - ancho - 192)) + 96;
	y = (rand() % (_alto - alto  - 192)) + 96;


	saludHabitante = 100;

	pedirAyuda = false;

	direccionHabitante = rand() % 2;

	if (direccionHabitante == 0)
		posehabitante = HCaminarAbajo;
	else
		posehabitante = HCaminarDerecha;

}

bool PHabitante::VerificaSalud()
{
	if (this->pedirAyuda && this->saludHabitante >= 50) {
		this->pedirAyuda = false;
		return true;
	}
	else

		return false;

}

void PHabitante::SubeSalud()
{

	if ((saludHabitante<100) && this->pedirAyuda==true)
		saludHabitante++;


}

void PHabitante::Mover(Graphics^ g) {

	if ((rand() % 15 == 0)&& saludHabitante>0)
		saludHabitante--;




	if( (dx == 0 || dy == 0) && (rand()% 5 ==0))
	{
		IDx = 0;

		int xm = rand() % 4;
		switch (xm)
		{
		case 0:
			posehabitante = HCaminarAbajo;
			break;
		case 1:
			posehabitante = HCaminarArriba;
			break;
		case 2:
			posehabitante = HCaminarIzquierda;
			break;
		case 3:
			posehabitante = HCaminarDerecha;
			break;
		default:
			break;
		}

		return;
	}


	if (((rand() % 100 + 1) % 8) == 0) {
	
		

	}
		

	if (direccionHabitante == 0)
	{
		if (!(y + dy >= 96 && y + alto + dy < g->VisibleClipBounds.Height-96))
		{
			dy *= -1;
			IDx = 0;

			if (posehabitante == HCaminarAbajo)
				posehabitante = HCaminarArriba;
			else
				posehabitante = HCaminarAbajo;
		}
		y += dy;

	}

	else if(direccionHabitante == 1)
	{


		if (!(x + dx >= 96 && x + ancho + dx <= g->VisibleClipBounds.Width-96))
		{
			dx *= -1;
			IDx = 0;

			if (posehabitante == HCaminarIzquierda)
				posehabitante = HCaminarDerecha;
			else
				posehabitante = HCaminarIzquierda;

		}

		x += dx;

	}
	
}

void PHabitante::Dibujar(Graphics^ g, Bitmap^ img) {
	Rectangle corte = Rectangle(IDx * ancho, posehabitante * alto, ancho, alto);



	if (saludHabitante>=50)
	{

		g->DrawString("(* u *) " + saludHabitante + " Feliz!", gcnew Font("Arial", 12), Brushes::Green, this->x, this->y - 25);
	}
	else if (saludHabitante>=25 && saludHabitante <=49)
	{
		g->DrawString("- _ - " + saludHabitante + " Ayuda!", gcnew Font("Arial", 12), Brushes::Orange, this->x, this->y - 25);
		this->pedirAyuda = true;

	}
	else
	{

		g->DrawString("(x n x) " + saludHabitante + " Haaa Ayuda!!", gcnew Font("Arial", 12), Brushes::Red, this->x, this->y - 25);

		

	}



	g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);


	if (dx != 0 || dy != 0)
		IDx = (IDx + 1) % 4;

}


int GenHabitante::AsisteAliado(Rectangle aliado)
{
	int puntosganados = 0;

	for (int z = 0; z < habitantes.size();z++)
	{

		if (habitantes[z]->Area().IntersectsWith(aliado))
		{
			habitantes[z]->SubeSalud();

			if (habitantes[z]->VerificaSalud())
				puntosganados += 10;

		}

	}

	return puntosganados;

}



GenHabitante::~GenHabitante()
{
	for each (PHabitante * S in habitantes)
		delete S;
}

int GenHabitante::Size()
{
	return habitantes.size();
}

PHabitante* GenHabitante::Get(int pos)
{
	return habitantes[pos];
}

void GenHabitante::Agregar(PHabitante* aliado)
{
	habitantes.push_back(aliado);
}
void GenHabitante::Vaciar()
{
	for each (PHabitante * S in habitantes)
		delete S;
	habitantes.clear();
}

void GenHabitante::Mover(Graphics^ g)
{
	for each (PHabitante * S in habitantes)
		S->Mover(g);
}
void GenHabitante::Dibujar(Graphics^ g, Bitmap^ img)
{
	for each (PHabitante * S in habitantes)
		S->Dibujar(g, img);
}
