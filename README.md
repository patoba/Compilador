# Compilador

## Integrantes del Equipo

El equipo está formado formado por:
* *Adolfo Patricio Barrero Olguín*
* *Emanuel Flores Martínez*

## Estructura del Proyecto

* **entrada.pato:** La entrada del programa
* **codigo_intermedio.o:** Codigo intermedio generado por el complador
* **ensamblador.asm:** Codigo objeto generado por el compilador
* **lexer.l:** Contiene el analizador lexico del compilador, encargado de detectar cadenas bien escritas del mismo
* **parser.y:** Contiene el analizar sintáctico y semántico del compilador
* **main:** Engloba todos los archivos

## Proceso de Compilación y Ejecución

### Forma 1 (Automatica)

1. Compilamos (es necesario tener make instalado)

```
$ make
```

2. Ejecutar el compilador con la entrada

```
$ ./main.out ubicacion_entrada
```

**Nota:** En la carpeta "entrada" hay entradas disponibles

### Forma 2 (Manual)

1. Compilar el analizador léxico (*lexer.l*)

```
$ flex lexer.l
```

2. Compilar el analizador semántico (*parser.y*)

```
$ byacc -d parser.y
```

3. Compilar todos los archivos

```
gcc lex.yy.c y.tab.c tabla_simbolos.c tabla_tipos.c tipos.c cuadruplas.c backpatch.c pila_dir.c main.c -o main.out
```

4. Ejecutar el compilador con la entrada

```
$ ./main.out ubicacion_entrada
```

**Nota:** En la carpeta "entrada" hay entradas disponibles

## Grámatica

**sin: sin tipo, car: tipo caracter**
1. programa → declaraciones funciones

2. declaraciones → tipo lista_var; declaraciones
| tipo_registro lista_var; declaraciones | ε

3. tipo_registro → **estructura inicio** declaraciones **fin**

4. tipo → base tipo_arreglo

5. base → **ent** | **real** | **dreal** | **car** | **sin***

6. tipo_arreglo → **[num]** tipo_arreglo | ε

7. lista_var → lista_var **, id** | **id**

8. funciones → **def** tipo **id(** argumentos **)  inicio** declaraciones sentencias **fin** funciones | ε

9. argumentos → listar_arg | **sin**

10. lista_arg → lista_arg, arg | arg

11. arg → tipo_arg **id**

12. tipo_arg → base param_arr

13. param_arr → **[]** param_arr | ε

14. sentencias → sentencias sentencia | sentencia

15. sentencia → **si** e_bool **entonces** sentencia **fin**
| **si** e_bool **entonces** sentencia **sino** sentencia **fin**
| **mientras** e_bool **hacer** sentencia **fin**
| **hacer** sentencia **mientras** e_bool;
| **segun (**variable **) hacer** casos predeterminado **fin**
| variable **:=** expresion **;**
| **escribir** expresion **;**
| **leer** variable **;** | **devolver;**
| **devolver** expresion **;**
| **terminar;**
| **inicio** sentencias **fin**

16. casos → **caso num:** sentencia casos | **caso num:** sentencia

17. predeterminado → **pred:** sentencia | ε

18. e_bool → e_bool **o** e_bool | e_bool **y** e_bool | **no** e_bool
| relacional_op | **verdadero** | **falso**

19. relacional_op → relacional > relacional
| relacional < relacional
| relacional <= relacional
| relacional >= relacional
| relacional <> relacional
| relacional = relacional
| expresion

20. expresion → expresion + expresion
| expresion − expresion
| expresion ∗ expresion
| expresion / expresion
| expresion % expresion | **(** expresion **)** | variable | **num** | **cadena** | **caracter**

21. variable → **id** variable_comp

22. variable_comp → dato_est_sim | arreglo | **(** parametros **)**

23. dato_est_sim → dato_est_sim **.id** | ε

24. arreglo → **[** expresion **]** | arreglo **[** expresion **]**

25. parametros → lista_param | ε

26. lista_param → lista_param, expresion | expresion

## Definición Dirigida por Sintaxis

### programa → declaraciones funciones

```
STS.push(newTS())
STT.push(newTT())
dir = 0
programa.codigo = funciones.codigo 
```
### declaraciones → tipo lista var; declaraciones
```
typeGBL = tipo.type
```

### declaraciones → tipo_registro lista_var; declaraciones
```
typeGBL= tipo_registro.type
```

### declaraciones → ε

