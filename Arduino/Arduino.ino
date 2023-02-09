#include <math.h>

#define A 8
#define B 9
#define C 4
#define D 3
#define E 2
#define F 7
#define G 6
#define button 10
#define led 11
#define movimento 12
#define luz 13
#define buzzer 14
#define delay_ms 500
#define interval 10000

byte digits[10][7] = { 
 { 0,0,0,0,0,0,1 },  //DIGITO 0
 { 1,0,0,1,1,1,1 },  //DIGITO 1
 { 0,0,1,0,0,1,0 },  //DIGITO 2
 { 0,0,0,0,1,1,0 },  //DIGITO 3
 { 1,0,0,1,1,0,0 },  //DIGITO 4
 { 0,1,0,0,1,0,0 },  //DIGITO 5
 { 0,1,0,0,0,0,0 },  //DIGITO 6
 { 0,0,0,1,1,1,1 },  //DIGITO 7
 { 0,0,0,0,0,0,0 },  //DIGITO 8
 { 0,0,0,1,1,0,0 },  //DIGITO 9
}
int count = 2;
unsigned long current_time = 0;
unsigned long begin_time = 0;
bool ligando = 0;
bool ligado = 0;
bool check = 0;
bool hostil = 0;

void escrever_numero(int numero) {
  bool* display = sete_segmentos[numero];
  digitalWrite(A,display[0]);
  digitalWrite(B,display[1]);
  digitalWrite(C,display[2]);
  digitalWrite(D,display[3]);
  digitalWrite(E,display[4]);
  digitalWrite(F,display[5]);
  digitalWrite(G,display[6]);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  pinMode(movimento, INPUT);
  pinMode(luz, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(hostil){
    while(1){
      tone(buzzer, 1000);
      digitalWrite(led, HIGH);
      delay(delay_ms/10);
      digitalWrite(led, LOW);
      delay(delay_ms/10);
    }
  }
  
  if(ligando == 1){
    ligado = 1;
    for(i==0;i<10;i++){
      digitalWrite(led, HIGH);
      delay(delay_ms);
      digitalWrite(led, LOW);
      delay(delay_ms);
    }
      
  }
  
  
  if (ligado == 1){
    if (invasion){
      for(i==0;i<2;i++){
        begin_time = millis();
        current_time = millis();
        while(current_time - begin_time < interval){
          number = Serial.read();
          if(number == password){
            check = 1;
            break;
          }
          escrever_numero(math.floor(current_time - begin_time));
          current_time = millis();
        }
        if(check == 1){
          Serial.write("Welcome!");
          ligando = 0;
          ligado = 0;
          break;
        }
        Serial.write("Wrong Password");
      }
      hostil = 1;
              
    }else{
      mov_sensor = digitalRead(movimento);
      luz_sensor = digitalRead(luz);
      if (mov_sensor || luz_sensor){
        for(i==0;i<2;i++){
          tone(buzzer, 1000);
          delay(delay_ms);       
          noTone(buzzer);
        }
        invasion = 1;
      }
    } 
  }
  
  ligando = digitalRead(button);

}
