/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2013  <copyright holder> <email>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "component.h"
#include <math.h>
#include <QFile>

Component::Component()
{

}

Component::Component(const Component& other)
: Gas(other)
{
    Number=other.Number;
    Name=other.Name;
    Formula=other.Formula;
    File=other.File;
    v=other.v;
}

Component::~Component()
{

}

Component& Component::operator=(const Component& other)
{
    Number=other.Number;
    Name=other.Name;
    Formula=other.Formula;
    File=other.File;
    v=other.v;
}

bool Component::operator==(const Component& other)
{

}

QTextStream & operator<<(QTextStream & out, const Component & component)
{
    out<<component.Number<<"\t";
    out<<component.Name<<"\t";
    out<<component.Formula<<"\t";
    out<<component.File<<"\t";
    out<<component.v<<"\n";

    const Gas & g= dynamic_cast <const Gas &> (component);
    out<<g;
    return out;
}

QTextStream & operator>>(QTextStream & in, Component & component)
{
    in>>component.Number;
    in>>component.Name;
    in>>component.Formula;
    in>>component.File;
    in>>component.v;
    QString s_tmp=QString("")+"../ComponentData/"+component.File+".txt";

    QFile i(s_tmp);
    if (i.open( QFile::ReadOnly))
    {
        QTextStream IN(&i);
        IN.setCodec("UTF-8");
        Gas &g= dynamic_cast <Gas &> (component);
        IN >> g;
    }
    i.close();

    return in;
}

double Component::mu_0i(double ateta)
{
    double rez=0.0;
    for (int i=0; i<4; ++i)
        rez+=Aik[i]*pow(ateta,i);
    return rez;
}
