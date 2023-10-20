import tkinter as tk

if __name__ == "__main__":
    start, increment, sum = map(int, input("Enter the starting length, increment, and sum of all lengths: ").split())

    root = tk.Tk()
    canvas = tk.Canvas(root, width=800, height=800)
    canvas.pack()

    initial_increment = increment
    line_length = start
    x, y = 150, 150
    current_sum = 0

    canvas.create_line(x, y, x + line_length, y, fill="black")
    x += line_length
    current_sum += line_length
    line_length += initial_increment

    while current_sum < sum :
        current_line_length = 0
        while current_sum < sum and current_line_length < line_length:
            canvas.create_line(x, y, x, y + 1, fill="black")
            current_line_length += 1
            y += 1
            current_sum += 1
        line_length += initial_increment

        current_line_length = 0
        while current_sum < sum and current_line_length < line_length:
            canvas.create_line(x, y, x - 1, y, fill="black")
            current_line_length += 1
            x -= 1
            current_sum += 1
        line_length += initial_increment
        
        current_line_length = 0
        while current_sum < sum and current_line_length < line_length:
            canvas.create_line(x, y, x, y - 1, fill="black")
            current_line_length += 1
            y -= 1
            current_sum += 1
        line_length += initial_increment
        
        current_line_length = 0
        while current_sum < sum and current_line_length < line_length:
            canvas.create_line(x, y, x + 1, y, fill="black")
            current_line_length += 1
            x += 1
            current_sum += 1
        line_length += initial_increment

    root.mainloop()