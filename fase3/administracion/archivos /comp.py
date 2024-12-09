text_1 = """[[
  {
      "nombres": "Sofia",
      "apellidos": "Gonzalez",
      "fecha_de_nacimiento": "1994/06/28",
      "correo": "10sofia@G",
      "contraseña": "sofiapass"
  },
  {
      "nombres": "fase3_2preuba",
      "apellidos": "arriba",
      "fecha_de_nacimiento": "1994/06/28",
      "correo": "11fase3@",
      "contraseña": "sofiapass"
  },
  {
      "nombres": "Carlos",
      "apellidos": "Gomez",
      "fecha_de_nacimiento": "1990/05/12",
      "correo": "1carlos@G",
      "contraseña": "carlospass"
  },
  {
      "nombres": "Maria",
      "apellidos": "Lopez",
      "fecha_de_nacimiento": "1985/08/23",
      "correo": "2maria@L",
      "contraseña": "mariapass"
  },
  {
      "nombres": "Juan",
      "apellidos": "Martinez",
      "fecha_de_nacimiento": "1992/02/17",
      "correo": "3juan@M",
      "contraseña": "juanpass"
  },
  {
      "nombres": "Ana",
      "apellidos": "Hernandez",
      "fecha_de_nacimiento": "1995/11/30",
      "correo": "4ana@H",
      "contraseña": "anapass"
  },
  {
      "nombres": "Luis",
      "apellidos": "Perez",
      "fecha_de_nacimiento": "1988/04/09",
      "correo": "5luis@P",
      "contraseña": "luispass"
  },
  {
      "nombres": "Laura",
      "apellidos": "Ramirez",
      "fecha_de_nacimiento": "1993/09/05",
      "correo": "6laura@R",
      "contraseña": "laurapass"
  },
  {
      "nombres": "Jose",
      "apellidos": "Garcia",
      "fecha_de_nacimiento": "1991/07/14",
      "correo": "7jose@G",
      "contraseña": "josepass"
  },
  {
      "nombres": "Elena",
      "apellidos": "Torres",
      "fecha_de_nacimiento": "1987/12/22",
      "correo": "8elena@T",
      "contraseña": "elenapass"
  },
  {
      "nombres": "Miguel",
      "apellidos": "Rodriguez",
      "fecha_de_nacimiento": "1989/03/11",
      "correo": "9miguel@R",
      "contraseña": "miguelpass"
  },
  {
      "nombres": "Fase3",
      "apellidos": "Fase3",
      "fecha_de_nacimiento": "2000/02/20",
      "correo": "fase3@gio",
      "contraseña": "fase3"
  }
]]"""  # Reemplaza con el primer texto completo.
text_2 = """[[
  {
      "nombres": "Sofia",
      "apellidos": "Gonzalez",
      "fecha_de_nacimiento": "1994/06/28",
      "correo": "10sofia@G",
      "contraseña": "sofiapass"
  },
  {
      "nombres": "fase3_2preuba",
      "apellidos": "arriba",
      "fecha_de_nacimiento": "1994/06/28",
      "correo": "11fase3@",
      "contraseña": "sofiapass"
  },
  {
      "nombres": "Carlos",
      "apellidos": "Gomez",
      "fecha_de_nacimiento": "1990/05/12",
      "correo": "1carlos@G",
      "contraseña": "carlospass"
  },
  {
      "nombres": "Maria",
      "apellidos": "Lopez",
      "fecha_de_nacimiento": "1985/08/23",
      "correo": "2maria@L",
      "contraseña": "mariapass"
  },
  {
      "nombres": "Juan",
      "apellidos": "Martinez",
      "fecha_de_nacimiento": "1992/02/17",
      "correo": "3juan@M",
      "contraseña": "juanpass"
  },
  {
      "nombres": "Ana",
      "apellidos": "Hernandez",
      "fecha_de_nacimiento": "1995/11/30",
      "correo": "4ana@H",
      "contraseña": "anapass"
  },
  {
      "nombres": "Luis",
      "apellidos": "Perez",
      "fecha_de_nacimiento": "1988/04/09",
      "correo": "5luis@P",
      "contraseña": "luispass"
  },
  {
      "nombres": "Laura",
      "apellidos": "Ramirez",
      "fecha_de_nacimiento": "1993/09/05",
      "correo": "6laura@R",
      "contraseña": "laurapass"
  },
  {
      "nombres": "Jose",
      "apellidos": "Garcia",
      "fecha_de_nacimiento": "1991/07/14",
      "correo": "7jose@G",
      "contraseña": "josepass"
  },
  {
      "nombres": "Elena",
      "apellidos": "Torres",
      "fecha_de_nacimiento": "1987/12/22",
      "correo": "8elena@T",
      "contraseña": "elenapass"
  },
  {
      "nombres": "Miguel",
      "apellidos": "Rodriguez",
      "fecha_de_nacimiento": "1989/03/11",
      "correo": "9miguel@R",
      "contraseña": "miguelpass"
  },
  {
      "nombres": "Fase3",
      "apellidos": "Fase3",
      "fecha_de_nacimiento": "2000/02/20",
      "correo": "fase3@gio",
      "contraseña": "fase3"
  }
]]"""  # Reemplaza con el segundo texto completo.

# Comparación caracter por caracter
differences = [(i, text_1[i], text_2[i]) for i in range(min(len(text_1), len(text_2))) if text_1[i] != text_2[i]]

# Verifica si las longitudes son diferentes
if len(text_1) != len(text_2):
    print("Diferencia de longitud entre los textos.")
else:
    print("Las longitudes son iguales.")

# Muestra las diferencias
if differences:
    for index, char1, char2 in differences:
        print(f"Diferencia en el índice {index}: '{char1}' vs '{char2}'")
else:
    print("No se encontraron diferencias.")