### tipo registro → **estructura inicio** declaraciones **fin**
```
STS.push(newTS())
STT.push(newTT())
SDir.push(dir)
dir = 0
SymTab = STS.pop()
SymTab.typeTab = STT.pop()
tam = getTam(SymTab)
dir = SDir.pop()
tipo registro.type = STT.getTop().insert(”struct”, tam, SymTab )
```

###  tipo → base tipo_arreglo
```
baseGBL = base.base
tipo.type = tipo_arreglo.type
```

### base → ent 
```
base.base = STT.getTop().getType(’ent’)
```

### base → real 
```
base.base = STT.getTop().getType(’real’)
```

### base → dreal 
```
base.base = STT.getTop().getType(’dreal’)
```

### base → car 
```
base.base = STT.getTop().getType(’car’)
```

### base → sin 
```
base.base = STT.getTop().getType(’sin’)
```

### tipo_arreglo → **[num]** tipo_arreglo1 
```
Si num.type = ent Entonces
    Si num.dir > 0 Entonces
        tipo arreglo.type =
        STT.getTop().insert(’array’,num, tipo arreglo1.tipo)
    Sino
        error(’...’)
    Fin Si
Sino
    error(’...’)
Fin Si
```
### tipo arreglo → ε
```
tipo_arreglo.type = baseGBL
``` 

### lista_var → lista_var1 **, id**
```
Si STS.getTop().existe(id) Entonces
    STS.getTop().insert(id, typeGBL, dir, ’var’, null, null )
    dir ← dir + STT.getTop().getTam(typeGBL)
Sino
    error(’...’)
Fin Si
```

### lista var → **id**
```
Si STS.getTop().existe(id) Entonces
    STS.getTop().insert(id, typeGBL, dir, ’var’, null, null )
    dir ← dir + STT.getTop().getTam(typeGBL)
Sino
    error(’...’)
Fin Si
```
### funciones → **def** tipo **id(** argumentos **)  inicio** declaraciones sentencias **fin** funciones

```
Si no STS.getGlobal().existe(id) Entonces
    STS.push(newTS())
    STT.push(newTT())
    SDir.push(dir)
    dir = 0
    listaRET = newListRet()
    Si cmpRet(lista retorno, tipo.type) Entonces
        L = newLabel()
        backpatch(sentencias.nextlist, L)
        genCode(label L)
        STS.pop()
        STT.pop()
    Sino
        error(’...’)
    Fin Si
Sino
    error(’...’)
Fin Si
```
### funciones → ε

### argumentos → listar_arg
```
argumentos.lista = lista arg.lista
argumentos.num = lista arg.num
```

### argumentos → **sin**
```
argumentos.lista = NULO
argumentos.num = 0
```
### lista_arg → lista_arg1 , arg 
```
lista_arg.lista = lista_arg1.lista
lista_arg.lista.append(arg.type)
lista_arg.num = lista_arg1.num + 1
```
### lista_arg → arg
```
lista_arg.lista = newList()
lista_arg.lista.append(arg.type)
lista_arg.num = 1
```
### arg → tipo_arg **id**
```
Si no STS.getTop().existe(id) Entonces
    STS.getTop().append(id, tipo.type, dir, ’arg’, NULO, NULO)
    dir←dir + STT.getTop().getTam(tipo.type)
    arg.type = tipo.type
Sino
    error(...)
Fin Si
```
### tipo_arg → base param_arr
```
baseGBL = base.base
tipo.type = param_arr.type
```
### param_arr → **[]** param_arr
```
param_arr.type = STT.getTop().insert(’array), 0, param_arr1.tipo)
```
### param_arr → ε
```
param_arr.type = baseGBL
```
### sentencias → sentencias1 sentencia
```
L = newLabel()
backpatch(sentencias1.nextlist, L)
genCode(label L)
```
### sentencia → **si** e_bool **entonces** sentencia1 **fin**
```
L = newLabel()
backpatch(e bool.truelist, L)
sentencia.nextlist = combinar(e bool.falselist, sentencia1.nextlist)
genCode(label L)
```

