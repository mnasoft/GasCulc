
#include "gas.h"
#include <QFile>
#include <QMessageBox>

int Gas::delta_i[] = {1, 1, 0, 1, 0, 1};
const double Gas::R = 8.31451;
QDir Gas::inDir = QDir();

QStringList Gas::names_ru =
    QStringList()
    << QString::fromUtf8 ( "Азот" )
    << QString::fromUtf8 ( "Диоксид_углерода" )
    << QString::fromUtf8 ( "Метан" )
    << QString::fromUtf8 ( "Этан" )
    << QString::fromUtf8 ( "Пропан" )
    << QString::fromUtf8 ( "Н-Бутан" )
    << QString::fromUtf8 ( "Изобутан" )
    << QString::fromUtf8 ( "Н-Пентан" )
    << QString::fromUtf8 ( "Изопентан" )
    << QString::fromUtf8 ( "Н-Гексан" )
    << QString::fromUtf8 ( "Н-Гептан" )
    << QString::fromUtf8 ( "Н-Октан" )
    << QString::fromUtf8 ( "Н-Нонан" )
    << QString::fromUtf8 ( "Н-Декан" )
    << QString::fromUtf8 ( "Водород" )
    << QString::fromUtf8 ( "Кислород" )
    << QString::fromUtf8 ( "Монооксид_углерода" )
    << QString::fromUtf8 ( "Вода" )
    << QString::fromUtf8 ( "Сероводород" )
    << QString::fromUtf8 ( "Гелий" )
    << QString::fromUtf8 ( "Аргон" );

QStringList Gas::names_en =
    QStringList()
    << QString::fromUtf8 ( "N2" )
    << QString::fromUtf8 ( "CO2" )
    << QString::fromUtf8 ( "CH4" )
    << QString::fromUtf8 ( "C2H6" )
    << QString::fromUtf8 ( "C3H8" )
    << QString::fromUtf8 ( "N-C4H10" )
    << QString::fromUtf8 ( "I-C4H10" )
    << QString::fromUtf8 ( "N-C5H12" )
    << QString::fromUtf8 ( "I-C5H12" )
    << QString::fromUtf8 ( "N-C6H14" )
    << QString::fromUtf8 ( "N-C7H16" )
    << QString::fromUtf8 ( "N-C8H18" )
    << QString::fromUtf8 ( "N-C9H20" )
    << QString::fromUtf8 ( "N-C10H22" )
    << QString::fromUtf8 ( "H2" )
    << QString::fromUtf8 ( "O2" )
    << QString::fromUtf8 ( "CO" )
    << QString::fromUtf8 ( "H2O" )
    << QString::fromUtf8 ( "H2S" )
    << QString::fromUtf8 ( "He" )
    << QString::fromUtf8 ( "Ar" );

QTextStream & tab_string ( QTextStream &out, const QString &s, int tab = 3 ) {
    int len = tab - s.length() / 8;
    out << s;

    for ( int i = 0; i < len ; ++i )
        out << "\t";

    return out;
}

Gas::Gas() {
    init_coeffs();
}

void Gas::init_coeffs() {
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

    for ( int i = 0; i < 21; ++i )
        Eij_zv[i] = Vij[i] = Kij[i] = Gij_zv[i] = 1.0;
}

Gas::Gas ( const QString & fileName ) {
    init_coeffs();
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
    init_coeffs();

    Name = other.Name;
    Formula = other.Formula;
    Zamenitel = other.Zamenitel;
    Number = other.Number;

    for ( int i = 0; i < 4; ++i )
        Aik[i] = other.Aik[i];

    T_c = other.T_c;
    Ro_c = other.Ro_c;
    M = other.M;
    Omega = other.Omega;

    for ( int i = 0; i < 6; ++i )
        Dik[i] = other.Dik[i];

    Ei = other.Ei;
    Ki = other.Ki;
    Gi = other.Gi;
    Qi = other.Qi;
    Fi = other.Fi;
    Si = other.Si;
    Wi = other.Wi;

    for ( int i = 0; i < 21; ++i ) {
        Eij_zv[i] = other.Eij_zv[i];
        Vij[i] = other.Vij[i];
        Kij[i] = other.Kij[i] ;
        Gij_zv[i] = other.Gij_zv[i];
    }
}

Gas::~Gas() {
}

Gas &Gas::operator= ( const Gas &other ) {
    Name = other.Name;
    Formula = other.Formula;
    Zamenitel = other.Zamenitel;
    Number = other.Number;

    for ( int i = 0; i < 4; ++i )
        Aik[i] = other.Aik[i];

    T_c = other.T_c;
    Ro_c = other.Ro_c;
    M = other.M;
    Omega = other.Omega;

    for ( int i = 0; i < 6; ++i )
        Dik[i] = other.Dik[i];

    Ei = other.Ei;
    Ki = other.Ki;
    Gi = other.Gi;
    Qi = other.Qi;
    Fi = other.Fi;
    Si = other.Si;
    Wi = other.Wi;

    for ( int i = 0; i < 21; ++i ) {
        Eij_zv[i] = other.Eij_zv[i];
        Vij[i] = other.Vij[i];
        Kij[i] = other.Kij[i] ;
        Gij_zv[i] = other.Gij_zv[i];
    }
}

bool Gas::operator== ( const Gas &other ) {
    return this->Number == other.Number;
}

