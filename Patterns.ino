
void follow(int t)
{
  int fol[20] = {
    35,37,41,49,65,61,66,55,46,36,38,32,30,12,8,4,17,21,25,33                                                                                                                            };
  all_off();
  for (int f=0;f<20;f++)
  {
    peak(fol[f],t);
  }
}

void all_off()
{
  for (int i=0;i<69;i++)
  {
    digitalWrite(i,LOW);  
  }


}

void peak (int p, int t)
{
  digitalWrite(p,HIGH);  
  delay(t);
  digitalWrite(p,LOW);  
  delay(t);
}



void dots(int t)
{
  for (int i=7;i>=0;i--)
  {
    numbpad(i,10);
    delay(t);
  }
  all_off();
}


void test_funct ()
{
  for (int i=5;i<8;i++)
  {
    for (int j=0;i<8;j++)
    {
      digitalWrite(deci[i][j],HIGH);
      delay(500);
      digitalWrite(deci[i][j],LOW); 
      delay(500);
    }
  } 

}

void dance()
{
  int t = random(0,8);
  int u = random(0,8);
  digitalWrite(deci[t][u],HIGH);
  delay(10);
  digitalWrite(deci[t][u],LOW);
  delay(10);   

}

void pattern_1 (int t)
{
  for (int dig=7;dig>-1;dig--)
  {
    digitalWrite(deci[dig][1],HIGH);
    delay(t); 
    digitalWrite(deci[dig][2],HIGH);
    delay(t);

    digitalWrite(deci[dig][1],LOW);
    delay(t); 
    digitalWrite(deci[dig][2],LOW);
    delay(t); 

    digitalWrite(deci[dig][0],HIGH);
    delay(t); 
    digitalWrite(deci[dig][3],HIGH);
    delay(t); 
    digitalWrite(deci[dig][4],HIGH);
    delay(t); 
    digitalWrite(deci[dig][5],HIGH);
    delay(t); 

    digitalWrite(deci[dig][0],LOW);
    delay(t); 
    digitalWrite(deci[dig][3],LOW);
    delay(t); 
    digitalWrite(deci[dig][4],LOW);
    delay(t); 
    digitalWrite(deci[dig][5],LOW);
    delay(t); 

    digitalWrite(deci[dig][6],HIGH);
    delay(t); 
    digitalWrite(deci[dig][7],HIGH);
    delay(t); 

    digitalWrite(deci[dig][6],LOW);
    delay(t); 
    digitalWrite(deci[dig][7],LOW);
    delay(t); 
  }
}


void pattern_2 (int t)
{
  for (int dig=7;dig>-1;dig--)
  {
    digitalWrite(deci[dig][0],HIGH);
    delay(t); 
    digitalWrite(deci[dig][0],LOW);
    delay(t); 

    digitalWrite(deci[dig][1],HIGH);
    delay(t); 
    digitalWrite(deci[dig][1],LOW);
    delay(t); 

    digitalWrite(deci[dig][2],HIGH);
    delay(t); 
    digitalWrite(deci[dig][2],LOW);
    delay(t); 

    digitalWrite(deci[dig][5],HIGH);
    delay(t); 
    digitalWrite(deci[dig][5],LOW);
    delay(t); 

    digitalWrite(deci[dig][6],HIGH);
    delay(t); 
    digitalWrite(deci[dig][6],LOW);
    delay(t); 

    digitalWrite(deci[dig][7],HIGH);
    delay(t); 
    digitalWrite(deci[dig][7],LOW);
    delay(t); 

    digitalWrite(deci[dig][4],HIGH);
    delay(t); 
    digitalWrite(deci[dig][4],LOW);
    delay(t); 

    digitalWrite(deci[dig][1],HIGH);
    delay(t); 
    digitalWrite(deci[dig][1],LOW);
    delay(t); 

    digitalWrite(deci[dig][2],HIGH);
    delay(t); 
    digitalWrite(deci[dig][2],LOW);
    delay(t); 

    digitalWrite(deci[dig][3],HIGH);
    delay(t); 
    digitalWrite(deci[dig][3],LOW);
    delay(t); 


  }
}

