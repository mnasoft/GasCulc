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
