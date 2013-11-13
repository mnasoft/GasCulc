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
    for(int i=0; i<agas.X.size(); ++i)
        out<<agas.X.at(i);
    return out;
}

QTextStream & operator>>(QTextStream & in, aGas & agas)
{
    int i=0;
    Component c_tmp;
    while (!(in>>c_tmp).atEnd())
      agas.X.append(c_tmp);

    return in;
}

double aGas::Mm()
{
  int sz=X.size();
  double rez=0.0;
  for(int i=0;i<sz;++i)
  {
    double a=X.at(i).M;
    double b=X.at(i).v;
    rez+=a*b;
  }
  return rez;
}


void aGas::culc_fi_im()
{
  int sz=X.size();
  for(int i=0;i<6;++i)
  {
    fi_im[i]=Gas::delta_i[i];
    for(int k=0; k<sz;++k)
    {
      double a=X.at(i).Dik[i];
      double b=X.at(i).v;
      fi_im[i]+=a*b;
    }
  }
}
