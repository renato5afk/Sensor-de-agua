import paho.mqtt.client as mqtt
import requests
BROKER = "broker.hivemq.com"
TOPIC = "ST/IOT2025/CENTINELA-PIR/SENSOR/MOVIMIENTO"
URL = "http://localhost/iot_mqtt/guardar_dato.php"

def on_message(client, userdata, msg):
    valor = msg.payload.decode()
    print(f"Dato recibido: {valor}")
    try:
        r = requests.get(URL, params={'valor': valor})
        print("Servidor:", r.text)
    except Exception as e:
        print("Error enviando al servidor:", e)
client = mqtt.Client()
client.on_message = on_message
client.connect(BROKER, 1883, 60)
client.subscribe(TOPIC)
print(f"Escuchando tópico: {TOPIC}")
client.loop_forever()