### sentencia → **si** e_bool **entonces** sentencia1 **sino** sentencia2 **fin**
```
L1 = newLabel()
L2 = newLabel()
backpatch(e bool.truelist, L1)
backpatch(e bool.falselist, L2)
sentencia.nextlist = combinar(sentencia1.nextlist, sentencia2.nextlist)
genCode(label L1)
genCode(’goto’ sentencia1.nextlist[0])
genCode(label L2)
```
### sentencia → **mientras** e_bool **hacer** sentencia1 **fin**
```
L1 = newLabel()
L2 = newLabel()
backpatch(sentencia1.nextlist, L1)
backpatch(e bool.truelist, L2)
sentencia.nextlist = e bool.falselist
genCode(label L1)
genCode(label L2)
genCode(’goto’ sentencia1.nextlist[0])
```
### sentencia → **hacer** sentencia1 **mientras** e_bool;
```
L = newLabel()
genCode(”label” L)
batckbatch(sentencia1.nextlist, L)
```
### sentencia → **segun (** variable **) hacer** casos predeterminado **fin**
```
L1 = newLabel()
prueba = combinar(casos.prueba,predeterminado.prueba)
backpatch(casos.nextlist, L2)
sustituir(”??”, variable.dir, prueba)
```
### sentencia → variable **:=** expresion **;**
```
dir = reducir(expresion.dir, epresion.type, variable.type)
Si variable.code est = true Entonces
    genCode(variable.base’[’variable.des’]’ ’=’ dir)
Sino
    genCode(variable.dir ’=’ dir)
Fin Si
```
### sentencia → **escribir** expresion **;**
```
gen(”write” expresion.dir)
```
### sentencia → **leer** variable **;** 
``` 
gen(”read” variable.dir)
```
### sentencia → **devolver;**
```
genCode(”return”)
```
### sentencia → **devolver** expresion **;**
```
genCode(”return” expresion.dir)
```
### sentencia → **terminar;**
```
index = newIndex()
sentencia.nextlist = newIndexList(index)
genCode(”goto” index)
```
### sentencia → **inicio** sentencias1 **fin**
```
sentencia.nextlist = sentencia1.nextlist
```
### casos → **caso num:** sentencia casos1
```
casos.nextlist = combinar(casos.nextlist, sentencia1.nextlist)
L = newLabel()
/*Indica el inicio del codigo para la sentencia*/ ´
genCode(”label” L)
casos.prueba = casos1.prueba
casos.prueba.append(if ”??” ”==” num.dir ”goto” L )
```
### casos → **caso num:** sentencia
```
casos.prueba = newCode()
L = newLabel()
/*Indica el inicio del codigo para la sentencia*/ ´
genCode(”label” L)
casos.prueba.append(if ”??” ”==” num.dir ”goto” L )
casos.nextlist = sentencia.nextlist
```
### predeterminado → **pred:** sentencia
```
predeterminado.prueba = newCode()
L = newLabel()
/*Indica el inicio del codigo para la sentencia*/ ´
genCode(”label” L)
predeterminado.prueba.append(”goto” L)
```
### predeterminado → ε
```
pretederminado.prueba = NULO
```
### e_bool → e_bool1 **o** e_bool2
```
L = newLabel()
backpatch(e_bool1.falselist, L)
e_bool.truelist = combinar(e_bool1.truelist,e_bool2.truelist)
e_bool.falselist = e_bool2.falselist
genCode(label L)
```
### e_bool → e_bool1 **y** e_bool2
```
L = newLabel()
backpatch(e_bool1.truelist, L)
e_bool.truelist = e_bool1.truelist
e_bool.falselist = combinar(e_bool1.falselist, e_bool2.falselist)
genCode(label L)
```
### e_bool → **no** e_bool
```
e_bool.truelist = e_bool1.falselist
e_bool.falselist = e_bool.truelist
```
### e_bool → relacional_op
```
e bool.truelist = relacional_op.truelist
e bool.falselist = relacional_op.falselist
```
### e_bool → **verdadero**
```
index0 = newIndex()
e bool.truelist = newIndexList(index0)
genCode(’goto’ index0)
```
### e_bool → **falso**
```
index0 = newIndex()
e bool.falselist = newIndexList(index0)
genCode(’goto’ index0)
```
### relacional_op → relacional1 > relacional2 
```
index0 = newIndex()
index1 = newIndex()
relacional.truelist = newIndexList(index0)
relacional.falselist = newIndexList(index1)
genCode(’if’ relacional1.dir > relacional2 ’goto’ index0)
genCode(’goto’ index1)
```
### relacional_op → relacional1 < relacional2
```
index0 = newIndex()
index1 = newIndex()
relacional.truelist = newIndexList(index0)
relacional.falselist = newIndexList(index1)
genCode(’if’ relacional1.dir < relacional2 ’goto’ index0)
genCode(’goto’ index1)
```
### relacional_op → relacional1 <= relacional2
```
index0 = newIndex()
index1 = newIndex()
relacional.truelist = newIndexList(index0)
relacional.falselist = newIndexList(index1)
genCode(’if’ relacional1.dir <= relacional2 ’goto’ index0)
genCode(’goto’ index1)
```
### relacional_op → relacional1 >= relacional2
```
index0 = newIndex()
index1 = newIndex()
relacional.truelist = newIndexList(index0)
relacional.falselist = newIndexList(index1)
genCode(’if’ relacional1.dir >= relacional2 ’goto’ index0)
genCode(’goto’ index1)
``` 
### relacional_op → relacional <> relacional
```
index0 = newIndex()
index1 = newIndex()
relacional.truelist = newIndexList(index0)
relacional.falselist = newIndexList(index1)
genCode(’if’ relacional1.dir > relacional2 ’goto’ index0)
genCode(’goto’ index1)
```
### relacional → expresion
```
relacional.dir = expresion.dir
relacional.tipo = expresion.tipo
```
### expresion → expresion1 + expresion2 
```
expresion.type = max(expresion1.type, expresion2.type)
expresion.dir = newTemp()
dir1 = ampliar(expresion1.dir, epxresion1.type,expresion.type)
dir2 = ampliar(expresion2.dir, epxresion2.type,expresion.type)
getCode(expresion.dir ’=’ dir1 ’+’ dir2)
```
### expresion → expresion1 − expresion2 
```
expresion.type = max(expresion1.type, expresion2.type)
expresion.dir = newTemp()
dir1 = ampliar(expresion1.dir, epxresion1.type,expresion.type)
dir2 = ampliar(expresion2.dir, epxresion2.type,expresion.type)
getCode(expresion.dir ’=’ dir1 ’-’ dir2)
```
### expresion → expresion1 ∗ expresion2
```
expresion.type = max(expresion1.type, expresion2.type)
expresion.dir = newTemp()
dir1 = ampliar(expresion1.dir, epxresion1.type,expresion.type)
dir2 = ampliar(expresion2.dir, epxresion2.type,expresion.type)
getCode(expresion.dir ’=’ dir1 ’*’ dir2)
```
### expresion → expresion1 / expresion2
```
expresion.type = max(expresion1.type, expresion2.type)
expresion.dir = newTemp()
dir1 = ampliar(expresion1.dir, epxresion1.type, expresion.type)
dir2 = ampliar(expresion2.dir, epxresion2.type, expresion.type)
getCode(expresion.dir ’=’ dir1 ’/’ dir2)
```
### expresion → expresion1 % expresion2
```
Si expresion1.type = entero and expresion2.type = entero Entonces   
    expresion.type = max(expresion1.type, expresion2.type)
    expresion.dir = newTemp()
    dir1 = ampliar(expresion1.dir, epxresion1.type,expresion.type)
    dir2 = ampliar(expresion2.dir, epxresion2.type,expresion.type)
    getCode(expresion.dir ’=’ dir1 ’+’ dir2)
Sino
    error(’...’)
Fin Si
```
###  expresion → **(** expresion1 **)**
```
epxresion.type = expresion1.type
expresion.dir = expresion1.dir
```
###  expresion → variable
```
expresion.type = variable.type
expresion.dir = variable.dir
```
### expresion → **num**
```
epxresion.type = num.type
expresion.dir = num.dir
```
### expresion → **cadena**
```
expresion.type =’string’
Si TablaCadenas.existe(cadena) Entonces
    expresion.dir= TablaCadena.getIndexStr(cadena)
Sino
    expresion.dir=TalbaCadena.insert(cadena)
Fin Si
```
### expresion → **caracter**
```
expresion.type =’car’
Si TablaCadenas.existe(car) Entonces
    expresion.dir= TablaCadena.getIndexStr(car)
Sino
    expresion.dir=TalbaCadena.insert(car)
Fin Si
```
### variable → **id** variable_comp
```
Si STS.getTop().existe(id) Entonces
    IDGBL = id
    Si variable com.code est=true Entonces
        variable.dir=newTemp()
        variable.type = variable com.type
        genCode(variable.dir ’=’ id’[’ variable com.des’]’)
        variable.base = id.dir
        variable.code est= true
        variable.des = variable com.des
    Sino
        variable.dir = id)
        variable.type = STS.getTop().getType(id)
        variable.code est= false
Sino
    error(’...’)
Fin Si
```
### variable_comp → dato_est_sim
```
variable_comp.type = dato_est_sim.type
variable_comp.des = dato_est_sim.des
variable_comp.code_est = dato_est_sim.code_est
```
### variable_comp → arreglo
```
variable_comp.type = arreglo.type
variable_comp.des = arreglo.dir
variable_comp.code_est = true
```
### variable_comp → **(** parametros **)**
```
Si STS.getGlobal().getVar(IDGBL)= ’func’ Entonces
    lista = STS.getGlobal().getListaArgs(IDGBL)
    num = STS.getGlobal().
    Si
```
### dato_est_sim → dato_est_sim **.id**
```
Si dato_est_sim1.estructura = true Entonces
    Si dato_est_sim1.tabla.existe(id) Entonces
        dato_est_sim.des = dato_est_sim1.des + dato_est_sim.tabla1.getDir(id)
        typeTemp=dato est sim1.tabla.getType(id)
        estTemp = dato_est_sim1.tabla.tablaTipos.getName(typeTemp)
        Si estTemp = ’struct’ Entonces
            dato_est_sim.estructura= true
            dato_est_sim.tabla= dato_est_sim.tabla.tablaTipos.getTipoBase(typeTemp).tabla
        Sino
            dato_est_sim.estructura= false
            dato_est_sim.tabla= NULO
            dato_est_sim.type = dato_est_sim1.tabla.getType(id)
        FinSi
        dato_est_sim.code est=true
    Sino
        error(...)
    FinSi
Sino
    error(...)
FinSi
```
### dato_est_sim → ε
```
typeTemp = STS.getTop().getType(id)
Si STT.getTop().getName(typeTemp) =’struct’ Entonces
    dato_est_sim.estructura= true
    dato_est_sim.tabla= STT.getTop().getTipoBase(typeTemp).tabla
    dato_est_sim.des = 0
Sino
    dato_est_sim.estructura= false
    dato_est_sim.type = STT.getTop().getType(id)
Fin Si
dato_est_sim.code_est=false
```
### arreglo → **[** expresion **]**
```
arreglo.type = STS.getTop().getType(IDGBL)
Si STT.getTop().getName(arreglo.type) = ’array’ Entonces
    Si expresion.type = entero Entonces
        typeTemp = STT.getTop().getTypeBase(arreglo.type)
        tam = STT.getTop().getTam(typeTemp)
        arreglo.dir = newTemp()
        genCode(arreglo.dir’=’ expresion.dir ’*’ tam)
    Sino
        error(...)
    Fin Si
Sino
    error(...)
Fin Si
```
### arreglo → arreglo1 **[** expresion **]**
```
arreglo.type = STS.getTop().getType(arreglo1.type)
Si STT.getTop().getName(arreglo.type) = ’array’ Entonces
    Si expresion.type = entero Entonces
        typeTemp = STT.getTop().getTypeBase(arreglo.type)
        tam = STT.getTop().getTam(typeTemp)
        dirTemp = newTemp()
        arreglo.dir = newTemp()
        genCode(dirTemp’=’ expresion.dir ’*’ tam)
        genCode(arreglo.dir’=’ arreglo1.dir ’+’ dirTemp)
    Sino
        error(...)
    Fin Si
Sino
    error(...)
Fin Si
```
### parametros → lista_param
```
parametros.lista = lista_param.lista
parametros.num = lista_param.num
```
### parametros → ε 
```
parametros.lista = NULO
parametros.num = 0
```
### lista_param → lista_param1 **,** expresion
```
lista_param.lista = lista_param1.lista
lista_param.lista.append(expresion.type)
lista_param.num = lista_param1 + 1
```
### lista_param → expresion 
```
lista_param.lista = newList()
lista_param.lista.append(expresion.type)
lista_param.num = 1
```










