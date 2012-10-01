#!/usr/bin/env python2
# _*_ coding: utf-8 _*_

lista = []
while True:
    n = int(input("Digite um numero (0 para sair): "))
    if n == 0:
        break
    lista.append(n)
x = 0
while x < len(lista):
    print(lista[x])
    x += 1
