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

/**
 * @brief Класс Component представляет отдельный компонент смеси газов (газ).
 *
 * Доля компонента в смеси газов задается в мольной частью.\n
 * Для загрузка значений констант, характеризующих компонент, выполняется из файла.
 */

class Component: public Gas {
    friend class aGas;
public:
    Component();
    Component ( const Component& other );
    Component ( double ax, const QString & fileName );
    ~Component();
    Component& operator= ( const Component& other );
    bool operator== ( const Component& other ) const;

    QString File;       ///<Имя файла со значениями коэффициентов.
    double x;           ///<Мольная доля компонента.

    double mu_0i ( double ateta );
    double teta ( double T ) {
        return T/100.0;
    }
public:
    void readGasData();
    void writeGasData ( QTextStream & out ) const;
public:
    friend QTextStream & operator<< ( QTextStream & out, const Component & component );
    friend QTextStream & operator>> ( QTextStream & in, Component & component );
};

#endif // COMPONENT_H
