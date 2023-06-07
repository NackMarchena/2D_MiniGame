#include "PresentacionInicio.h"

using namespace System::Threading;

static void ThreadProc()
{
	Stream^ musica;

	musica = CallSound("RecursoMedia", "music");
	musica->Position = 0;
	SoundPlayer^ sonido = gcnew SoundPlayer(musica);
	
	sonido->Load();
	sonido->Play();
}


int main()
{
	//Thread^ oThread = gcnew Thread(gcnew ThreadStart(&ThreadProc));
	//oThread->Start();

	Application::Run(gcnew ProjectCLRtest::PresentacionInicio);
	return 0;
}