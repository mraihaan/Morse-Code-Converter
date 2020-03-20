//5 denotes ending of a morse code letter
//7 indicates a pause between each blink/dash
//1 means dash and 0 means dot
//3 denotes nothing and it's just there so it can skip to 5 directly

int buzzer = 6;//          a                  b                     c              d                     e                 f                  g                 h                   i                  j                    k                 l                  m                  n                  o                 p                  q                   r                  s                 t                   u                  v                   w                x                  y                   z                                                              
int codes[26][8] = {{0,7,1,3,3,3,3,5}, {1,7,0,7,0,7,0,5}, {1,7,0,7,1,7,0,5}, {1,7,0,7,0,3,3,5}, {0,3,3,3,3,3,3,5}, {0,7,0,7,1,7,0,5}, {1,7,1,7,0,3,3,5}, {0,7,0,7,0,7,0,5}, {0,7,0,3,3,3,3,5}, {0,7,1,7,1,7,1,5}, {1,7,0,7,1,3,3,5}, {0,7,1,7,0,7,0,5}, {1,7,1,7,3,3,3,5}, {1,7,0,7,3,3,3,5}, {1,7,1,7,1,3,3,5}, {0,7,1,7,1,7,0,5}, {1,7,1,7,0,7,1,5}, {0,7,1,7,0,3,3,5}, {0,7,0,7,0,3,3,5}, {1,3,3,3,3,3,3,5}, {0,7,0,7,1,3,3,5}, {0,7,0,7,0,7,1,5}, {0,7,1,7,1,3,3,5}, {1,7,0,7,0,7,1,5}, {1,7,0,7,1,7,1,5}, {1,7,1,7,0,7,0,5}};
char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; 

String message = "hello world";                      //Enter word as string to convert into morse code
int index;  
int n = message.length();

void setup(){
  pinMode(buzzer, OUTPUT);
}

void loop(){
  noTone(buzzer);
  for(int s=0; s<n; s++){                //string iteration
    for (int l=0; l<26; l++){            //letters array iteration
      if(message[s] == letters[l]){      
        index=l;

        for(int c=0; c<8; c++){
//dot          
          if (codes[index][c] == 0){
            tone(buzzer, 600);
            delay(800/3);
          }
//dash
          else if (codes[index][c] == 1){
            tone(buzzer, 600);
            delay(800);
            
          }
//break b/w dots and dashes
          else if (codes[index][c] == 7){
            noTone(buzzer);
            delay(800/3);
            
          }
//break b/w letters
          else if (codes[index][c] == 5){
            noTone(buzzer);
            delay(800);   
          }
        }
      } 
    } 
  }
  noTone(buzzer);
  for(;;){
  }
}
