from serial import*
from time import*


ser = Serial('COM1', 115200, bytesize=EIGHTBITS, parity=PARITY_NONE, stopbits=STOPBITS_ONE)  # open serial port

print(ser.name)# check which port was really used

mensaje_rx = ""
mensaje_tx = ""

# Inicializar variables
Punto = 0
quemador = 0
molino = 0
precalentador = 0
timeout = 0

dato_Rx = "" 
RX_CHECK_C = 0x00
CHECK_C = 0x2E  # Debes definir el valor de CHEK_C según tu lógica
CRC = 0x0C


T = 0
dR = 0 
NDB = 0
NDMAX = 0
NDMIN = 0 
NEQ = 0  
PEMP = 0
PETARA = 0
PIRMAX = 0
PIRNOM = 0
STALARM = 0
TCCORT = 0
TCFAlar = 0
TDMax = 0
tESTR = 0
TEXT = 0
TIRBP = 0
TIRC1 = 0
TIRC2 = 0
TIRC3 = 0
TIRNA = 0
TPCMAX = 0 
tPIR1 = 0
tPIR2 = 0
tPIR3 = 0
TMAN = 0 
TPIRO1 = 0 
TPIRO2 = 0 
TPIRO3 = 0 
TVUELC = 0 
Esc500 = 0 
Esc800 = 0 
Esc060 = 0 
EscMPX = 0 
EscNIV = 0 
dPIR = 0
ALARLAV = 0
ALARINM = 0


tCIC = 0x000
PIR = 0x000
TIR = 0x000
TIR1 = 0x00
TIR2 = 0x000
TIB = 0x000
TIP = 0x000
TCF = 0x000
TD = 0x000
ND = 0x000
DB = 0x0000
DA = 0x0000
ApSApSV = 0x000
ET = 0x00
tETAP = 0x000
FINAL = 0x000
RES1 = 0x000
RES2 = 0x000
RES3 = 0x000
SKTXT = 0x000000
SK = 0x00
CHECK_A = 0x00
RX_CHECK_A = 0x00
CHEK_P = 0x00

def generar_A(SKTXT, db, SK, RES1):
    global mensaje_tx
    global CHECK_A
    
    # Verificar y convertir las variables a cadenas hexadecimales
    SKTXT = f"{SKTXT:06x}"
    db = f"{db:04x}"
    SK = f"{SK:02x}"
    RES1 = f"{RES1:03x}"
    
    DB = db
    
    # Verificar que las cadenas hexadecimales tengan la longitud correcta
    if len(SKTXT) != 6 or len(db) != 4 or len(SK) != 2 or len(RES1) != 3:
        raise ValueError("Las variables no cumplen con el formato hexadecimal esperado.")
    

    # Calcular CHECK_A
    CHECK_A = (TIR2 + PIR + ApSApSV + tCIC + TIB + TIP + TCF + TD + ND +
               int(SKTXT, 16) + int(RES1, 16) + int(SK, 16) + DA + int(DB, 16) + ET + tETAP + FINAL) & 0x00FF

    # Crear el mensaje formateado
    mensaje_tx = "A={:03x}{:03x}{:03x}{:03x}{:03x}{:03x}{:03x}{:03x}{:03x}{:02x}{:03x}{:03x}{:04x}{:04x}{:03x}{:03x}{:03x}{:06x}{:02x}{:02x}\n".format(
        TIR2, PIR, ApSApSV, tCIC, TIB, TIP, TCF, TD, ND, ET, tETAP, FINAL, DA, int(DB, 16), 
        int(RES1, 16), RES2, RES3, int(SKTXT, 16), int(SK, 16), CHECK_A)

    return mensaje_tx
    

