#include <QtGui/QApplication>
#include "GasCulc.h"

#include "gas.h"

#include <QFile>
#include <iostream>

int main(int argc, char** argv)
{
    QStringList components;
    components << "N2"<<"CO2"<<"CH4"<<"C2H6"<<"C3H8"<<"C4H10"<<"I-C4H10"<<"N-C5H12"<<"I-C5H12"<<"C6H14"<<"C7H16"<<"H2"<<"CO"<<"H2O" <<"He";
    int len = components.length();
    Gas gases[len];

    int i=0;
    QStringList::const_iterator c_Iter;
    for (c_Iter = components.constBegin(); c_Iter != components.constEnd(); ++c_Iter)
    {
        QString s_tmp=QString("../")+"ComponentData"+"/" + (*c_Iter) + ".txt";
        std::cout << s_tmp.toLocal8Bit().constData() << "\n";

        QFile in(s_tmp);
        if (in.open( QFile::ReadOnly))
        {
            QTextStream IN(&in);
            IN.setCodec("UTF-8");
            IN>>gases[i];
        }
        in.close();
        ++i;
    }
    
    int z1=sizeof(gases);
    int z2 =sizeof(gases[0]);

    for (int j=0; j < sizeof(gases)/sizeof(gases[0]); ++j)
    {
      QString s_tmp=components[j]+".rez";
        QFile out(s_tmp);
        if (out.open( QFile::WriteOnly))
        {
            QTextStream OUT(&out);
            OUT.setCodec("UTF-8");
            OUT.setRealNumberPrecision (10 );
            OUT.setRealNumberNotation(QTextStream::ScientificNotation);
            OUT.setNumberFlags(QTextStream::ForceSign);
            OUT<<gases[j];
        }
        out.close();
    }

//        std::cout << (*c_Iter).toLocal8Bit().constData() << endl;

}
/*
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
*/

/*
    QApplication app(argc, argv);
    GasCulc foo;
    foo.show();
    return app.exec();
*/
