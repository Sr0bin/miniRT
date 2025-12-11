from math import sqrt
x = float(input("x: "))
y = float(input("y: "))
z = float(input("z: "))

val = sqrt(x * x + y * y + z * z)
print(f"{x/val},{y/val},{z/val}")