## Esquema de Traducción

```
programa → {STS.push(newTS())
            STT.push(newTT())
            dir = 0
            }declaraciones funciones{programa.codigo = funciones.codigo}
```

```
declaraciones → tipo{typeGBL = tipo.type} lista_var; declaraciones

declaraciones → tipo_registro{typeGBL= tipo_registro.type} lista_var; declaraciones

declaraciones → ε 
```

```
tipo_registro → estructura inicio{STS.push(newTS())
                                   STT.push(newTT())
                                   SDir.push(dir)
                                   dir = 0
                                   } declaraciones{SymTab = STS.pop()
                                                    SymTab.typeTab = STT.pop()
                                                    tam = getTam(SymTab)
                                                    dir = SDir.pop()
                                                    tipo registro.type =
                                                    STT.getTop().insert(”struct”, tam, SymTab )} fin
```

```
tipo → base{baseGBL = base.base} tipo_arreglo{tipo.type = tipo arreglo.type}
```

```
base → ent{base.base = STT.getTop().getType(’ent’)}

base → real{base.base = STT.getTop().getType(’real’)}

base → dreal{base.base = STT.getTop().getType(’dreal’)}

base → car{base.base = STT.getTop().getType(’car’)}

base → sin{base.base = STT.getTop().getType(’sin’)}
```

