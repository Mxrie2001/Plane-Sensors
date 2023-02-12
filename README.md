# Plane Sensors

## Explication :

Modélisation d'un écosystème de capteurs ayant pour but de monitorer l’environnement intérieur d’un avion en vol. L'écosystème étant basé sur quatre types de capteurs différents, monitorant la température, la lumière, l’humidité et la pression dans l’avion. Ces capteurs communiquent avec un serveur sur lequel seront affiché et stocké les données transmises.

N.B. Les données de chaque capteur sont réecupérées et transmises à intervalles de temps différents.

## Commandes utiles :

### 1. Creation des differents fichiers .o (apres s'etre placé dans le dossier cpp)
    g++ -c Sensor.cpp Temperature.cpp Pression.cpp Humidity.cpp Light.cpp Server.cpp Scheduler.cpp main.cpp 

### 2. Création du fichier executable
    g++ -o app Sensor.o Temperature.o Pression.o Humidity.o Light.o Server.o Scheduler.o main.o 
    
### 3. Lancement du programme
    ./app
