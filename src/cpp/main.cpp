/*
@author BENEDUCI Marie
@file  main.cpp
@date 19/09/2022
@brief  Class main servant au lancement du programme.
*/

#include "../hpp/Scheduler.hpp"


int main()

{

    Scheduler sch; //création d'un objet Scheduleur
    sch.getSensorData(); //Lancement de la fonction permettant de run tout le programme en recuperant les données envoyées des sensors et les envoyant au Server pour l'affichage et le stockage
    return 0;

}


