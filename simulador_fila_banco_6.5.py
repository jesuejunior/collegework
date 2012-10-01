#!/usr/bin/env python2
#_*_ coding: utf-8 _*_

msg = "Digite F para adicionar um cliente ao fim da fila \n ou A para realizar um atendimento. S para sair."
msg_invalido = "Operação inválida! Utilize apenas F, A ou S!"
ultimo = 10
x = 0
operacao = None
fila = list(range(1, ultimo + 1))
while operacao != "S":
    print("Existem %d clientes na fila" % len(fila))
    print("Fila atual: ", fila)
    print(msg)
    entrada = input("Operação (F, A ou S):")
    for x in entrada[:]:
        operacao = x
        if operacao == "A":
            if (len(fila)) > 0:
                atendido = fila.pop(0)
                print("Cliente %d atendido." % atendido)
            else:
                print("Fila vazia! Ninguem para atender.")
        elif operacao == "F":
            ultimo += 1
            fila.append(ultimo)
        elif operacao == "S":
            break
        else:
            print(msg_invalido)
