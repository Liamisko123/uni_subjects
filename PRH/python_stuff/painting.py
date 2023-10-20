import tkinter as tk
import time
def timeOut(delay=1):
    desired = time.time() + delay
    while True:
        print(time.time() - desired)
        if time.time() - desired > delay:
            print("here")
            return
def square(canvas, x, y, size, color):
    x1 = x
    y1 = y
    x2 = x + size
    y2 = y + size
    canvas.create_rectangle(x1, y1, x2, y2, fill=color)

root = tk.Tk()
canvas = tk.Canvas(root, width=500, height=500)
canvas.pack()

x, y = 50, 50
a1, a2 = 180, 100
offset = (180 - 100)/ 2

square(canvas, x, y, a1, "indian red")
square(canvas, x + offset, y + offset, a2, "light blue")
root.mainloop()

timeOut(3)
canvas.create_text(x, y, text="A", fill="black")
canvas.create_text(x + a1, y, text="B", fill="black")
canvas.create_text(x, y + a1, text="C", fill="black")
canvas.create_text(x + a1, y + a1, text="D", fill="black")

canvas.create_text(x + a1, y+ a1/2, text=str(a1), fill="black")
canvas.create_text(x + offset + a2/2, y + a1 - offset, text=str(a2), fill="black")

