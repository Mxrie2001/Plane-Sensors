/*
@author BENEDUCI Marie
@file  Sensor.hpp
@date 19/09/2022
@brief  Déclaration de la Classe ayant pour objectif de generer à intervalle régulier des données en int
*/
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <iomanip>
#include <map>

template<typename T>
class Sensor
{
protected:
    virtual T aleaGenVal() = 0; // Fonction de generation de nombre aléatoire

public:
    T m_data; 
    std::string m_unit;
    std::string m_name;
    Sensor<T>(); // Constructeur par défaut
    virtual ~Sensor<T>(); // Destructeur
    Sensor<T> (const Sensor<T>&); // Constructeur de recopie
    Sensor<T> &operator=(const Sensor<T>&); // Opérateur d'affectation
    T getData();// Fonction permettant de récuperer la donnée à envoyer
    std::string getName(); // Fonction permettant de récuperer le nom du sensor
    std::string getUnit();  // Fonction permettant de récuperer l'unité du sensor

};

//Les fonctions templates doivent être initialisés dans le fichier header de la classe

template<typename T>
Sensor<T>::Sensor(){
	this -> m_data = 0;
    this -> m_name = "";
    this -> m_unit = "";
}

template<typename T>
Sensor<T>::~Sensor<T>(){}

template<typename T> 
Sensor<T>::Sensor(const Sensor<T>&) = default;

template<typename T> 
Sensor<T>& Sensor<T>::operator=(const Sensor<T> &) = default;

template<typename T>
std::string Sensor<T>::getName(){ //fonction permettant de récuperer le nom de l'objet Sensor
    return m_name;
}
template<typename T>
std::string Sensor<T>::getUnit(){ //fonction permettant de récuperer l'unité de l'objet Sensor
    return m_unit;
}

template<typename T>
T Sensor<T>::getData(){ //fonction permettant de récuperer le résultat du relevé de l'objet Sensor
    return m_data;
}; 