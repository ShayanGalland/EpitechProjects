import socket

server_ip = '127.0.0.1'
server_port = 12345
buffer_size = 1024

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.connect((server_ip, server_port))

def handle_server_message(message):
    message_parts = message.split()
    command = message_parts[0]
    
    if command == "msz":
        handle_msz(message_parts[1:])
    elif command == "bct":
        handle_bct(message_parts[1:])
    elif command == "tna":
        handle_tna(message_parts[1:])

def handle_msz(args):
    x, y = args
    print(f"La taille de la carte est {x}x{y}")

def handle_bct(args):
    x, y, *resources = args
    print(f"La tuile en position {x},{y} contient {resources}")

def handle_tna(args):
    team_name = args[0]
    print(f"Nom de l'équipe: {team_name}")


while True:
    data = s.recv(buffer_size)
    if data:
        messages = data.decode("utf-8").strip().split("\n")
        for message in messages:
            handle_server_message(message)
