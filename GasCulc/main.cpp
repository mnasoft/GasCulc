#include <QtGui/QApplication>
#include "GasCulc.h"

#include "gas.h"

#include <QFile>

int main(int argc, char** argv)
{
    Gas N2;
    QFile in("N2.txt");
    if (in.open( QFile::ReadOnly))
    {
        QTextStream IN(&in);
        IN.setCodec("UTF-8");
        IN>>N2;
    }
    in.close();

    QFile out("N2.rez");
    if (out.open( QFile::WriteOnly))
    {
        QTextStream OUT(&out);
	OUT.setCodec("UTF-8");
	OUT.setRealNumberPrecision (10 );
	OUT.setRealNumberNotation(QTextStream::ScientificNotation);
	OUT.setNumberFlags(QTextStream::ForceSign);
        OUT<<N2;
    }
    out.close();

}

"N2"
"CO2"
"CH4"
"C2H6"
"C3H8"
"C4H10"
"I-C4H10"
"N-C5H12"
"I-C5H12"
"C6H14"
"C7H16"
"H2"
"CO"
"H2O" 
"He"


/*
    QApplication app(argc, argv);
    GasCulc foo;
    foo.show();
    return app.exec();
*/
