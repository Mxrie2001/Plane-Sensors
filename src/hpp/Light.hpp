/*
@author BENEDUCI Marie
@file  Light.hpp
@date 26/09/2022
@brief  Déclaration de la Classe capteur permetant d'avoir les données de luminosité
*/

#ifndef SENSOR_HPP
#define SENSOR_HPP
#include "Sensor.hpp"
#endif 
 
#ifndef LIGHT_HPP
#define LIGHT_HPP

class Light : public Sensor<bool>
{
public:
    Light(); //Constructeur par défaut
    bool aleaGenVal(); //réécriture de la fonction de Sensor pour retourner un bool aléatoire
    
};

#endif 
