
#include "gas.h"
#include <QFile>
#include <QMessageBox>

int Gas::delta_i[] = {1, 1, 0, 1, 0, 1};
const double Gas::R = 8.31451;
QDir Gas::inDir= QDir();


Gas::Gas() {
    Name = QString ( "Unknown" );
    Formula = QString ( "Unknown" );

    for ( int i = 0; i < 4; ++i )
        Aik[i] = 0.00;

    T_c = 0.0;
    Ro_c = 0.0;
    M = 0.0;
    Omega = 0.0;
    for ( int i = 0; i < 6; ++i )
        Dik[i] = 0.00;
}

Gas::Gas ( const QString & fileName ) {
    QString fn = inDir.filePath ( fileName );
    QFile in ( fn );
    if ( in.open ( QFile::ReadOnly ) ) {
        QTextStream IN ( &in );
        IN >> *this;
        in.close();
    }
    else {
        QMessageBox msgBox;
        msgBox.setText ( QString ( "Cannot open file " ) + fn );
        msgBox.setInformativeText ( "Do you want to save your changes?" );
        msgBox.setStandardButtons ( QMessageBox::Ignore | QMessageBox::Abort );
        msgBox.setDefaultButton ( QMessageBox::Abort );
        int ret = msgBox.exec();
        switch ( ret ) {
        case QMessageBox::Abort :
            break;
        case  QMessageBox::Ignore :
            break;
        }
    }
}

Gas::Gas ( const Gas &other ) {
    Name = other.Name;
    Formula = other.Formula;
    Zamenitel = other.Zamenitel;
    Number=other.Number;

    for ( int i = 0; i < 4; ++i )
        Aik[i] = other.Aik[i];

    T_c = other.T_c;
    Ro_c = other.Ro_c;
    M = other.M;
    Omega = other.Omega;

    for ( int i = 0; i < 6; ++i )
        Dik[i] = other.Dik[i];

    Ei=other.Ei;
    Ki=other.Ki;
    Gi=other.Gi;
    Qi=other.Qi;
    Fi=other.Fi;
    Si=other.Si;
    Wi=other.Wi;
}

Gas::~Gas() {
}

Gas &Gas::operator= ( const Gas &other ) {
    Name = other.Name;
    Formula = other.Formula;
    Zamenitel= other.Zamenitel;
    Number=other.Number;

    for ( int i = 0; i < 4; ++i )
        Aik[i] = other.Aik[i];

    T_c = other.T_c;
    Ro_c = other.Ro_c;
    M = other.M;
    Omega = other.Omega;

    for ( int i = 0; i < 6; ++i )
        Dik[i] = other.Dik[i];

    Ei=other.Ei;
    Ki=other.Ki;
    Gi=other.Gi;
    Qi=other.Qi;
    Fi=other.Fi;
    Si=other.Si;
    Wi=other.Wi;
}

bool Gas::operator== ( const Gas &other ) {

}

QTextStream &operator<< ( QTextStream &out, const Gas &gas ) {
    out << gas.Name << "\n";
    out << gas.Formula << " -> " << gas.Zamenitel << "\n";
    out << "Number" <<"\t\t\t\t\t"<< gas.Number << "\n";

    for ( int i = 0; i < 4; ++i )
        out <<"Aik["<<i<<"]"<<"\t\t\t\t\t"<< gas.Aik[i] << "\n";
    out << "\n";

    out <<"T_c"<<"\t\t\t\t\t"<<gas.T_c << "\n";
    out <<QString ( "ρ_c" ) <<"\t\t\t\t\t"<< gas.Ro_c << "\n";
    out <<QString::fromUtf8 ( "Молярная_масса_Μi,кг/кмоль" ) <<"\t\t"<< gas.M << "\n";
    out <<QString ( "Ω" ) <<"\t\t\t\t\t"<< gas.Omega << "\n";
    out << "\n";

    for ( int i = 0; i < 6; ++i )
        out <<"Dik["<<i<<"]"<<"\t\t\t\t\t"<< gas.Dik[i] << "\n";
    out << "\n";

    out << QString::fromUtf8 ( "Энергетический_параметр_Ei" ) << "\t\t" << gas.Ei<< "\n";
    out << QString::fromUtf8 ( "Параметр_размера_Ki,(м3/кмоль)^1/3" ) << "\t" << gas.Ki<< "\n";
    out << QString::fromUtf8 ( "Ориентационный_параметр_Gi" ) << "\t\t"<< gas.Gi<< "\n";
    out << QString::fromUtf8 ( "Квадрупольный_параметр_Qi" ) << "\t\t"<< gas.Qi<< "\n";
    out << QString::fromUtf8 ( "Высокотемпературный_параметр_Fi" ) << "\t\t"<< gas.Fi<< "\n";
    out << QString::fromUtf8 ( "Дипольный_параметр_Si" ) << "\t\t\t"<< gas.Si<< "\n";
    out << QString::fromUtf8 ( "Параметр_ассоциации_Wi" ) << "\t\t\t"<< gas.Wi<< "\n";
    out << "\n";

    return out;
}

QTextStream &operator>> ( QTextStream &in, Gas &gas ) {
    QString tmp;
    in >> gas.Name;
    in >> gas.Formula >> tmp >> gas.Zamenitel;
    in >> tmp >> gas.Number;

    for ( int i = 0; i < 4; ++i )
        in >> tmp >>gas.Aik[i];

    in >> tmp >> gas.T_c;
    in >> tmp >> gas.Ro_c;
    in >> tmp >> gas.M;
    in >> tmp >> gas.Omega;

    for ( int i = 0; i < 6; ++i )
        in >> tmp >> gas.Dik[i];

    in >> tmp >> gas.Ei;
    in >> tmp >> gas.Ki;
    in >> tmp >> gas.Gi;
    in >> tmp >> gas.Qi;
    in >> tmp >> gas.Fi;
    in >> tmp >> gas.Si;
    in >> tmp >> gas.Wi;

    return in;
}

void Gas::setInDir ( const QDir &other ) {
    inDir=other;
}

QDir Gas::getInDir ( void ) {
    return inDir;
}
