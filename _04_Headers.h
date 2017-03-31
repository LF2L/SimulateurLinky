#define nodebug

#include "Arduino.h"
#include <SPI.h>
#include <Ethernet.h>
#include <SoftwareSerial.h>

class TeleInfo
{
public:
  TeleInfo(String version);
  boolean readTeleInfo();
  boolean recordTeleInfoOnMySQLServer();
  void displayTeleInfo();
  void setHistoricalMode(boolean HistoricalMode);
  boolean getHistoricalMode();
  void setIINST(int value);
  int getIINST();
  int getISOUSC();
  
private :
  SoftwareSerial* mySerial;

  boolean historicMode; 

  char HHPHC;
  
  int ISOUSC;             // intensité souscrite  
  int IINST;              // intensité instantanée en A
  int IMAX;               // intensité maxi en A
  int PAPP;               // puissance apparente en VA
  
  unsigned long BBRHCJB;  // compteur Heures Creuses Bleu  en W
  unsigned long BBRHPJB;  // compteur Heures Pleines Bleu  en W
  unsigned long BBRHCJW;  // compteur Heures Creuses Blanc en W
  unsigned long BBRHPJW;  // compteur Heures Pleines Blanc en W
  unsigned long BBRHCJR;  // compteur Heures Creuses Rouge en W
  unsigned long BBRHPJR;  // compteur Heures Pleines Rouge en W

  unsigned long EJPHN;  // compteur Heures Pleines Rouge en Wh
  unsigned long EJPHPM;  // compteur Heures Pleines Rouge en Wh

  unsigned long HCHC;  // compteur Heures Pleines Rouge en Wh
  unsigned long HCHP;  // compteur Heures Pleines Rouge en Wh

  unsigned long BASE;  // compteur Heures Pleines Rouge en Wh
  
  String PTEC;            // Régime actuel : HPJB, HCJB, HPJW, HCJW, HPJR, HCJR
  String DEMAIN;          // Régime demain ; ----, BLEU, BLAN, ROUG
  String ADCO;            // adresse compteur
  String OPTARIF;         // option tarifaire selon contrat
  String MOTDETAT;        // status word
  String pgmVersion;      // TeleInfo program version

  char chksum(char *buff, uint8_t len);
  boolean handleBuffer(char *bufferTeleinfo, int sequenceNumnber);
};
