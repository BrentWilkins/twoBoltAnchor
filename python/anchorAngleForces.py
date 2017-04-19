#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'''
o     o
 \ θ / F
  \ /
   o
   |
   L

L = 2 * F * cos(θ/2)
F = L * (1 / (2 * cos(θ/2)))

@author: brent
'''

import math
import matplotlib.pyplot as plt

# Get the angles of interest from the user
minimum = int(input("Enter minumim angle between cords: "))
maximum = int(input("Enter maximum angle between cords: "))

if (maximum < minimum):
	maximum = int(input("Enter maximum angle between cords (must be greater): "))

# Caluclate the resultant forces
angles = list(range(minimum, maximum + 1))
force = [100 / (2 * math.cos( math.radians(angle/2) )) for angle in range(minimum, maximum + 1)]

# Generate plot
plt.plot(angles, force)
plt.xlabel('Angle formed between bolts (degrees)')
plt.ylabel('% of load force on each bolt')

# Crop plot at 200% if necessary
top = max(force)
if (max(force) > 200):
	top = 200

plt.axis([minimum, maximum, min(force), top])
plt.savefig('resultantForces.png')
plt.show()