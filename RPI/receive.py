import pika, sys, os
from paho.mqtt.client import Client
import json


def main():
    connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
    channel = connection.channel()

    channel.queue_declare(queue='hello')
    client=Client(client_id="client_1")
    client.connect('test.mosquitto.org') #broker a cui si deve connettere il client

        
    def callback(ch, method, properties, body):
        print(" [x] Received %r" % body)
        client.subscribe('topic_1',2)
        client.publish(topic = "topic_2", payload = body) 
        print("Successfully published on MQTT body"%body)

    channel.basic_consume(queue='hello', on_message_callback=callback, auto_ack=True)

    print(' [*] Waiting for messages. To exit press CTRL+C')
    channel.start_consuming()

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print('Interrupted')
        try:
            sys.exit(0)
        except SystemExit:
            os._exit(0)
    

#str="Supercalifragilistichespiralidoso"
#x = {
#   "name": "John",
#   "age": 30,
#   "married": True,
#   "divorced": False,
#   "children": ("Ann","Billy"),
#   "pets": None,
#   "cars": [
#     {"model": "BMW 230", "mpg": 27.5},
#     {"model": "Ford Edge", "mpg": 24.1}
#   ]
# }
# j=json.dumps(str)
# print(j)
