#include "SMS.h"

SMS::SMS(): serie(SerieRx, SerieTx)
{
    //création de la software serie
    this->serie.begin(GPRSPEED);
    this->serie.print("AT\r");           // un petit OK pour commencer
    WaitOK(1000);                   // Attendre que le modem renvoie "OK" ET afficher cette réponse
    this->serie.print("AT+CMGF=1\r");    // Se mettre en mode texte
    WaitOK(1000);
    
}


void SMS::send(String message)
{
    this->serie.print("AT+CMGS=\"+33630379034\"\r");  //le numero de telephone cible. Remplacez les n par les 9 derniers chiffres de votre 06
    this->serie.print(message);   //le message
    this->serie.write(0x1A);  // Ctrl+Z 
    WaitOK(5000);
}
