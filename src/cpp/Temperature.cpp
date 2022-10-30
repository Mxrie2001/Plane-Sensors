/*
@author BENEDUCI Marie
@file  Temperature.cpp
@date 26/09/2022
@brief  Implementation de la Classe capteur permetant d'avoir les données de temperature
*/

#include "../hpp/Temperature.hpp"

Temperature :: Temperature(){
    m_data = this -> aleaGenVal(); //instanciation de la valeur Temperature avec un nombre aléatoire generé par la fonction de la classe mère Sensor
    m_name = "Temperature"; //instanciation d'un nom par défaut
    m_unit = "°C"; //instanciation d'une unité par défaut
}

float Temperature::aleaGenVal(){ //réécriture de la fonction de generation aléatoire de sensor pour qu'elle retourne un float aléatoire
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_real_distribution<float> distr(22, 24);
        std::setprecision(1);
        float randomData = distr(eng);
        return randomData;
    }; // La temperature dans un avion peut aller en moyenne de 22°C à 24°C