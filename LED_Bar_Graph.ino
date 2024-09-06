/* LED Bar Graph 
LED dikontrol dari potentiometer sebagai                analog input */
const int analogPin = 0; // pin potentiometer dipasang
const int ledCount = 10; // jumlah elemen/LED bar graph
int ledPins[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
   // mendeklarasikan array pada pin LED
void setup() {
	// loop pin array dan menset semua pin array sbg output:
	for (int thisLed = 0; thisLed < ledCount; thisLed++) {
		pinMode(ledPins[thisLed], OUTPUT); 
	}
}
void loop() {
	// Baca potensiometer
	int sensorReading = analogRead(analogPin);
	// hasil range input analog dari 0 ke sejumlah led
	int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);
	// loop LED array
	for (int thisLed = 0; thisLed < ledCount; thisLed++) {
		// jika elemen pada array lebih kecil dari ledLevel,
		// ON-kan pin 
		if (thisLed < ledLevel) {
			digitalWrite(ledPins[thisLed], HIGH);
		} 
			// OFF kan semua pin yang lebih tinggi dari ledLevel:
		else {
			digitalWrite(ledPins[thisLed], LOW); 
		}
	}
}
