int sw=8;
int outputCLK = 10;
int outputDT =9;
int most = 1;
int ezelott =1; 
int szamlalo=0;
void setup() {

  Serial.begin(9600);
  Serial.println("Encoder kezelő program!");
  for(int i=8;i<=10;i++) pinMode(i, INPUT_PULLUP);
  }

void loop() {
  if (digitalRead (sw)==0) szamlalo=0;
  most=digitalRead(outputCLK);
  if (most != ezelott)
  {
    //Serial.println("Tekerés van!!!");
    if (digitalRead(outputDT) != most)
    {
      szamlalo--;
     
    }
    else {
      szamlalo++;
      szamlalo=constrain(szamlalo, -10,10);
    }
    Serial.println(szamlalo);
    
  }
    ezelott=most;
  }
