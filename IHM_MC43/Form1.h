#pragma once

#define taille 1000

namespace IHM_MC43 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description r�sum�e de Form1
	///
	/// AVERTISSEMENT�: si vous modifiez le nom de cette classe, vous devrez modifier la
	///          propri�t� 'Nom du fichier de ressources' de l'outil de compilation de ressource manag�e
	///          pour tous les fichiers .resx dont d�pend cette classe. Dans le cas contraire,
	///          les concepteurs ne pourront pas interagir correctement avec les ressources
	///          localis�es associ�es � ce formulaire.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO�: ajoutez ici le code du constructeur
			serialPort1->Open();
			ind = 0 ;	// initialisation de l�indice
			numbyte = 0;
			typevar = 0;

			//variables relatives � V1
			Tab_V1 = gcnew array< double >(taille);	// allocation dynamique de 1000 �l�ments
			Taff_V1 = gcnew array< PointF >(taille);	// allocation de 1000 points � Taff_V1
			k_V1 = 3.0/0.4204/4096.0;	// facteur d'�chelle de la donn�e re�ue (� adapter selon le capteur reli� au DSP)
			V1min = -3.0 ;		// ordonn�e la plus faible � afficher (� adapter aux donn�es)
			V1max = 3.0 ; 	// ordonn�e la plus �lev�e � afficher (� adapter aux donn�es)
			dy_V1 = V1max-V1min;	// zone d�affichage choisie (� adapter en fonction du zoom voulu)
			y0_V1 = V1min;			// ordonn�e du bas du graphe choisie (� adapter aux donn�es)
			pen_V1 = gcnew Pen( Color::Blue,1.0f );	// couleur, taille du trait de la courbe

			//variables relatives � V2
			Tab_V2 = gcnew array< double >(taille);	// allocation dynamique de 1000 �l�ments
			Taff_V2 = gcnew array< PointF >(taille);	// allocation de 1000 points � Taff_V1
			k_V2 = 1.0;	// facteur d'�chelle de la donn�e re�ue (� adapter selon le capteur reli� au DSP)
			V2min = -1500.0 ;		// ordonn�e la plus faible � afficher (� adapter aux donn�es)
			V2max = 1500.0 ; 	// ordonn�e la plus �lev�e � afficher (� adapter aux donn�es)
			dy_V2 = V2max-V2min;	// zone d�affichage choisie (� adapter en fonction du zoom voulu)
			y0_V2 = V2min;			// ordonn�e du bas du graphe choisie (� adapter aux donn�es)
			pen_V2 = gcnew Pen( Color::Red,1.0f );	// couleur, taille du trait de la courbe

			pen2 = gcnew Pen( Color::White,1.0f );	// couleur, taille du trait de la grille
			pen2->DashStyle = System::Drawing::Drawing2D::DashStyle::Dash;	// pointill�s
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
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
		/// Variables n�cessaires au concepteur.
		UInt16 ind ;		// indice utilis� pour le stockage dans les tableaux
		UInt16 numbyte;		// comptage du num�ro d'octet dans le mot
		Int16 temp16s;		// variable temporaire 16 bits sign�e
		char typevar;		// identificateur d�j� re�u (variable en cours de r�ception)

		//variables relatives � V1
		array< double >^ Tab_V1;	// d�claration du tableau des donn�es re�ues
		double k_V1;				// facteur d��chelle de la donn�e V1 et V2
		array< PointF >^ Taff_V1;	// d�claration du tableau de PointF (identique � une structure de deux doubles X et Y : chaque �l�ment de Taff_V1 est accessible par la syntaxe Taff_V1[i].X et Taff_V1[i].Y)
		double V1min, V1max, dy_V1, y0_V1;	// variables permettant la mise � l��chelle du trac�
		Pen^ pen_V1;		// variable d�finissant le style de trac� de la courbe

		//variables relatives � V2
		array< double >^ Tab_V2;	// d�claration du tableau des donn�es re�ues
		double k_V2 ;				// facteur d��chelle de la donn�e V1 et V2
		array< PointF >^ Taff_V2;	// d�claration du tableau de PointF (identique � une structure de deux doubles X et Y : chaque �l�ment de Taff_V1 est accessible par la syntaxe Taff_V1[i].X et Taff_V1[i].Y)
		double V2min, V2max, dy_V2, y0_V2;	// variables permettant la mise � l��chelle du trac�
		Pen^ pen_V2;		// variable d�finissant le style de trac� de la courbe
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label2;

		Pen^ pen2;	// variable d�finissant le style de trac� de la grille
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m�thode avec l'�diteur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
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
			this->label1->Location = System::Drawing::Point(157, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Voie0";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox2->Location = System::Drawing::Point(364, 61);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(269, 211);
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox2_Paint);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(488, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Voie1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(713, 328);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void serialPort1_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) {
				 UInt16 n = serialPort1->BytesToRead;	// nb de valeur dans le buffer circulaire de r�ception
				 while(n--)		// on lit et on traite les n donn�es du buffer
				 {
					 Byte x=serialPort1->ReadByte();	// lecture d�une valeur du buffer
					 switch(typevar)	// typevar d�finit le param en cours de lecture
					 {
					 case 'a':	// r�ception des donn�es (V1 et V2) � tracer (identifiant �a�)
						 if(numbyte==0)	// r�ception du LSB de V1
						 {
							 temp16s=x;
							 numbyte++;
						 }
						 else if(numbyte==1)	// r�ception du MSB de V1
						 {
							 temp16s += x<<8;
							 numbyte++;
							 Tab_V1[ind] = k_V1*(double)temp16s;	// mise � l��chelle
						 }
						 else if(numbyte==2)	// r�ception du LSB de V2
						 {
							 temp16s=x;
							 numbyte++;
						 }
						 else if(numbyte==3)	// r�ception du MSB de V2
						 {
							 temp16s += x<<8;
							 Tab_V2[ind++] = k_V2*(double)temp16s;	// mise � l��chelle
							 if(ind>=1000)
							 {
								 ind=0;
							 }
							 numbyte=0;
							 typevar=0;
						 }
						 break;
					 default:	// lettre d'identification re�u ou erreur
						 switch(x)
						 {
						 case 'a':	// r�ception des donn�es en graphe (U et I)
							 typevar=x;
							 break;
						 }
					 }

				 }
				 pictureBox1->Invalidate();
				 pictureBox2->Invalidate();
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
			 Graphics^ g = e->Graphics;	// variable g pointant sur la fen�tre graphique
			 if(pictureBox1->Width < 5) return;	// d�tecte si la fen�tre est trop petite
			 if(pictureBox1->Height < 5) return;
			 for(UInt16 i=0;i<1000;i++) 	// calcul du tableau de points pour l�affichage
			 {
				 Taff_V1[i].X = pictureBox1->Width*(double)i/1000.0;	// abscisse
				 Taff_V1[i].Y = (pictureBox1->Height-5)-(pictureBox1->Height-5)*(Tab_V1[i]-y0_V1)/dy_V1;	// ordonn�e
			 }
			 grid(g,pictureBox1->Height,pictureBox1->Width,10);
			 g->DrawLines( pen_V1, Taff_V1);		// trace de la courbe compl�te
		 }
private: System::Void pictureBox2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 Graphics^ g = e->Graphics;	// variable g pointant sur la fen�tre graphique
			 if(pictureBox2->Width < 5) return;	// d�tecte si la fen�tre est trop petite
			 if(pictureBox2->Height < 5) return;
			 for(UInt16 i=0;i<1000;i++) 	// calcul du tableau de points pour l�affichage
			 {
				 Taff_V2[i].X = pictureBox2->Width*(double)i/1000.0;	// abscisse
				 Taff_V2[i].Y = (pictureBox2->Height-5)-(pictureBox2->Height-5)*(Tab_V2[i]-y0_V2)/dy_V2;	// ordonn�e
			 }
			 grid(g,pictureBox2->Height,pictureBox2->Width,10);
			 g->DrawLines( pen_V2, Taff_V2);		// trace de la courbe compl�te
		 }
};
}

