/////////////////////////MUSICAL NOTES/////////////////////////////
#define  a2     110 
#define  aS2    117

#define  b2     124

////////////////////////////////////

#define  c3     131 
#define  cS3    139 

#define  d3     147  
#define  dS3    156 

#define  e3     165 
#define  f3     175 
#define  fS3    185 

#define  g3     196 
#define  gS3    208

#define  a3     220 
#define  aS3    233 

#define  b3     247

///////////////////////////////////

#define  c4     261 
#define  cS4    278 

#define  d4     294  
#define  dS4    311 

#define  e4     329  
#define  f4     349  
#define  fS4    370 

#define  g4     392  
#define  gS4    208

#define  a4     440 
#define  aS4    466

#define  b4     493 

///////////////////////////////////

#define  c5     523 
#define  cS5    554

#define  d5     587  
#define  dS5    622 

#define  e5     659  
#define  f5     698  
#define  fS5    740 

#define  g5     784  
#define  gS5    830

#define  a5     880 
#define  aS5    932

#define  b5     988
///////////////////////////////

#define  c6     1046 
#define  cS6    1109

#define  d6     1174  
#define  dS6    1245

#define  e6     1319  
#define  f6     1397  
#define  fS6    1480

#define  g6     1568  
#define  gS6    1661

#define  a6     1760
#define  aS6    1865

#define  b6     1976
///////////////////////////////

#define  c7     2093 
#define  cS7    2217

#define  d7     2349 
#define  dS7    2489

#define  e7     2637 
#define  f7     2794 
#define  fS7    2960

#define  g7     3136 
#define  gS7    3322

#define  a7     3520
#define  aS7    3729

#define  b7     3951
///////////////////////////////
#define  R     0
/////////////////////////MUSICAL NOTES/////////////////////////////


////////////VARIABLES///////////////////////////////////////
//Connect the piezo wires to these pins
const int piezoPin1 =  12;
const int piezoPin2 =  13;  

//speed the music plays at (<1 increase speed, >1 decrease speed)
const float sped = 1; 

//vars used in program
int piezoState1 = LOW;
int piezoState2 = HIGH;             
  
////////////VARIABLES///////////////////////////////////////


///////////////////////////SONGS N STUFF///////////////////////////////////
//tetris  
int melodyT[] = {a6 ,e6 ,f6 ,g6 ,a6 ,g6 ,f6 ,e6 ,   d6 ,d6 ,f6 ,a6 ,g6 ,f6 ,   e6 ,f6 ,g6 ,a6 ,   f6 ,d6 ,d6 ,   R  ,g6 ,aS6 ,d7 ,c7 ,b6 ,   a6 ,f6 ,a6 ,g6 ,f6 ,   e6 ,e6 ,f6 ,g6 ,a6 ,   f6 ,d6 ,d6 ,R };
int beatsT[]  = {320,160,160,160,80 ,80 ,160,160,   320,160,160,320,160,160,   480,160,320,320,   320,320,640,   160,320,160 ,320,160,160,   480,160,320,160,160,   320,160,160,320,320,   320,320,320,320};

//galaga
int melodyG[] = {a5,d6,e6,e6,g6,fS6,d6,e6,b6,a6,d6,e6,e6,g6,fS6,d6,a6,cS7,d7,c7,aS6,aS6,a6,g6,f6,e6,c6,c7,d7,c7,c7,a6,b6,g6,e6,a6,fS6,e6,R};
int beatsG[]  = {320,160,160,160,160,320,160,320,160,320,160,160,   160,160,320,160,320,160,320,160,160,160,160,320,   160,320,160,320,160,160,160,160,160,160,160,160,160,160,320};

//mario
int melodyM[] = {e6,e6,R,e6, R,c6,e6,R, g6,R,R,R, g5,R,R,R, c6,R,R,g5, R,R,e5,R, R,a5,R,b5, R,aS5,a5,R, g5,e6,g6,a6,R,f6,g6, R,e6,R,c6, d6,b5,R,R};
int beatsM[]  = {160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160,160 };


//child of light (low)
//int melodyL[] = {g5 ,a5 ,b5 ,a5 ,g5 ,   b5, d5 ,d5 ,   g5 ,a5 ,b5 ,a5 ,g5 ,   b5, d5 ,d5 , b5,    a5 ,g5 ,fS5,g5 ,a5 ,    g5 ,fS5,e5 ,   d6 ,c6 ,fS5,g5 ,a5 ,   g5 ,fS5,e5 };
//int beatsL[] =  {375,125,250,125,125,   125,125,750,   375,125,250,125,125,   125,125,500,250,    375,125,250,125,125,    62 ,63 ,875,   375,125,250,125,125,   62 ,63 ,875};

//child of light (high)
int melodyL[] = {g6 ,a6 ,b6 ,a6 ,g6 ,   b6, d6 ,d6 ,   g6 ,a6 ,b6 ,a6 ,g6 ,   b6, d6 ,d6 , b6,    a6 ,g6 ,fS6,g6 ,a6 ,    g6 ,fS6,e6 ,   d7 ,c7 ,fS6,g6 ,a6 ,   g6 ,fS6,e6 };
int beatsL[] =  {375,125,250,125,125,   125,125,750,   375,125,250,125,125,   125,125,500,250,    375,125,250,125,125,    62 ,63 ,875,   375,125,250,125,125,   62 ,63 ,875};
///////////////////////////SONGS N STUFF///////////////////////////////////


void setup() {
  pinMode(piezoPin1, OUTPUT);
  pinMode(piezoPin2, OUTPUT);
}


void loop() {
  //change melodyL and beatsL to other respective melody and beats arrays to change music
  for(int i = 0; i < (sizeof(melodyL)/sizeof(int)); i++){
    //Determine if there's a rest and do stuff accordingly
    if(melodyL[i] == 0){
      playRest(beatsL[i] * sped);
    }
    else{
      playNote(melodyL[i], beatsL[i] * sped);
    }
  }

  //pause between looping music
  playRest(2000);

}

//THIS FUNCTION PLAYS NOTES (wow)
void playNote(double frequency, unsigned long duration){ //frequency in Hz, duration in ms
  
  double pause = (1000000.0/frequency); //pause is period in microseconds
  unsigned long startMicros = micros(); //start time of note in microseconds
  unsigned long currentMicros = micros(); //current system time in microseconds
  unsigned long previousMicros = 0; //start time of cycle/period in microseconds
  while((currentMicros-startMicros) < (duration*1000)){  //Once note duration in ms has elapsed, stop playing note
    currentMicros = micros();
    if (currentMicros - previousMicros >= pause) { //once a cycle/period has elapsed change piezo polarity
    previousMicros = currentMicros;
    if (piezoState1 == LOW) {
      piezoState1 = HIGH;
      piezoState2 = LOW;
    } else {
      piezoState1 = LOW;
      piezoState2 = HIGH;
    }
    digitalWrite(piezoPin1, piezoState1);
    digitalWrite(piezoPin2, piezoState2);
  }
  }
  
}

//waits a rest
void playRest(unsigned long duration){ //frequency in Hz, duration in ms
  
  unsigned long startMicros = micros();
  unsigned long currentMicros = micros();
  while((currentMicros-startMicros) < (duration*1000)){ //wait until duration in ms has elapsed
    currentMicros = micros();
  }
  
}


