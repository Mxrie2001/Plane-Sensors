/*
@author BENEDUCI Marie
@file  Humidity.cpp
@date 26/09/2022
@brief  Implementation de la Classe capteur permetant d'avoir les données d'humidité
*/

#include "../hpp/Humidity.hpp"



Humidity :: Humidity(){
    m_data = this -> aleaGenVal(); //instanciation de la valeur Humidity avec un nombre aléatoire generé par la fonction de la classe mère Sensor
    m_name = "Humidity"; //instanciation d'un nom par défaut
    m_unit = "%"; //instanciation d'une unité par défaut
}

float Humidity::aleaGenVal(){ //réécriture de la fonction de generation aléatoire de sensor pour qu'elle retourne un float aléatoire
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_real_distribution<float> distr(1, 20);
        std::setprecision(1);
        float randomData = distr(eng);
        return randomData;
    }; // L'humidité dans un avion peut aller en moyenne de 1% à 20%