def check (mensaje):
    global Punto
    global RX_CHECK_C
    global CRC
    global CHECK_A
    global RX_CHECK_A
    global timeout
    
    mensaje = mensaje.decode()
    mensaje = mensaje.strip()
    

    if (Punto > 1 and Punto != 2):
        while (True):
            print(f"chequeando el mensaje: {mensaje}")

            if mensaje.startswith('H'):
                try:
                    RX_CHECK_A = int(mensaje[2:4], 16)
                    if RX_CHECK_A == CHECK_A:
                        print(f"RX_CHECK_A OKEY: {RX_CHECK_A:#x}")  # Mostrar el valor de RX_CHECK_A en hexadecimal
                        if Punto == 1:
                            Punto = 3
                        elif (Punto == 3):
                            Punto = 4
                        elif Punto == 4:
                            Punto = 5
#                         elif Punto == 5:
#                             Punto = 6
                        return
                    else:
                        print(f"No coincide CHECKSUM_A: {RX_CHECK_A:#x} y CHECK_A: {CHECK_A:#x}")
                        return
                except ValueError:
                    print("Valor inválido, debe ser hexadecimal.")
            else:
                print("No coincide CHECKSUM_A")
                return
    elif (Punto == 1):
        print(f"chequeando el mensaje: {mensaje}")

        if mensaje.startswith('H'):
            try:
                RX_CHECK_A = int(mensaje[2:4], 16)
                if RX_CHECK_A == 0x31:
                    print(f"RX_CHECK_A OKEY: {RX_CHECK_A:#x}")  # Mostrar el valor de RX_CHECK_A en hexadecimal
                    return
                else:
                    print(f"No coincide CHECKSUM_A: {RX_CHECK_A:#x} y CHECK_A: {CHECK_A:#x}")
                    return
            except ValueError:
                print("Valor inválido, debe ser hexadecimal.")
        else:
            print("No coincide CHECKSUM_A")
            return
    elif (Punto == 2):
    
        print(f"chequeando el mensaje: {mensaje}")
        
        if mensaje.startswith('H'):
            try:
                RX_CHECK_A = int(mensaje[2:4], 16)
                if RX_CHECK_A == 0x02:
                    print(f"RX_CHECK_A OKEY: {RX_CHECK_A:#x}")  # Mostrar el valor de RX_CHECK_A en hexadecimal
                    return
                else:
                    print(f"No coincide CHECKSUM_A: {RX_CHECK_A:#x} y CHECK_A: {CHECK_A:#x}")
                    return
            except ValueError:
                print("Valor inválido, debe ser hexadecimal.")
        elif mensaje.startswith('G'):
            print(f"Parametros: {mensaje}")
            return
        else:
            print("No coincide CHECKSUM_A")
            return
    
    elif (Punto == 0):
        while (True):
            print(f"chequeando el mensaje: {mensaje}")

            if mensaje.startswith('H'):
                try:
                    RX_CHECK_C = int(mensaje[2:4], 16)
                    if RX_CHECK_C == CRC:
                        print(f"RX_CHECK_C OKEY: {RX_CHECK_C:#x}")  # Mostrar el valor de CRC en hexadecimal
                        Punto = 1
                        return
                    else:
                        if timeout >= 10:
                            Punto = 2
                            timeout = 0
                            print("Cambiando Punto para editar parametros")
                        else:
                            timeout += 1
                        print(f"No coincide CHECKSUM_C: {RX_CHECK_C:#x}")
                        return
                except ValueError:
                    print("Valor inválido, debe ser hexadecimal.")
            else:
                print("No coincide letra inicial")
                return



for x in range(0, 4, 1):
    sleep(0.2)
    ser.write(f"{x}\n".encode())


sleep(1)

def send_msg():
    global mensaje_rx
    global mensaje_tx
    global RX_CHECK_A
    global CHECK_A
    
    while RX_CHECK_A != CHECK_A:
        ser.write(mensaje_tx.encode())
        sleep(0.4)
        mensaje_rx = ser.read_until('\n'.encode(), 90)
        check(mensaje_rx)
    RX_CHECK_A = 0x00
    print(f"Mensaje enviado: {mensaje_tx}")
    print(f"mensaje recibido: {mensaje_rx.decode()}")
    return




