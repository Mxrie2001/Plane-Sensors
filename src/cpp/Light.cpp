/*
@author BENEDUCI Marie
@file  Light.cpp
@date 26/09/2022
@brief  Implementation de la Classe capteur permetant d'avoir les données de luminosité
*/

#include "../hpp/Light.hpp"


Light :: Light(){
    m_data = this -> aleaGenVal(); //instanciation de la valeur Light avec un nombre aléatoire generé par la fonction de la classe mère Sensor
    m_name = "Light"; //instanciation d'un nom par défaut
    m_unit = ""; //instanciation d'une unité par défaut
}

bool Light::aleaGenVal(){ //réécriture de la fonction de generation aléatoire de sensor pour qu'elle retourne un bool aléatoire
        bool randomData = 0 + (rand() % (1 - 0 + 1)) == 1;
        return randomData;
    } // La lumiere est allumée ou éteinte dans un avion


