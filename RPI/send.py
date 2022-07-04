import json
import pika
def send_to_queue(list,queue):

    connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
    channel = connection.channel()

    channel.queue_declare(queue=queue)
    message=json.dumps(list)
    channel.basic_publish(exchange='', routing_key=queue, body=message) #Mettendo un byte alla volta, provare a inserire tutti il necessario
    print(" [x] Sent 'Hello World!'")
    connection.close()
 