"""
Conversor de PDF a BITS y viceversa
--

Programado por Thiago Grillo para el proyecto Col-Fi de Feria de Ciencias 2026

"""

from tkinter import filedialog
from os import system

def cls():
    system("cls")

def pdf_to_bits():
    """
    Convierte un PDF a una secuencia de bits (8 bits por byte)
    """
    pdf = filedialog.askopenfilename(title="Selecciona un PDF", filetypes=(("Archivo PDF", "*.pdf"),))
    with open(pdf, "rb") as f:
        data = f.read()

    bits = ''.join(f'{byte:08b}' for byte in data)

    with open("data_bits.txt", "w") as f:
        f.write(bits)

    cls()
    print(f"--- PDF convertido a bits correctamente. ---")
    print(f"Bytes originales: {len(data)}")
    print(f"Bits generados: {len(bits)}")


def bits_to_pdf():
    """
    Reconstruye un PDF desde una secuencia de bits
    """
    archivo_bits = filedialog.askopenfilename(title="Selecciona un texto", filetypes=(("Archivo texto", "*.txt"),))
    with open(archivo_bits, "r") as f:
        bits = f.read().strip()

    # Verificación
    if len(bits) % 8 != 0:
        raise ValueError("La cantidad de bits no es múltiplo de 8.")

    bytes_recuperados = bytearray()

    for i in range(0, len(bits), 8):
        byte = bits[i:i+8]
        bytes_recuperados.append(int(byte, 2))

    with open("documento_recuperado.pdf", "wb") as f:
        f.write(bytes_recuperados)

    cls()
    print("PDF reconstruido correctamente.")
    print(f"Bytes reconstruidos: {len(bytes_recuperados)}")

if __name__ == "__main__":
    cls()
    while(True):
        print("-----------------------------------------")
        print("--- CONVERSOR PDF A BITS / BITS A PDF ---")
        print("-----------------------------------------")
        print("Hecho por Thiago Grillo para Proyecto Col-Fi")
        print("")
        print("1. PDF a BITS")
        print("2. BITS a PDF")
        print("3. Salir")
        opt = input("> ")

        if (opt == "1"):
            pdf_to_bits()
        elif (opt == "2"):
            bits_to_pdf()
        elif (opt == "3"):
            exit()
        else:
            cls()
            print("Seleccione una opcion valida.")