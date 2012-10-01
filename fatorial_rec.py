#!/usr/bin/env python2
#_*_ coding: utf8 _*_

valor = int(input("Digite o numero que deseja saber o fatorial: "))


def fatorial(valor):
    if valor == 0 or valor == 1:
        return 1
    else:
        fat = valor * fatorial(valor - 1)
        return fat

print ("Fatorial de %d é: %d" % (valor, fatorial(valor)))
