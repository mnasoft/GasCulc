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

    QString Name;           ///<Имя компонента
    QString Formula;        ///<Химичестая формула
    double Aik[4];          ///<Значения коэффициентов  a_ik (см. ГОСТ Р 8.770—2011 - Таблица А.1 — Коэффициенты a_ik уравнения (5) для μ_0i основных компонентов природного газа).
    
    double T_c;             ///<Критическая температура, К (см. ГОСТ Р 8.770—2011 - Таблица А.3).
    double Ro_c;            ///<Критическая плотность, кг/м3 (см. ГОСТ Р 8.770—2011 - Таблица А.3).
    double M;               ///<Молярная масса компонента, кг/кмоль (см. ГОСТ Р 8.770—2011 - Таблица А.3).
    double Omega;           ///<Ω - Фактор Питцера (см. ГОСТ Р 8.770—2011 - Таблица А.3).
    
    static int delta_i [6]; ///<δ_i Массив коэффициентов (см. ГОСТ Р 8.770—2011 - Таблица А.4).
    double Dik[6];          ///<Коэффициенты d_ik (см. ГОСТ Р 8.770—2011 - Таблица А.4 - Значения коэффициентов {d_ik} для параметров афинных преобразований по формуле (15)).
    static const double R;  ///<Универсальная газовая постоянная.
    
    
    friend QTextStream & operator<<(QTextStream & out, const Gas & gas);
    friend QTextStream & operator>>(QTextStream & in, Gas & gas);
};

#endif // GAS_H
