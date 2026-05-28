"""
Conversor de PDF a BITS y viceversa
--

Programado por Thiago Grillo para el proyecto Col-Fi de Feria de Ciencias 2026

"""

from tkinter import filedialog
from tkinter import messagebox
import os
import tkinter as tk
import webbrowser
import time

root = tk.Tk()
root.geometry("500x300")
root.resizable(False, False)
root.title("colFi. - Conversor de PDF a bytes")
#root.attributes("-toolwindow", True)

root.config(bg="#111212")
modo = tk.IntVar(value=0)

def pdf_to_bits():
    """
    Convierte un PDF a una secuencia de bits (8 bits por byte) 
    """
    try:
        pdf = filedialog.askopenfilename(title="Selecciona un PDF", filetypes=(("Archivo PDF", "*.pdf"),))
        log(f"Archivo seleccionado: {pdf}")
        with open(pdf, "rb") as f:
            data = f.read()
        log(f'Leyendo archivo...')

        filename = os.path.splitext(os.path.basename(pdf))[0]
        log(f"Iniciando conversión de {filename}...")
    except Exception as e:
        log("-------------------")
        log(f"ERROR: Hubo un error o la operación fue cancelada ({e}).")
        messagebox.showerror("Error", "ERROR: Hubo un error o la operacion fue cancelada ({e})")
        return
    
    log("Esperando por la ruta de destino...")
    try:
        path = filedialog.askdirectory(title="Selecciona la ruta de destino")
        bits = ''.join(f'{byte:08b}' for byte in data)
        log(f"Se generaron {len(bits)} bits")
        log("Creando archivo de cadena de bytes...")
        output_path = os.path.join(path, f"{filename}.txt")
        with open(output_path, "w") as f:
            f.write(bits)
    except Exception as e:
        log("-------------------")
        log(f"ERROR: Hubo un error o la operacion fue cancelada ({e})")
        messagebox.showerror("Error", f"ERROR: Hubo un error o la operacion fue cancelada ({e})")
        return

    log("La operación finalizó con éxito.")
    log("-------------------")
    messagebox.showinfo("Operacion exitosa", f"Se convirtió el archivo con éxito. Guardado en {path}")

def bits_to_pdf():
    """
    Reconstruye un PDF desde una secuencia de bits
    """
    try:
        txt_path = filedialog.askopenfilename(title="Selecciona un texto", filetypes=(("Archivo texto", "*.txt"),))
        log(f"Archivo seleccionado: {txt_path}")
        with open(txt_path, "r") as f:
            bits = f.read().strip()
        log(f'Leyendo archivo...')

        filename = os.path.splitext(os.path.basename(txt_path))[0]
    except Exception as e:
        log("-------------------")
        log(f"ERROR: Hubo un error o la operacion fue cancelada ({e})")
        messagebox.showerror("Error", f"ERROR: Hubo un error o la operacion fue cancelada ({e})")
        return

    # Verificación
    log(f"Verificando {filename}...")
    try:
        if len(bits) % 8 != 0:
            raise ValueError("La cantidad de bits no es múltiplo de 8.")
    except ValueError as e:
        log("-------------------")
        log(f"ERROR: {e}")
        messagebox.showerror("Error", f"ERROR: Hubo un error o la operacion fue cancelada ({e})")
        return
    
    log("Esperando por la ruta de destino...")
    try:
        path = filedialog.askdirectory(title="Selecciona la ruta de destino")
        log(f"Iniciando conversión de {filename}...")
        bytes_recuperados = bytearray()

        for i in range(0, len(bits), 8):
            byte = bits[i:i+8]
            bytes_recuperados.append(int(byte, 2))

        log(f"Se recuperaron {len(bytes_recuperados)} bytes")
        log("Creando archivo...")
        output_path = os.path.join(path, f"{filename}.pdf")
        with open(output_path, "wb") as f:
            f.write(bytes_recuperados)
    except Exception as e:
        log("-------------------")
        log(f"ERROR: Hubo un error o la operacion fue cancelada ({e})")
        messagebox.showerror("Error", f"ERROR: Hubo un error o la operacion fue cancelada ({e})")

    log("La operación finalizó con éxito.")
    log("-------------------")
    messagebox.showinfo("Operacion exitosa", f"Se convirtió el archivo con éxito. Guardado en {path}")

consola = tk.Text(
    root,
    height=8.5,
    width=67,
    bg="#0d0d0d",
    fg="#00ff88",
    state='disabled',
    wrap="word",
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
    tm = time.strftime("[%H:%M:%S]")
    consola.config(state="normal")
    consola.insert(tk.END, f'{tm} {text}\n')
    consola.see(tk.END)
    consola.config(state="disabled")

def start_conversion():
    global modo, consola
    consola.config(state="normal")
    consola.insert(tk.END, " \n")
    consola.config(state="disabled")
    if (modo.get() == 0):
        log("--- PDF a Bytes ---")
        log("Esperando por un archivo PDF...")
        pdf_to_bits()
    elif (modo.get() == 1):
        log("--- Bytes a PDF ---")
        log("Esperando por un archivo de cadena de bytes...")
        bits_to_pdf()
    else:
        log("ERROR!")

logo_text = tk.Label(
    root, 
    text="colFi. ------------------------------", 
    foreground="#fff", 
    background="#111212", 
    cursor="hand2", 
    font=('Arial', 28, 'italic bold')
)
logo_text.place(x=9, y=5)
def open_page(event):
    webbrowser.open("https://col-fi.netlify.app/")
logo_text.bind("<Button-1>", open_page)

select_text = tk.Label(
    root, 
    text="Seleccione su operacion", 
    foreground="#fff", 
    background="#111212", 
    font=('Arial', 9)
)
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

def open_gh(event):
    webbrowser.open("https://github.com/gr1ll0o/proyect-colfi.git")

github = tk.Label(
    root,
    text="GitHub",
    fg="blue",
    bg="#111212",
    cursor="hand2", 
    font=("Arial", 12, "underline")
)

github.place(x=425, y=4)
github.bind("<Button-1>", open_gh)

log('¡Pulsa el logo para ver la página del proyecto!')
log('Seleccione el modo deseado y presione "Convertir".')

if __name__ == "__main__":
    root.mainloop()