```
tipo_arreglo → [num]{Si num.type = ent Entonces
                        Si num.dir > 0 Entonces
                            tipo arreglo.type = STT.getTop().insert(’array’,num, tipo arreglo1.tipo)
                        Sino
                            error(’...’)
                        Fin Si
                     Sino
                        error(’...’)
                     Fin Si} tipo_arreglo1

tipo_arreglo → ε{tipo_arreglo.type = baseGBL}
```

```
lista_var → lista_var1, id{Si STS.getTop().existe(id) Entonces
                                STS.getTop().insert(id, typeGBL, dir, ’var’, null, null )
                                dir ← dir + STT.getTop().getTam(typeGBL)
                            Sino
                                error(’...’)
                            Fin Si}

lista_var → id{Si STS.getTop().existe(id) Entonces
                    STS.getTop().insert(id, typeGBL, dir, ’var’, null, null )
                    dir ← dir + STT.getTop().getTam(typeGBL)
                Sino
                    error(’...’)
                Fin Si}
```

```
funciones → def tipo id{Si no STS.getGlobal().existe(id) Entonces
                            STS.push(newTS())
                            STT.push(newTT())
                            SDir.push(dir)
                            dir = 0
                            listaRET = newListRet()
                        Sino
                            error('')
                        Fin Si}(argumentos) inicio declaraciones sentencias{Si cmpRet(lista retorno, tipo.type) Entonces
                                                                                L = newLabel()
                                                                                backpatch(sentencias.nextlist, L)
                                                                                genCode(label L)
                                                                                STS.pop()
                                                                                STT.pop()
                                                                            Sino
                                                                                error(’...’)} fin funciones

funciones → ε
```

