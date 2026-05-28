"""
Conversor de PDF a BITS y viceversa
--

Programado por Thiago Grillo para el proyecto Col-Fi de Feria de Ciencias 2026

"""

from tkinter import filedialog
from os import system
import tkinter as tk
# from PIL import Image, ImageTk

root = tk.Tk()
root.geometry("500x300")
root.resizable = False
root.title("colFi. - Conversor de PDF a bytes")
#root.attributes("-toolwindow", True)

root.config(bg="#111212")
modo = tk.IntVar(value=0)

def cls():
    system("cls")

def pdf_to_bits():
    """
    Convierte un PDF a una secuencia de bits (8 bits por byte)
    """
    try:
        pdf = filedialog.askopenfilename(title="Selecciona un PDF", filetypes=(("Archivo PDF", "*.pdf"),))
        log(f"Archivo seleccionado: {pdf}")
        log(f'Leyendo archivo...')
        with open(pdf, "rb") as f:
            data = f.read()
        log(f"Iniciando conversión...")
    except Exception:
        log("-------------------")
        log("ERROR: Operación cancelada.")
        return

    bits = ''.join(f'{byte:08b}' for byte in data)
    log(f"Se generaron {len(bits)} bits")
    log("Creando archivo de cadena de bytes...")
    with open("data_bits.txt", "w") as f:
        f.write(bits)
    log("La operación finalizó con éxito.")
    log("-------------------")

def bits_to_pdf():
    """
    Reconstruye un PDF desde una secuencia de bits
    """
    try:
        archivo_bits = filedialog.askopenfilename(title="Selecciona un texto", filetypes=(("Archivo texto", "*.txt"),))
        with open(archivo_bits, "r") as f:
            bits = f.read().strip()
    except Exception:
        log("-------------------")
        log("ERROR: Operación cancelada.")
        return

    # Verificación
    if len(bits) % 8 != 0:
        raise ValueError("La cantidad de bits no es múltiplo de 8.")

    bytes_recuperados = bytearray()

    for i in range(0, len(bits), 8):
        byte = bits[i:i+8]
        bytes_recuperados.append(int(byte, 2))

    with open("documento_recuperado.pdf", "wb") as f:
        f.write(bytes_recuperados)

consola = tk.Text(
    root,
    height=8.5,
    width=67,
    bg="#0d0d0d",
    fg="#00ff88",
    state='disabled',
    insertbackground="white",  # color del cursor
    borderwidth=1,
    font=("Consolas", 9)
)
consola.place(x=12, y=164)

scroll = tk.Scrollbar(root)
scroll.place(x=480, y=164, height=130)
scroll.config(command=consola.yview)

def log(text):
    global consola
    consola.config(state="normal")
    consola.insert(tk.END, f'{text}\n')
    consola.see(tk.END)
    consola.config(state="disabled")

def start_conversion():
    global modo

    if (modo.get() == 0):
        log("--- PDF a Bytes ---")
        log("Esperando por un archivo PDF..")
        pdf_to_bits()
    elif (modo.get() == 1):
        log("--- Bytes a PDF ---")
    else:
        log("ERROR!")

'''
img_logo = tk.PhotoImage(master=root, file="colFi.png")
img_logo
img_logo_label = tk.Label(root, image=img_logo, background="#111212")
img_logo_label.pack()
'''

logo_text = tk.Label(root, text="colFi. ------------------------------", foreground="#fff", background="#111212", font=('Arial', 28, 'italic bold'))
logo_text.place(x=9, y=5)

select_text = tk.Label(root, text="Seleccione su operacion", foreground="#fff", background="#111212", font=('Arial', 9))
select_text.place(x= 185, y=55)

tk.Radiobutton(
    root,
    text="PDF a Bytes",
    variable=modo,
    value=0,
    bg="#111212",
    fg="white",
    selectcolor="#2b2b2b",   # color del círculo seleccionado
    activebackground="#111212",
    activeforeground="white",
    highlightthickness=0
).place(x=155, y=75)
tk.Radiobutton(
    root,
    text="Bytes a PDF",
    variable=modo,
    value=1,
    bg="#111212",
    fg="white",
    selectcolor="#2b2b2b",
    activebackground="#111212",
    activeforeground="white",
    highlightthickness=0
).place(x=255, y=75)

# CONVERT BUTTON
boton_convertir = tk.Button(
    root,
    text="Convertir",
    bg="#2b2b2b",
    fg="white",
    activebackground="#3a3a3a",
    activeforeground="white",
    borderwidth=0,
    padx=20,
    pady=10,
    cursor="hand2",
    command=start_conversion
)
boton_convertir.place(x=205, y= 110)

log('Seleccione el modo deseado y presione "Convertir".')

if __name__ == "__main__":
    root.mainloop()
