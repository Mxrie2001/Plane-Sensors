/*
@author BENEDUCI Marie
@file  Server.hpp
@date 19/09/2022
@brief  Déclaration de la Classe ayant pour objectif de recevoir les données des capteurs, les stocker dans un fichier de log (rendu intermediaire) et les afficher dans la console
*/

#include <string>


#ifndef SERVER_HPP
#define SERVER_HPP

class Server
{
private:
    void fileWrite(std::string nom_p, std::string value_p, std::string unit_p, int relevé_p, int choixClient_p) ; // fonction d'écriture des données reçues pour chaques capteurs dans un fichier log (pour le rendu intermédiaire)
    void consolWrite(std::string nom_p, std::string value_p, std::string unit_p, int choixClient_p); // fonction d'écriture des données reçues pour chaques capteurs dans le terminal

public:
    Server(); // Constructeur par défaut
    ~Server(); // Destructeur
    Server (const Server&); // Constructeur de recopie
    Server &operator=(const Server&); // Opérateur d'affectation
    void newStatement(int relevé_p); // fonction d'affichage du numéro de relevé des données des Sensors.
    void emptyFile(std::string nom_p); // fonction permettant de vider le fichier Sensor dont le nom est en parametre
    template<typename T>
    void fileAndConsoleWrite(std::string nom_p, T value_p, std::string unit_p, int relevé_p, int relevéPfch_p, int choixClient_p);// Fonction regroupant l'affichage dans la console et le stockage dans le fichier log
};

//Fonction template à declarer dans le fichier header de la classe
template<typename T>
void Server::fileAndConsoleWrite(std::string nom_p, T value_p, std::string unit_p, int relevé_p, int relevéPfch_p, int choixClient_p){ //fonction d'ecriture dans le fichier et dans le terminal des données
    if (choixClient_p == 0 || choixClient_p == 2){
        consolWrite(nom_p, std::to_string(value_p), unit_p, choixClient_p);
    }
    if (choixClient_p == 1 || choixClient_p == 2){
        fileWrite(nom_p,std::to_string(value_p), unit_p, relevéPfch_p, choixClient_p);
    } 
} 


#endif