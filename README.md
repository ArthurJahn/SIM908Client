# SIM908Client

SIM908 Simple Client to control GPS and GPRS modes of DFRobot [GPS/GPRS/GSM Module V3.0](http://www.dfrobot.com/wiki/index.php/GPS/GPRS/GSM_Module_V3.0_(SKU:TEL0051))

## Usage
Import SIM908Client to your Arduino porject and:
- Create a `SIM908Client`
  ```
  SIM908Client simClient(0,1,5,4,3);
  ```
  
- Setup your client 
  ```
  //starting client with baud rate 9600
  simClient.begin(9600);

  //starting GPS module
  simClient.startGPS();

  //attaching GPRS network and creating a web connection
  simClient.attach(apn,usr,psw);
  ```
  After this you will be able to use gps location and internet, if you provide valid values for `apn`, `usr` and `psw`.

- call getGPS to retrieve location
```
  //get current location
  simClient.getGPS();
```

- Follow the provided example to use MQTT over the provided internet connection, and to send location over the socket.
  
Note: the example shows only the client side of the MQTT conn. We used a configured [Mosquitto Broker](http://mosquitto.org/) to provide the infrastructure to interconnect multiple clients. The [SisAFA](https://github.com/SisAFA) project provides a more complete example about configuring a Broker and creating a mobile app to retrieve location info via MQTT.


## Contributing
If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

