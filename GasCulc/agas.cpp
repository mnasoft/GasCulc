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

#include "agas.h"

aGas::aGas()
{

}

aGas::aGas(const aGas& other)
{

}

aGas::~aGas()
{

}

aGas& aGas::operator=(const aGas& other)
{

}

bool aGas::operator==(const aGas& other)
{

}

QTextStream & operator<<(QTextStream & out, const aGas & agas)
{
    for(int i=0; i<21; ++i)
        out<<agas.c[i];
    return out;
}

QTextStream & operator>>(QTextStream & in, aGas & agas)
{
    for(int i=0; i<21; ++i)
        in>>agas.c[i];
    return in;
}