```
argumentos → lista_arg{argumentos.lista = lista_arg.lista
                        argumentos.num = lista_arg.num}

argumentos → sin{argumentos.lista = NULO
                argumentos.num = 0}
```

```
lista_arg → lista_arg1, arg{lista_arg.lista = lista_arg1.lista
                            lista_arg.lista.append(arg.type)
                            lista_arg.num = lista_arg1.num + 1}

lista_arg → arg{lista_arg.lista = newList()
                lista_arg.lista.append(arg.type)
                lista_arg.num = 1}
```

```
arg → tipo_arg id{Si no STS.getTop().existe(id) Entonces
                    STS.getTop().append(id, tipo.type, dir, ’arg’, NULO, NULO)
                    dir = dir + STT.getTop().getTam(tipo.type)
                    arg.type = tipo.type
                Sino
                    error(...)
                Fin Si}
```

```
tipo_arg → base{baseGBL = base.base} param_arr{baseGBL = base.base}
```

```
param_arr → [ ] param_arr1{param_arr.type = STT.getTop().insert('array'), 0, param_arr1.tipo)}

param_arr → ε{param_arr.type = baseGBL}
```

----------

```
sentencias→ sentencias1{L = newLabel()
                        backpatch(sentencias1.nextlist, L)
                        genCode(label L)} sentencia 
```

```
sentencia → si e_bool{L = newLabel()
                      backpatch(e_bool.truelist, L)
                      } entonces sentencia1 fin {sentencia.nextlist = combinar(e_bool.falselist, sentencia1.nextlist)
                                                 genCode(label L)}
```

```
sentencia → si e_bool {L1 = newLabel()
                       L2 = newLabel()
                       backpatch(e_bool.truelist, L1)
                       backpatch(e_bool.falselist, L2)
                       } 
                       entonces sentencia1 sino sentencia2 fin {sentencia.nextlist = combinar(sentencia1.nextlist, sentencia2.nextlist)
                                                                genCode(label L1)
                                                                genCode('goto' sentencia1.nexlist[0])
                                                                genCode(label L2)
                                                                }
```

