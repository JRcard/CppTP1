#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <getopt.h>
#include "MesOptions.h"
#include "MesFichiers.h"

using namespace std;

MesOptions :: MesOptions(){}

int main(int argc, char* argv[])
{

	MesOptions options;
	options.setOpt(argc, argv);
	cout << options.getError() << endl;

	return 0;
}