while(True):
    
    if Punto == 0:
        print(f"Punto {Punto}")
        while Punto == 0:
            mensaje_tx = ("C=010b{:02x}\n".format(CRC))
            ser.write(mensaje_tx.encode())
            sleep(0.2)
            mensaje_rx = ser.read_until('\n'.encode(), 60)
            check(mensaje_rx)
        print(f"Mensaje enviado: {mensaje_tx}")
        print(f"mensaje recibido: {mensaje_rx.decode()}")
    
    if Punto == 1:
        print(f"Punto {Punto}")
        mensaje_tx = ("A=00000000000000000000000000000000000000001110000000000000200031\n")
        while RX_CHECK_A != 0x31:
            ser.write(mensaje_tx.encode())
            sleep(0.4)
            mensaje_rx = ser.read_until('\n'.encode(), 60)
            check(mensaje_rx)
            print(f"Mensaje enviado: {mensaje_tx}")
            print(f"mensaje recibido: {mensaje_rx.decode()}")
        
        modulo = input("Elija opcion\n1 - SERVOS\n2- PARAMETROS\nOpcion: ")
        modulo = modulo.strip()
        try:
            modulo = int(modulo[0])
        except ValueError:
                    print("Valor inválido")
        
        if modulo == 1:
            Punto = 3
        elif modulo == 2:
            Punto = 2
    
    if Punto == 2:
        print(f"Punto {Punto}")
        sleep(0.4)
        
        SK = 2
        CHEK_A = 0x0C;
        
        mensaje_tx = (f"P={T:03x}{dR:03x}{NDB:03x}{NDMAX:03x}{NDMIN:03x}{NEQ:03x}{PEMP:03x}{PETARA:03x}"
          f"{PIRMAX:03x}{PIRNOM:03x}{STALARM:03x}{TCCORT:03x}{TCFAlar:03x}{TDMax:03x}{tESTR:03x}"
          f"{TEXT:03x}{TIRBP:03x}{TIRC1:03x}{TIRC2:03x}{TIRC3:03x}{TIRNA:03x}{TPCMAX:03x}"
          f"{tPIR1:03x}{tPIR2:03x}{tPIR3:03x}{TMAN:03x}{TPIRO1:03x}{TPIRO2:03x}{TPIRO3:03x}"
          f"{TVUELC:03x}{Esc500:03x}{Esc800:03x}{Esc060:03x}{EscMPX:03x}{EscNIV:03x}{dPIR:03x}"
          f"{ALARLAV:03x}{ALARINM:03x}{SK:02x}{CHEK_A:02x}\n")
        
        
        while RX_CHECK_A != CHEK_A:
            send_msg()
        
        SK = 0
        CHEK_A = 0x0C;
        
        mensaje_tx = (f"P={T:03x}{dR:03x}{NDB:03x}{NDMAX:03x}{NDMIN:03x}{NEQ:03x}{PEMP:03x}{PETARA:03x}"
          f"{PIRMAX:03x}{PIRNOM:03x}{STALARM:03x}{TCCORT:03x}{TCFAlar:03x}{TDMax:03x}{tESTR:03x}"
          f"{TEXT:03x}{TIRBP:03x}{TIRC1:03x}{TIRC2:03x}{TIRC3:03x}{TIRNA:03x}{TPCMAX:03x}"
          f"{tPIR1:03x}{tPIR2:03x}{tPIR3:03x}{TMAN:03x}{TPIRO1:03x}{TPIRO2:03x}{TPIRO3:03x}"
          f"{TVUELC:03x}{Esc500:03x}{Esc800:03x}{Esc060:03x}{EscMPX:03x}{EscNIV:03x}{dPIR:03x}"
          f"{ALARLAV:03x}{ALARINM:03x}{SK:02x}{CHEK_A:02x}\n")
            
        
        while RX_CHECK_A != CHEK_A:
            send_msg()
        
        while RX_CHECK_A != 0x02:
            mensaje_tx = ("A=00000000000000000000000000000000000000002000000000000000000202\n")
            send_msg()

        Punto = 1
        
        
    
    if Punto == 3:
        print(f"Punto {Punto}")
        DA = 0x0400
        mensaje_tx = generar_A(0x650321, 0x0100, 1, 0)
        send_msg()
        
        modulo = input("Ingrese SoftKey: ")
        modulo = modulo.strip()
        try:
            modulo = int(modulo[0])
        except ValueError:
                    print("Valor inválido")
        
        if modulo == 3:
            Punto = 4
        elif modulo == 6:
            Punto = 1
        
    if Punto == 4:
        print(f"Punto {Punto}")
        DA = 0x0800
        generar_A(0x650edc, 0x0333, 0, 0)
        send_msg()
        Punto = 5
        
        
    if Punto == 5:
        print(f"Punto {Punto}")
        modulo = input("Ingrese SoftKey: ")
        modulo = modulo.strip()
        try:
            modulo = int(modulo[0])
        except ValueError:
                    print("Valor inválido")
        
        if modulo == 1:
            if quemador == 0:
                quemador = 1
            else:
                quemador = 0
        elif modulo == 2:
            if molino == 0:
                molino = 1
            else:
                molino = 0
        elif modulo == 3:
            if precalentador == 0:
                precalentador = 1
            else:
                precalentador = 0
        elif modulo == 6:
            Punto = 3
            
        if Punto == 5:
            
            if modulo == 1 and quemador == 1:
                generar_A(0x650004, 0x0400, 0, 0) #Me lleva a la pantalla del quemador
                send_msg()
                SK = input("Ingrese SoftKey: ")
                SK = int(SK[0])
                if SK == 1:
                    generar_A(0x650000, 0x1500, 0, 0) #Inicia rutina de arranque
                    send_msg()
                    sleep(3)
                    modulo = 0
                    
            elif molino == 1 and modulo == 2:
                generar_A(0x650007, 0x0800, 0, 0) #Me lleva a la pantalla del molino
                send_msg()
                SK = input("Ingrese SoftKey: ")
                SK = int(SK[0])
                if SK == 1:
                    generar_A(0x650000, 0x1900, 0, 0) #Inicia rutina de arranque
                    send_msg()
                    sleep(3)
                    modulo = 0
            elif precalentador == 1 and modulo == 3:
                generar_A(0x650800, 0x0600, 0, 0) #Me lleva a la pantalla del precalentador
                send_msg()
                SK = input("Ingrese SoftKey: ")
                SK = int(SK[0])
                if SK == 3:
                    generar_A(0x650000, 0x1700, 0, 0) #Inicia rutina de arranque
                    send_msg()
                    sleep(3)
                    modulo = 0
            
            
            ESTADO = (quemador << 2 | molino << 1 | precalentador)
            
            match ESTADO:
                case 0:
                    DA = 0x0800
                    generar_A(0x650edc, 0x0333, 0, 0)
                case 1:
                    DA = 0x0830
                    generar_A(0x650bdc, 0x0300, 0, 0)
                case 2:
                    DA = 0x0BC0 # 0 - 4 - 8(tacho lleno 0b10) - 12 
                    generar_A(0x650eac, 0x0300, 0, 0)
                case 3:
                    DA = 0x0B30
                    generar_A(0x650bac, 0x0300, 0, 0)
                case 4:
                    DA = 0x0803
                    generar_A(0x650ed9, 0x0355, 0, 0)
                case 5:
                    DA = 0x0833
                    generar_A(0x650bd9, 0x0330, 0, 0)
                case 6:
                    DA = 0x0B03
                    generar_A(0x650ea9, 0x0330, 0, 0)
                case 7:
                    DA = 0x0B33
                    generar_A(0x650ba9, 0x0330, 0, 0)
            
            send_msg()
            
    
    sleep(1)
    
ser.close()             # close port

