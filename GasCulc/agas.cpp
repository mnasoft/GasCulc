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
#include <math.h>

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

double aGas::M_m()
{
    int sz=X.size();
    double rez=0.0;
    for(int i=0; i<sz; ++i)
    {
        double a=X.at(i).M;
        double b=X.at(i).v;
        rez+=a*b;
    }
    return rez;
}

double aGas::Omikron_m()
{
    int sz=X.size();
    double rez=0.0;
    for(int i=0; i<sz; ++i)
    {
        double a=X.at(i).Omikron;
        double b=X.at(i).v;
        rez+=a*b;
    }
    return rez;
}

double aGas::Z_cm()
{
    return 0.291-0.08*Omikron_m();
}

double aGas::v_cm_tilda()
{
    const double n_1_3=1.0/3.0;
    int sz=X.size();
    double rez=0.0;
    for(int k=0; k<sz; ++k)
        for(int l=0; l<sz; ++l)
        {
            double xk=X.at(k).v;
            double xl=X.at(l).v;
            double Mk=X.at(k).M;
            double Ml=X.at(l).M;
            double rok=X.at(k).Ro_c;
            double rol=X.at(l).Ro_c;
            double v_ckl=pow(0.5*(pow(Mk/rok, n_1_3)+pow(Ml/rol, n_1_3)), 3.0);
            rez+=xk*xl*v_ckl;
        }
    return rez;
}

double aGas::ro_cm_tilda()
{
    return 1.0/v_cm_tilda();
}

double aGas::T_cm()
{
    const double n_1_3=1.0/3.0;
    int sz=X.size();
    double rez=0.0;
    for(int k=0; k<sz; ++k)
        for(int l=0; l<sz; ++l)
        {
            double xk=X.at(k).v;
            double xl=X.at(l).v;
            double Mk=X.at(k).M;
            double Ml=X.at(l).M;
            double rok=X.at(k).Ro_c;
            double rol=X.at(l).Ro_c;
            double tck=X.at(k).T_c;
            double tcl=X.at(l).T_c;
            double v_ckl=pow(0.5*(pow(Mk/rok, n_1_3)+pow(Ml/rol, n_1_3)), 3.0);
            double tckl=pow(tck*tcl, 0.5);
            rez+=xk*xl*v_ckl*tckl;
        }
    return rez*ro_cm_tilda();
}

double aGas::P_cm()
{
    return 0.001*Gas::R*ro_cm_tilda()*T_cm()*Z_cm();
}

void aGas::culc_fi_im()
{
    int sz=X.size();
    for(int i=0; i<6; ++i)
    {
        fi_im[i]=Gas::delta_i[i];
        for(int k=0; k<sz; ++k)
        {
            double a=X.at(i).Dik[i];
            double b=X.at(i).v;
            fi_im[i]+=a*b;
        }
    }
}
