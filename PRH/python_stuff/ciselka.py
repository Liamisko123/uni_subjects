import random
import tkinter

canvas = tkinter.Canvas()
canvas.pack()
y = 50
n = int(input("Zadaj číslo: "))
nlen = len(str(int)) + 1
max_x = nlen * 20


while n > 0:
    max_x -= 20
    cifra = n % 10
    print(cifra)
    n //= 10
    canvas.create_rectangle(max_x, y, max_x - 10, y + 30, fill='light blue')
    canvas.create_text(max_x - 5, y + 15, text=f"{cifra}")

tkinter.mainloop()