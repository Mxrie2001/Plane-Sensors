/*
@author BENEDUCI Marie
@file  Temperature.hpp
@date 26/09/2022
@brief  Déclaration de la Classe capteur permetant d'avoir les données de temperature
*/

#ifndef SENSOR_HPP
#define SENSOR_HPP
#include "Sensor.hpp"
#endif 


#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP

class Temperature : public Sensor<float>
{
public:
    Temperature(); //Constructeur par défaut
    float aleaGenVal(); //réécriture de la fonction de Sensor pour retourner un float aléatoire
};

#endif 



