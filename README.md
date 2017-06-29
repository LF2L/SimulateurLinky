# Simulateur Linky

## Description
Générateur de trames similaires à celles générées par Linky pour tester des objets connectés exploitants ces informations
![montage temporaire](/images/Simulateur.jpg)

## Fonction
* Générer les differentes trames (historique et standard) pour simuler le fonctionnement d'un compteur communicant Linky

## Composants
* Arduino Uno
* écran LCD 16x2
* I2C pour écran
* boutons
* resistances
* module RF

## Schéma d'assemblage électronique
![schéma assemblage](/images/SimulateurV1_bb.png)

## Echanges d'informations
Le simulateur échange des information avec le serveur centralisant les informations (raspberry) via une connection RF. 
Le choix de la RF pour l'échange entre le serveur et le module TIC du compteur du à sa faible consommation par rapport au WIFI.

### Fonctionnement
* Les boutons permettent de modifier les informations envoyées par le simulateur Linky au serveur de centralisation des données qui communique avec l'ensemble des objets connectés. En fonction des informations, le serveur va envoyer des commandes aux objets connectés.

## To do
* Monter un écran LCD en I2C pour libérer des ports GPIO de l'Arduino  
* Réaliser une interface permettant de modifier plus d'element dans la trame et pas uniquement IINST
* Ajouter au programme l'envoie de la trame par RF 
* Crypter les données transmise en RF