#include <cstdio>
#include <cstdlib>
#include <getopt.h>
#include "MesOptions.h"
#include "MesFichiers.h"
#include "MonMenu.h"

using namespace std;

MesOptions :: MesOptions(){}

int main(int argc, char* argv[])
{
	MonMenu menu;
	MesOptions options;

	options.setOpt(argc, argv);
	cout << "erreur d'option: " << options.getError() << endl;

	if (options.getStatus())
	{
		MesFichiers fichiers(options.getdFlg(), options.getrFlg());

		if (fichiers.ok())
		{
			cout << menu;
		}
		
		else cout << "erreur de fichier: " << fichiers.getError() << endl;
	}

	return 0;
}
