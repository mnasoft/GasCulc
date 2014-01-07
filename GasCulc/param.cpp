/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2014  <copyright holder> <email>
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

#include "param.h"

Param::Param() : T ( 273.15 ), p ( 0.101325 ) {

}

Param::Param ( const Param& other ) {
    T=other.T;
    p=other.p;
}

Param::~Param() {

}

Param& Param::operator= ( const Param& other ) {
    T=other.T;
    p=other.p;
}

bool Param::operator== ( const Param& other ) {
    if ( T==other.T && p==other.p )
        return true;
    else
        return false;
}
