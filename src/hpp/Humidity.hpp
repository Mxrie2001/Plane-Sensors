/*
@author BENEDUCI Marie
@file  Humidity.hpp
@date 26/09/2022
@brief  Déclaration de la Classe capteur permetant d'avoir les données d'humidité
*/

#ifndef SENSOR_HPP
#define SENSOR_HPP
#include "Sensor.hpp"
#endif 

#ifndef HUMIDITY_HPP
#define HUMIDITY_HPP

class Humidity : public Sensor<float>
{
public:
    Humidity(); //Constructeur par défaut
    float aleaGenVal(); //réécriture de la fonction de Sensor pour retourner un float aléatoire
};

#endif 