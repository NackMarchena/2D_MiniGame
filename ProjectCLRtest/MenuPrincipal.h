#pragma once

#include "Configuracion.h"
#include "Credito.h"
#include "Instrucciones.h"
#include "SelectorNivel.h"


namespace ProjectCLRtest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MenuPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pbInstrucciones;
	private: System::Windows::Forms::PictureBox^ pbconfiguracion;
	private: System::Windows::Forms::PictureBox^ pbcreditos;
	private: System::Windows::Forms::PictureBox^ pbsalir;
	protected:

	protected:



	private: System::Windows::Forms::PictureBox^ pbniveles;
	private: System::Windows::Forms::PictureBox^ pictureBox1;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPrincipal::typeid));
			this->pbInstrucciones = (gcnew System::Windows::Forms::PictureBox());
			this->pbconfiguracion = (gcnew System::Windows::Forms::PictureBox());
			this->pbcreditos = (gcnew System::Windows::Forms::PictureBox());
			this->pbsalir = (gcnew System::Windows::Forms::PictureBox());
			this->pbniveles = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbInstrucciones))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbconfiguracion))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbcreditos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbsalir))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbniveles))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pbInstrucciones
			// 
			this->pbInstrucciones->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbInstrucciones.Image")));
			this->pbInstrucciones->Location = System::Drawing::Point(211, 126);
			this->pbInstrucciones->Name = L"pbInstrucciones";
			this->pbInstrucciones->Size = System::Drawing::Size(172, 50);
			this->pbInstrucciones->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pbInstrucciones->TabIndex = 0;
			this->pbInstrucciones->TabStop = false;
			this->pbInstrucciones->Click += gcnew System::EventHandler(this, &MenuPrincipal::pbInstrucciones_Click);
			// 
			// pbconfiguracion
			// 
			this->pbconfiguracion->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbconfiguracion.Image")));
			this->pbconfiguracion->Location = System::Drawing::Point(211, 204);
			this->pbconfiguracion->Name = L"pbconfiguracion";
			this->pbconfiguracion->Size = System::Drawing::Size(172, 50);
			this->pbconfiguracion->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pbconfiguracion->TabIndex = 1;
			this->pbconfiguracion->TabStop = false;
			this->pbconfiguracion->Click += gcnew System::EventHandler(this, &MenuPrincipal::pbconfiguracion_Click);
			// 
			// pbcreditos
			// 
			this->pbcreditos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbcreditos.Image")));
			this->pbcreditos->Location = System::Drawing::Point(211, 280);
			this->pbcreditos->Name = L"pbcreditos";
			this->pbcreditos->Size = System::Drawing::Size(172, 57);
			this->pbcreditos->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pbcreditos->TabIndex = 2;
			this->pbcreditos->TabStop = false;
			this->pbcreditos->Click += gcnew System::EventHandler(this, &MenuPrincipal::pbcreditos_Click);
			// 
			// pbsalir
			// 
			this->pbsalir->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbsalir.Image")));
			this->pbsalir->Location = System::Drawing::Point(12, 392);
			this->pbsalir->Name = L"pbsalir";
			this->pbsalir->Size = System::Drawing::Size(153, 50);
			this->pbsalir->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pbsalir->TabIndex = 3;
			this->pbsalir->TabStop = false;
			this->pbsalir->Click += gcnew System::EventHandler(this, &MenuPrincipal::pbsalir_Click);
			// 
			// pbniveles
			// 
			this->pbniveles->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbniveles.Image")));
			this->pbniveles->Location = System::Drawing::Point(421, 392);
			this->pbniveles->Name = L"pbniveles";
			this->pbniveles->Size = System::Drawing::Size(150, 50);
			this->pbniveles->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pbniveles->TabIndex = 4;
			this->pbniveles->TabStop = false;
			this->pbniveles->Click += gcnew System::EventHandler(this, &MenuPrincipal::pbniveles_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(559, 84);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkCyan;
			this->ClientSize = System::Drawing::Size(583, 454);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pbniveles);
			this->Controls->Add(this->pbsalir);
			this->Controls->Add(this->pbcreditos);
			this->Controls->Add(this->pbconfiguracion);
			this->Controls->Add(this->pbInstrucciones);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->Name = L"MenuPrincipal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MenuPrincipal";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MenuPrincipal::MenuPrincipal_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbInstrucciones))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbconfiguracion))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbcreditos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbsalir))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbniveles))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
private: System::Void pbInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {

	Instrucciones^ instru = gcnew Instrucciones();


	instru->ShowDialog();

}


private: System::Void pbconfiguracion_Click(System::Object^ sender, System::EventArgs^ e) {

	Configuracion^ config = gcnew Configuracion();

	config->ShowDialog();

}
private: System::Void pbcreditos_Click(System::Object^ sender, System::EventArgs^ e) {

	Credito^ credito = gcnew Credito();

	credito->ShowDialog();



}
private: System::Void pbniveles_Click(System::Object^ sender, System::EventArgs^ e) {


	this->Hide();

	SelectorNivel^ niveles = gcnew SelectorNivel();

	niveles->Show();

	

}
private: System::Void pbsalir_Click(System::Object^ sender, System::EventArgs^ e) {

	System::Windows::Forms::DialogResult r=MessageBox::Show(this,"Desea Salide del Juego?","Confirmacion",MessageBoxButtons::YesNo);

	if (r == System::Windows::Forms::DialogResult::Yes)
	{
		Application::Exit();

	}



}
private: System::Void MenuPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MenuPrincipal_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {

	Application::Exit();

}
};
}
