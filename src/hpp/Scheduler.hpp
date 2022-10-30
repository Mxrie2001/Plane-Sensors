/*
@author BENEDUCI Marie
@file  Scheduler.hpp
@date 19/09/2022
@brief  Déclaration de la Classe ayant pour objectif d'envoyer au Server les données des Sensor récupérées
*/
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

class Scheduler
{
private:
    void sendTemperatureDataToServer(int i_p, int choixClient_p); // Fonction permettant l'envoie des données de temperature au serveur avec une mise à jour de la valeur relevée.
    void sendLightDataToServer(int i_p, int choixClient_p); // Fonction permettant l'envoie des données de light au serveur avec une mise à jour de la valeur relevée.
    void sendHumidityDataToServer(int i_p, int choixClient_p); // Fonction permettant l'envoie des données de humidity au serveur avec une mise à jour de la valeur relevée.
    void sendPressionDataToServer(int i_p, int choixClient_p); // Fonction permettant l'envoie des données de pression au serveur avec une mise à jour de la valeur relevée.
    void emptyFiles();

public:
    Scheduler(); // Constructeur par défaut
    ~Scheduler(); // Destructeur
    Scheduler (const Scheduler&); // Constructeur de recopie
    Scheduler &operator=(const Scheduler&); // Opérateur d'affectation
    int getSensorData(); // Fonction de récuperation des données des Sensors
    void affichageDonneesClient(); // Fonction donnant a l'utilisateur le choix d'affichage ou non des differents relevé de capteur dans les fichiers et/ou le terminal
    void affichageChoixClient(); // Fonction regroupant les choix offers au client concernant les données avec traitement d'erreur
};



#endif