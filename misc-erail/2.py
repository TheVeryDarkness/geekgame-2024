import csv

csv.register_dialect('mydialect', delimiter='\t', quoting=csv.QUOTE_NONE)

csv.reader(open('1.csv', 'r'), dialect='mydialect')

diff: list[int] = []

import datetime

datetime.datetime.fromordinal

for data in csv.reader(open('1.csv', 'r'), dialect='mydialect'):
    print(data)
    h1, m1 = map(int, data[3].split(':'))
    h2, m2 = map(int, data[4].split(':'))
    diff.append(((h2-h1)*60+(m2-m1)+1440)%1440)

print(diff)
