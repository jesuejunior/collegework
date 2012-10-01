#!/usr/bin/env python2
#_*_ coding: utf-8 _*_

msg = "Digite F para adicionar um cliente ao fim da fila 1 e G na fila 2 \n ou A para realizar um atendimento na fila 1 e B na fila 2. S para sair."
msg_invalido = "Operação inválida! Utilize apenas F, A ou S!"
ultimof1 = 10
ultimof2 = 10
x = 0
operacao = None
fila1 = list(range(1, ultimof1 + 1))
fila2 = list(range(1, ultimof2 + 1))

while operacao != "S":
    print("Existem %d clientes na fila 1" % len(fila1))
    print("Existem %d clientes na fila 2" % len(fila2))
    print("")
    print("Fila 1 atual: ", fila1)
    print("Fila 2 atual: ", fila2)
    print(msg)
    entrada = input("Operação (A, B, F, G ou S):")

    for x in entrada[:]:
        operacao = x
        if operacao == "A" or operacao == "a":
            if (len(fila1)) > 0:
                atendido = fila1.pop(0)
                print("Cliente %d atendido na fila 1." % atendido)
            else:
                print("Fila vazia! Ninguem para atender.")
        elif operacao == "F" or operacao == "f":
            ultimof1 += 1
            fila1.append(ultimof1)
        elif operacao == "B" or operacao == "b":
            if (len(fila2)) > 0:
                atendido = fila2.pop(0)
                print("Cliente %d atendido na fila 2." % atendido)
            else:
                print("Fila vazia! Ninguem para atender.")
        elif operacao == "G" or operacao == "g":
            ultimof2 += 1
            fila2.append(ultimof2)
        elif operacao == "S" or operacao == "s":
            break

        else:
            print(msg_invalido)
