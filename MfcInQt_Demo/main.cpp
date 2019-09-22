#include "mfcinqt_demo.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MfcInQt_Demo w;
	w.show();
	return a.exec();
}
