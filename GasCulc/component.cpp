#include "component.h"
#include <math.h>
#include <QFile>

Component::Component() {
    x=0.0;
    File="";
}

Component::Component ( const Component& other )
    : Gas ( other ) {
    File=other.File;
    x=other.x;
}

Component::Component ( double ax, const QString & fileName )
    : x ( ax ), Gas ( fileName ) {
}

Component::~Component() {

}

Component& Component::operator= ( const Component& other ) {
    File=other.File;
    x=other.x;
}

bool Component::operator== ( const Component& other ) const {

}

void Component::readGasData() {

    QString s_tmp=Gas::getInDir().filePath ( File );

    QFile i ( s_tmp );
    if ( i.open ( QFile::ReadOnly ) ) {
        QTextStream IN ( &i );
        IN.setCodec ( "UTF-8" );
        Gas *g= this;
        IN >> *g;
    }
    i.close();
}

void Component::writeGasData ( QTextStream & out ) const {
    const Gas * g = this ;
    out << *g;
}

QTextStream & operator<< ( QTextStream & out, const Component & component ) {
    out<<component.File<<"\t";
    out<<component.x<<"\n";
    component.writeGasData ( out );
    return out;
}



QTextStream & operator>> ( QTextStream & in, Component & component ) {
    in>>component.File;
    in>>component.x;
    component.readGasData();
    return in;
}

double Component::mu_0i ( double ateta ) {
    double rez=0.0;
    for ( int i=0; i<4; ++i )
        rez+=Aik[i]*pow ( ateta,i );
    return rez;
}
