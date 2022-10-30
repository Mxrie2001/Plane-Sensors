/*
@author BENEDUCI Marie
@file  Server.cpp
@date 19/09/2022
@brief  Implementation de la Classe ayant pour objectif de recevoir les données des capteurs, les stocker dans un fichier de log (rendu intermediaire) et les afficher dans la console
*/

#include "../hpp/Server.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <cstring>



Server::Server(){}

Server::~Server(){}

Server::Server(const Server&) = default;

Server& Server::operator=(const Server&) = default;


void Server::newStatement(int relevé_p){    
    std::cout << "--------------Relevé n°"<< relevé_p <<"--------------" << std::endl; // affichage du numéro des relevé pour plus de lisibilité dans le terminal
}

void Server::fileWrite(std::string nom_p, std::string value_p, std::string unit_p, int relevé_p, int choixClient_p){  //fonction d'écriture des données dans le fichier associé au capteur renseigné en paramètre
    
    //Concatenation du nom du capteur et du debut et fin de chemin afin d'obtenir le chemin associé au capteur en parametre
    std::string nomFichier("../log/");
    std::string nomF = nom_p;
    std::string extensionF(".txt");

    nomFichier += nomF;
    nomFichier += extensionF;

    //ecriture dans le fichier, à la suite sans écrasement de données
    std::ofstream monFlux(nomFichier, std::ios::app);

    if(monFlux)    
    {
        monFlux << "--------------Relevé n°"<< relevé_p <<"--------------" << std::endl; // affichage du numéro des relevé pour plus de lisibilité dans le fichier log
        monFlux << nom_p << " : " << value_p << " " << unit_p << std::endl; // ecriture des données dans le fichier log
            }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl; // Affichage d'une erreur dans le terminal dans le cas où il est impossible d'ouvrir le fichier log
    }

}

void Server::consolWrite(std::string nom_p, std::string value_p, std::string unit_p, int choixClient_p){
    std::cout << nom_p << " : " << value_p << " " << unit_p << std::endl; // ecriture des données dans le terminal
}

void Server::emptyFile(std::string nom_p){ //fonction permettant de vider le fichier du capteur renseigné en parametre
    //Concatenation du nom du capteur et du debut et fin de chemin afin d'obtenir le chemin associé au capteur en parametre
    std::string nomFichier("../log/");
    std::string nomF = nom_p;
    std::string extensionF(".txt");

    nomFichier += nomF;
    nomFichier += extensionF;

    //permet de vider le fichier en question
    std::ofstream monFlux(nomFichier);
}



