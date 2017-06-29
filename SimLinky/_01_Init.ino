void setup() 
{
  //initialization of the button
  pinMode(plusButtonPin, INPUT);
  pinMode(minusButtonPin, INPUT);
  
  Serial.begin(115200);
  Serial.println(F("\nStarting ..."));
  delay(300);
  // attempting to connect with Ethernet
  //ethernetIsConnected = internetConnect();
  // starting TeleInfo capture
  myTeleInfo = new TeleInfo(version);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("IINST");
  lcd.setCursor(7, 0);
  lcd.print(myTeleInfo->getIINST());
}

boolean internetConnect()
{
  // Starting Ethernet
  boolean ethernetIsConnected = (Ethernet.begin(mac) == 1);
  Serial.print(F("Ethernet connexion "));
  if(!ethernetIsConnected)
    Serial.print(F("failed !\n"));
  else
    Serial.print(F("is OK\n"));
  delay(200);
  return ethernetIsConnected;
}
