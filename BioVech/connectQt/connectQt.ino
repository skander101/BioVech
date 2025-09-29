void setup() {
    Serial.begin(9600); // Initialiser la communication série à 9600 bauds
}

void loop() {
        Serial.println("Hello Qt!");
        delay(3000);
    if (Serial.available() > 0) {
        String data = Serial.readStringUntil('\0'); // Lire jusqu'à la nouvelle ligne
        Serial.println("Données reçues : " + data); // Afficher les données reçues
    }


}