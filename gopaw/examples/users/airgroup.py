
from math import pow

def airgroup(x):
  k0 = 238.0185
  k1 = 5792105
  k2 = 57.362
  k3 = 167917.0
  s = pow(x/1.24,2)
  return (k1*(k0+s)/pow(k0-s,2)+k3*(k2+s)/pow(k2-s,2))/1e5

