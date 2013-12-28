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

#ifndef AGAS_H
#define AGAS_H

#include <QVector>
#include "component.h"

class aGas
{
public:
    aGas();
    aGas(const aGas& other);
    ~aGas();
    aGas& operator=(const aGas& other);
    bool operator==(const aGas& other);
    
    QVector<Component> X; ///<Мольный состав газа в долях (см. таблица В.1 для контрольных смесей ГОСТ Р 8.770-2011).
    
    double fi_im[6];
    double M_m();
    double Omikron_m();
    double Z_cm();
    double v_cm_tilda();
    double ro_cm_tilda();
    double T_cm();
    double P_cm();
    
    void culc_fi_im();    
    
    friend QTextStream & operator<<(QTextStream & out, const aGas & agas);
    friend QTextStream & operator>>(QTextStream & in, aGas & agas);
};

#endif // AGAS_H
