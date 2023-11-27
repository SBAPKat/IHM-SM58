#pragma once

#define taille 1000
#include "stdio.h"
#include "string.h"

namespace IHM_MC43 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Form1
	///
	/// AVERTISSEMENT : si vous modifiez le nom de cette classe, vous devrez modifier la
	///          propriété 'Nom du fichier de ressources' de l'outil de compilation de ressource managée
	///          pour tous les fichiers .resx dont dépend cette classe. Dans le cas contraire,
	///          les concepteurs ne pourront pas interagir correctement avec les ressources
	///          localisées associées à ce formulaire.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO : ajoutez ici le code du constructeur
			//serialPort1->Open();
			ind = 0 ;	// initialisation de l’indice
			numbyte = 0;
			typevar = 0;

			//variables relatives à V1
			Tab_V1 = gcnew array< double >(taille);	// allocation dynamique de 1000 éléments
			Taff_V1 = gcnew array< PointF >(taille);	// allocation de 1000 points à Taff_V1
			k_V1 = 3.0/0.4204/4096.0;	// facteur d'échelle de la donnée reçue (à adapter selon le capteur relié au DSP)
			V1min = -3.0 ;		// ordonnée la plus faible à afficher (à adapter aux données)
			V1max = 3.0 ; 	// ordonnée la plus élevée à afficher (à adapter aux données)
			dy_V1 = V1max-V1min;	// zone d’affichage choisie (à adapter en fonction du zoom voulu)
			y0_V1 = V1min;			// ordonnée du bas du graphe choisie (à adapter aux données)
			pen_V1 = gcnew Pen( Color::Blue,2.0f );	// couleur, taille du trait de la courbe

			//variables relatives à V2
			Tab_V2 = gcnew array< double >(taille);	// allocation dynamique de 1000 éléments
			Taff_V2 = gcnew array< PointF >(taille);	// allocation de 1000 points à Taff_V1
			k_V2 = 1.0;	// facteur d'échelle de la donnée reçue (à adapter selon le capteur relié au DSP)
			V2min = -1500.0;		// ordonnée la plus faible à afficher (à adapter aux données)
			V2max = 1500.0; 	// ordonnée la plus élevée à afficher (à adapter aux données)
			dy_V2 = V2max - V2min;	// zone d’affichage choisie (à adapter en fonction du zoom voulu)
			y0_V2 = V2min;			// ordonnée du bas du graphe choisie (à adapter aux données)
			pen_V2 = gcnew Pen(Color::Red, 2.0f);	// couleur, taille du trait de la courbe


			//variables relatives à V3
			Tab_V3 = gcnew array< double >(taille);	// allocation dynamique de 1000 éléments
			Taff_V3 = gcnew array< PointF >(taille);	// allocation de 1000 points à Taff_V1
			k_V3 = 1.0;	// facteur d'échelle de la donnée reçue (à adapter selon le capteur relié au DSP)
			V3min = -1500.0;		// ordonnée la plus faible à afficher (à adapter aux données)
			V3max = 1500.0; 	// ordonnée la plus élevée à afficher (à adapter aux données)
			dy_V3 = V3max - V3min;	// zone d’affichage choisie (à adapter en fonction du zoom voulu)
			y0_V3 = V3min;			// ordonnée du bas du graphe choisie (à adapter aux données)
			pen_V3 = gcnew Pen(Color::Orange, 2.0f);	// couleur, taille du trait de la courbe


			//variables relatives à V2
			Tab_V4 = gcnew array< double >(taille);	// allocation dynamique de 1000 éléments
			Taff_V4 = gcnew array< PointF >(taille);	// allocation de 1000 points à Taff_V1
			k_V4 = 1.0;	// facteur d'échelle de la donnée reçue (à adapter selon le capteur relié au DSP)
			V4min = -1500.0;		// ordonnée la plus faible à afficher (à adapter aux données)
			V4max = 1500.0; 	// ordonnée la plus élevée à afficher (à adapter aux données)
			dy_V4 = V4max - V4min;	// zone d’affichage choisie (à adapter en fonction du zoom voulu)
			y0_V4 = V4min;			// ordonnée du bas du graphe choisie (à adapter aux données)
			pen_V4 = gcnew Pen(Color::Green, 2.0f);	// couleur, taille du trait de la courbe

			pen2 = gcnew Pen( Color::Black,1.0f );	// couleur, taille du trait de la grille
			pen2->DashStyle = System::Drawing::Drawing2D::DashStyle::Dash;	// pointillés
			//
		}



	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
			serialPort1->Close();
		}
	private: System::IO::Ports::SerialPort^  serialPort1;
	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variables nécessaires au concepteur.
		UInt16 ind ;		// indice utilisé pour le stockage dans les tableaux
		UInt16 numbyte;		// comptage du numéro d'octet dans le mot
		Int16 temp16s;		// variable temporaire 16 bits signée
		char typevar;		// identificateur déjà reçu (variable en cours de réception)

		//variables relatives à V1
		array< double >^ Tab_V1;	// déclaration du tableau des données reçues
		double k_V1;				// facteur d’échelle de la donnée V1 et V2
		array< PointF >^ Taff_V1;	// déclaration du tableau de PointF (identique à une structure de deux doubles X et Y : chaque élément de Taff_V1 est accessible par la syntaxe Taff_V1[i].X et Taff_V1[i].Y)
		double V1min, V1max, dy_V1, y0_V1;	// variables permettant la mise à l’échelle du tracé
		Pen^ pen_V1;		// variable définissant le style de tracé de la courbe

		//variables relatives à V2
		array< double >^ Tab_V2;	// déclaration du tableau des données reçues
		double k_V2;				// facteur d’échelle de la donnée V1 et V2
		array< PointF >^ Taff_V2;	// déclaration du tableau de PointF (identique à une structure de deux doubles X et Y : chaque élément de Taff_V1 est accessible par la syntaxe Taff_V1[i].X et Taff_V1[i].Y)
		double V2min, V2max, dy_V2, y0_V2;	// variables permettant la mise à l’échelle du tracé
		Pen^ pen_V2;		// variable définissant le style de tracé de la courbe

		//variables relatives à V3
		array< double >^ Tab_V3;	// déclaration du tableau des données reçues
		double k_V3;				// facteur d’échelle de la donnée V1 et V2
		array< PointF >^ Taff_V3;	// déclaration du tableau de PointF (identique à une structure de deux doubles X et Y : chaque élément de Taff_V1 est accessible par la syntaxe Taff_V1[i].X et Taff_V1[i].Y)
		double V3min, V3max, dy_V3, y0_V3;	// variables permettant la mise à l’échelle du tracé
		Pen^ pen_V3;		// variable définissant le style de tracé de la courbe

		//variables relatives à V4
		array< double >^ Tab_V4;	// déclaration du tableau des données reçues
		double k_V4;				// facteur d’échelle de la donnée V1 et V2
		array< PointF >^ Taff_V4;	// déclaration du tableau de PointF (identique à une structure de deux doubles X et Y : chaque élément de Taff_V1 est accessible par la syntaxe Taff_V1[i].X et Taff_V1[i].Y)
		double V4min, V4max, dy_V4, y0_V4;	// variables permettant la mise à l’échelle du tracé
		Pen^ pen_V4;		// variable définissant le style de tracé de la courbe

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
private: System::Windows::Forms::TextBox^ speedInputBox;

