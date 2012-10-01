#!/usr/bin/env python2
# coding: utf-8

class Pardal:
    def multa(self, speed_user):
        speed_violation = speed_user - speed_max
        full = speed_violation * 500.0
        return full

speed_max = 80
speed_user = int(input("Digite a velocidade: "))
#pardal = Pardal()
valor = Pardal().multa(speed_user)

if speed_user > speed_max:
    print("Você foi multado por excesso de velocidade e o valor da multa é: R$%.2f" % (valor))

elif speed_user <= speed_max:
    print("Velocidade compativel.")
