import tkinter as tk
from tkinter import messagebox
import sqlite3

# Criar banco e tabela
conn = sqlite3.connect('clientes.db')
cursor = conn.cursor()
cursor.execute('''
CREATE TABLE IF NOT EXISTS clientes (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nome TEXT,
    cpf TEXT,
    telefone TEXT,
    endereco_coleta TEXT,
    endereco_entrega TEXT,
    valor REAL
)
''')
conn.commit()

# Função para salvar cliente
def salvar_cliente():
    nome = entry_nome.get()
    cpf = entry_cpf.get()
    telefone = entry_telefone.get()
    coleta = entry_coleta.get()
    entrega = entry_entrega.get()
    valor = entry_valor.get()

    if nome and cpf and telefone and coleta and entrega and valor:
        try:
            conn = sqlite3.connect('clientes.db')
            cursor = conn.cursor()
            cursor.execute('''
            INSERT INTO clientes (nome, cpf, telefone, endereco_coleta, endereco_entrega, valor)
            VALUES (?, ?, ?, ?, ?, ?)
            ''', (nome, cpf, telefone, coleta, entrega, float(valor)))
            conn.commit()
            conn.close()

            messagebox.showinfo("Sucesso", "Cliente cadastrado com sucesso!")
            limpar_campos()
        except ValueError:
            messagebox.showerror("Erro", "O valor deve ser numérico.")
    else:
        messagebox.showwarning("Aviso", "Preencha todos os campos!")

# Função para limpar campos
def limpar_campos():
    entry_nome.delete(0, tk.END)
    entry_cpf.delete(0, tk.END)
    entry_telefone.delete(0, tk.END)
    entry_coleta.delete(0, tk.END)
    entry_entrega.delete(0, tk.END)
    entry_valor.delete(0, tk.END)

# Criar janela
root = tk.Tk()
root.title("Cadastro de Clientes")
root.geometry("400x350")

# Labels e entradas
tk.Label(root, text="Nome:").pack()
entry_nome = tk.Entry(root, width=40)
entry_nome.pack()

tk.Label(root, text="CPF:").pack()
entry_cpf = tk.Entry(root, width=40)
entry_cpf.pack()

tk.Label(root, text="Telefone:").pack()
entry_telefone = tk.Entry(root, width=40)
entry_telefone.pack()

tk.Label(root, text="Endereço de Coleta:").pack()
entry_coleta = tk.Entry(root, width=40)
entry_coleta.pack()

tk.Label(root, text="Endereço de Entrega:").pack()
entry_entrega = tk.Entry(root, width=40)
entry_entrega.pack()

tk.Label(root, text="Valor:").pack()
entry_valor = tk.Entry(root, width=40)
entry_valor.pack()

# Botão salvar
tk.Button(root, text="Salvar Cliente", command=salvar_cliente).pack(pady=10)

root.mainloop()
