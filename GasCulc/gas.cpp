
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
    } else {
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

    for ( int i = 0; i < 4; ++i )
        Aik[i] = other.Aik[i];

    T_c = other.T_c;
    Ro_c = other.Ro_c;
    M = other.M;
    Omega = other.Omega;

    for ( int i = 0; i < 6; ++i )
        Dik[i] = other.Dik[i];
}

Gas::~Gas() {
}

Gas &Gas::operator= ( const Gas &other ) {
    Name = other.Name;
    Formula = other.Formula;

    for ( int i = 0; i < 4; ++i )
        Aik[i] = other.Aik[i];

    T_c = other.T_c;
    Ro_c = other.Ro_c;
    M = other.M;
    Omega = other.Omega;

    for ( int i = 0; i < 6; ++i )
        Dik[i] = other.Dik[i];
}

bool Gas::operator== ( const Gas &other ) {

}

QTextStream &operator<< ( QTextStream &out, const Gas &gas ) {
    out << gas.Name << "\n";
    out << gas.Formula << "\n";

    for ( int i = 0; i < 4; ++i )
        out << gas.Aik[i] << "\n";
    out << "\n";

    out << gas.T_c << "\n";
    out << gas.Ro_c << "\n";
    out << gas.M << "\n";
    out << gas.Omega << "\n";
    out << "\n";

    for ( int i = 0; i < 6; ++i )
        out << gas.Dik[i] << "\n";

    return out;
}

QTextStream &operator>> ( QTextStream &in, Gas &gas ) {

    in >> gas.Name;
    in >> gas.Formula;

    for ( int i = 0; i < 4; ++i )
        in >> gas.Aik[i];

    in >> gas.T_c;
    in >> gas.Ro_c;
    in >> gas.M;
    in >> gas.Omega;

    for ( int i = 0; i < 6; ++i )
        in >> gas.Dik[i];

    return in;
}

void Gas::setInDir ( const QDir &other ) {
    inDir=other;
}
QDir Gas::getInDir ( void ) {
    return inDir;
}
