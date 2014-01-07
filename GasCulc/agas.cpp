#include "agas.h"
#include <math.h>

bool aGas::is_D1_tbl_laded=false;
double aGas::an[58];
double aGas::bn[58];
double aGas::cn[58];
double aGas::kn[58];
double aGas::un[58];
double aGas::gn[58];
double aGas::qn[58];
double aGas::fn[58];
double aGas::sn[58];
double aGas::wn[58];

aGas::aGas() {
    read_D1_tbl();
}

aGas::aGas ( const aGas& other ) {
    read_D1_tbl();
}

aGas::~aGas() {

}

aGas& aGas::operator= ( const aGas& other ) {

}

bool aGas::operator== ( const aGas& other ) {

}

QTextStream & operator<< ( QTextStream & out, const aGas & agas ) {
    for ( int i=0; i<agas.X.size(); ++i )
        out<<agas.X.at ( i );
    return out;
}

QTextStream & operator>> ( QTextStream & in, aGas & agas ) {
    int i=0;
    Component c_tmp;
    while ( ! ( in>>c_tmp ).atEnd() )
        agas.X.append ( c_tmp );

    return in;
}

double aGas::M_m() {
    int sz=X.size();
    double rez=0.0;
    for ( int i=0; i<sz; ++i ) {
        double a=X.at ( i ).M;
        double b=X.at ( i ).x;
        rez+=a*b;
    }
    return rez;
}

double aGas::Omega_m() {
    int sz=X.size();
    double rez=0.0;
    for ( int i=0; i<sz; ++i ) {
        double a=X.at ( i ).Omega;
        double b=X.at ( i ).x;
        rez+=a*b;
    }
    return rez;
}

double aGas::Z_cm() {
    return 0.291-0.08*Omega_m();
}

double aGas::v_cm_tilda() {
    const double n_1_3=1.0/3.0;
    int sz=X.size();
    double rez=0.0;
    for ( int k=0; k<sz; ++k )
        for ( int l=0; l<sz; ++l ) {
            double xk=X.at ( k ).x;
            double xl=X.at ( l ).x;
            double Mk=X.at ( k ).M;
            double Ml=X.at ( l ).M;
            double rok=X.at ( k ).Ro_c;
            double rol=X.at ( l ).Ro_c;
            double v_ckl=pow ( 0.5* ( pow ( Mk/rok, n_1_3 ) +pow ( Ml/rol, n_1_3 ) ), 3.0 );
            rez+=xk*xl*v_ckl;
        }
    return rez;
}

double aGas::ro_cm_tilda() {
    return 1.0/v_cm_tilda();
}

double aGas::T_cm() {
    const double n_1_3=1.0/3.0;
    int sz=X.size();
    double rez=0.0;
    for ( int k=0; k<sz; ++k )
        for ( int l=0; l<sz; ++l ) {
            double xk=X.at ( k ).x;
            double xl=X.at ( l ).x;
            double Mk=X.at ( k ).M;
            double Ml=X.at ( l ).M;
            double rok=X.at ( k ).Ro_c;
            double rol=X.at ( l ).Ro_c;
            double tck=X.at ( k ).T_c;
            double tcl=X.at ( l ).T_c;
            double v_ckl=pow ( 0.5* ( pow ( Mk/rok, n_1_3 ) +pow ( Ml/rol, n_1_3 ) ), 3.0 );
            double tckl=pow ( tck*tcl, 0.5 );
            rez+=xk*xl*v_ckl*tckl;
        }
    return rez*ro_cm_tilda();
}

double aGas::P_cm() {
    return 0.001*Gas::R*ro_cm_tilda() *T_cm() *Z_cm();
}

void aGas::culc_fi_im() {
    int sz=X.size();
    for ( int i=0; i<6; ++i ) {
        fi_im[i]=Gas::delta_i[i];
        for ( int k=0; k<sz; ++k ) {
            double a=X.at ( k ).Dik[i];
            double b=X.at ( k ).x;
            fi_im[i]+=a*b;
        }
    }
}

void aGas::read_D1_tbl() {
    QString fname=Gas::getInDir().filePath ( QString ( "tbl_D.1.txt" ) );
    {
        QFile in ( fname );
        if ( in.open ( QFile::ReadOnly ) ) {
            QTextStream IN ( &in );
            IN.setCodec ( "UTF-8" );
            int n;
            for ( int i=0; i<58; ++i ) {
                IN>>n>>an[i]>>bn[i]>>cn[i]>>kn[i]>>un[i]>>gn[i]>>qn[i]>>fn[i]>>sn[i]>>wn[i];
            }

        }
        in.close();
    }
}
