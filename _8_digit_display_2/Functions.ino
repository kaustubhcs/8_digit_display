void numbpad(int dig,int numb,int zero=100)
{
  digitalWrite(deci[dig][0],LOW);
  digitalWrite(deci[dig][1],LOW);
  digitalWrite(deci[dig][2],LOW);
  digitalWrite(deci[dig][3],LOW);
  digitalWrite(deci[dig][4],LOW);
  digitalWrite(deci[dig][5],LOW);
  digitalWrite(deci[dig][6],LOW);
  digitalWrite(deci[dig][7],LOW);

  switch (numb)
  {
  case 0:
    if (dig < zero)
    {
      digitalWrite(deci[dig][1],HIGH);
      digitalWrite(deci[dig][2],HIGH);
      digitalWrite(deci[dig][5],HIGH);
      digitalWrite(deci[dig][6],HIGH);
      digitalWrite(deci[dig][7],HIGH);
      digitalWrite(deci[dig][4],HIGH);
    }
    break;
  case 1:
    digitalWrite(deci[dig][4],HIGH);
    digitalWrite(deci[dig][7],HIGH);

    break;
  case 2:
    digitalWrite(deci[dig][6],HIGH);
    digitalWrite(deci[dig][7],HIGH);
    digitalWrite(deci[dig][3],HIGH);
    digitalWrite(deci[dig][2],HIGH);
    digitalWrite(deci[dig][1],HIGH);

    break;
  case 3:
    digitalWrite(deci[dig][6],HIGH);
    digitalWrite(deci[dig][7],HIGH);
    digitalWrite(deci[dig][3],HIGH);
    digitalWrite(deci[dig][4],HIGH);
    digitalWrite(deci[dig][1],HIGH);

    break;
  case 4:
    digitalWrite(deci[dig][5],HIGH);
    digitalWrite(deci[dig][3],HIGH);
    digitalWrite(deci[dig][7],HIGH);
    digitalWrite(deci[dig][4],HIGH);

    break;
  case 5:
    digitalWrite(deci[dig][6],HIGH);
    digitalWrite(deci[dig][5],HIGH);
    digitalWrite(deci[dig][3],HIGH);
    digitalWrite(deci[dig][4],HIGH);
    digitalWrite(deci[dig][1],HIGH);

    break;
  case 6:
    digitalWrite(deci[dig][6],HIGH);
    digitalWrite(deci[dig][5],HIGH);
    digitalWrite(deci[dig][2],HIGH);
    digitalWrite(deci[dig][1],HIGH);
    digitalWrite(deci[dig][4],HIGH);
    digitalWrite(deci[dig][3],HIGH);

    break;
  case 7:
    digitalWrite(deci[dig][6],HIGH);
    digitalWrite(deci[dig][7],HIGH);
    digitalWrite(deci[dig][4],HIGH);

    break;
  case 8:
    digitalWrite(deci[dig][2],HIGH);
    digitalWrite(deci[dig][5],HIGH);
    digitalWrite(deci[dig][6],HIGH);
    digitalWrite(deci[dig][7],HIGH);
    digitalWrite(deci[dig][4],HIGH);
    digitalWrite(deci[dig][1],HIGH);
    digitalWrite(deci[dig][3],HIGH);

    break;
  case 9:
    digitalWrite(deci[dig][5],HIGH);
    digitalWrite(deci[dig][6],HIGH);
    digitalWrite(deci[dig][7],HIGH);
    digitalWrite(deci[dig][3],HIGH);
    digitalWrite(deci[dig][4],HIGH);
    digitalWrite(deci[dig][1],HIGH);

    break;

  case 10:
    digitalWrite(deci[dig][0],HIGH);
    break;
  case 11:
    digitalWrite(deci[dig][3],HIGH);
    break;

  } 
}


void number(long int n)
{
  if (n<10)
  {
    for (int i=1;i<8;i++)
    {
      zero=1;
    }
  }
  else if (n<100) 
  {
    for (int i=2;i<8;i++)
    {
      zero=2;
    }   
  }
  else if (n<1000) 
  {
    for (int i=3;i<8;i++)
    {
      zero=3;
    }   
  }

  else if (n<10000) 
  {
    for (int i=4;i<8;i++)
    {
      zero=4;
    }   
  }

  else if (n<100000) 
  {
    for (int i=5;i<8;i++)
    {
      zero=5;
    }   
  }

  else if (n<1000000) 
  {
    for (int i=6;i<8;i++)
    {
      zero=6;
    }   
  }

  else if (n<10000000) 
  {
    for (int i=7;i<8;i++)
    {
      zero=7;
    }   
  }


  if (n<99999999)
  {
    all_off();
    numbpad(0, n%10,zero);
    numbpad(1, (n%100 - n%10)/10,zero);
    numbpad(2, (n%1000 - n%100)/100,zero);
    numbpad(3, (n%10000 - n%1000)/1000,zero);
    numbpad(4, (n%100000 - n%10000)/10000,zero);
    numbpad(5, (n%1000000 - n%100000)/100000,zero);
    numbpad(6, (n%10000000 - n%1000000)/1000000,zero);
    numbpad(7, (n%100000000 - n%10000000)/10000000,zero);
  }
  else
  {
    for (int i=0;i<8;i++)
    {
      numbpad(i, 11);
    }
  }


} 