private: System::Windows::Forms::Button^ sendSpeedButton;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::TextBox^ errorOutput;


		Pen^ pen2;	// variable définissant le style de tracé de la grille
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->speedInputBox = (gcnew System::Windows::Forms::TextBox());
			this->sendSpeedButton = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->errorOutput = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// serialPort1
			// 
			this->serialPort1->BaudRate = 115200;
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &Form1::serialPort1_DataReceived);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Location = System::Drawing::Point(35, 61);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(269, 211);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(116, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(152, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Vitesse roues appliquée [RPM]";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox2->Location = System::Drawing::Point(328, 61);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(269, 211);
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox2_Paint);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(419, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(108, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Couple appliqué [Nm]";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(710, 34);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(106, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Courant Mesuré [mA]";
			// 
			// pictureBox3
			// 
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox3->Location = System::Drawing::Point(619, 61);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(269, 211);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox3_Paint);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(985, 34);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(146, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Vitesse roues mesurée [RPM]";
			// 
			// pictureBox4
			// 
			this->pictureBox4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox4->Location = System::Drawing::Point(904, 61);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(269, 211);
			this->pictureBox4->TabIndex = 4;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox4_Paint);
			// 
			// speedInputBox
			// 
			this->speedInputBox->Location = System::Drawing::Point(159, 295);
			this->speedInputBox->Name = L"speedInputBox";
			this->speedInputBox->Size = System::Drawing::Size(100, 20);
			this->speedInputBox->TabIndex = 6;
			// 
			// sendSpeedButton
			// 
			this->sendSpeedButton->Location = System::Drawing::Point(265, 295);
			this->sendSpeedButton->Name = L"sendSpeedButton";
			this->sendSpeedButton->Size = System::Drawing::Size(128, 22);
			this->sendSpeedButton->TabIndex = 7;
			this->sendSpeedButton->Text = L"Envoyer vitesse";
			this->sendSpeedButton->UseVisualStyleBackColor = true;
			this->sendSpeedButton->Click += gcnew System::EventHandler(this, &Form1::sendSpeedButton_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(32, 298);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(121, 13);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Vitesse moteur [<3000tr]";
			// 
			// errorOutput
			// 
			this->errorOutput->Location = System::Drawing::Point(34, 514);
			this->errorOutput->Name = L"errorOutput";
			this->errorOutput->Size = System::Drawing::Size(359, 20);
			this->errorOutput->TabIndex = 9;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1325, 546);
			this->Controls->Add(this->errorOutput);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->sendSpeedButton);
			this->Controls->Add(this->speedInputBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void serialPort1_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) {
				 UInt16 n = serialPort1->BytesToRead;	// nb de valeur dans le buffer circulaire de réception
				 while(n--)		// on lit et on traite les n données du buffer
				 {
					 Byte x=serialPort1->ReadByte();	// lecture d’une valeur du buffer
					 switch(typevar)	// typevar définit le param en cours de lecture
					 {
					 case 's':	// réception des données (V1 et V2) à tracer (identifiant ‘s’)
						 if(numbyte==0)	// réception du LSB de V1
						 {
							 temp16s=x;
							 numbyte++;
						 }
						 else if(numbyte==1)	// réception du MSB de V1
						 {
							 temp16s += x<<8;
							 numbyte++;
							 Tab_V1[ind] = k_V1*(double)temp16s;	// mise à l’échelle
						 }
						 else if(numbyte==2)	// réception du LSB de V2
						 {
							 temp16s=x;
							 numbyte++;
						 }
						 else if(numbyte==3)	// réception du MSB de V2
						 {
							 temp16s += x<<8;
							 Tab_V2[ind++] = k_V2*(double)temp16s;	// mise à l’échelle
							 if(ind>=1000)
							 {
								 ind=0;
							 }
							 numbyte=0;
							 typevar=0;
						 }
						 break;
					 default:	// lettre d'identification reçu ou erreur
						 switch(x)
						 {
						 case 'a':	// réception des données en graphe (U et I)
							 typevar=x;
							 break;
						 }
					 }

				 }
				 pictureBox1->Invalidate();
				 pictureBox2->Invalidate();
				 pictureBox3->Invalidate();
				 pictureBox4->Invalidate();
			 }

   private: void grid(Graphics^ g, UInt16 hauteur, UInt16 largeur, double frac) {
				if(frac<=1) return;
				double dx,dy;
				dx = (double)largeur/frac;
				dy = (double)(hauteur-5)/frac;
				for(double i=1;i<frac;i++)
				{
					g->DrawLine(pen2,i*dx,0.0,i*dx,(float)hauteur-5);
					g->DrawLine(pen2,0.0,i*dy,(float)largeur,i*dy);
				}
			}

private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 Graphics^ g = e->Graphics;	// variable g pointant sur la fenêtre graphique
			 if(pictureBox1->Width < 5) return;	// détecte si la fenêtre est trop petite
			 if(pictureBox1->Height < 5) return;
			 for(UInt16 i=0;i<1000;i++) 	// calcul du tableau de points pour l’affichage
			 {
				 Taff_V1[i].X = pictureBox1->Width*(double)i/1000.0;	// abscisse
				 Taff_V1[i].Y = (pictureBox1->Height-5)-(pictureBox1->Height-5)*(Tab_V1[i]-y0_V1)/dy_V1;	// ordonnée
			 }
			 grid(g,pictureBox1->Height,pictureBox1->Width,10);
			 g->DrawLines( pen_V1, Taff_V1);		// trace de la courbe complète
		 }
