/*
@author BENEDUCI Marie
@file  Scheduler.cpp
@date 19/09/2022
@brief  Implementation de la Classe ayant pour objectif d'envoyer au Server les données des Sensor récupérées
*/

#include<cstdio>
#include<iostream>
#include<ctime>

#include "../hpp/Scheduler.hpp"
#include "../hpp/Temperature.hpp"
#include "../hpp/Pression.hpp"
#include "../hpp/Humidity.hpp"
#include "../hpp/Light.hpp"
#include "../hpp/Server.hpp"

// Création des 4 objet Sensors
Temperature temperature;
Light light;
Humidity humidity;
Pression pression;

// Creation d'un objet server
Server server;

//Initialisation de 4 variables pour l'affiche relatifs des relevé de chaques sensor dans leurs fichiers respectifs.
int j = 1;
int k = 1;
int l = 1;
int m = 1;

// Initialisations des variables permettant les gestion des choix du client
int choix, a,b,c,d;
bool afficheNumReleveTerminal = false;


Scheduler::Scheduler(){}

Scheduler::~Scheduler(){}

Scheduler::Scheduler(const Scheduler&) = default;

Scheduler& Scheduler::operator=(const Scheduler&) = default;


void Scheduler::affichageDonneesClient(){ // Fonction donnant a l'utilisateur le choix d'affichage ou non des differents relevé de capteur dans les fichiers et/ou le terminal
    std::cout << "\nBonjour! Ici votre commandant de bord, nous avons réalisé plusieurs relevés sur notre avion\n";
    std::cout << "Il s'agit de la temperature, la pression, la luminosité et l'humidité\n";
    std::cout << "Pour chacun des relevés nous allons vous demandez si vous souhaitez remplir un fichier avec les données, les afficher sur le terminal, faire les 2 ou rien du tout\n";

    std::cout << "\nConcernant la température, que souhaitez vous faire ?\n";
    affichageChoixClient();
    a = choix;
    std::cout << "\nConcernant l'humidité, que souhaitez vous faire ?\n";
    affichageChoixClient();
    b = choix;
    std::cout << "\nConcernant la luminosité, que souhaitez vous faire ?\n";
    affichageChoixClient();
    c = choix;
    std::cout << "\nConcernant la pression, que souhaitez vous faire ?\n";
    affichageChoixClient();
    d = choix;

    std::cout << "\nMerci pour vos réponses, notre programme va pouvoir maintenant s'executer selon vos choix !\n";
    
}


void Scheduler::affichageChoixClient(){ // Fonction regroupant les choix offers au client concernant les données avec traitement d'erreur
    std::cout << "0 : je souhaite afficher les données dans le terminal uniquement\n";
    std::cout << "1 : je souhaite écrire les données dans le fichier correspondant uniquement\n";
    std::cout << "2 : je souhaite réaliser les 2 proposition ci-dessus\n";
    std::cout << "3 : je ne souhaire rien faire de ces données\n";

    std::cin >> choix;

    if ( choix < 0 || choix > 3){
        std::cout << "La proposition que vous avez choisis n'existe pas, veuillez recommencer votre saisie\n";
        affichageChoixClient();
    }
}



void Scheduler::sendTemperatureDataToServer(int i_p, int choixClient_p){ // Fonction permettant l'envoie des données de temperature au serveur avec une mise à jour de la valeur relevée.
    temperature.m_data = temperature.aleaGenVal();
    server.fileAndConsoleWrite<float>(temperature.getName() , temperature.getData(), temperature.getUnit(), i_p+1,j, choixClient_p);
    j+=1;
}

void Scheduler::sendLightDataToServer(int i_p, int choixClient_p){ // Fonction permettant l'envoie des données de light au serveur avec une mise à jour de la valeur relevée.
    light.m_data = light.aleaGenVal();
    server.fileAndConsoleWrite<bool>(light.getName() , light.getData(), light.getUnit(), i_p+1,k, choixClient_p);
    k+=1;
}

void Scheduler::sendHumidityDataToServer(int i_p, int choixClient_p){ // Fonction permettant l'envoie des données de humidity au serveur avec une mise à jour de la valeur relevée.
    humidity.m_data = humidity.aleaGenVal();
    server.fileAndConsoleWrite<float>(humidity.getName() , humidity.getData(), humidity.getUnit() , i_p+1,l, choixClient_p);
    l+=1;

}

void Scheduler::sendPressionDataToServer(int i_p, int choixClient_p){ // Fonction permettant l'envoie des données de pression au serveur avec une mise à jour de la valeur relevée.

    pression.m_data = pression.aleaGenVal();
    server.fileAndConsoleWrite<int>(pression.getName() , pression.getData(), pression.getUnit(), i_p+1,m, choixClient_p);
    m+=1;
}

void Scheduler::emptyFiles(){ // fonction permettant de vider tout les fichiers des sensor afin de commencer un nouveau relevé
    server.emptyFile(temperature.getName());
    server.emptyFile(light.getName());
    server.emptyFile(pression.getName());
    server.emptyFile(humidity.getName());
}


int Scheduler::getSensorData()  // Fonction de récuperation des données des Sensors en envoie vers le serveur à interval irregulier (en secondes) en fonction du sensor en question apres avoir vider les fichiers, pour les remplir des nouvelles données et afficher ces dernieres dans le terminal
{
    affichageDonneesClient();

    emptyFiles(); // permet de vider tout les fichiers

    for(int i =0;i<15; i++){ // création d'une boucle de 15 instances pour recuperer 15 fois les valeurs des sensors

        int delay = 1;
        delay *= CLOCKS_PER_SEC;

        clock_t now = clock();
        
        while(clock() - now <delay); // boucle permettant de faire l'action ci dessous toute les secondes jusqu'a la fin des 15 itérations
            // Appels des differentes fonctions de la classe Server pour afficher dans la console et ecrire dans les fichiers logs correspondants aux sensors, les données récuperées.
            

            // gestion de l'affichage des numeros de relevés selon les choix du client
            if(a == 0 || a== 2){
                afficheNumReleveTerminal = true;
            }

            if(b == 0 || b== 2){
                afficheNumReleveTerminal = true;
            }

            if(c == 0 || c== 2){
                afficheNumReleveTerminal = true;
            }

            if(d == 0 || d== 2){
                afficheNumReleveTerminal = true;
            }

            if(afficheNumReleveTerminal == true){
                server.newStatement(i+1);
            }

            //les differents if permettent de réaliser les appels en meme temps si ces derniers sont verifiés
            if ((i+1)%2 == 0){ // la temperature est relevée toute les 2 secondes
                sendTemperatureDataToServer(i,a);
            }

            if ((i+1)%6 == 0){ // la light est relevée toute les 6 secondes
                sendLightDataToServer(i,c);
            }

            if ((i+1)%5 == 0){ // l' humidity est relevée toute les 5 secondes
                sendHumidityDataToServer(i,b);
            }

            if ((i+1)%1 == 0){ // la pression est relevée toute les 2 secondes
                sendPressionDataToServer(i,d);
            }
    }
    return 0;
}