QTextStream &operator<< ( QTextStream &out, const Gas &gas ) {
    out.setFieldAlignment ( QTextStream::AlignLeft );

    out << gas.Name << "\n";
    out << gas.Formula << " -> " << gas.Zamenitel << "\n";

    out.setFieldWidth ( 12 );
    out << "Number" << gas.Number ;
    out.setFieldWidth ( 0 );
    out << "\n";

    for ( int i = 0; i < 4; ++i ) {
        out << "Aik[" << i << "]" ;
        out.setFieldWidth ( 12 );
        out << "" << gas.Aik[i] ;
        out.setFieldWidth ( 0 );
        out << "\n";
    }

    out << "\n";
    out.setFieldWidth ( 40 );
    out << "T_c" <<  gas.T_c;
    out.setFieldWidth ( 0 );
    out << "\n";
    out.setFieldWidth ( 40 );
    out << QString ( "ρ_c" )  << gas.Ro_c;
    out.setFieldWidth ( 0 );
    out << "\n";
    out.setFieldWidth ( 40 );
    out << QString::fromUtf8 ( "Молярная_масса_Μi,кг/кмоль" )  << gas.M ;
    out.setFieldWidth ( 0 );
    out << "\n";
    out.setFieldWidth ( 40 );
    out << QString ( "Ω" ) << gas.Omega ;
    out.setFieldWidth ( 0 );
    out << "\n";
    out << "\n";

    for ( int i = 0; i < 6; ++i ) {
        out << "Dik[" << i << "]";
        out.setFieldWidth ( 12 );
        out << "" << gas.Dik[i];
        out.setFieldWidth ( 0 );
        out << "\n";
    }

    out << "\n";
    out.setFieldWidth ( 40 );
    out << QString::fromUtf8 ( "Энергетический_параметр_Ei" ) << gas.Ei ;
    out.setFieldWidth ( 0 );
    out << "\n";
    out.setFieldWidth ( 40 );
    out << QString::fromUtf8 ( "Параметр_размера_Ki,(м3/кмоль)^1/3" ) << gas.Ki ;
    out.setFieldWidth ( 0 );
    out << "\n";
    out.setFieldWidth ( 40 );
    out << QString::fromUtf8 ( "Ориентационный_параметр_Gi" )  << gas.Gi ;
    out.setFieldWidth ( 0 );
    out << "\n";
    out.setFieldWidth ( 40 );
    out << QString::fromUtf8 ( "Квадрупольный_параметр_Qi" )  << gas.Qi ;
    out.setFieldWidth ( 0 );
    out << "\n";
    out.setFieldWidth ( 40 );
    out << QString::fromUtf8 ( "Высокотемпературный_параметр_Fi" )  << gas.Fi ;
    out.setFieldWidth ( 0 );
    out << "\n";
    out.setFieldWidth ( 40 );
    out << QString::fromUtf8 ( "Дипольный_параметр_Si" )  << gas.Si ;
    out.setFieldWidth ( 0 );
    out << "\n";
    out.setFieldWidth ( 40 );
    out << QString::fromUtf8 ( "Параметр_ассоциации_Wi" )  << gas.Wi ;
    out.setFieldWidth ( 0 );
    out << "\n";

    out.setFieldWidth ( 0 );
    out << "\n";

    out.setFieldWidth ( 8 );
    out << "i" << "j";
    out.setFieldWidth ( 24 );
    out << "Comp1" << "Comp2";
    out.setFieldWidth ( 16 );
    out << "Eij*"  << "Vij"  << "Kij" << "Gij*" ;
    out.setFieldWidth ( 0 );
    out << "\n";

    for ( int i = 0; i < 21; ++i ) {
        out.setFieldWidth ( 8 );
        out << gas.Number << i + 1;
        out.setFieldWidth ( 24 );
        out << Gas::names_ru.at ( gas.Number - 1 ) << Gas::names_ru.at ( i );
        out.setFieldWidth ( 16 );
        out.setFieldAlignment ( QTextStream::AlignLeft );
        out << gas.Eij_zv[i] << gas.Vij[i] << gas.Kij[i] << gas.Gij_zv[i] ;
        out.setFieldWidth ( 0 );
        out << "\n";
    }

    return out;
}

QTextStream & operator>> ( QTextStream &in, Gas &gas ) {
    QString tmp;
    in >> gas.Name;
    in >> gas.Formula >> tmp >> gas.Zamenitel;
    in >> tmp >> gas.Number;

    for ( int i = 0; i < 4; ++i )
        in >> tmp >> gas.Aik[i];

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

    QString Si, Sj, SComp1, SComp2, SEij_zv, SVij, SKij, SGij_zv;

    in >> Si >> Sj >> SComp1 >> SComp2 >> SEij_zv >> SVij >> SKij >> SGij_zv;

    int Di = 0, Dj = 0;
    QString DComp1, DComp2;
    double DEij_zv = 0.0, DVij = 0.0, DKij = 0.0, DGij_zv = 0.0;
    bool doit = true;

    while ( doit ) {
        in >> Di >> Dj >> DComp1 >> DComp2 >> DEij_zv >> DVij >> DKij >> DGij_zv;

        if ( in.status() == QTextStream::Ok ) {
            gas.Eij_zv[Dj - 1] = DEij_zv;
            gas.Vij[Dj - 1] = DVij;
            gas.Kij[Dj - 1] = DKij;
            gas.Gij_zv[Dj - 1] = DGij_zv;
        }
        else
            doit = false;
    }

    return in;
}

void Gas::setInDir ( const QDir &other ) {
    inDir = other;
}

QDir Gas::getInDir ( void ) {
    return inDir;
}
