int switchPin1 = 7;
int switchPin2 = 9;
int switchPin3 = 11;
int switchPin4 = 12;
int switchPin5 = 6;
int switchPin6 = 5;
boolean anjatich = false;
boolean anjatich1 = false;
int ledPin = 13;
int tiv = 1;
int tiv1 = 0;
const byte PIN_ANALOG_X = 0;
const byte PIN_ANALOG_Y = 1;
const int X_THRESHOLD_LOW = 405;
const int X_THRESHOLD_HIGH = 625;
const int Y_THRESHOLD_LOW = 405;
const int Y_THRESHOLD_HIGH = 625;
int x_position;
int y_position;
int x_direction;
int y_direction;
void setup() {  
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(switchPin3, INPUT);
  pinMode(switchPin4, INPUT);
  pinMode(switchPin5, INPUT);
  pinMode(switchPin6, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.write("$X");
  Serial.write(13);
  Serial.write(10);
}

void loop () {
  //djostiki kod
  x_direction = 0; 
  y_direction = 0;
  x_position = analogRead(PIN_ANALOG_X);  
  y_position = analogRead(PIN_ANALOG_Y);  
  if (x_position > X_THRESHOLD_HIGH) { 
          x_direction = 1;  
  }else if (x_position < X_THRESHOLD_LOW) { 
          x_direction = -1; 
  }  
  if (y_position > Y_THRESHOLD_HIGH) {  
          y_direction = 1;  
  } else if (y_position < Y_THRESHOLD_LOW) {  
          y_direction = -1; 
  }
  //djostiki kod
  
  if(digitalRead(switchPin6)==HIGH && anjatich1==false){
        if(tiv1==1){
            tiv1=0;
        }
        else{
            ++tiv1;
        }
        anjatich1 = true;
        delay(10);
  }
  if(digitalRead(switchPin6)==LOW && anjatich1==true){
        anjatich1=false;  
  }
  
  if(digitalRead(switchPin5)==HIGH && anjatich==false){
        if(tiv==4){
            tiv=1;
        }
        else{
            ++tiv;
        }
      //  Serial.print(tiv);
        anjatich = true;
        delay(10);
  }
  if(digitalRead(switchPin5)==LOW && anjatich==true){
      anjatich=false;  
  }

  if(tiv==1)
  {
    //djostiki kod
    if(tiv1==0){
          if (x_direction == -1) {
                if (y_direction == -1) {
                      Serial.write("G91 X0.3 Y0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("right-up"); 
                } else if (y_direction == 0) {
                      Serial.write("G91 Y0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("up");   
                } else { 
                // y_direction == 1
                      Serial.write("G91 X-0.3 Y0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("left-up");   
                }  
        } else if (x_direction == 0) { 
                if (y_direction == -1) {
                      Serial.write("G91 X0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("right");
                
                } else if (y_direction == 0) {
                    /*Serial.write("0x85");Serial.write(13);
                      Serial.write(10);
                      Serial.println("center");
                    */   
                } else {     
                // y_direction == 1      
                      Serial.write("G91 X-0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("left");       
                } 
        } else { 
                // x_direction == 1  
                if (y_direction == -1) {
                      Serial.write("G91 X0.3 Y-0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("right-down");          
                } else if (y_direction == 0) {
                      Serial.write("G91 Y-0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("down");                          
                } else {          
                // y_direction == 1
                      Serial.write("G91 X-0.3 Y-0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("left-down");                          
                }  
        } 
    }
  //djostiki kod verj

  //knopki rejimi skizb
    if(tiv1==1){
        if (digitalRead(switchPin1) == HIGH)
            {
                Serial.write("G91 Y-0.3 F500");
                Serial.write(13);
                Serial.write(10);
                Serial.println("down");
            }      
        if (digitalRead(switchPin2) == HIGH)
            {
                Serial.write("G91 Y0.3 F500");
                Serial.write(13);
                Serial.write(10);
                Serial.println("up");
            }     
        if (digitalRead(switchPin3) == HIGH)
            {
                Serial.write("G91 X-0.3 F500");
                Serial.write(13);
                Serial.write(10);
                Serial.println("left");
            }     
        if (digitalRead(switchPin4) == HIGH)
            {
                Serial.write("G91 X0.3 F500");
                Serial.write(13);
                Serial.write(10);
                Serial.println("right");
            } 
      }
        //knopki rejimi verj
  }
  if(tiv==2)
  {
    //djostiki kod
    if(tiv1==0){
        if (x_direction == -1) {
              if (y_direction == -1) {
                    Serial.write("G91 X0.3 Y-0.3 F500");
                    Serial.write(13);
                    Serial.write(10);
                    Serial.println("right-up"); 
              } else if (y_direction == 0) {
                    Serial.write("G91 X0.3 F500");
                    Serial.write(13);
                    Serial.write(10);
                    Serial.println("up");   
              } else { 
              // y_direction == 1
                    Serial.write("G91 X0.3 Y0.3 F500");
                    Serial.write(13);
                    Serial.write(10);
                    Serial.println("left-up");   
              }  
      } else if (x_direction == 0) { 
              if (y_direction == -1) {
                    Serial.write("G91 Y-0.3 F500");
                    Serial.write(13);
                    Serial.write(10);
                    Serial.println("right");
              
              } else if (y_direction == 0) {
                  /*Serial.write("0x85");Serial.write(13);
                    Serial.write(10);
                    Serial.println("center");
                  */   
              } else {     
              // y_direction == 1      
                    Serial.write("G91 Y0.3 F500");
                    Serial.write(13);
                    Serial.write(10);
                    Serial.println("left");       
              } 
      } else { 
              // x_direction == 1  
              if (y_direction == -1) {
                    Serial.write("G91 X-0.3 Y-0.3 F500");
                    Serial.write(13);
                    Serial.write(10);
                    Serial.println("right-down");          
              } else if (y_direction == 0) {
                    Serial.write("G91 X-0.3 F500");
                    Serial.write(13);
                    Serial.write(10);
                    Serial.println("down");                          
              } else {          
              // y_direction == 1
                    Serial.write("G91 X-0.3 Y0.3 F500");
                    Serial.write(13);
                    Serial.write(10);
                    Serial.println("left-down");                          
              }
      }  
  } 
  //djostiki kod verj

  //knopki rejimi skizb
  if(tiv1==1){
        if (digitalRead(switchPin1) == HIGH)
            {
                Serial.write("G91 X-0.3 F500");
                Serial.write(13);
                Serial.write(10);
                Serial.println("down");
            }      
        if (digitalRead(switchPin2) == HIGH)
            {
                Serial.write("G91 X0.3 F500");
                Serial.write(13);
                Serial.write(10);
                Serial.println("up");
            }     
        if (digitalRead(switchPin3) == HIGH)
            {
                Serial.write("G91 Y0.3 F500");
                Serial.write(13);
                Serial.write(10);
                Serial.println("left");
            }     
        if (digitalRead(switchPin4) == HIGH)
            {
                Serial.write("G91 Y-0.3 F500");
                Serial.write(13);
                Serial.write(10);
                Serial.println("right");
            } 
  }
  //knopki rejimi verj
  }
  if(tiv==3)
  {
    //djostiki kod
    if(tiv1==0){
          if (x_direction == -1) {
                if (y_direction == -1) {
                      Serial.write("G91 X-0.3 Y-0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("right-up"); 
                } else if (y_direction == 0) {
                      Serial.write("G91 Y-0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("up");   
                } else { 
                // y_direction == 1
                      Serial.write("G91 X0.3 Y-0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("left-up");   
                }  
        } else if (x_direction == 0) { 
                if (y_direction == -1) {
                      Serial.write("G91 X-0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("right");
                
                } else if (y_direction == 0) {
                    /*Serial.write("0x85");Serial.write(13);
                      Serial.write(10);
                      Serial.println("center");
                    */   
                } else {     
                // y_direction == 1      
                      Serial.write("G91 X0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("left");       
                } 
        } else { 
                // x_direction == 1  
                if (y_direction == -1) {
                      Serial.write("G91 X-0.3 Y0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("right-down");          
                } else if (y_direction == 0) {
                      Serial.write("G91 Y0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("down");                          
                } else {          
                // y_direction == 1
                      Serial.write("G91 X0.3 Y0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("left-down");                          
                }  
        } 
    }
  //djostiki kod verj

  //knopki rejimi skizb
  if(tiv1==1){
          if (digitalRead(switchPin1) == HIGH)
              {
                  Serial.write("G91 Y0.3 F500");
                  Serial.write(13);
                  Serial.write(10);
                  Serial.println("down");
              }      
          if (digitalRead(switchPin2) == HIGH)
              {
                  Serial.write("G91 Y-0.3 F500");
                  Serial.write(13);
                  Serial.write(10);
                  Serial.println("up");
              }     
          if (digitalRead(switchPin3) == HIGH)
              {
                  Serial.write("G91 X0.3 F500");
                  Serial.write(13);
                  Serial.write(10);
                  Serial.println("left");
              }     
          if (digitalRead(switchPin4) == HIGH)
              {
                  Serial.write("G91 X-0.3 F500");
                  Serial.write(13);
                  Serial.write(10);
                  Serial.println("right");
              } 
  }
  //knopki rejimi verj
  }
  if(tiv==4)
  {
    //djostiki kod
    if(tiv1==0){
          if (x_direction == -1) {
                if (y_direction == -1) {
                      Serial.write("G91 X-0.3 Y0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("right-up"); 
                } else if (y_direction == 0) {
                      Serial.write("G91 X-0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("up");   
                } else { 
                // y_direction == 1
                      Serial.write("G91 X-0.3 Y-0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("left-up");   
                }  
        } else if (x_direction == 0) { 
                if (y_direction == -1) {
                      Serial.write("G91 Y0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("right");
                
                } else if (y_direction == 0) {
                    /*Serial.write("0x85");Serial.write(13);
                      Serial.write(10);
                      Serial.println("center");
                    */   
                } else {     
                // y_direction == 1      
                      Serial.write("G91 Y-0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("left");       
                } 
        } else { 
                // x_direction == 1  
                if (y_direction == -1) {
                      Serial.write("G91 X0.3 Y0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("right-down");          
                } else if (y_direction == 0) {
                      Serial.write("G91 X0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("down");                          
                } else {          
                // y_direction == 1
                      Serial.write("G91 X0.3 Y-0.3 F500");
                      Serial.write(13);
                      Serial.write(10);
                      Serial.println("left-down");                          
                }  
        } 
    }
  //djostiki kod verj

  //knopki rejimi skizb
  if(tiv1==1){
        if (digitalRead(switchPin1) == HIGH)
            {
                Serial.write("G91 X0.3 F500");
                Serial.write(13);
                Serial.write(10);
                Serial.println("down");
            }      
        if (digitalRead(switchPin2) == HIGH)
            {
                Serial.write("G91 X-0.3 F500");
                Serial.write(13);
                Serial.write(10);
                Serial.println("up");
            }     
        if (digitalRead(switchPin3) == HIGH)
            {
                Serial.write("G91 Y-0.3 F500");
                Serial.write(13);
                Serial.write(10);
                Serial.println("left");
            }     
        if (digitalRead(switchPin4) == HIGH)
            {
                Serial.write("G91 Y0.3 F500");
                Serial.write(13);
                Serial.write(10);
                Serial.println("right");
            } 
  }
  //knopki rejimi verj
  }
delay(50);
}
