# Projet C++

### 1. Creation des differents fichiers .o (apres s'etre placé dans le dossier cpp)
    g++ -c Sensor.cpp Temperature.cpp Pression.cpp Humidity.cpp Light.cpp Server.cpp Scheduler.cpp main.cpp 

### 2. Création du fichier executable
    g++ -o app Sensor.o Temperature.o Pression.o Humidity.o Light.o Server.o Scheduler.o main.o 
    
### 3. Lancement du programme
    ./app