```
sentencia → mientras e_bool hacer sentencia1 fin {L1 = newLabel()
                                                  L2 = newLabel()
                                                  backpatch(e_bool.truelist, L2)
                                                  backpatch(sentencia1.nextlist, L1)
                                                  sentencia.nextlist = e_bool.falselist
                                                  genCode(label L1)
                                                  genCode(label L2)
                                                  genCode('goto' sentencia1.nexlist[0])
                                                 }
```

```
sentencia → hacer sentencia1 mientras e_bool; {L = newLabel()
                                               backpatch(sentencia1.nextlist, L)
                                               genCode("label" L)}
```

```
sentencia → segun (variable) hacer casos predeterminado fin {L1 = newLabel()
                                                             prueba = combinar(casos.prueba, predeterminado.prueba)
                                                             backpatch(casos.nextlist, L1)
                                                             sustituir("??", variable.dir, prueba)}
```

--------

```
sentencia → variable := expresion;{ dir = reducir(expresion.dir, epresion.type, variable.type)
                                    Si variable.code est = true Entonces
                                        genCode(variable.base’[’variable.des’]’ ’=’ dir)
                                    Sino
                                        genCode(variable.dir ’=’ dir)
                                    Fin Si}

sentencia → escribir expresion;{gen(”write” expresion.dir)}

sentencia → leer expresion;{gen(”read” expresion.dir)}

sentencia → devolver expresion;{genCode(”return” expresion.dir)}

sentencia → terminar;{index = newIndex()
                    sentencia.nextlist = newIndexList(index)
                    genCode(”goto” index)}

sentencia → inicio sentencias1{sentencia.nextlist = sentencia1.nextlist} fin
```

```
relacional → expresion{relacional.dir = expresion.dir
                       relacional.tipo = expresion.tipo}
```

```
expresion → expresion1 + expresion2{expresion.type = max(expresion1.type, expresion2.type)
                                    expresion.dir = newTemp()
                                    dir1 = ampliar(expresion1.dir, expresion1.type, expresion.type)
                                    dir2 = ampliar(expresion2.dir, expresion2.type, expresion.type)
                                    getCode(expresion.dir ’=’ dir1 ’+’ dir2)}

expresion → expresion1 − expresion2{expresion.type = max(expresion1.type, expresion2.type)
                                    expresion.dir = newTemp()
                                    dir1 = ampliar(expresion1.dir, expresion1.type, expresion.type)
                                    dir2 = ampliar(expresion2.dir, expresion2.type, expresion.type)
                                    getCode(expresion.dir ’=’ dir1 ’-’ dir2)}

expresion → expresion1 * expresion2{expresion.type = max(expresion1.type, expresion2.type)
                                    expresion.dir = newTemp()
                                    dir1 = ampliar(expresion1.dir, expresion1.type, expresion.type)
                                    dir2 = ampliar(expresion2.dir, expresion2.type, expresion.type)
                                    getCode(expresion.dir ’=’ dir1 ’*’ dir2)}

expresion → expresion1 / expresion2{expresion.type = max(expresion1.type, expresion2.type)
                                    expresion.dir = newTemp()
                                    dir1 = ampliar(expresion1.dir, expresion1.type, expresion.type)
                                    dir2 = ampliar(expresion2.dir, expresion2.type, expresion.type)
                                    getCode(expresion.dir ’=’ dir1 ’/’ dir2)}

expresion → expresion1 % expresion2{Si expresion1.type = entero and expresion2.type = entero Entonces
                                        expresion.type = max(expresion1.type,expresion2.type)
                                        expresion.dir = newTemp()
                                        dir1 = ampliar(expresion1.dir, expresion1.type, expresion.type)
                                        dir2 = ampliar(expresion2.dir, expresion2.type, expresion.type)
                                        getCode(expresion.dir ’=’ dir1 ’+’ dir2)
                                    Sino
                                        error(’...’)
                                    Fin Si}

expresion → (expresion1){expresion.type = expresion1.type
                         expresion.dir = expresion1.dir}

expresion → variable{expresion.type = variable.type
                    expresion.dir = variable.dir}

expresion → num{expresion.type = num.type
                expresion.dir = num.dir}

expresion → cadena{expresion.type =’string’
                    Si TablaCadenas.existe(cadena) Entonces
                        expresion.dir= TablaCadena.getIndexStr(cadena)
                    Sino
                        expresion.dir=TalbaCadena.insert(cadena)
                    Fin Si}

expresion → caracter{expresion.type =’car’
                    Si TablaCadenas.existe(car) Entonces
                        expresion.dir= TablaCadena.getIndexStr(car)
                    Sino
                        expresion.dir=TalbaCadena.insert(car)
                    Fin Si}
```

