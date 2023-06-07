#pragma once

#include "LogicaJuego.h"
#include "JuegoPerdido.h"
#include "GanadorWin.h"


namespace ProjectCLRtest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// Resumen de JuegoMain
	/// </summary>
	public ref class JuegoMain : public System::Windows::Forms::Form
	{

		LogicaJuego^ juego;
		JuegoPerdido^ frmPerdido;
		GanadorWin^ frmGanador;
		//Stream^ musica;
	
	public:
		JuegoMain(int alto,int ancho, String^ xnivel)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		/*	musica = CallSound("RecursoMedia", "mm2");

			SoundPlayer^ sonido = gcnew SoundPlayer(musica);
			sonido->Load();
			sonido->PlayLooping();*/

		

			this->ClientSize = System::Drawing::Size(ancho, alto);
			
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;


			juego = gcnew LogicaJuego(alto,ancho, xnivel);
			frmPerdido = gcnew JuegoPerdido();
			frmGanador= gcnew GanadorWin();

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~JuegoMain()
		{
		

			if (components)
			{
				delete components;
			
			}
		}

	private: System::Windows::Forms::Timer^ timer1;



	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		/// 
		/// 
	



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &JuegoMain::timer1_Tick);
			// 
			// JuegoMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(689, 479);
			this->Name = L"JuegoMain";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"JuegoMain";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &JuegoMain::JuegoMain_FormClosing);
			this->Load += gcnew System::EventHandler(this, &JuegoMain::JuegoMain_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &JuegoMain::JuegoMain_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &JuegoMain::JuegoMain_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void JuegoMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		juego->LeerTeclas(true, e->KeyCode);

	}


	private: System::Void JuegoMain_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		juego->LeerTeclas(false, e->KeyCode);

	}


	private: System::Void JuegoMain_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		int statusJUego;

		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = bfc->Allocate(g, this->ClientRectangle);

		bf->Graphics->Clear(Color::White);
		juego->MoverTodosObjetos(bf->Graphics);
		juego->MostrarTodosObjetos(bf->Graphics);
		statusJUego = juego->ComprobarEstado();

		bf->Render(g);

		if (statusJUego == 1)
		{
			
			this->timer1->Enabled = false;
			frmPerdido->Show();
			frmPerdido->TopMost = true;
			this->Close();
	
			

		}
		else if (statusJUego == 2)
		{
		
		this->timer1->Enabled = false;
		frmGanador->Show();
		frmGanador->TopMost = true;
		this->Close();

		}



	}
	private: System::Void JuegoMain_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {

		

	}
};
}
