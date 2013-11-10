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

}

Gas::~Gas()
{

}

Gas& Gas::operator=(const Gas& other)
{

}

bool Gas::operator==(const Gas& other)
{

}

QTextStream & operator<<(QTextStream & out, const Gas & gas)
{
    out<<gas.Name<<"\n";
    for (int i=0; i<4; ++i)
        out<<gas.K_i[i]<<"\n";
    out<<"\n";

    out<<gas.T_c<<"\n";
    out<<gas.Ro_c<<"\n";
    out<<gas.M<<"\n";
    out<<gas.Omega<<"\n";
    out<<"\n";

    for (int i=0; i<6; ++i)
        out<<gas.Delta_i[i]<<"\n";

    return out;
}

QTextStream & operator>>(QTextStream & in, Gas & gas)
{

    in>>gas.Name;

    for (int i=0; i<4; ++i)
        in>>gas.K_i[i];

    in>>gas.T_c;
    in>>gas.Ro_c;
    in>>gas.M;
    in>>gas.Omega;

    for (int i=0; i<6; ++i)
        in>>gas.Delta_i[i];
    /*
    */
    return in;

}
