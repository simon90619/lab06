#include <SevSeg.h>
#include <Keypad.h>
SevSeg sevseg; 
#define Do 523
#define Re 587
#define Mi 659
#define Fa 698
#define So 784
#define La 880
#define Si 988
#define Do2 1046
#define Re2 1175
#define Re22 1247
#define Mi2 1318
#define Fa2 1397
#define So2 1568
#define La2 1760
#define La22 1865
#define Si2 1976
#define Do3 2092




const byte ROWS = 4;
const byte COLS = 4;
char key;


int SW[]={493,523,587,659,698,784,880,988,1046,1175,1318,1397,1568,1760,1976,2092};

char keys[ROWS][COLS]={
   {'F', 'E', 'D', 'C'},
  {'B','3' , '6', '9'},
  {'A', '2', '5', '8'},
  {'0', '1', '4', '7'}
};
int k;  //                                 /                         /                           /                                 /
int mus[]={La,Do2,Si,So,So,La,La,Do2,Si,So,Mi2,Do2,Re2,Si,Do2,La,Si,So,Mi2,Do2,Re2,Si,Do2,Si,La,So,So2,Re22,Fa2,Re2,Re2,Do2,Re2,La22,So2,Mi2,Fa2,Mi2,Mi2,Mi2,Do2,Si};
 //                                              /                               /                               /                              /
int sp[]={600,250,500,250,250,500,250,500,500,500,500,250,500,500,500,500,500,700,500,250,500,500,500,500,500,700,600,250,400,400,400,500,400,700,500,250,500,500,500,500,500,700};

byte rowPins[ROWS]={2,3,4,5};
byte colPins[COLS]={6,7,8,9};
Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

void setup() {
   Serial.begin(9600);
  pinMode(12,OUTPUT);
  int i;
  int s;

  
 for(i=0;i<26;i++)
    {
  s = sp[i]*0.6;
  tone(12,mus[i]);
  delay(s);
  noTone(12);
    }
    noTone(12);
  //---------------------------------------------------------------------------------
}
void loop() {

  key = keypad.getKey();
  int k;
  if(key>='A' && key<='F')
       k=key-'A'+10;
    else
       k=key-'0';
  
  if (key != NO_KEY)
  {
    tone(12,SW[k],300);
   
    Serial.println(key);
    // sevseg.setNumber(k,1);
     sevseg.refreshDisplay(); 
  }
   



  
 
}
