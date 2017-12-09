#include "NewPing.h" // ajoute la bibliothèque du capteur ultrason
#include "Servo.h" // ajoute la bibliothèque servo-moteurs

Servo servoAvant, servoArriere; // créé deuxobjets servos
NewPing sonar(2, 4, 200); //

char avant[] = {60, 110, 120, 110, 120, 70, 60, 70}; // créé un array
int distance = 0; // initialise la distance mesurée
int distMin = 20; // définit la distance minimal pour avancer

void setup()
{
	servoAvant.attach(6); // lie un moteur au pin 6
	servoArriere.attach(8); //lie un moteur au pin 8
}

void loop()
{
	distance = 0;
	while (distance == 0)
	{
		distance = quelleDistance();
	}

	if (distance > distMin)
	{
		avance();
	}
}

void avance()
{
	for (int n = 0; n < 4; n++)
	{
		servoAvant.write(avant[2 * n]);
		servoArriere.write(avant[(2 * n) + 1]);
		delay(250);
	}
}

int quelleDistance()
{
	delay(70);

	int uS = sonar.ping();

	int cm = uS/US_ROUNDTRIP_CM;

	return cm;
}


