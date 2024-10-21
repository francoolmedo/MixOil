from serial import*
from time import*


ser = Serial('COM14', 115200, bytesize=EIGHTBITS, parity=PARITY_NONE, stopbits=STOPBITS_ONE)  # open serial port

print(ser.name)# check which port was really used

mensaje_rx = ""
mensaje_tx = ""

# Inicializar variables
Punto = 0
dato_Rx = "" 
RX_CHECK_C = 0x00
CHECK_C = 0x2E  # Debes definir el valor de CHEK_C según tu lógica
CRC = 0x01

tCIC = 0x005
PIR = 0x006
TIR = 0x008
TIR1 = 0x045
TIR2 = 0x010
TIB = 0x100
TIP = 0x002
TCF = 0x003
TD = 0x007
ND = 0x009
DB = 0x0000
DA = 0x0000
ApSApSV = 0x00A
ET = 0x02
tETAP = 0x000
FINAL = 0x000
RES1 = 0x004
RES2 = 0x005
RES3 = 0x008
SKTXT = 0x000000
SK = 0x00
CHECK_A = 0x00

def generar_A(SKTXT, db, SK, RES1):
    global mensaje_tx
    
    # Verificar y convertir las variables a cadenas hexadecimales
    SKTXT = f"{SKTXT:06x}"
    db = f"{db:04x}"
    SK = f"{SK:02x}"
    RES1 = f"{RES1:03x}"
    
    # Verificar que las cadenas hexadecimales tengan la longitud correcta
    if len(SKTXT) != 6 or len(db) != 4 or len(SK) != 2 or len(RES1) != 3:
        raise ValueError("Las variables no cumplen con el formato hexadecimal esperado.")
    
    # Calcular CHECK_A usando las variables como enteros
    CHECK_A = (TIR2 + PIR + ApSApSV + tCIC + TIB + TIP + TCF + TD + ND +
               int(SKTXT, 16) + int(RES1, 16) + int(SK, 16) + DA + DB + ET + tETAP + FINAL) & 0x00FF

    # Crear la cadena de texto en el formato equivalente
    mensaje_tx = "A={:03x}{:03x}{:03x}{:03x}{:03x}{:03x}{:03x}{:03x}{:03x}{:02x}{:03x}{:03x}{:04x}{:04x}{:03x}{:03x}{:03x}{:06x}{:02x}{:02x}\n".format(
        TIR2, PIR, ApSApSV, tCIC, TIB, TIP, TCF, TD, ND, ET, tETAP, FINAL, DA, DB, 
        int(RES1, 16), RES2, RES3, int(SKTXT, 16), int(SK, 16), CHECK_A)
    

def check (mensaje, punto):
    global RX_CHECK_C
    global CHECK_C
    global CRC
    
    if (punto == 1):
        while (True):
            print(f"chequeando el mensaje: {mensaje}")

            if mensaje.startswith("H="):
                try:
                    RX_CHECK_C = int(mensaje[2:4], 16)
                    print(f"RX_CHECK_C recibido: {RX_CHECK_C:#x}")  # Mostrar el valor de RX_CHECK_C en hexadecimal
                    return
                except ValueError:
                    print("Valor inválido, debe ser hexadecimal.")
                    
    elif (punto == 0):
        while (True):
            print(f"chequeando el mensaje: {mensaje}")

            if mensaje.startswith("C="):
                try:
                    CRC = int(mensaje[2:4], 16)
                    print(f"CRC recibido: {CRC:#x}")  # Mostrar el valor de CRC en hexadecimal
                    return
                except ValueError:
                    print("Valor inválido, debe ser hexadecimal.")




while(True):
    if Punto == 0:
        mensaje_tx = ("C=01c8{:02x}\n".format(CRC))
        ser.write(mensaje_tx.encode())
        mensaje_rx = ser.read_until('\n', 50)
        check(mensaje_rx, 0)
        Punto = 1
    
    if Punto == 1:
        mensaje_rx = ser.read_until('\n', 50)
        check(mensaje_rx, 1)
        Punto = 2
    
#     if Punto = 2:
#         
                
    
#     
#     generar_A(0x650321, 0x0100, 0x01, 0x000)
#     print(f"mensaje por enviar: {mensaje_tx}")
#     
#     # Convertir la cadena a bytes y enviarla por el puerto serial
#     ser.write(mensaje_tx.encode())
#     mensaje_rx = ser.read_until('\n', 50)
#     
#     print(f"mensaje enviado: {mensaje_tx}")
#     print(f"mensaje recibido: {mensaje_rx}")
#     
    sleep(1)
    
ser.close()             # close port

