#include <LiquidCrystal.h>

LiquidCrystal lcd(11, 10, 6, 5, 4, 3);

int x,y,z,v,val1,val2,val3,val4,score=0,a=0;
int col,row;
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A5,INPUT);
Serial.begin(9600);
lcd.begin(16,2);
//analogWrite(9,240);
 //lcd.print("cool"); 
 lcd.cursor();
 col=0;
 row=0;
 game();
}


// starts the game
void game()
{val1=random(0,15);
val2=random(0,2);
lcd.setCursor(val1,val2);
lcd.write("X");
val3=random(0,15);
val4=random(0,2);
lcd.setCursor(val3,val4);
delay(300);
col=val3;
 row=val4;
}

void loop() {
//hard mode delay (100);
//easy mode delay (250);
  if (col>15)
  col=0;
  if (col<=0)
  col=0;
  //lcd.print("cool");
  x=analogRead(A0);
  y=analogRead(A1);
  z=analogRead(A5); 
 /*Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print('\n');*/
//on  different joysticks use different analog values for movement if needed  
//movement script form here (1)
if(0<=y&&y<=20&&x<=525&&x>=500)
{col++;

  lcd.setCursor(col, row); 
  delay(150); //modifying this delay make the character (mouse) go faster/slower  
}
if(1000<=y&&y<=1024&&x<=525&&x>=500)
{col--;
  lcd.setCursor(col, row);
  delay(150);//modifying this delay make the character (mouse) go faster/slower  
}
//lcd.setCursor(col, row)
  if (0<=x&&x<=20&&y<=525&&y>=480)
  {row=0;
  lcd.setCursor(col, row);}
  if (1000<=x&&x<=1024&&y<=525&&y>=480)
  {row=1;
  lcd.setCursor(col, row);}
 // to here (1)
  
 // condtion for wining a round and starting a new one 
if (col==val1&&row==val2&&z==0&&y>0&&x>0)
{score++;
lcd.clear();
game();
}
 Serial.print(score);
 Serial.print('\n');
}
