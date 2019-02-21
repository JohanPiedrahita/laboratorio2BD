//Este laboratorio consiste en la programacion para controlar los servos de forma que se pueda manejar por medio del teclado y el bluetooth.
//Este laboratorio fue elaborado por Johan Alexander Piedrahita y Juan Jose Nontoa.
#include <Servo.h>
#include <SoftwareSerial.h>

#define PINSERVODERECHO 9 //pin del servo derecho como 9
#define PINSERVOIZQUIERDO 8 //pin del servo derecho como 8
#define PinTX_BT 3 //Pin del Tx del Bluetooth
#define PinRX_BT 2 //Pin del Rx del Bluetooth


SoftwareSerial Bt(PinRX_BT, PinTX_BT); //Conexión del Bluetooth al Arduino
Servo ServoDerecho; // Declaración de los Servos
Servo ServoIzquierdo;

char tecla; // Variable que almacena las órdenes del teclado



void setup()
{
 ServoDerecho.attach(PINSERVODERECHO); // Conexión de los Servos al Arduino
 ServoIzquierdo.attach(PINSERVOIZQUIERDO);
 
 Serial.begin(9600);   // comunicacion de monitor serial a 9600 bps
 Bt.begin(9600);       // Comunicación del Bluetooth a 9600 bps

}

void loop() 
{
if (Serial.available()>0) // Lectura del valor del Teclado
{
  tecla = Serial.read();
}
if(Bt.available()>0) // Lectura del valor puesto desde la aplicación
{
tecla=Bt.read();
}
  switch(tecla) // Movimiento según cada caso
  {
    case 'w': // Avanzar
    ServoIzquierdo.write(0);
    ServoDerecho.write(180);
    break;
     case 's': // Retroceder
    ServoIzquierdo.write(180);
    ServoDerecho.write(0);
    break; 
    case 'a': // Girar a la izquierda
    ServoIzquierdo.write(90);
    ServoDerecho.write(0);
    break;
    case 'd': // Girar a la Derecha
    ServoIzquierdo.write(180);
    ServoDerecho.write(90);
    break;
    case 'r': // Detenerse
    ServoIzquierdo.write(90);
    ServoDerecho.write(90);
    break;
  }
  }
