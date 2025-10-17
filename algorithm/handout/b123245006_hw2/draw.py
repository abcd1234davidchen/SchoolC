import pandas as pd
import matplotlib.pyplot as plt
import sys
import os

# check if arguements are correct
if len(sys.argv)!=4:
    print("Invalid arguements")

# points file/order file/output figure
pointFileName = sys.argv[1]
orderFileName = sys.argv[2]
plotFileName = sys.argv[3]

# check if point file and order exist
if not os.path.isfile(pointFileName):
    print(f"File not found: {pointFileName}")
    sys.exit(1)
if not os.path.isfile(orderFileName):
    print(f"File not found: {orderFileName}")
    sys.exit(1)

# read point file and put into pandas
df = pd.read_csv(pointFileName, sep=r'\s+', header=None, dtype={0: str})
df.columns = ['ID','x','y']
df = df.set_index('ID')

# reorder by order file
f = open(orderFileName,'r')
lines = f.readlines()
f.close()
# keep IDs as strings (skip the header line like "distance: ...")
lines = [x.strip() for x in lines[1:] if x.strip()]
df = df.loc[lines]

# Disassemble x and y line and append head to form circle
x = list(df['x'])
y = list(df['y'])
x.append(x[0])
y.append(y[0])

fig = plt.figure(figsize=(6, 6)) 
ax = plt.subplot(1,1,1)
ax.plot(x,y)
axis_max = max(max(x), max(y),max(y)+min(y),max(x)+min(x))
axis_min = min(min(x), min(y),0)
ax.set_ylim(axis_min, axis_max)
ax.set_xlim(axis_min, axis_max)
ax.set_aspect('equal', adjustable='box')

plt.savefig(plotFileName,bbox_inches='tight')