private: System::Void pictureBox2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 Graphics^ g = e->Graphics;	// variable g pointant sur la fenêtre graphique
			 if(pictureBox2->Width < 5) return;	// détecte si la fenêtre est trop petite
			 if(pictureBox2->Height < 5) return;
			 for(UInt16 i=0;i<1000;i++) 	// calcul du tableau de points pour l’affichage
			 {
				 Taff_V2[i].X = pictureBox2->Width*(double)i/1000.0;	// abscisse
				 Taff_V2[i].Y = (pictureBox2->Height-5)-(pictureBox2->Height-5)*(Tab_V2[i]-y0_V2)/dy_V2;	// ordonnée
			 }
			 grid(g,pictureBox2->Height,pictureBox2->Width,10);
			 g->DrawLines( pen_V2, Taff_V2);		// trace de la courbe complète
		 }
private: System::Void pictureBox3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		   Graphics^ g = e->Graphics;	// variable g pointant sur la fenêtre graphique
		   if (pictureBox3->Width < 5) return;	// détecte si la fenêtre est trop petite
		   if (pictureBox3->Height < 5) return;
		   for (UInt16 i = 0; i < 1000; i++) 	// calcul du tableau de points pour l’affichage
		   {
			   Taff_V3[i].X = pictureBox3->Width * (double)i / 1000.0;	// abscisse
			   Taff_V3[i].Y = (pictureBox3->Height - 5) - (pictureBox3->Height - 5) * (Tab_V3[i] - y0_V3) / dy_V3;	// ordonnée
		   }
		   grid(g, pictureBox3->Height, pictureBox3->Width, 10);
		   g->DrawLines(pen_V3, Taff_V3);		// trace de la courbe complète
	   }