```
variable → id{Si STS.getTop().existe(id) Entonces
              IDGBL = id
              Sino
                error(’...’)
              Fin Si} variable_comp{Si variable_comp.code_est=true Entonces
                                        variable.dir=newTemp()
                                        variable.type = variable_comp.type
                                        genCode(variable.dir ’=’ id’[’ variable_comp.des’]’)
                                        variable.base = id.dir
                                        variable.code_est= true
                                        variable.des = variable_comp.des
                                    Sino
                                        variable.dir = id)
                                        variable.type = STS.getTop().getType(id)
                                        variable.code_est= false}
```

```_
variable_comp → dato_est_sim{variable_comp.type = dato_est_sim.type
                            variable_comp.des = dato_est_sim.des
                            variable_comp.code_est = dato_est_sim.code_est}

variable_comp → arreglo{variable_comp.type = arreglo.type
                        variable_comp.des = arreglo.dir
                        variable_comp.code est = true}

variable_comp → ( parametros )   ##El profe lo tiene incompleto
```

```
dato_est_sim → dato_est_sim1.id{Si dato_est_sim1.estructura = true Entonces
                                    Si dato_est_sim1.tabla.existe(id) Entonces
                                        dato_est_sim.des = dato_est_sim1.des +
                                        dato_est_sim.tabla1.getDir(id)
                                        typeTemp=dato_est_sim1.tabla.getType(id)
                                        estTemp = dato_est_sim1.tabla.tablaTipos.getName(typeTemp)
                                            Si estTemp = ’struct’ Entonces
                                                dato_est_sim.estructura= true
                                                dato_est_sim.tabla= dato_est_sim.tabla.tablaTipos.getTipoBase(typeTemp).tabla
                                            Sino
                                                dato_est_sim.estructura= false
                                                dato_est_sim.tabla= NULO
                                                dato_est_sim.type = dato_est_sim1.tabla.getType(id)
                                            FinSi
                                        dato_est_sim.code est=true
                                    Sino
                                        error(...)
                                    FinSi
                                Sino
                                    error(...)
                                FinSi}

dato_est_sim → ε{typeTemp = STS.getTop().getType(id)
                Si STT.getTop().getName(typeTemp) =’struct’ Entonces
                    dato_est_sim.estructura= true
                    dato_est_sim.tabla = STT.getTop().getTipoBase(typeTemp).tabla
                    dato_est_sim.des = 0
                Sino
                    dato_est_sim.estructura = false
                    dato_est_sim.type = STT.getTop().getType(id)
                Fin Si
                dato_est_sim.code est=false}
```

```
arreglo → [ expresion ]{arreglo.type = STS.getTop().getType(IDGBL)
                        Si STT.getTop().getName(arreglo.type) = ’array’ Entonces
                            Si expresion.type = entero Entonces
                                typeTemp = STT.getTop().getTypeBase(arreglo.type)
                                tam = STT.getTop().getTam(typeTemp)
                                arreglo.dir = newTemp()
                                genCode(arreglo.dir’=’ expresion.dir ’*’ tam)
                            Sino
                                error(...)
                            Fin Si
                        Sino
                            error(...)
                        Fin Si}

arreglo → arreglo1 [ expresion ]{arreglo.type = STS.getTop().getType(arreglo1.type)
                                Si STT.getTop().getName(arreglo.type) = ’array’ Entonces
                                    Si expresion.type = entero Entonces
                                        typeTemp = STT.getTop().getTypeBase(arreglo.type)
                                        tam = STT.getTop().getTam(typeTemp)
                                        dirTemp = newTemp()
                                        arreglo.dir = newTemp()
                                        genCode(dirTemp’=’ expresion.dir ’*’ tam)
                                        genCode(arreglo.dir’=’ arreglo1.dir ’+’ dirTemp)
                                    Sino
                                        error(...)
                                    Fin Si
                                Sino
                                    error(...)
                                Fin Si}

parametros → lista_param{parametros.lista = lista_param.lista
                        parametros.num = lista_param.num}

parametros→ ε{parametros.lista = NULO
              parametros.num = 0}
```

```
lista_param → lista_param1 , expresion

lista_param → expresion 
```
