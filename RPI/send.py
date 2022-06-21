import pika

connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
channel = connection.channel()

channel.queue_declare(queue='hello')
count=0
x=""
while(count<10):
    channel.basic_publish(exchange='', routing_key='hello', body=str(x))
    x="cicciapasticcia"
    count+=1
print(" [x] Sent 'Hello World!'")
connection.close()
# #channel.basic_publish(exchange='', routing_key='hello', body='Hello World!')
# print(" [x] Sent 'Hello World!'")
# connection.close()