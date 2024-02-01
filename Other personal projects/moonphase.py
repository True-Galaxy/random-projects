# Calculates the moon phase given a date. Algorithm from https://www.subsystems.us/uploads/9/8/9/4/98948044/moonphase.pdf

# Retrieve user input and parse at the / character
userin = input("Please input the current date in MM/DD/YYYY: ")
data = userin.split("/")

m = int(data[0])
d = int(data[1])
y = int(data[2])

if m <= 2:
    m += 12
    y -= 1

#Calculating the Julian Date
a = y / 100
b = a / 4
c = 2 - a + b
e , f = 365.25 * (y + 4716), 30.6001 * (m + 1)
Julian = c + d + e + f - 1524.5

#Days since new moon
CycleDay = Julian - 2451549.5
Cycles = int(CycleDay) / 29.53
SinceNewMoon = (Cycles % 1) * 29.53

if SinceNewMoon < 3.69125:
    print("Waxing Crescent")
elif SinceNewMoon < 7.3825:
    print("First Quarter")
elif SinceNewMoon < 11.07375:
    print("Waxing Gibbous")
elif SinceNewMoon < 14.765:
    print("Full Moon")
elif SinceNewMoon < 18.45625:
    print("Waning Gibbous")
elif SinceNewMoon < 22.1475:
    print("Last Quarter")
else:
    print("Waning Crescent")

#Sourced from https://www.napea.info/hawaiian-moon-names
Moons = {
    1: "Hilo",
    2: "Hoaka",
    3: "Kūkahi",
    4: "Kūlua",
    5: "Kūkolu",
    6: "Kūpau",
    7: "ʻOlekūkahi",
    8: "ʻOlekūlua",
    9: "ʻOlekūkolu",
    10: "ʻOlepau",
    11: "Huna",
    12: "Mohalu",
    13: "Hua",
    14: "Akua",
    15: "Hoku",
    16: "Māhealani",
    17: "Kulu",
    18: "Lāʻaukūkahi",
    19: "Lāʻaukūlua",
    20: "Lāʻaupau",
    21: "ʻOlekūkahi",
    22: "ʻOlekūlua",
    23: "ʻOlekūkolu",
    24: "ʻOlepau",
    25: "Kāloakūkahi",
    26: "Kāloakūlua",
    27: "Kāloapau",
    28: "Kāne",
    29: "Lono",
    30: "Mauli",
    31: "Muku"
}

print(Moons[round(SinceNewMoon*1.04977988486)])