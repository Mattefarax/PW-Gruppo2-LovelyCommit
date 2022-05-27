import pika

connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
channel = connection.channel()

channel.queue_declare(queue='hello')
x=0
while(x<10):
    channel.basic_publish(exchange='', routing_key='hello', body=str(x))
    x+=1
print(" [x] Sent 'Hello World!'")
connection.close()
#channel.basic_publish(exchange='', routing_key='hello', body='Hello World!')
print(" [x] Sent 'Hello World!'")
connection.close()