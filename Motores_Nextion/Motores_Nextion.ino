/*--------------------------------------------------------------------
 * Teste de validação com os dois motores usando o nextion
 * 
 * -------------------------------------------------------------------*/

//importando a biblioteca Nextion
#include "Nextion.h"

//declaração de objeto -- id page, id componente e nome do componente;
NexDSButton motorA = NexDSButton(0, 1, "bt0");
NexDSButton motorB = NexDSButton(0, 2, "bt1");

uint32_t estado_botao; //armazena o estado do botão
uint32_t estado_botao2;

//Declarações para drivers
const int steppin1 = 7;
const int steppin2 = 9;

const int dirpin1 = 13;
const int dirpin2 = 11;
int x = 0;

void setup() 
{
  nexInit();

   //declaração de IO
  pinMode(steppin1, OUTPUT);
  pinMode(steppin2, OUTPUT);
  pinMode(dirpin1, OUTPUT);
  pinMode(dirpin2, OUTPUT);
}

void loop() 
{
  motorA.getValue(&estado_botao);
  if(estado_botao > 0)
  {
   //Setando a direção do motor A
    digitalWrite(dirpin1, LOW);

    for(x = 0; x < 3600; x++)
    {
      digitalWrite(steppin1, HIGH);
      delayMicroseconds(1000);
      digitalWrite(steppin1, LOW);
      delayMicroseconds(1000);
    }
    
    //setando o botão para zero 
    motorA.setValue(0);
  }

/*--------------------------------------------------------------------
 * Teste de validação com Motor B
 * -------------------------------------------------------------------*/
  motorB.getValue(&estado_botao2);
   if(estado_botao2 > 0)
  {
   //Setando a direção do motor A
    digitalWrite(dirpin2, HIGH);

    for(x = 0; x < 3600; x++)
    {
      digitalWrite(steppin2, HIGH);
      delayMicroseconds(1000);
      digitalWrite(steppin2, LOW);
      delayMicroseconds(1000);
    }
    //setando o botão para zero 
    motorA.setValue(0);
  }  
}
