import pika
def send_to_queue(list):

    connection = pika.BlockingConnection(pika.ConnectionParameters(host='localhost'))
    channel = connection.channel()

    channel.queue_declare(queue='hello')
    count=len(list)
    while(count>0):

        channel.basic_publish(exchange='', routing_key='hello', body=list[count-1]) #Mettendo un byte alla volta, provare a inserire tutti il necessario
        print(" [x] Sent 'Hello World!'")
        count-=1
    connection.close()
    # #channel.basic_publish(exchange='', routing_key='hello', body='Hello World!')
    # print(" [x] Sent 'Hello World!'")
    # connection.close()
