import pandas as pd
import matplotlib.pyplot as plt
import sys
import os

print(sys.argv)

if len(sys.argv)!=4:
    print("Invalid arguements")
    
pointFileName = sys.argv[1]
orderFileName = sys.argv[2]
plotFileName = sys.argv[3]

if not os.path.isfile(pointFileName):
    print(f"File not found: {pointFileName}")
    sys.exit(1)
if not os.path.isfile(orderFileName):
    print(f"File not found: {orderFileName}")
    sys.exit(1)

df = pd.read_csv(pointFileName,sep=r'\s+',header=None)
df.columns = ['ID','x','y']
df = df.set_index('ID')

f = open(orderFileName,'r')
lines = f.readlines()
f.close()
lines = [int(x.strip()) for x in lines[1:]]
df = df.loc[lines]

x = list(df['x'])
y = list(df['y'])
x.append(x[0])
y.append(y[0])

plt.plot(x,y)
plt.savefig(plotFileName)