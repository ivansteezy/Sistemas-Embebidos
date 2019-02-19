/*
  Servidor Web

 Modificado por Araceli Garcia
 Junio 2018

 Desmuestra como configurar un servidor We

 */

#include <SPI.h>
#include <Ethernet.h>
#include <dht11.h>
#define DHT11_PIN 4
dht11 DHT;

//Se introducen los valores correspondientes a MAC, IP local, Puerta de Enlace y Máscara de Red

byte mac[] = {
  0x00, 0x37, 0x19, 0xDD, 0x84, 0x32
};
IPAddress ip(192, 168, 1, 1111111111);

// Inicializa la libreria Ethernet server  
// con la dirección IP y el puerto con el que se usara  
// (port 80 is default for HTTP):
EthernetServer server(80);

void setup() {
  // Abre el puerto serial de comunicaciones  
  Serial.begin(9600);
  while (!Serial) {
    ; // espera por el puerto serial conectado  
  }


  // Inicia la conexión Ethernet y el servidor  
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop() {
  // Escucha por clientes  
  EthernetClient client = server.available();
  if (client) {
    Serial.println("cliente nuevo");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
       
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // La conexion sera cerrada despues de completar la respuesta  
          client.println("Refresh: 3");  // refresca la pagina automaticamente cada 3 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          // output the value of each analog input pinclient.print("Ejemplo de Servidor Web ");
          client.println("<br />");
          client.println("<br />");
          client.print("Rembrandt, Gabo, Ivan, Luis ");
          client.println("<br />");
          client.print("Sensor de humedad DHT11     ");
          client.println("<br />");
          client.println("<br />");
          client.print(" ");
          int chk = DHT.read(DHT11_PIN);
          client.print("La humedad en el ambiente es: ");
          client.print(DHT.humidity);
          client.println("<br />");
          client.println("<br />");
          client.print("La temperatura en el ambiente es: ");
          client.print(DHT.temperature);
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}
 

