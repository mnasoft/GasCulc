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

#ifndef COMPONENT_H
#define COMPONENT_H

#include <QTextStream>
#include "gas.h"

class Component: protected Gas
{
  friend class aGas;
public:
    Component();
    Component(const Component& other);
    ~Component();
    Component& operator=(const Component& other);
    bool operator==(const Component& other);
    
    int Number;
    QString Name;
    QString Formula;
    QString File;
    double v;
    
    double mu_0i(double ateta);
    double teta(double T){return T/100.0;} 

    friend QTextStream & operator<<(QTextStream & out, const Component & component);
    friend QTextStream & operator>>(QTextStream & in, Component & component);
};

#endif // COMPONENT_H
