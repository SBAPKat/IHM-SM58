// IHM_MC43.cpp : fichier projet principal.

#include "stdafx.h"
#include "Form1.h"

using namespace IHM_MC43;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Activation des effets visuels de Windows XP avant la création de tout contrôle
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Créer la fenêtre principale et l'exécuter
	Application::Run(gcnew Form1());
	return 0;
}