void clock()
{

  if (starter2)
  {
    Serial.println("Press any key and hit ENTER to enter time:-");
    for (long int i=1;i<2000;i++)
    {
      delay(1);
      if(Serial.available())
      {
        Serial.read();
        starter=1;
        break;
      }
      else
      {
        starter=0;
      } 
      starter2=0;
    }
  }


  if (starter)
  {
    Serial.print("Enter HOURS:- ");
    while(Serial.available() == 0);

    {
      h2= Serial.read() - 48;
    }   
    while(Serial.available() == 0);

    {

      h1= Serial.read() - 48;
    }
    Serial.print(h2);
    Serial.println(h1);
    Serial.print("Enter MINUTES:- ");
    while(Serial.available() == 0);

    {

      m2= Serial.read() - 48;
    }
    while(Serial.available() == 0);

    {

      m1= Serial.read() - 48;
    }
    Serial.print(m2);
    Serial.println(m1);
    Serial.print("Enter SECONDS:- ");
    while(Serial.available() == 0);

    {

      s2= Serial.read() - 48;
    }
    while(Serial.available() == 0);

    {

      s1= Serial.read() - 48;
    }
    Serial.print(s2);
    Serial.println(s1);

    sec = s1 + s2*10;

    mins = m1 + m2*10;

    hour = h1 + h2*10;





    starter=0;
  }  






  if (sec>59)
  {
    mins++; 
    sec=0;
  }

  if (mins>59)
  {
    hour++;
    mins=0; 
  }

  if (hour>12)
  {
    hour = 1; 
  }

  EEPROM.write(0,sec);
  EEPROM.write(1,mins);
  EEPROM.write(2,hour);


  numbpad(0,sec%10);
  numbpad(1,(sec-(sec%10))/10); 

  numbpad(3,mins%10);
  numbpad(4,(mins-(mins%10))/10); 

  numbpad(6,hour%10);
  numbpad(7,(hour-(hour%10))/10); 

  delay(983.333);
  sec++;

}






void timer ()
{

  if (starter2)
  {
    for (long int i=-1;i<tmt;i++)
    {
      delay(1);
      if(Serial.available())
      {
        starter=1;
        break;
      }
      else
      {
        starter=0;
      } 
      starter2=0;
    }
  }

  if (starter)
  {
    while(Serial.available() == 0);

    {
      n0= Serial.read() - 48;
    }   

    while(Serial.available() == 0);

    {
      n1= Serial.read() - 48;
    }   
    while(Serial.available() == 0);

    {
      n2= Serial.read() - 48;
    }   
    while(Serial.available() == 0);

    {
      n3= Serial.read() - 48;
    }   
    while(Serial.available() == 0);

    {
      n4= Serial.read() - 48;
    }   
    while(Serial.available() == 0);

    {
      n5= Serial.read() - 48;
    }   
    while(Serial.available() == 0);

    {
      n6= Serial.read() - 48;
    }   
    while(Serial.available() == 0);

    {
      n7= Serial.read() - 48;
    }   

    starter=0;

    EEPROM.write(10,n0);
    EEPROM.write(11,n1);
    EEPROM.write(12,n2);
    EEPROM.write(13,n3);
    EEPROM.write(14,n4);
    EEPROM.write(15,n5);
    EEPROM.write(16,n6);
    EEPROM.write(17,n7);

  }  

  while(1)
  {
    n0 = EEPROM.read(10);
    n1 = EEPROM.read(11);
    n2 = EEPROM.read(12);
    n3 = EEPROM.read(13);
    n4 = EEPROM.read(14);
    n5 = EEPROM.read(15);
    n6 = EEPROM.read(16);
    n7 = EEPROM.read(17);

    n = n7 + n6*10 + n5*100 + n4*1000 + n3*10000 + n2*100000 + n1*1000000 + n0*10000000;

    number(n);
    delay(1000);
    n--;

    n7 = n%10;
    n6 = (n%100 - n%10)/10;
    n5 = (n%1000 - n%100)/100;
    n4 = (n%10000 - n%1000)/1000;
    n3 = (n%100000 - n%10000)/10000;
    n2 = (n%1000000 - n%100000)/100000;
    n1 = (n%10000000 - n%1000000)/1000000;
    n0 = (n%100000000 - n%10000000)/10000000;


    EEPROM.write(10,n0);
    EEPROM.write(11,n1);
    EEPROM.write(12,n2);
    EEPROM.write(13,n3);
    EEPROM.write(14,n4);
    EEPROM.write(15,n5);
    EEPROM.write(16,n6);
    EEPROM.write(17,n7);


  }



}



long int rn=0;

void read_serial()
{
  if (Serial.available())
  {
    int cr=0;
    cr = Serial.read();
    while(cr != 10 && cr != 13)
    {
      rn = rn*10 + (cr-48);
      while(Serial.available()==0);
      cr = Serial.read();
    }
    number(rn);
    rn=0;
  }
}







