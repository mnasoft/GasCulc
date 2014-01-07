#ifndef GAS_H
#define GAS_H

#include <QTextStream>
#include <QString>
#include <QDir>

/** 
 * @brief Класс Gas представляет отдельное химическое соединение (газ).
 * 
 * Данный класс предназначен для хранения констанат, используемых при расчете коэффициента динамической вязкости многокомпонентной газовой смеси по ГОСТ Р 8.770—2011 (Уравнение AGA8).
 */

class Gas {
public:
    /** @brief Конструктор.
     *
     */
    Gas();
    /** @brief Конструктор.
     *
     * @param FileName - определяет имя файла в котором хранятся константы для создаваемого (конструируемого) элемента.
     * При выполнении конструктора перед именем файла добавляется путь, заданный при помощи функции setInDir ( const QDir &other ).
     */
    Gas ( const QString &fileName );
    Gas ( const Gas &other );
    ~Gas();
    Gas &operator= ( const Gas &other );
    bool operator== ( const Gas &other );

    /**
     * @brief ...
     * 
     */
    QString Name;			///<Имя компонента
    QString Formula;			///<Химичестая формула
    double Aik[4];			///<Значения коэффициентов  a_ik (см. ГОСТ Р 8.770—2011 - Таблица А.1 — Коэффициенты a_ik уравнения (5) для μ_0i основных компонентов природного газа).

    double T_c;				///<Критическая температура, К (см. ГОСТ Р 8.770—2011 - Таблица А.3).
    double Ro_c;			///<Критическая плотность, кг/м3 (см. ГОСТ Р 8.770—2011 - Таблица А.3).
    double M;				///<Молярная масса компонента, кг/кмоль (см. ГОСТ Р 8.770—2011 - Таблица А.3).
    double Omega;			///<Ω - Фактор Питцера (см. ГОСТ Р 8.770—2011 - Таблица А.3).

    static int delta_i [6];		///<δ_i Массив коэффициентов (см. ГОСТ Р 8.770—2011 - Таблица А.4).
    double Dik[6];			///<Коэффициенты d_ik (см. ГОСТ Р 8.770—2011 - Таблица А.4 - Значения коэффициентов {d_ik} для параметров афинных преобразований по формуле (15)).
    static const double R;		///<Универсальная газовая постоянная, кДж/(кмоль*К).

public:
    static void setInDir ( const QDir &other );	///<Устанавливает каталог для счивывания файлов.
    static QDir getInDir ( void );		///<Возвращает каталог для счивывания файлов.
private:
    static QDir inDir;			///<Указывает путь к файлам для выполнения конструирования и ввода.

    friend QTextStream &operator<< ( QTextStream &out, const Gas &gas );	///<Вывод данных в поток.
    friend QTextStream &operator>> ( QTextStream &in, Gas &gas );		///<Считывание данных из потока.
};

#endif // GAS_H
