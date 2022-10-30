/*
@author BENEDUCI Marie
@file  Pression.cpp
@date 26/09/2022
@brief Implementation de la Classe capteur permetant d'avoir les données de pression
*/

#include "../hpp/Pression.hpp"

Pression :: Pression(){
    m_data = this -> aleaGenVal(); //instanciation de la valeur Pression avec un nombre aléatoire generé par la fonction de la classe mère Sensor
    m_name = "Pression"; //instanciation d'un nom par défaut
    m_unit = "kPa"; //instanciation d'une unité par défaut
}

int Pression::aleaGenVal(){ //réécriture de la fonction de generation aléatoire de sensor pour qu'elle retourne un int aléatoire
        int randomData = 54 + rand() % (82 - 54 + 1);
        return randomData;
    }; // La pression dans un avion peut aller en moyenne de 54 kPa à 82 kPa


