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

        Curso(std::string id="",
                std::string name="",
                int year=0,
                int month=0,
                int day=0,
                std::string ponente="",
                std::string estudio="",
                std::string duracion="",
                std::string descripcion="",
                std::string lugar="",
                std::string aula="",
                int aforo=0){
                
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
        inline int get_month(){return month_;}
        inline int get_year(){return year_;}
        inline int get_day(){return day_;}
        inline std::string get_ponente(){return ponente_;}
        inline std::string get_descripcion(){return descripcion_;}
        inline std::string get_lugar(){return lugar_;}
        inline std::string get_aula(){return aula_;}
        inline int get_aforo(){return aforo_;}

        inline std::list<std::string> get_lista_inscritos(){return lista_inscritos_;}

        bool inscribir_usuario(std::string id);
        bool desinscribir_usuario(std::string id);
    
        inline void set_id(std::string id){id_=id;}
        inline void set_name(std::string name){name_=name;}
        inline void set_estudio(std::string estudio){estudio_=estudio;}
        inline void set_duracion(std::string duracion){duracion_=duracion;}
        inline void set_month(int month){month_=month;}
        inline void set_year(int year){year_=year;}
        inline void set_day(int day){day_=day;}
        inline void set_ponente(std::string ponente){ponente_=ponente;}
        inline void set_descripcion(std::string descripcion){descripcion_=descripcion;}
        inline void set_lugar(std::string lugar){lugar_=lugar;}
        inline void set_aula(std::string aula){aula_=aula;}
        inline void set_aforo(int aforo){aforo_=aforo;}
};

#endif
