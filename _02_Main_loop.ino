void loop() 
{
  boolean teleInfoReceived;

  // we parse the teleInfo frame
  //teleInfoReceived = myTeleInfo->readTeleInfo();
#ifdef debug
    myTeleInfo->displayTeleInfo();
#endif
  plusButtonState = digitalRead(plusButtonPin);
  minusButtonState = digitalRead(minusButtonPin);
  
  if( plusButtonState == HIGH && minusButtonState == LOW){
    int IINSTtemp = myTeleInfo->getIINST();
    if (IINSTtemp < myTeleInfo->getISOUSC() ){
      IINSTtemp = IINSTtemp +5;
      myTeleInfo->setIINST(IINSTtemp);
    }
    
    //  Print the updated value on the LCD.
    lcd.setCursor(7, 0);
    lcd.print("    ");
    lcd.setCursor(7, 0);
    lcd.print(IINSTtemp);
    delay(500);
  }

  if( minusButtonState == HIGH && plusButtonState == LOW){
    int IINSTtemp = myTeleInfo->getIINST();
    if (IINSTtemp >0){
      IINSTtemp = IINSTtemp - 5;
      myTeleInfo->setIINST(IINSTtemp);
    }
    
    // Print the updated value on the LCD.
    lcd.setCursor(7, 0);
    lcd.print("    ");
    lcd.setCursor(7, 0);
    lcd.print(IINSTtemp);
    delay(500);
  }

  if( myTeleInfo->getISOUSC() == myTeleInfo->getIINST()){
    lcd.setCursor(15, 0);
    lcd.print("!");
  }else{
    lcd.setCursor(15, 0);
    lcd.print(" ");
  }

  //myTeleInfo->sendInfo();

}
