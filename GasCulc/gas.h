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

#ifndef GAS_H
#define GAS_H

#include <QTextStream>

class Gas
{
public:
    Gas();
    Gas(const QString &FileName);
    Gas(const Gas& other);
    ~Gas();
    Gas& operator=(const Gas& other);
    bool operator==(const Gas& other);

    QString Name;
    QString Formula;
    double Aik[4];
    double Dik[6];
    
    double T_c;
    double Ro_c;
    double M;
    double Omikron;    
    
    static int delta_i [6];
    static const double R;
    
    
    friend QTextStream & operator<<(QTextStream & out, const Gas & gas);
    friend QTextStream & operator>>(QTextStream & in, Gas & gas);
};

#endif // GAS_H
