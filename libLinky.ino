/*=======================================================================================================================
                                                        my_teleinfo "Light version"
=========================================================================================================================
                                                 (c) 2012-2014 by P. CARDON
                                                  Script name : my_teleinfo
=========================================================================================================================
 Usage :   
     + Arduino Teleinfo report program
     + This program receives data frames from the EDF counter teleinfo port, it parse it,
       validate each data group by verfying the checksum, stores it in local variables, 
       displays the actual counter, consumption ... on a LCD with real time updates,
       and sent the frame content to a remote PHP server, thru Internet. The remote PHP
       server records the received data in a MySQL data base.                                                          
     + This is the prod Light version with no LCD, no status LED, no mode button ... 
     + Runs on an Arduino R3, RX on PIN 08
                                                                                                                        */
char version[18] = "LinkyTeleInfo V0.1";
/*________________________________________________________________________________________________________________________	  
                VERSIONS HISTORY                                                        | Program space | Dynamic memory |
                                                                                        |  used / total | used  / total  |
========================================================================================|---------------|----------------|
	Version 1.01	23/03/2014	+ Some code cleaning                            | 21070 /32256  | 781 used /2048 |
	Version 1.00	22/03/2014	+ Based on TéléInfo V1.61, this is a light      | 21356 /32256  | 785 used /2048 |
          	                 	  that don't have LCD, mode button, status leds |               |                |
========================================================================================================================*/
/*
Hardware needed :
  + 1 x Arduino UNO r3
  + 1 x Ethernet shield (used in the final project)
  + 1 x Opto Coupler : SFH620A
  + 1 x LED
  + 1 x 1 kΩ resistor
  + 1 x 4,7 kΩ resistor
  
PIN USED :
  PIN 8  : Software Serial RX
  PIN 10 : ETH, SS
  PIN 11 : ETH, SPI bus MOSI
  PIN 12 : ETH, SPI bus MISO
  PIN 13 : ETH, SPI bus SCK
  
Sample TEMPO Teleinfo frame content (Frame length = 274):

Heures pleines/Heures creuses :
ADCO 270622224349 B
OPTARIF HC.. <
ISOUSC 30 9
HCHC 014460852 $
HCHP 012506372 -
PTEC HP..  
IINST 002 Y
IMAX 035 G
PAPP 00520 (
HHPHC C .
MOTDETAT 000000 B

Tempo :
 ADCO 031328141543 :
 OPTARIF BBR( S
 ISOUSC 45 ?
 BBRHCJB 000010828 0
 BBRHPJB 000007345 =
 BBRHCJW 000000000 2
 BBRHPJW 000000000 ?
 BBRHCJR 000000000 -
 BBRHPJR 000000000 :
 PTEC HPJB P
 DEMAIN ---- "
 IINST 002 Y
 IMAX 030 B
 PAPP 00430 (
 HHPHC Y D
 MOTDETAT 000000 B 
=====================================================================================*/
