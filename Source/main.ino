#define PINS1 A0
#define PINS2 A1
#define PINS3 A2

#define D1 0.525f
#define D2 1.056f

int a1,a2,a3;
int r1,r2,r3;
unsigned long t1,t2,t3;
float dt1,dt2;
float f1,f2;
float g;
unsigned long totalTime = 2000000, initialTime;


void setup() {
  Serial.begin(115200);
}

void loop() {

    if(analogRead(PINS1) > 800){
       r1 = -1;
       r2 = -1;
       r3 = -1;
       a1 = -1;
       a2 = -1;
       a3 = -1;
      
        
        initialTime = micros();
        while(micros() - initialTime < totalTime){
            r1 = analogRead(PINS1);
            r2 = analogRead(PINS2);
            r3 = analogRead(PINS3);
        
            if(r1 > a1){
              a1 = r1;
              t1 = micros();
            }
            if(r1 > a2){
              a2 = r2;
              t2 = micros();
            }
            if(r3 > a3){
              a3 = r3;
              t3 = micros();
            }
            
        }
    
        dt1 = (float) (t2-t1)/1000000;
        dt2 = (float) (t3-t1)/1000000;
    
        g = (2*(D1/dt1 - D2/dt2))/(dt1-dt2);
        
        Serial.print("{");
        Serial.print(dt1);
        Serial.print(":");
        Serial.print(dt2);
        Serial.print(":");
        Serial.print(g);
        Serial.print("}");
        Serial.flush();
        delay(5000);
    }  
}
