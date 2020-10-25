#!/usr/bin/env python
import random
import time
import json
import pika
import sys

MESSAGE_INTERVAL = 1
PROBABILITY_USEFUL_MESSAGE = 0.5
USEFUL_ROUTING_KEY = "event.info"
NON_USEFUL_ROUTING_KEY = "no_event.private"

connection = pika.BlockingConnection(pika.ConnectionParameters(host="localhost"))
channel = connection.channel()

channel.exchange_declare(exchange="topic_logs", exchange_type="topic")


def generate_fake_message():
    routing_key = NON_USEFUL_ROUTING_KEY
    if PROBABILITY_USEFUL_MESSAGE > random.random():
        routing_key = USEFUL_ROUTING_KEY


    message = []
    resp={routing_key: message}
    for i in range(random.randint(1, 3)):
        x = random.uniform(0.00, 0.97)
        y = random.uniform(0.00, 0.97)
        obj = {
            "class": "CLASS" + str(random.randint(1, 3)),
            "score": random.random(),
            "timestamp": int(time.time() * 1000000),
            "x": round(x, 2),
            "y": round(y, 2),
            "height": round(random.uniform(0.00, 0.99 - x), 2),
            "width": round(random.uniform(0.00, 0.99 - y), 2),
            "objectid": random.randint(0, 100),
            "type": "object",
            "parameter1": "VALUE1",
            "parameter2": "VALUE2",
            "parameter3": "VALUE3",
        }
        message.append(obj)

    return routing_key, resp


def send_message(routing_key, message, channel):
    message = json.dumps(message, ensure_ascii=False)
    channel.basic_publish(exchange="topic_logs", routing_key=routing_key, body=message)
    print(" [x] Sent %r:%r" % (routing_key, message))
    print("\n")


try:
    while True:
        routing_key, message = generate_fake_message()
        send_message(routing_key, message, channel)

        time.sleep(MESSAGE_INTERVAL)
except:
    print("KILLING EMITTER PROPERLY!")

connection.close()
print("EMITTER CLOSED")
