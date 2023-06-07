#pragma once

namespace ProjectCLRtest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Resumen de Configuracion
	/// </summary>
	public ref class Configuracion : public System::Windows::Forms::Form
	{
	public:
		Configuracion(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			Restaurar();

		}
	

	protected:


		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Configuracion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::MaskedTextBox^ txttgame;
	private: System::Windows::Forms::MaskedTextBox^ txthabitantes;
	protected:


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::MaskedTextBox^ txtaliados;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::MaskedTextBox^ txtagentes;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private:

		void Guardar()
		{
			
			String^ mt;

			mt = txttgame->Text + " " + txthabitantes->Text + " " + txtaliados->Text + " " + txtagentes->Text;

			File::WriteAllText("Configuracion.txt", mt);

		}


		void Restaurar()
		{
			
			String^ mt = File::ReadAllText("Configuracion.txt");
			int g = 0;

			for each (String ^ a in mt->Split(' '))
			{
				switch (g)
				{
				case 0:
					txttgame->Text = a;
					break;

				case 1:
					txthabitantes->Text = a;
					break;
				case 2:
					txtaliados->Text = a;
					break;
				case 3:
					txtagentes->Text = a;
					break;

				}

				
				g++;
			}	


		}
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Configuracion::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txttgame = (gcnew System::Windows::Forms::MaskedTextBox());
			this->txthabitantes = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtaliados = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtagentes = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cooper Black", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::LimeGreen;
			this->label1->Location = System::Drawing::Point(25, 124);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(278, 21);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Tiempo de Juego (Minutos) ";
			// 
			// txttgame
			// 
			this->txttgame->Location = System::Drawing::Point(315, 127);
			this->txttgame->Mask = L"99999";
			this->txttgame->Name = L"txttgame";
			this->txttgame->Size = System::Drawing::Size(192, 20);
			this->txttgame->TabIndex = 1;
			this->txttgame->ValidatingType = System::Int32::typeid;
			// 
			// txthabitantes
			// 
			this->txthabitantes->Location = System::Drawing::Point(315, 173);
			this->txthabitantes->Mask = L"99999";
			this->txthabitantes->Name = L"txthabitantes";
			this->txthabitantes->Size = System::Drawing::Size(192, 20);
			this->txthabitantes->TabIndex = 3;
			this->txthabitantes->ValidatingType = System::Int32::typeid;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cooper Black", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::LimeGreen;
			this->label2->Location = System::Drawing::Point(25, 170);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(226, 21);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Numero de Habitantes";
			// 
			// txtaliados
			// 
			this->txtaliados->Location = System::Drawing::Point(315, 219);
			this->txtaliados->Mask = L"99999";
			this->txtaliados->Name = L"txtaliados";
			this->txtaliados->Size = System::Drawing::Size(192, 20);
			this->txtaliados->TabIndex = 5;
			this->txtaliados->ValidatingType = System::Int32::typeid;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cooper Black", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::LimeGreen;
			this->label3->Location = System::Drawing::Point(25, 216);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(193, 21);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Numero de Aliados";
			// 
			// txtagentes
			// 
			this->txtagentes->Location = System::Drawing::Point(315, 267);
			this->txtagentes->Mask = L"99999";
			this->txtagentes->Name = L"txtagentes";
			this->txtagentes->Size = System::Drawing::Size(192, 20);
			this->txtagentes->TabIndex = 7;
			this->txtagentes->ValidatingType = System::Int32::typeid;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Cooper Black", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::LimeGreen;
			this->label4->Location = System::Drawing::Point(25, 264);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(198, 21);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Numero de Agentes";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Bauhaus 93", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::DarkRed;
			this->label5->Location = System::Drawing::Point(94, 36);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(350, 36);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Configuracón General";
			this->label5->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(212, 338);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(139, 50);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Configuracion::pictureBox1_Click);
			// 
			// Configuracion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightBlue;
			this->ClientSize = System::Drawing::Size(548, 419);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtagentes);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtaliados);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txthabitantes);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txttgame);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Configuracion";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Configuracion";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {

		System::Windows::Forms::DialogResult r = MessageBox::Show(this, "Esta Seguro de Guardar la Configuracion?", "Confirmacion", MessageBoxButtons::YesNo);

		if (r == System::Windows::Forms::DialogResult::Yes)
		{

			Guardar();


		}

		this->Close();




	}
};
}
