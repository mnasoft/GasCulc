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

#include "gas.h"
#include <QFile>

int Gas::delta_i[]={1,1,0,1,0,1};
const double R=8.31451;

Gas::Gas()
{

}

Gas::Gas(const QString &FileName)
{
    QFile in(FileName);
    if (in.open( QFile::ReadOnly))
    {
        QTextStream IN(&in);
        IN>>*this;
    }
    in.close();
}

Gas::Gas(const Gas& other)
{
    Name=other.Name;
    Formula=other.Formula;

    for (int i=0; i<4; ++i)
        Aik[i]=other.Aik[i];

    T_c=other.T_c;
    Ro_c=other.Ro_c;
    M=other.M;
    Omikron=other.Omikron;

    for (int i=0; i<6; ++i)
        Dik[i]=other.Dik[i];
}

Gas::~Gas()
{
}

Gas& Gas::operator=(const Gas& other)
{
    Name=other.Name;
    Formula=other.Formula;

    for (int i=0; i<4; ++i)
        Aik[i]=other.Aik[i];

    T_c=other.T_c;
    Ro_c=other.Ro_c;
    M=other.M;
    Omikron=other.Omikron;

    for (int i=0; i<6; ++i)
        Dik[i]=other.Dik[i];
}

bool Gas::operator==(const Gas& other)
{

}

QTextStream & operator<<(QTextStream & out, const Gas & gas)
{
    out<<gas.Name<<"\n";
    out<<gas.Formula<<"\n";

    for (int i=0; i<4; ++i)
        out<<gas.Aik[i]<<"\n";
    out<<"\n";

    out<<gas.T_c<<"\n";
    out<<gas.Ro_c<<"\n";
    out<<gas.M<<"\n";
    out<<gas.Omikron<<"\n";
    out<<"\n";

    for (int i=0; i<6; ++i)
        out<<gas.Dik[i]<<"\n";

    return out;
}

QTextStream & operator>>(QTextStream & in, Gas & gas)
{

    in>>gas.Name;
    in>>gas.Formula;

    for (int i=0; i<4; ++i)
        in>>gas.Aik[i];

    in>>gas.T_c;
    in>>gas.Ro_c;
    in>>gas.M;
    in>>gas.Omikron;

    for (int i=0; i<6; ++i)
        in>>gas.Dik[i];

    return in;
}
