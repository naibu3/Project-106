/*
curso.h

Clase que representa un curso de extension
*/

#ifndef _CURSO_H_
#define _CURSO_H_

#include <string>
#include <list>
#include <chrono>
#include <iostream>
#include <stdio.h>


class Curso{

    private:

        std::string name_;
        std::string id_;
        int year_;
        int month_;
        int day_;
        std::string ponente_;
        std::string estudio_;
        std::string duracion_;
        std::string descripcion_;
        std::string lugar_;
        std::string aula_;
        int aforo_;

        std::list<std::string> lista_inscritos_;

    public:

        Curso(std::string id,
                std::string name,
                int year,
                int month,
                int day,
                std::string ponente,
                std::string estudio,
                std::string duracion,
                std::string descripcion,
                std::string lugar,
                std::string aula,
                int aforo){
                
            id_=id;
            name_=name;
            year_=year;
            month_=month;
            day_=day;
            ponente_=ponente;
            estudio_=estudio;
            descripcion_=descripcion;
            lugar_=lugar;
            aula_=aula;
            aforo_=aforo;
        }

        inline std::string get_name(){return name_;}
        inline std::string get_id(){return id_;}
        inline std::string get_estudio(){return estudio_;}
        inline std::string get_month(){return month_;}
        inline int get_year(){return year_;}
        inline int get_day(){return day_;}
        inline std::string get_ponente(){return ponente_;}
        inline std::string get_descripcion(){return descripcion_;}
        inline std::string get_lugar(){return lugar_;}
        inline std::string get_aula(){return aula_;}
        inline int get_aforo(){return aforo_;}

        inline std::list<std::string> get_lista_inscritos(){return lista_inscritos_;}

        bool inscribir_usuario(std::string id);
};

#endif