private: System::Void pictureBox4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Graphics^ g = e->Graphics;	// variable g pointant sur la fenêtre graphique
	if (pictureBox4->Width < 5) return;	// détecte si la fenêtre est trop petite
	if (pictureBox4->Height < 5) return;
	for (UInt16 i = 0; i < 1000; i++) 	// calcul du tableau de points pour l’affichage
	{
		Taff_V4[i].X = pictureBox4->Width * (double)i / 1000.0;	// abscisse
		Taff_V4[i].Y = (pictureBox4->Height - 5) - (pictureBox4->Height - 5) * (Tab_V4[i] - y0_V4) / dy_V4;	// ordonnée
	}
	grid(g, pictureBox4->Height, pictureBox4->Width, 10);
	g->DrawLines(pen_V4, Taff_V4);		// trace de la courbe complète
}


private: System::Void sendSpeedButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!serialPort1->IsOpen) {
		errorOutput->Text = "Port COM non ouvert";
		return;
	}
	// get the number from string to char
	String^ userInput = speedInputBox->Text;
	char userInput_buf[6] = { 0 };
	//check that the input only contains numbers, max 5chars
	if (userInput->Length > 4) {
		errorOutput->Text = "Erreur Commande de vitesse: Entrez un nombre inférieur à 3000";
		return;
	}
	for (int i = 0; i < userInput->Length; i++) {
		if (!Char::IsDigit(userInput[i])) {
			errorOutput->Text = "Erreur commande de vitesse: Entrez un nombre";
			return;
		}
		userInput_buf[i] = userInput[i];
		userInput_buf[i + 1] = '\0';

	}
	errorOutput->Text = "Envoi commande ok";
	unsigned int Speed = 0;
	if (sscanf(userInput_buf, "%d", &Speed) != 1) {
		errorOutput->Text = "Erreur lors de la lecture de la vitesse demand�e par l'utilisateur";
		return;
	}
	if (Speed >= 3000) {
		errorOutput->Text = "Erreur Commande de vitesse: Entrez un nombre inférieur à 3000";
		return;
	}

	//send the speed as a 16bit number
	array<unsigned char>^ speed_buf = gcnew array<unsigned char>(3);
	speed_buf[0] = 'S';
	speed_buf[1] = (unsigned char)(Speed & 0xFF);
	speed_buf[2] = (unsigned char)((Speed >> 8) & 0xFF);
	serialPort1->Write(speed_buf, 0, 3);
}
};
}

