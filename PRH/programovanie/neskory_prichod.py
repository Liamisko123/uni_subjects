# chp   55 56 57 58 59 00 01
# bus            58 59 00 01 02
#index  00 01 02 03 04 05 06 07 08

KOEFICIENT = 1000   
chlapec = range(0, 7*KOEFICIENT)
pocet_moznosti = int()
pocet_uspechov = int()
for prichod in chlapec:
    for bus in range(3*KOEFICIENT, 8*KOEFICIENT):
        if prichod <= bus:
            pocet_uspechov += 1
        pocet_moznosti += 1

print(f"Pocet pokusov = {pocet_moznosti}")
print(f"Pocet neskorych prichodov = {pocet_moznosti - pocet_uspechov}")

print(abs((pocet_uspechov / pocet_moznosti) - 1))
