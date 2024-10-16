import subprocess

token = '256:MEYCIQDRGm_v_YIBd5HzshlAQwahPR0eXiFMI_zAzZU-JLvAFQIhAO6SCgDNRpeZMHHqc6G6zi_B6IEYFis9m8q7Nq5xMV9H'

with open('output.txt', 'w') as f:
    f.write(token + '\n')
    f.write('\n' * 1024)

# child = subprocess.Popen(
#     ["nc", "prob15.geekgame.pku.edu.cn", "10015"], encoding='utf-8', stdin=subprocess.PIPE, stdout=subprocess.PIPE)

# assert child.stdin is not None
# child.stdin.write(token + '\n')
# child.stdin.flush()

# for i in range(1024):
#     child.stdin.write('\n')
#     child.stdin.flush()

# child.stdin.close()

# assert child.stdout is not None

# while True:
#     line = child.stdout.readline()
#     if not line:
#         break
#     print(line, end='')

# with open('output.txt', 'w') as f:
#     f.write(child.stdout)
