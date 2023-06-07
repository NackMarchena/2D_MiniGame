#include "LogicaJuego.h"

enum StadoJuego
{
	perdido=1,
	ganado=2
};

 LogicaJuego::LogicaJuego(int _alto,int _ancho,String^ _nombrefondo)
{

	alto_form = _alto;ancho_form = _ancho;

	nombrefondo = _nombrefondo;

	imglider = CallImage("RecursoMedia", "lider");
	lider = new PLider(imglider);

	imgaliados = CallImage("RecursoMedia", "agente");
	aliados = new GenPAliados();

	imgagentes = CallImage("RecursoMedia", "aliado");
	agentes = new GenPAgentes();

	imghabitantes = CallImage("RecursoMedia", "habitante");
	habitantes = new GenHabitante();

	/*fondos*/

	imgfondo_salud = CallImage("RecursoMedia", "salud");
	imgfondo_seguridad = CallImage("RecursoMedia", "seguridad");

	/*sistema de puntos*/

	puntos =0; tiempo = 0;

	agregar = 0; controlTiempo = 0;

	cant_aliados = 0;cant_agentes =0;cant_habitantes = 0;

	Restaurar();


	for (int nh = 0;nh < cant_habitantes;nh++)
	{
		habitantes->Agregar(new PHabitante(imghabitantes,alto_form,ancho_form));

	}


}

void LogicaJuego::Restaurar()
{

	String^ mt = File::ReadAllText("Configuracion.txt");
	int g = 0;

	for each (String ^ a in mt->Split(' '))
	{
		switch (g)
		{
		case 0:
		
			this->tiempo = Int32::Parse(a);
			break;

		case 1:
		
			this->cant_habitantes = Int32::Parse(a);
			break;
		case 2:
			this->cant_aliados = Int32::Parse(a);
			break;
		case 3:
			this->cant_agentes = Int32::Parse(a);
			break;

		}


		g++;
	}


}

LogicaJuego::~LogicaJuego() {

	delete lider;
	delete aliados;
	delete agentes;
	delete habitantes;

}

void LogicaJuego::MoverTodosObjetos(Graphics^ led)
{
	if (clock() - agregar >= 2000 && agentes->Size()< cant_agentes)
	{
		if (rand() % 2 == 0)
			agentes->Agregar(new PAgente(imgagentes,alto_form,ancho_form));
		

		agregar = clock();
	}

	if (clock() - controlTiempo >= 60000)
	{
		
		tiempo--;

		controlTiempo = clock();
	}

	
	lider->Mover(led);
	agentes->Mover(led,lider->Area(),aliados->getAliado(),aliados);
	aliados->Mover(led);
	habitantes->Mover(led);

	/*verificamos coliciones*/

	/*colisiones entre agentes y liados*/

	for (int k = 0; k < agentes->Size();k++)
	{

		puntos+= - aliados->EliminaAliado(agentes->Get(k)->Area());
	
		if (puntos < 0)
			puntos = 0;
		
	}

	/*colisiones entre Habitante y aliados para ayudar a subir level*/
	for (int k = 0; k < aliados->Size();k++)
	{

	 puntos+=habitantes->AsisteAliado(aliados->Get(k)->Area());

	}

	
	
}


int LogicaJuego::ComprobarEstado()
{
	/*veo si he perdido*/

	if ((tiempo <= 0) && (puntos < 100))
	{
		return StadoJuego::perdido;


	}/* si he ganado*/
	else if ((puntos >= 100) && (tiempo > 0))
	{

		return StadoJuego::ganado;

	}



	return 0;


}

void LogicaJuego::MostrarComponentesJuego(Graphics^ g)
{	
	if (nombrefondo->CompareTo("seguridad"))
		g->DrawImage(imgfondo_seguridad, 0, 0);
	else

	g->DrawImage(imgfondo_salud, 0, 0);

	g->DrawString("Puntaje: " + this->puntos,gcnew Font( "Arial",10,FontStyle::Bold), Brushes::DarkRed, 5, 10);
	g->DrawString("Aliados: " + (this->cant_aliados - aliados->Size()), gcnew Font("Arial", 10, FontStyle::Bold), Brushes::DarkRed,5, 30);
	g->DrawString("Tiempo : " + this->tiempo, gcnew Font("Arial", 10, FontStyle::Bold), Brushes::DarkRed, 5, 50);
}

void LogicaJuego::MostrarTodosObjetos(Graphics^ led)
{

	this->MostrarComponentesJuego(led);

	lider->Dibujar(led, imglider);

	aliados->Dibujar(led, imgaliados);

	agentes->Dibujar(led, imgagentes);

	habitantes->Dibujar(led, imghabitantes);
}


void LogicaJuego::LeerTeclas(bool estado, Keys tecla)
{

	if (estado == true)
	{
		int v = 5;

		if (tecla == Keys::Up)
		{
			lider->SetDY(-v);
			lider->SetAccion(CaminarArriba);
		}
		else if (tecla == Keys::Down)
		{
			lider->SetDY(v);
			lider->SetAccion(CaminarAbajo);
		}
		else if (tecla == Keys::Left)
		{
			lider->SetDX(-v);
			lider->SetAccion(CaminarIzquierda);
		}
		else if (tecla == Keys::Right)
		{
			lider->SetDX(v);
			lider->SetAccion(CaminarDerecha);
		}
		else if (tecla == Keys::A)
		{
		
			
			if (aliados->Size()<cant_aliados)
					aliados->Agregar(new PAliados(imgaliados,alto_form,ancho_form));


		}
		
	}
	else
	{
		if (tecla == Keys::Up)
		{
			lider->SetDY(0);
		}
		else if (tecla == Keys::Down)
		{
			lider->SetDY(0);
		}
		else if (tecla == Keys::Left)
		{
			lider->SetDX(0);
		}
		else if (tecla == Keys::Right)
		{
			lider->SetDX(0);
		}
	}



}