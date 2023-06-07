#pragma once


#include "JuegoMain.h"
//#include "MenuPrincipal.h"


namespace ProjectCLRtest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de SelectorNivel
	/// </summary>
	public ref class SelectorNivel : public System::Windows::Forms::Form
	{
	public:
		SelectorNivel(void)
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
		~SelectorNivel()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pbhome;
	private: System::Windows::Forms::PictureBox^ pbgame;
	private: System::Windows::Forms::Label^ lbltexto;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SelectorNivel::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pbhome = (gcnew System::Windows::Forms::PictureBox());
			this->pbgame = (gcnew System::Windows::Forms::PictureBox());
			this->lbltexto = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbhome))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbgame))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(45, 90);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(269, 177);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &SelectorNivel::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(367, 90);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(269, 177);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &SelectorNivel::pictureBox2_Click);
			// 
			// pbhome
			// 
			this->pbhome->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbhome.Image")));
			this->pbhome->Location = System::Drawing::Point(45, 294);
			this->pbhome->Name = L"pbhome";
			this->pbhome->Size = System::Drawing::Size(167, 47);
			this->pbhome->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pbhome->TabIndex = 2;
			this->pbhome->TabStop = false;
			this->pbhome->Click += gcnew System::EventHandler(this, &SelectorNivel::pbhome_Click);
			// 
			// pbgame
			// 
			this->pbgame->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbgame.Image")));
			this->pbgame->Location = System::Drawing::Point(490, 294);
			this->pbgame->Name = L"pbgame";
			this->pbgame->Size = System::Drawing::Size(146, 47);
			this->pbgame->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pbgame->TabIndex = 3;
			this->pbgame->TabStop = false;
			this->pbgame->Click += gcnew System::EventHandler(this, &SelectorNivel::pbgame_Click);
			// 
			// lbltexto
			// 
			this->lbltexto->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbltexto->ForeColor = System::Drawing::Color::Red;
			this->lbltexto->Location = System::Drawing::Point(142, 9);
			this->lbltexto->Name = L"lbltexto";
			this->lbltexto->Size = System::Drawing::Size(422, 57);
			this->lbltexto->TabIndex = 4;
			this->lbltexto->Text = L"Nivel Seguridad";
			this->lbltexto->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SelectorNivel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(680, 364);
			this->ControlBox = false;
			this->Controls->Add(this->lbltexto);
			this->Controls->Add(this->pbgame);
			this->Controls->Add(this->pbhome);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"SelectorNivel";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SelectorNivel";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbhome))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbgame))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pbhome_Click(System::Object^ sender, System::EventArgs^ e) {


		this->Close();

		for each (Form ^ g in Application::OpenForms)
		{

			if (g->Text->Equals("MenuPrincipal")) {

				g->Show();
				break;

			}

		}

	//MenuPrincipal^ mpe2 = gcnew MenuPrincipal();

	//	mpe2->Show();
	//
	//	this->Close();


	}
private: System::Void pbgame_Click(System::Object^ sender, System::EventArgs^ e) {
	
	String^ x  ;

	if (lbltexto->Text->CompareTo("Nivel Salud"))
		x = "salud";
	else
		x = "seguridad";



	JuegoMain^ jmain = gcnew  JuegoMain(640,800,x);

	jmain->ShowDialog();


}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {

	lbltexto->Text = "Nivel Salud";

}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	lbltexto->Text = "Nivel Seguridad";
}
};
}
