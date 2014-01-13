
#ifndef AGAS_H
#define AGAS_H

#include <QVector>
#include "component.h"
#include "param.h"

/**
 * @brief Класс aGas представляет монгокомпонентную смесь газов.
 *
 */
class aGas {
public:
    aGas();
    aGas ( const aGas& other );
    ~aGas();
    aGas& operator= ( const aGas& other );
    bool operator== ( const aGas& other );
public:
    QVector<Component> X;	///<Мольный состав газа в долях (см. таблица В.1 для контрольных смесей ГОСТ Р 8.770-2011).
public:
    double M_m();		///<Вычисляет молярную массу смеси (см. формула 14 ГОСТ Р 8.770-2011, используемую в формуле 2).
    double Omega_m();		///<Ω_m - ацентрический фактор Питцера для смеси (см. формула 13 ГОСТ Р 8.770-2011).
    double Z_cm();		///<Псевдо критический фактор сжимаемости смеси газов (см. формула 11 ГОСТ Р 8.770-2011).
    double v_cm_tilda();	///<Псевдо критический молярный объем смеси газов (см. формула 9 ГОСТ Р 8.770-2011).
    double ro_cm_tilda();	///<Псевдо критическая молярная плотность смеси газов (см. формула 9 ГОСТ Р 8.770-2011).
    double T_cm();		///<Псевдо критическая температура смеси газов (см. формула 10 ГОСТ Р 8.770-2011).
    double P_cm();		///<Псевдо критическая плотнось смеси газов (см. формула 10 ГОСТ Р 8.770-2011).
    void culc_fi_im();		///<Вычисляет параметры афинных преобразований для относительной плотности и температуры смеси(см. формулу 15 ГОСТ Р 8.770-2011).

    double w_m ( const Param &par );	///<Относительная плотность смеси (см. формула 8 ГОСТ Р 8.770-2011).
    double tau_m ( const Param &par );	///<Относительная темепратура смеси (см. формула 8 ГОСТ Р 8.770-2011).


public: //public->private
    double fi_im[6];		///<Параметры афинных преобразований для относительной плотности и температуры смеси (см. ГОСТ Р 8.770-2011, используемые в формулах 7).
    double Bn_Zv [18];		///<(D.2)
//    double 
public: //public->private    
    void culc_Bn_Zv();		///< Вычисление коэффициентов Β_n^* ГОСТ Р 8.662_2009.
    double calc_Bnij_Zv(int i, int j);	///< Вычисление коэффициентов Β_nij^* ГОСТ Р 8.662_2009.
    
    double calc_Gij_Zv(int i, int j);
    double calc_Eij_Zv(int i, int j);
    
    
    double calc_Gij(int i, int j);
    double calc_Eij(int i, int j);
//     double calc_Qij(int i, int j);
//     double calc_Fij(int i, int j);
//     double calc_Wij(int i, int j);
    
    
    
    
  
private:
    static void read_D1_tbl();
    static bool is_D1_tbl_laded;///<Признак, того была-ли загружена таблица D.1
    static double an[58];
    static double bn[58];
    static double cn[58];
    static double kn[58];
    static double un[58];
    static double gn[58];
    static double qn[58];
    static double fn[58];
    static double sn[58];
    static double wn[58];

  
    friend QTextStream & operator<< ( QTextStream & out, const aGas & agas );
    friend QTextStream & operator>> ( QTextStream & in, aGas & agas );
};

#endif // AGAS_H
